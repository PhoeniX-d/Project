## Note : Before using static library you have to match both Client application and library both should be for same architecture,  
## for ex. If .lib is x86 then it can be used in x86 similarly for x64 also
## Step : 1  
**1. Build use static library via command line**  
Compile file which is going to use static library along with library paths:
```
cl.exe /EHsc [NameofAppFile.cpp] /I [PathofStaticLibFile\] [NameofStaticLibFileWithPath]
```
Ex.
```
cl.exe /EHsc MyApp.cpp /I C:\Users\Pranav\Desktop\StaticLib\ C:\Users\Pranav\Desktop\StaticLib\Strlib.lib
```
**2. After building you will get .exe which contains static library in it**
```
NameofAppFile.exe
```
