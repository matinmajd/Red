# Introduction To Read Team Operation

## Defination

### Red Team

 `Defination` : rea team emulate tactics , techniques , and procedure of real adversaries to improve the people , process and technology in target Environment 

`Goal` :make blue team better , measure and train  blue team gave better detection and response 

`Effort` : Manual , some read team framework and automation tools

`frequency` : new exploit , tool or  TTP

### Blue Team

`Defination` : rea team emulate tactics , techniques , and procedure of real adversaries to improve the people , process and technology in target Environment

`Goal` :make blue team better , measure and train blue team gave better detection and response

`Effort` : Manual , some read team framework and automation tools

`frequency` : new exploit , tool or TTP

### Blue Team

`Defination` : rea team emulate tactics , techniques , and procedure of real adversaries to improve the people , process and technology in target Environment

`Goal` :make blue team better , measure and train blue team gave better detection and response

`Effort` : Manual , some read team framework and automation tools

`frequency` : new exploit , tool or TTP



#### chsarp basic

```csharp
System.Diagnostics.Process process = new System.Diagnostics.Process();
System.Diagnostics.ProcessStartInfo startInfo = new System.Diagnostics.ProcessStartInfo();
startInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;

#اجرای دستور 
startInfo.FileName = "cmd.exe";
#آرگومان هایی که به سمت دستور ارسال می شود
startInfo.Arguments = "/C net user /add nooranetred Aa123456";
process.StartInfo = startInfo;
process.Start();
```


