## Step : 1  
**1. Build DLL using command line**  
Compile:
```
cl /c /EHsc /Strlibdll.c
```
Link:
```
link Strlibdll.obj /DLL /DEF:Strlibdll.def kernel32.lib
```

**2. After building dll get .dll and place it in proper path**
  1. A.For 32bit DLL in Directory C:\Windows\SysWOW64  
		 B.For 64bit DLL in Directory C:\Windows\system32  
2. Where your .exe will generate i.e. Debug or x64 directory of this project  
3. Direcotory which is there in Environment variable path  
4. Windows Directory  

**3. Implicit Linking**  
Compile:
```
cl /c /EHsc StrlibdllClientIm.c
```
Link: here link with import library created while building dll
```
link StrlibdllClientIm.obj Strlibdll.lib kernel32.lib  
```
Execute:
```
StrlibdllClientIm.exe
```
**4. Explicit Linking**  
Compile:
```
cl /c /EHsc StrlibdllClientIm.c
```
Link: We don not have to use Import Library
```
link StrlibdllClientIm.obj kernel32.lib  
```
Execute:
```
StrlibdllClientIm.exe
```
