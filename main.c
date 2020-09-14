
/*
 
 message的定义
 message[0]  操作符
 if message[0]==101  则操作为获取设备信息
 返回的result的信息（字节流）按照
 unsinged char Operation[1]
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
 规范
 
 if message[0]==100 则操作为设置初始化
 
 if message[0]==103 则操作为终止设备信息
 
 if message[0]==102 则操作符为设置修改设备信息
 返回值1为成功，0为失败
 message的信息规范：
 unsinged char Operation[1]
 enum InfoType type
 unsinged char Content[32]
 
 */
#include<stdio.h>
#include <string.h>
#include "function.h"

int main(){
    void **pMangeHandle;
    void *MangeHandle;
    unsigned char message[20];
    unsigned char result[360];
    //memset(message,'\0',360*sizeof(unsigned char ));
    message[0]=103;
    message[1]=1;
    message[2]='a';
    switch (message[0]) {
        case 100:
            printf("%d\n",SMF_Initialize(pMangeHandle, message));
            printf("initializa success");
            break;
        case 101:
            SMF_GetDeviceInfo(MangeHandle, message, result);
            for(int i=1;i<360;i++){
                if(result[i]=='\0')
                    printf(" ");
                printf("%c",result[i]);
            }
            printf("\n%d\n",strlen(result));
            break;
        case 102:
            printf("%d",SMF_SetDeviceInfo(MangeHandle, message));
            
            break;
        case 103:
            printf("%d\n",SMF_Finalize(MangeHandle));
        default:
            break;
    }
    return 0;
}



