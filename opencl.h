#ifndef OPENCL_H
#define OPENCL_H
#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10000 // 读取文件的最大字符数
struct DeviceInfo
{
    cl_platform_id platform;    // 平台ID
    cl_device_id device;        // 设备ID
    cl_device_type type;        // 设备类型
    char name[128];             // 设备名称
    char vendor[128];           // 设备制造商
    char version[128];          // 设备支持的OpenCL版本
    char driverVersion[128];    // 设备驱动版本
    cl_uint maxComputeUnits;    // 设备的计算单元数量
    cl_uint maxClockFrequency;  // 设备的时钟频率
    cl_ulong globalMemSize;     // 设备的全局内存大小（字节）
    cl_ulong maxMemAllocSize;   // 设备支持的最大内存分配大小（字节）
    size_t maxWorkGroupSize;    // 设备支持的最大工作组大小
    size_t maxWorkItemSizes[3]; // 设备支持的每个维度的最大工作项数量
    ~DeviceInfo()
    {
        clReleaseDevice(device);
    }
};
struct ContextInfo
{
    DeviceInfo *deviceInfo; // 设备信息
    cl_context context;     // 上下文
    cl_command_queue queue; // 命令队列
    cl_program program;     // 程序
    cl_kernel kernel;    // 内核
    ~ContextInfo()
    {
        //        clReleaseKernel(*kernel);
        clReleaseProgram(program);
        clReleaseCommandQueue(queue);
        clReleaseContext(context);
    }
};

float J1(float x);

void chkerr(cl_int err, const char *msg);

char *readKernelFile(const char *filename);

DeviceInfo *getAllDeviceInfo(cl_uint &num);

void printDeviceInfo(DeviceInfo *deviceInfo, cl_uint num);

ContextInfo *setupContext(DeviceInfo *deviceInfo, cl_uint num);

void setupProgram(ContextInfo *contextInfo, const char *filename);

void setupKernel(ContextInfo *contextInfo, const char *kernelname);

#endif // OPENCL_H
