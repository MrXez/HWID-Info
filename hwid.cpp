#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <winbase.h>
#include <stdio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Kernel32.lib")

using namespace std;

void main()
{
   SetConsoleTitle("HWID Information");

//First part gets the HDD informations
    cout << "HWID information" << endl;
    TCHAR volumeName[MAX_PATH + 1] = { 0 };
    TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
    DWORD serialNumber = 0;
    DWORD maxComponentLen = 0;
    DWORD fileSystemFlags = 0;
    if (GetVolumeInformation(
                _T("C:\\"),
                volumeName,
                ARRAYSIZE(volumeName),
                &serialNumber,
                &maxComponentLen,
                &fileSystemFlags,
                fileSystemName,
                ARRAYSIZE(fileSystemName)))
    {
        cout << "Volume Name: " << volumeName << endl;
        cout << "HDD Serial: " << serialNumber << endl;
        cout << "File System Type: " << fileSystemName << endl;
        cout << "Max Component Length: " << maxComponentLen << endl;
    }
    //Second part gets the computer name
    TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName) / sizeof(computerName[0]);
    if (GetComputerName(
                computerName,
                &size))
    {
        cout << "Computer Name: " << computerName << endl;
    }
    //Third part gets the CPU Hash
    int cpuinfo[4] = { 0, 0, 0, 0 }; //EAX, EBX, ECX, EDX
    __cpuid(cpuinfo, 0);
    char16_t hash = 0;
    char16_t* ptr = (char16_t*)(&cpuinfo[0]);
    for (char32_t i = 0; i < 8; i++)
        hash += ptr[i];
    cout << "CPU Hash: " << hash << endl;
    system("pause");


    auto serialNumber = 0



                        // Defining stuff
    HW_PROFILE_INFO HwProfInfo;

    SYSTEM_INFO siSysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure.

    GetSystemInfo(&siSysInfo);

    // Display the contents of the SYSTEM_INFO structure.

    printf("Hardware information: \n");
    printf("  OEM ID: %u\n", siSysInfo.dwOemId);
    printf("  Number of processors: %u\n",
           siSysInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", siSysInfo.dwPageSize);
    printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
    printf("  Active processor mask: %u\n",
           siSysInfo.dwActiveProcessorMask);
    printf("  Processor Level: %u\n",
           siSysInfo.wProcessorLevel);
    printf("  HW Profile Info %u\n",
           HwProfInfo.szHwProfileName);
    printf("  HWID %u\n",
           HwProfInfo.szHwProfileGuid);


    printf(" Other Information %u\n",
           HWID);


    return(0);
}
