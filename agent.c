// 安全设备管理.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
typedef struct DeviceInfo_st {
    unsigned char DeviceID[32];
    unsigned char DeviceType[16];
    unsigned int  DeviceVersion;
    unsigned char DeviceName[40];
    unsigned char DeviceCompany[32];
    unsigned char DeviceAsymmetric[32];
    unsigned char DeviceSymmertic[32];
    unsigned char DeviceHash[32];
    unsigned int  DeviceStorage;
    unsigned char DeviceDescription[32];
}DEVICEINFO;

# define SMR_OK  0X00000000
# define SMR_UNKNOWERR 0X03000001
# define SMR_ERRVAL 0X03000003
# define SMR_TRAPTYPE 0X03000004
# define SMR_DEVNUM 0X03000002
int SMF_Initialize(void** pMangeHandle)   //
{

    return 0;
}

int SMF_Finalize(void* MangeHandle)
{
    return 0;
}

int SMF_GetDeviceCount(void* MangeHandle, unsigned int* pDevivceCount, unsigned char pDeviceID[])
{
    return 0;
}

int SMF_GetDeviceInfo(void* MangeHandle, unsigned char deviceID[32], DEVICEINFO* pDeviceInfo)
{
    return 0;
}

int SMF_SetDeviceInfo(void* MangeHandle, unsigned char deviceID[32], SMD_AID typeAID, unsigned char* pData)
{
    return 0;
}

int SMF_SecTunnelSendData(void* MangeHandle, unsigned char* sendData, unsigned char* replyData, unsigned int* pDeviceCount, unsigned char deviceID[32])
{
    return 0;
}

int SMF_GetTrapInfo(void* MnageHandle, int trapType, unsigned int trapNum, unsigned char pDeviveID[])
{
    return 0;
}

int SMF_SetTrapInfo(void* MangeHandle, unsigned char deviceID[32], int trapType, unsigned int trapNum)
{
    return 0;
}

int mian()
{
    return 0;
}


// 线程1 监听  
// 线程2 对设备资源管理监听 
// 报警  cpu   
