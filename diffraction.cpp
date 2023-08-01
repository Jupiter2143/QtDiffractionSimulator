#include "diffraction.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SIZE 1024
#define CIRC 0
#define RECT 1
#define PT 2

#define scale Diffraction::load->scale
#define l0 Diffraction::load->l0
#define L0 Diffraction::load->L0
#define theta Diffraction::load->theta
#define beamShape Diffraction::load->beamShape
#define beamRadius Diffraction::load->beamRadius
#define beamLambda Diffraction::load->beamLambda
#define xSpacing Diffraction::load->xSpacing
#define ySpacing Diffraction::load->ySpacing
#define xOffset Diffraction::load->xOffset
#define yOffset Diffraction::load->yOffset
#define subpixelsCount Diffraction::load->subpixelsCount
#define subpixels Diffraction::load->subpixels
#define j_limit Diffraction::load->j_limit
#define r_square Diffraction::load->r_square
#define y_spacing_square Diffraction::load->y_spacing_square
#define sin_theta Diffraction::load->sin_theta
#define cos_theta Diffraction::load->cos_theta
#define wave_number Diffraction::load->wave_number

Load* Diffraction::load = nullptr;

static inline float sinc_pi(float x)
{
    if (x >= 1.43051e-5 || x <= -1.43051e-5) {
        return sin(x) / x;
    } else {
        return 1.0f - x * x / 6.0f;
    }
}
static inline float sinc(float x)
{
    return sinc_pi(M_PI * x);
}
static inline float J1(float x)
{
    float ax, z;
    float xx, y, ans, ans1, ans2;
    ax = (x > 0.0f) ? x : -x;
    if (ax < 8.0f) {
        y = x * x;
        ans1 = x * (72362614232.0f + y * (-7895059235.0f + y * (242396853.1f + y * (-2972611.439f + y * (15704.48260f + y * (-30.16036606f))))));
        ans2 = 144725228442.0f + y * (2300535178.0f + y * (18583304.74f + y * (99447.43394f + y * (376.9991397f + y))));
        ans = ans1 / ans2;
    } else {
        z = 8.0f / ax;
        y = z * z;
        xx = ax - 2.356194491f;
        ans1 = 1.0 + y * (-0.1098628627e-2f + y * (0.2734510407e-4f + y * (-0.2073370639e-5f + y * 0.2093887211e-6f)));
        ans2 = -0.1562499995e-1f + y * (0.1430488765e-3f + y * (-0.6911147651e-5f + y * (0.7621095161e-6f - y * 0.934935152e-7f)));
        ans = sqrt(0.636619772f / ax) * (cos(xx) * ans1 - z * sin(xx) * ans2);
    }
    return ans;
}
static inline float jinc(float x)
{
    if (x == 0.0f) {
        return 1.0f;
    }
    return 2.0f * J1(M_PI * x) / (M_PI * x);
}

static inline void doNormDiff(float x, float y, float l, float L, float* RE, float* IM)
{
    float temp = wave_number * ((x * x + y * y) / (2 * L) + l + L);
    *RE += cos(temp);
    *IM += sin(temp);
}
static inline void doRectDiff(float length, float width, float x, float y, float l, float L, float* RE, float* IM)
{

    float temp = wave_number * ((x * x + y * y) / (2 * L) + l + L);
    float Sinc_factor = sinc(length * x * cos_theta / (beamLambda * L)) * sinc(width * y / (beamLambda * L));
    *RE += Sinc_factor * cos(temp);
    *IM += Sinc_factor * sin(temp);
}
static inline void doCircDiff(float rho, float x, float y, float l, float L, float* RE, float* IM)
{
    float temp = wave_number * ((x * x + y * y) / (2 * L) + l + L);
    float Jinc_factor = jinc(2 * rho * sqrt(x * x * cos_theta * cos_theta + y * y) / (beamLambda * L));
    *RE += Jinc_factor * cos(temp);
    *IM += Jinc_factor * sin(temp);
}

