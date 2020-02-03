#include <iostream>
#include <initguid.h>
#include <windows.h>
#include <Setupapi.h>
#include <string>
#include "stdafx.h"
Buffer length
#define BUFF_LEN 20
using namespace std;

string input_line;
HANDLE port;

double Time[20000];
short Coord[20000];
int countK=0;
char buffer[16] = {0};
char read[3] = {0};


unsigned char dst[10] = {0};

unsigned long size = sizeof(dst);


short pendStartPoint;
short pendOffset;

enum work {WritePy, ReadPy, WriteArd,ReadArd};

enum afterRead {N,W,M,S,C};


void clear(){

for(int i=0;i<20000;i++)
    Time[i]=0;
    Coord[i]=0;
}


int _tmain(int argc, _TCHAR* argv[])
{
work w =ReadPy;
//Store com port information
TCHAR pszPortName[BUFF_LEN] ={0};
//function to get com id
GetComPort(pszPortName,L"2341",L"0042");


HANDLE port = CreateFile("COM"+pszPortName, GENERIC_READ | GENERIC_WRITE, 0, NULL,
			OPEN_EXISTING, 0, NULL);

			
			
swicth(w){
    

    
    case ReadPy:
        
        fgets(read,3,stdout);
        switch(read[0]){
        
        case 'S':
            fgets(read,3,stdout);
            for (int i = 0; i < sizeof (readbuffer); i++){
                bufe[i] = readbuffer[i];
                }
            pendStartPoint = atoi (bufe);
            
            
            fgets(read,3,stdout);
            
            for (int i = 0; i < sizeof (readbuffer); i++){
                bufe[i] = readbuffer[i];
                }
	        pendOffset = atoi (bufe);
	        
	        sprintf(dst, "%s\n",'S');
	        if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
            sprintf(dst, "%d\n", pendStartPoint);
            if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
            sprintf(dst, "%d\n", pendOffset);
            if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
                    usleep(10000);
                    w=work.ReadArd;
         
        
        break;
        
        
        case 'N':
            
             
	        sprintf(dst, "%s\n",'N');
	        if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
                    w=work.ReadArd;
        
        break;
        
        
        
        case 'W':
            sprintf(dst, "%s\n",'W');
	        if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
                    w=work.ReadArd;
        
        break;
        
        
        case 'M':
        
                   sprintf(dst, "%s\n",'M');
	        if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
                    w=work.ReadArd;
        
        
        
        break;
        
        case 'C':
            
            sprintf(dst, "%s\n",'C');
	        if(port!= INVALID_HANDLE_VALUE) 
                if(WriteFile(port,dst,size, &size,0))
                    w=work.ReadArd;
        
        break;
        }
                
    
    
    break;
    

    
    case ReadArd:
        
        switch(read[0]){
        
        case 'M':
        
        
        if(port!= INVALID_HANDLE_VALUE) 
                if(ReadFile(port,dst,size, &size,0)&&getCount)
                {
                    char n =((char *)buffer,dwNumBytesRead);
                    if(n!='\n')
                    string dataIn += ((char *)buffer,dwNumBytesRead);
                    countK = std::stoi(dataIn);
                }
                    
                 
        
        
           sprintf(buffer, "%d", countK);
          fputs(stdin,buffer);
          fputs(stdin,"\n");
          for(int i=0;i<countK;i++){
            sprintf(buffer, "%f", Time[i]);
            fputs(stdin,buffer);
            fputs(stdin,"\n");
            sprintf(buffer, "%d", Coord[i]);
            fputs(stdin,buffer);
            fputs(stdin,"\n");
          }
          
          break;
          
          
          case 'N':
           sprintf(buffer, "%d", countK);
          fputs(stdin,buffer);
          fputs(stdin,"\n");
          for(int i=0;i<countK;i++){
            sprintf(buffer, "%f", Time[i]);
            fputs(stdin,buffer);
            fputs(stdin,"\n");
            sprintf(buffer, "%d", Coord[i]);
            fputs(stdin,buffer);
            fputs(stdin,"\n");
          }
          
          break;
          
        }
    
    break;



}
			
			
			
}




void GetComPort(TCHAR *pszComePort, TCHAR * vid , TCHAR * pid)
{

HDEVINFO DeviceInfoSet;
DWORD DeviceIndex =0;
SP_DEVINFO_DATA DeviceInfoData;
PCWSTR DevEnum = L"USB";
TCHAR ExpectedDeviceId[80] = {0}; //Store hardware id
BYTE szBuffer[1024] = {0};
DEVPROPTYPE ulPropertyType;
DWORD dwSize = 0;
DWORD Error = 0;


//create device hardware id
wcscpy_s(ExpectedDeviceId,L"vid_");
wcscat_s(ExpectedDeviceId,vid);
wcscat_s(ExpectedDeviceId,L"&pid_");
wcscat_s(ExpectedDeviceId,pid);



//SetupDiGetClassDevs returns a handle to a device information set
DeviceInfoSet = SetupDiGetClassDevs(
NULL,
DevEnum,
NULL,
DIGCF_ALLCLASSES | DIGCF_PRESENT);

if (DeviceInfoSet == INVALID_HANDLE_VALUE)
return;


//Fills a block of memory with zeros
ZeroMemory(&DeviceInfoData, sizeof(SP_DEVINFO_DATA));
DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);



//Receive information about an enumerated device
while (SetupDiEnumDeviceInfo(
DeviceInfoSet,
DeviceIndex,
&DeviceInfoData))
{
DeviceIndex++;


//Retrieves a specified Plug and Play device property
if (SetupDiGetDeviceRegistryProperty (DeviceInfoSet, &DeviceInfoData, SPDRP_HARDWAREID,
&ulPropertyType, (BYTE*)szBuffer,
sizeof(szBuffer), // The size, in bytes
&dwSize))
{
HKEY hDeviceRegistryKey;



//Get the key
hDeviceRegistryKey = SetupDiOpenDevRegKey(DeviceInfoSet, &DeviceInfoData,DICS_FLAG_GLOBAL, 0,DIREG_DEV, KEY_READ);
if (hDeviceRegistryKey == INVALID_HANDLE_VALUE)
{
Error = GetLastError();

break; //Not able to open registry
}
else
{
// Read in the name of the port
wchar_t pszPortName[BUFF_LEN];
DWORD dwSize = sizeof(pszPortName);
DWORD dwType = 0;


if( (RegQueryValueEx(hDeviceRegistryKey,L"PortName", NULL, &dwType, (LPBYTE) pszPortName, &dwSize) == ERROR_SUCCESS) && (dwType == REG_SZ))
{
// Check if it really is a com port
if( _tcsnicmp( pszPortName, _T("COM"), 3) == 0)
{

int nPortNr = _ttoi( pszPortName + 3 );
if( nPortNr != 0 )
{
_tcscpy_s(pszComePort,BUFF_LEN,pszPortName);

}

}
}

// Close the key now that we are finished with it
RegCloseKey(hDeviceRegistryKey);
}
}

}

if (DeviceInfoSet)
{
SetupDiDestroyDeviceInfoList(DeviceInfoSet);
}

}
