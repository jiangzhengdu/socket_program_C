//
//  function.c
//  test
//
//  Created by  Du的mbp 13 on 9/13/20.
//  Copyright © 2020  Du的mbp 13. All rights reserved.
//

#include "function.h"
//unsigned char pData[32]="it's been modifyed";
int SMF_Initialize(void** pMangeHandle,unsigned char message[]) {     //初始化
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
    return 1;
}

int SMF_GetDeviceInfo(void* MangeHandle, unsigned char message[],unsigned char result[])
{
    result[0]=101;
    int i=0,j=0;  //i用于result的index。j用于buff的index
    char buff[33];
    int line=0;
    memset(buff,'\0',33);
    FILE*fpread=fopen("device.txt","r");
    while(!feof(fpread)){
        memset(buff,'\0',33);
        fgets(buff,33,fpread);
        int nLen=strlen(buff);
        if(buff[nLen-1]=='\n')
            buff[nLen-1]='\0';
        switch (line)
        {
            case 0:
                for(i=1,j=0;i<=32;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 1:
                for(i=33,j=0;i<=64;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 2:
                for(i=65,j=0;i<=96;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 3:
                for(i=97,j=0;i<=128;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 4:
                for(i=129,j=0;i<=160;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 5:
                for(i=161,j=0;i<=192;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 6:
                for(i=193,j=0;i<=224;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 7:
                for(i=225,j=0;i<=256;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 8:
                for(i=257,j=0;i<=288;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 9:
                for(i=289,j=0;i<=320;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            case 10:
                for(i=321,j=0;i<=352;i++,j++)
                    result[i]=buff[j];
                printf("%s\n",buff);
                break;
            default:
                break;
        }
        line++;
    }
    
    return 1;
}

int SMF_SetDeviceInfo(void* MangeHandle, unsigned char message[])
{
    int line=0;
    int i=0,j=0;
    FILE*fp1=fopen("device.txt","r");
    FILE*fp2=fopen("device_temp.txt","w");
    if(fp1==NULL||fp2==NULL){
        puts("file cannnot open！");
        return 0;
    }
    unsigned char buff1[33];
    unsigned char buff2[32];    //被修改后的属性
    memset(buff1,'\0',33);
    memset(buff1,'\0',32);
    for(i=2,j=0;i<=33; i++,j++)
        buff2[j]=message[i];
    while(!feof(fp1))
    {
        memset(buff1,'\0',32);
        fgets(buff1,33,fp1);
        line++;
        if(line==message[1])
        {
            printf("find the line\n");
            fputs(buff2,fp2);
            fputc('\n',fp2);
            continue;
        }
        else fputs(buff1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    // free(fp1);
    // free(fp2);
    system("mv device_temp.txt device.txt");
    return 0;
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
    //c=fgetc(fp1);
    while(!feof(fp1))
    {
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
   // free(fp1);
   // free(fp2);
    system("mv device_temp.txt device.txt");
    return 0;
}

int SMF_GetTrapInfo(void * MangeHandle, unsigned char message[]){
    unsigned char LocalTrap[32];
    memset(LocalTrap, '\0', 32*sizeof(unsigned char));
    FILE* fp1=fopen("TrapLog.txt","a");
    int i=0,j=0;
    for(i=0,j=1;j<=32;i++,j++)
        LocalTrap[i]=message[j];
    
    if(fp1==NULL){
        puts("file cannnot open！");
        return 0;
    }
    for(i=0;i<=31;i++)
        fputc(LocalTrap[i],fp1);
    fclose(fp1);
    return 0;
}
