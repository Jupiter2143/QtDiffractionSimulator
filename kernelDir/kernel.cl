#define SIZE 1024
#define CIRC 0
#define RECT 1
#define PT 2

typedef struct SubPixel
{
    int shape;
    float length;
    float width;
    float rho;
    float xRelative;
    float yRelative;
    float reflectance;
} SubPixel;

typedef struct LOAD
{
    float scale;
    float l0;
    float L0;
    float xCenter;
    float yCenter;
    float theta;
    int beamShape;
    float beamRadius;
    float beamLambda;
    float xSpacing;
    float ySpacing;
    float xOffset;
    float yOffset;
    int subpixelsCount;
    SubPixel subpixels[10];
    int j_limit;
    float r_square;
    float y_spacing_square;
    float sin_theta;
    float cos_theta;
    float wave_number;

} LOAD;

__global LOAD *load;

#define scale load->scale
#define l0 load->l0
#define L0 load->L0
#define theta load->theta
#define beamShape load->beamShape
#define beamRadius load->beamRadius
#define beamLambda load->beamLambda
#define xSpacing load->xSpacing
#define ySpacing load->ySpacing
#define xOffset load->xOffset
#define yOffset load->yOffset
#define subpixelsCount load->subpixelsCount
#define subpixels load->subpixels
#define j_limit load->j_limit
#define r_square load->r_square
#define y_spacing_square load->y_spacing_square
#define sin_theta load->sin_theta
#define cos_theta load->cos_theta
#define wave_number load->wave_number
#define xCenter load->xCenter
#define yCenter load->yCenter

static inline float sinc_pi(float x)
{
    if (x >= 1.43051e-5 || x <= -1.43051e-5)
    {
        return sin(x) / x;
    }
    else
    {
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
    if (ax < 8.0f)
    {
        y = x * x;
        ans1 = x * (72362614232.0f + y * (-7895059235.0f +
                                          y * (242396853.1f + y * (-2972611.439f +
                                                                   y * (15704.48260f + y * (-30.16036606f))))));
        ans2 = 144725228442.0f + y * (2300535178.0f +
                                      y * (18583304.74f + y * (99447.43394f +
                                                               y * (376.9991397f + y))));
        ans = ans1 / ans2;
    }
    else
    {
        z = 8.0f / ax;
        y = z * z;
        xx = ax - 2.356194491f;
        ans1 = 1.0 + y * (-0.1098628627e-2f + y * (0.2734510407e-4f +
                                                   y * (-0.2073370639e-5f + y * 0.2093887211e-6f)));
        ans2 = -0.1562499995e-1f + y * (0.1430488765e-3f +
                                        y * (-0.6911147651e-5f + y * (0.7621095161e-6f -
                                                                      y * 0.934935152e-7f)));
        ans = sqrt(0.636619772f / ax) *
              (cos(xx) * ans1 - z * sin(xx) * ans2);
    }
    return ans;
}
static inline float jinc(float x)
{
    if (x == 0.0f)
    {
        return 1.0f;
    }
    return 2.0f * J1(M_PI * x) / (M_PI * x);
}

static inline void doNormDiff(float x, float y, float l, float L, float *RE, float *IM)
{
    float temp = wave_number * ((x * x + y * y) / (2 * L) + l + L);
    *RE += cos(temp);
    *IM += sin(temp);
}
static inline void doRectDiff(float length, float width, float x, float y, float l, float L, float *RE, float *IM)
{

    float temp = wave_number * ((x * x + y * y) / (2 * L) + l + L);
    float Sinc_factor = sinc(length * x * cos_theta / (beamLambda * L)) * sinc(width * y / (beamLambda * L));
    *RE += Sinc_factor * cos(temp);
    *IM += Sinc_factor * sin(temp);
}
static inline void doCircDiff(float rho, float x, float y, float l, float L, float *RE, float *IM)
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
    for (int k = 0; k < subpixelsCount; k++)
    {
        RE = 0;
        IM = 0;
        temp_shape = subpixels[k].shape;
        temp_length = subpixels[k].length;
        temp_width = subpixels[k].width;
        temp_rho = subpixels[k].rho;
        temp_x_relative = subpixels[k].xRelative;
        temp_y_relative = subpixels[k].yRelative;
        for (int j = -j_limit; j <= j_limit; j++)
        {
            a_offset = fmod(j * xOffset, xSpacing);
            b = j * ySpacing + temp_y_relative;
            if (beamShape == CIRC)
                i_limit = sqrt(r_square - j * j * y_spacing_square) / xSpacing / cos_theta;
            else if (beamShape == RECT)
                i_limit = beamRadius / xSpacing / cos(theta);
            for (int i = -i_limit; i <= i_limit; i++)
            {
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

__kernel void diff(__global LOAD *input, __global float *result)
{
    int i = get_global_id(0);
    int j = get_global_id(1);
    load = input;
//    printf("xCenter = %f, yCenter = %f, scale = %f\n", xCenter, yCenter, scale);y
    result[i + j * SIZE] = calIntensity((i - 512) * scale + xCenter , (j - 512) * scale - yCenter);
}
