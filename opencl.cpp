#include "opencl.h"
#define MAX_PLATFORM 10
#define MAX_DEVICE 10

static cl_int err = CL_SUCCESS;
char* readKernelFile(const char* filename)
{
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        char filename2[100];
        sprintf(filename2, ".%s", filename);
        fopen_s(&file, filename2, "r");
        if (file == NULL) {
            printf("Could not open file %s\n", filename2);
            exit(1);
        }
    }

    char* charArray = (char*)malloc(sizeof(char) * MAX_SIZE);
    int i = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF && i < MAX_SIZE - 1) {
        charArray[i] = (char)ch;
        i++;
    }
    charArray[i] = '\0';
    fclose(file);
    return charArray;
}

void chkerr(cl_int err, const char* msg)
{
    if (err != CL_SUCCESS) {
        printf("Error %s: (%d)\n", msg, err);
        exit(EXIT_FAILURE);
    }
}

DeviceInfo* getAllDeviceInfo(cl_uint& num)
{
    cl_uint numPlatforms;
    cl_platform_id platforms[MAX_PLATFORM];
    cl_uint numDevices;
    cl_device_id devices[MAX_DEVICE];
    cl_uint totalDevices = 0;
    DeviceInfo* deviceInfos;
    err = clGetPlatformIDs(MAX_PLATFORM, platforms, &numPlatforms);
    chkerr(err, "getting platforms");
    for (cl_uint i = 0; i < numPlatforms; ++i) {
        err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, MAX_DEVICE,
            devices, &numDevices);
        chkerr(err, "getting devices number");
        totalDevices += numDevices;
    }
    num = totalDevices;
    int count = 0;
    deviceInfos = (DeviceInfo*)malloc(sizeof(DeviceInfo) * totalDevices);
    for (cl_uint i = 0; i < numPlatforms; ++i) {
        err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, MAX_DEVICE,
            devices, &numDevices);
        chkerr(err, "getting devices");
        for (int j = 0; j < numDevices; ++j) {
            deviceInfos[count].platform = platforms[i];
            deviceInfos[count].device = devices[j];
            count++;
        }
    }
    for (cl_uint i = 0; i < totalDevices; ++i) {
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_TYPE,
            sizeof(deviceInfos[i].type),
            &deviceInfos[i].type, NULL);
        chkerr(err, "getting device type");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_NAME,
            sizeof(deviceInfos[i].name), deviceInfos[i].name,
            NULL);
        chkerr(err, "getting device name");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_VENDOR,
            sizeof(deviceInfos[i].vendor),
            deviceInfos[i].vendor, NULL);
        chkerr(err, "getting device vendor");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_VERSION,
            sizeof(deviceInfos[i].version),
            deviceInfos[i].version, NULL);
        chkerr(err, "getting device version");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DRIVER_VERSION,
            sizeof(deviceInfos[i].driverVersion),
            deviceInfos[i].driverVersion, NULL);
        chkerr(err, "getting device driver version");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_MAX_COMPUTE_UNITS,
            sizeof(deviceInfos[i].maxComputeUnits),
            &deviceInfos[i].maxComputeUnits, NULL);
        chkerr(err, "getting device max compute units");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_MAX_CLOCK_FREQUENCY,
            sizeof(deviceInfos[i].maxClockFrequency),
            &deviceInfos[i].maxClockFrequency, NULL);
        chkerr(err, "getting device max clock frequency");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_MAX_WORK_GROUP_SIZE,
            sizeof(deviceInfos[i].maxWorkGroupSize),
            &deviceInfos[i].maxWorkGroupSize, NULL);
        chkerr(err, "getting device max work group size");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_GLOBAL_MEM_SIZE,
            sizeof(deviceInfos[i].globalMemSize),
            &deviceInfos[i].globalMemSize, NULL);
        chkerr(err, "getting device global memory size");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_MAX_MEM_ALLOC_SIZE,
            sizeof(deviceInfos[i].maxMemAllocSize),
            &deviceInfos[i].maxMemAllocSize, NULL);
        chkerr(err, "getting device max memory allocation size");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_MAX_WORK_GROUP_SIZE,
            sizeof(deviceInfos[i].maxWorkGroupSize),
            &deviceInfos[i].maxWorkGroupSize, NULL);
        chkerr(err, "getting device max work group size");
        err = clGetDeviceInfo(deviceInfos[i].device, CL_DEVICE_MAX_WORK_ITEM_SIZES,
            sizeof(deviceInfos[i].maxWorkItemSizes),
            &deviceInfos[i].maxWorkItemSizes, NULL);
        chkerr(err, "getting device max work item sizes");
    }
    return deviceInfos;
}

