#ifndef DIFFRACTION_H
#define DIFFRACTION_H
#include "opencl.h"
#include <chrono>
#include <cmath>
#include <iostream>
#include <omp.h>

struct SubPixel {
    int shape;
    float length;
    float width;
    float rho;
    float xRelative;
    float yRelative;
    float reflectance;
};

struct Load {
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
};

class Diffraction {
public:
    static Load* load;
    ContextInfo* contextInfo;
    float* tempMatrix;
    int* intensityMatrix;
    size_t global_work_size[2];
    size_t local_work_size[2];
    Diffraction();
    void initOpenCL(const char* kernelSource);
    int* doNormalDiff(int* progress = NULL);
    int* doOpenCLDiff(int* progress = NULL);
    ~Diffraction();

private:
    cl_int err;
    cl_uint numDevices;
    cl_mem loadBuffer;
    cl_mem intensityMatrixBuffer;
    void getMatrix();
};

#endif // DIFFRACTION_H