static inline float calIntensity(float x, float y)
{
    float a, b, a_offset, b_offset;
    int i_limit = 0;
    int temp_shape;
    float temp_length, temp_width, temp_rho, temp_x_relative, temp_y_relative;
    float temp1, temp2, temp3, temp4;
    float RE = 0;
    float IM = 0;
    float final_RE = 0;
    float final_IM = 0;
    for (int k = 0; k < subpixelsCount; k++) {
        RE = 0;
        IM = 0;
        temp_shape = subpixels[k].shape;
        temp_length = subpixels[k].length;
        temp_width = subpixels[k].width;
        temp_rho = subpixels[k].rho;
        temp_x_relative = subpixels[k].xRelative;
        temp_y_relative = subpixels[k].yRelative;
        for (int j = -j_limit; j <= j_limit; j++) {
            a_offset = fmod(j * xOffset, xSpacing);
            b = j * ySpacing + temp_y_relative;
            if (beamShape == CIRC)
                i_limit = sqrt(r_square - j * j * y_spacing_square) / xSpacing / cos_theta;
            else if (beamShape == RECT)
                i_limit = beamRadius / xSpacing / cos(theta);
            for (int i = -i_limit; i <= i_limit; i++) {
                b_offset = fmod(i * yOffset, ySpacing);
                a = i * xSpacing + temp_x_relative;
                temp1 = x - (a + a_offset) * cos_theta;
                temp2 = y - (b + b_offset);
                temp3 = l0 + a * sin_theta;
                temp4 = L0 - a * sin_theta;
                if (temp_shape == PT)
                    doNormDiff(temp1, temp2, temp3, temp4, &RE, &IM);
                else if (temp_shape == RECT)
                    doRectDiff(temp_length, temp_width, temp1, temp2, temp3, temp4, &RE, &IM);
                else if (temp_shape == CIRC)
                    doCircDiff(temp_rho, temp1, temp2, temp3, temp4, &RE, &IM);
            }
        }
        final_RE += RE * subpixels[k].reflectance;
        final_IM += IM * subpixels[k].reflectance;
    }
    return final_RE * final_RE + final_IM * final_IM;
}

Diffraction::Diffraction()
{
    tempMatrix = new float[SIZE * SIZE];
    intensityMatrix = new int[SIZE * SIZE];
    global_work_size[0] = SIZE;
    global_work_size[1] = SIZE;
    local_work_size[0] = 16;
    local_work_size[1] = 16;
    if (load == nullptr) {
        load = new Load {
            0.0002f,
            0.5f,
            0.8668f,
            0.0f,
            0.0f,
            58.89f / 180 * M_PI,
            CIRC,
            1.0e-3f,
            6.35e-7f,
            6.382e-5f,
            6.382e-5f,
            0,
            0,
            2,
            { { RECT, 3.191e-6f, 3.191e-6f, 1.5955e-5f, -1.5955e-5f, 0, 1 }, { RECT, 3.191e-6f, 3.191e-6f, 1.5955e-5f, 1.5955e-5f, 0, 2 } },
            (int)(1.0e-3f / 6.382e-5f),
            1.0e-3f * 1.0e-3f,
            6.382e-5f * 6.382e-5f,
            0.8571673f,
            0.5150381f,
            2 * M_PI / 6.35e-7f,
        };
    }
}

int* Diffraction::doNormalDiff(int* progress)
{
#pragma omp parallel for
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            tempMatrix[i + j * SIZE] = calIntensity((i - 512) * scale, (j - 512) * scale);
    getMatrix();
    return intensityMatrix;
}

void Diffraction::initOpenCL(const char* kernelSource)
{
    DeviceInfo* devices = getAllDeviceInfo(numDevices);
    contextInfo = setupContext(devices, numDevices);
    //    setupProgram(&contextInfo[0], ".\\kernel.cl");
    setupProgram2(&contextInfo[0], kernelSource);
    setupKernel(&contextInfo[0], "diff");

    loadBuffer = clCreateBuffer(contextInfo[0].context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(Load), load, &err);
    chkerr(err, "create buffer");
    intensityMatrixBuffer = clCreateBuffer(contextInfo[0].context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, sizeof(float) * SIZE * SIZE, NULL, &err);
    chkerr(err, "create buffer");
    err = clSetKernelArg(contextInfo[0].kernel, 0, sizeof(cl_mem), &loadBuffer);
    chkerr(err, "commit message");
    err = clSetKernelArg(contextInfo[0].kernel, 1, sizeof(cl_mem), &intensityMatrixBuffer);
    chkerr(err, "set arg 1");
}

void Diffraction::getMatrix()
{

    float max = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
        if (tempMatrix[i] > max)
            max = tempMatrix[i];
    for (int i = 0; i < SIZE * SIZE; i++)
        intensityMatrix[i] = (int)((tempMatrix[i] / max) * 255);
}

int* Diffraction::doOpenCLDiff(int* progress)
{
    clEnqueueWriteBuffer(contextInfo[0].queue, loadBuffer, CL_TRUE, 0, sizeof(Load), load, 0, NULL, NULL);
    chkerr(err, "write buffer");

    err = clEnqueueNDRangeKernel(contextInfo[0].queue, contextInfo[0].kernel, 2,
        NULL, global_work_size, local_work_size, 0, NULL,
        NULL);
    chkerr(err, "enqueueing kernel");

    err = clEnqueueReadBuffer(contextInfo[0].queue, intensityMatrixBuffer, CL_TRUE, 0,
        sizeof(float) * SIZE * SIZE, tempMatrix, 0, NULL, NULL);
    chkerr(err, "reading back buffer");

    getMatrix();

    return intensityMatrix;
}

Diffraction::~Diffraction()
{
    //    printf("Destructor called\n");
    free(tempMatrix);
    free(intensityMatrix);
}