void printDeviceInfo(DeviceInfo* deviceInfo, cl_uint num)
{
    for (cl_uint i = 0; i < num; i++) {
        printf("Device %d:\n", i);
        printf("  Name: %s\n", deviceInfo[i].name);
        switch (deviceInfo[i].type) {
        case CL_DEVICE_TYPE_CPU:
            printf("  Type: CPU\n");
            break;
        case CL_DEVICE_TYPE_GPU:
            printf("  Type: GPU\n");
            break;
        case CL_DEVICE_TYPE_ACCELERATOR:
            printf("  Type: ACCELERATOR\n");
            break;
        default:
            printf("  Type: UNKNOWN\n");
            break;
        }
        printf("  Vendor: %s\n", deviceInfo[i].vendor);
        printf("  Version: %s\n", deviceInfo[i].version);
        printf("  Driver version: %s\n", deviceInfo[i].driverVersion);
        printf("  Max clock frequency: %d MHz\n", deviceInfo[i].maxClockFrequency);
        printf("  Max compute units: %d\n", deviceInfo[i].maxComputeUnits);
        printf("  Max work group size: %llu\n", deviceInfo[i].maxWorkGroupSize);
        printf("  Global memory size: %llu MB\n", deviceInfo[i].globalMemSize / 1024 / 1024);
        printf("  Max memory allocation size: %llu MB\n", deviceInfo[i].maxMemAllocSize / 1024 / 1024);
        printf("  Max work item sizes: %llu x %llu x %llu\n\n", deviceInfo[i].maxWorkItemSizes[0],
            deviceInfo[i].maxWorkItemSizes[1], deviceInfo[i].maxWorkItemSizes[2]);
    }
}

ContextInfo* setupContext(DeviceInfo* deviceInfo, cl_uint num)
{
    ContextInfo* contextInfo = (ContextInfo*)malloc(num * sizeof(ContextInfo));
    for (cl_uint i = 0; i < num; ++i) {
        contextInfo[i].deviceInfo = &deviceInfo[i];
        contextInfo[i].context = clCreateContext(NULL, 1, &deviceInfo[i].device, NULL, NULL, &err);
        chkerr(err, "clCreateContext");
        contextInfo[i].queue = clCreateCommandQueue(contextInfo[i].context, deviceInfo[i].device, 0, &err);
        chkerr(err, "clCreateCommandQueue");
    }
    return contextInfo;
}

void setupProgram(ContextInfo* contextInfo, const char* filename)
{
    const char* kernelSource = readKernelFile(filename);
    contextInfo->program = clCreateProgramWithSource(contextInfo->context, 1, &kernelSource, NULL, &err);
    chkerr(err, "clCreateProgramWithSource");
    err = clBuildProgram(contextInfo->program, 1, &contextInfo->deviceInfo->device, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to build program executable!\n");
        size_t len;
        char buffer[1024 * 64];
        clGetProgramBuildInfo(contextInfo->program, contextInfo->deviceInfo->device, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        exit(1);
    }
    free((void*)kernelSource);
}
void setupProgram2(ContextInfo* contextInfo, const char* kernelSource)
{
    contextInfo->program = clCreateProgramWithSource(contextInfo->context, 1, &kernelSource, NULL, &err);
    chkerr(err, "clCreateProgramWithSource");
    err = clBuildProgram(contextInfo->program, 1, &contextInfo->deviceInfo->device, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to build program executable!\n");
        size_t len;
        char buffer[1024 * 64];
        clGetProgramBuildInfo(contextInfo->program, contextInfo->deviceInfo->device, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        exit(1);
    }
    free((void*)kernelSource);
}
void setupKernel(ContextInfo* contextInfo, const char* kernelname)
{
    contextInfo->kernel = clCreateKernel(contextInfo->program, kernelname, &err);
    chkerr(err, "clCreateKernel");
}
