//
//  function.h
//  test
//
//  Created by  Du的mbp 13 on 9/13/20.
//  Copyright © 2020  Du的mbp 13. All rights reserved.
//

#ifndef function_h
#define function_h

#include <stdio.h>
#include <stdlib.h>
#endif /* function_h */

typedef struct DeviceInfo_st {
    unsigned char DeviceID[32];
    unsigned char DeviceType[32];
    unsigned char DeviceVersion[32];
    unsigned char DeviceName[32];
    unsigned char DeviceCompany[32];
    unsigned char DeviceAsymmetric[32];
    unsigned char DeviceSymmertic[32];
    unsigned char DeviceHash[32];
    unsigned char DeviceStorage[32];
    unsigned char DeviceDescription[32];
    unsigned char Valid[32];
}DEVICEINFO;
enum Operation{Initialize=100,Finalize,GetDeviecCount,GetDeviceInfo,SetDeviceInfo,KeyGenerate};
enum InfoType{DeviceID=1,DeviceType,DeviceVersion,DeviceName,DeviceCompany,DeviceAsymmetric,DeviceSymmertic,DeviceHash,DeviceStroage,DeviceDescription,Valid};
//unsigned char pData[32]="it's been modifyed";
int SMF_Initialize(void** pMangeHandle,unsigned char message[]);
int SMF_GetDeviceInfo(void* MangeHandle, unsigned char message[],unsigned char result[]);
int SMF_SetDeviceInfo(void* MangeHandle, unsigned char message[]);
int SMF_Finalize(void* MangeHandle);
int SMF_GetTrapInfo(void * MangeHandle, unsigned char message[]);
int SMF_SetTrapInfo(void * MangeHandle, unsigned char message[]);
