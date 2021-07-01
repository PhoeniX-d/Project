## Step : 1  
**1. Build static library using command line**  
Compile file which is going to be our static library:
```
cl.exe /c /EHsc [NameofStaticLibFile.cpp]
```
Now create library:
```
lib [NameodStaticLibFile.obj]
```

**2. After building lib you will get .lib**
```
NameofStaticLibFile.lib
```
## Note : Based on Requirement you have to select either x86 or x64 command prompt to create static library
