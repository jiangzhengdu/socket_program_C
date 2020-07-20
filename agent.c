#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>
typedef struct DeviceInfo_st {
    unsigned char DeviceID[32];
    unsigned char DeviceType[32];
    unsigned char DeviceVersion[32];
    unsigned char DeviceName[32];
    unsigned char DeviceCompany[32];
    unsigned char DeviceAsymmetric[32];
    unsigned char DeviceSymmertic[32];
    unsigned char DeviceHash[32];
    unsigned char  DeviceStorage[32];
    unsigned char DeviceDescription[32];
    unsigned char Valid[32];
}DEVICEINFO;
enum Info{DeviceID=1,DeviceType,DeviceVersion,DeviceName,DeviceCompany,DeviceAsymmetric,DeviceSymmertic,DeviceHash,DeviceStroage,DeviceDescription,Valid};
int SMF_Initialize(void** pMangeHandle);
int SMF_Finalize(void* MangeHandle);
int SMF_GetDeviceCount(void* MangeHandle);
int SMF_GetDeviceInfo(void* MangeHandle, DEVICEINFO* pDeviceInfo);
int SMF_SetDeviceInfo(void* MangeHandle, unsigned char deviceID[32], unsigned char* pData,enum Info rank);

int main ()
{
void ** pMangeHandle;
void * MangeHandle;
SMF_Initialize(pMangeHandle);
//SMF_Finalize(MangeHandle);
DEVICEINFO device;
SMF_GetDeviceInfo(MangeHandle,&device);
// printf("%s,%d",device.Valid,strlen(device.Valid));
char DeviceId[32]="002";
enum Info rank=DeviceName;
unsigned char pData[32]="it's been modifyed";
SMF_SetDeviceInfo(MangeHandle,DeviceID,pData,rank);


}


int SMF_Initialize(void** pMangeHandle) {
DEVICEINFO device;
unsigned char DeviceID[32]="0001";
unsigned char DeviceType[32]="sercure device";
unsigned char DeviceVersion[32]="1.0";
unsigned char DeviceName[32]="first one";
unsigned char DeviceCompany[32]="jiangnan";
unsigned char DeviceAsymmetric[32]="RSA";
unsigned char DeviceSymmertic[32]="DES";
unsigned char DeviceHash[32]="HASH";
unsigned char DeviceStorage[32]="1 GB";
unsigned char DeviceDescription[32]="THIS IS A SECURE DEVICE";
unsigned char Valid[32]="valid";
strcpy(device.DeviceID,DeviceID);
strcpy(device.DeviceType,DeviceType);
strcpy(device.DeviceVersion,DeviceVersion);
strcpy(device.DeviceName,DeviceName);
strcpy(device.DeviceCompany,DeviceCompany);
strcpy(device.DeviceAsymmetric,DeviceAsymmetric);
strcpy(device.DeviceSymmertic,DeviceSymmertic);
strcpy(device.DeviceHash,DeviceHash);
strcpy(device.DeviceStorage,DeviceHash);
strcpy(device.DeviceStorage,DeviceStorage);
strcpy(device.DeviceDescription,DeviceDescription);
strcpy(device.Valid,Valid);
FILE *fpWrite=fopen("device.txt","w");
if(fpWrite==NULL){
return 0;
}
fprintf(fpWrite,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",device.DeviceID,device.DeviceType,device.DeviceVersion,device.DeviceName,device.DeviceCompany,device.DeviceAsymmetric,device.DeviceSymmertic,device.DeviceHash,device.DeviceStorage,device.DeviceDescription,device.Valid);
fclose(fpWrite);
}

int SMF_Finalize(void* MangeHandle)
{   
int line=0;
char modify[32]="not valid";
FILE*fp1=fopen("device.txt","r");
FILE*fp2=fopen("device_temp.txt","w");
if(fp1==NULL||fp2==NULL){
puts("file cannnot open！");
return 0;
}
char c;
c=fgetc(fp1);
while(!feof(fp1))
{  return 0;
c=fgetc(fp1);
if(c=='\n')
line++;
fputc(c,fp2);
if(line==10)
    {
    fputs(modify,fp2);
    fputc('\n',fp2);
    break;
    }
}
fclose(fp1);
fclose(fp2);
free(fp1);
free(fp2);
system("mv device_temp.txt device.txt");
return 0;
}

int SMF_GetDeviceCount(void* MangeHandle){
    return 1;
}

int SMF_GetDeviceInfo(void* MangeHandle, DEVICEINFO* pDeviceInfo)
{
char buff[32];
int line=0;
memset(buff,'\0',32);
FILE*fpread=fopen("device.txt","r");
while(!feof(fpread)){
memset(buff,'\0',32);
fgets(buff,33,fpread);
int nLen=strlen(buff);
if(buff[nLen-1]=='\n')
buff[nLen-1]='\0';
switch (line)
{
case 0:
    strcpy(pDeviceInfo->DeviceID,buff);
      printf("%s\n",buff);
      
    break;
case 1:
    strcpy(pDeviceInfo->DeviceType,buff);
    break;
case 2:
    strcpy(pDeviceInfo->DeviceVersion,buff);
    break;
case 3:
    strcpy(pDeviceInfo->DeviceName,buff);
    break;
case 4:
    strcpy(pDeviceInfo->DeviceCompany,buff);
    break;
case 5:
    strcpy(pDeviceInfo->DeviceAsymmetric,buff);
    break;
case 6:
    strcpy(pDeviceInfo->DeviceSymmertic,buff);
    break;
case 7:
    strcpy(pDeviceInfo->DeviceHash,buff);
    break;
case 8:
    strcpy(pDeviceInfo->DeviceStorage,buff);  
    break;
case 9:
    strcpy(pDeviceInfo->DeviceDescription,buff);
    break;
case 10:
    strcpy(pDeviceInfo->Valid,buff);
    break;
default:
    break;
}
line++;
}
}

int SMF_SetDeviceInfo(void* MangeHandle, unsigned char deviceID[32], unsigned char* pData,enum Info type)
{
int line=0;
FILE*fp1=fopen("device.txt","r");
FILE*fp2=fopen("device_temp.txt","w");
if(fp1==NULL||fp2==NULL){
puts("file cannnot open！");
return 0;
}
char buff[32];
memset(buff,'\0',32);
while(!feof(fp1))
{
memset(buff,'\0',32);
fgets(buff,33,fp1);
line++;
if(line==type)
    {
    fputs(pData,fp2);
    fputc('\n',fp2);
    continue;
    }
else fputs(buff,fp2);
}
fclose(fp1);
fclose(fp2);
free(fp1);
free(fp2);
system("mv device_temp.txt device.txt");
return 0;
}
