## LINUX
**1. Static Linking**  
    
	A] Creation
	
    command to create a static library
    ```g++ -c NameOfLib.cpp```
    ```ar -rcv libNameOfLib.a NameOfLib.o```
    
    After this NameOfLib.a i.e static library will get generated
    
    B] Usage
    
	Command to use static library
    a.  
	   ```g++ ClientApp.cpp -o Client libNameOfLib.a```
       ```./Client```

    b. You have to put .a file into standard libary path like /usr/lib/ then use following command
       
	   ```g++ ClientApp.cpp -o CLient -lNameOfLib```
       ```./Client```
    
    c. If you want to give your own library path then use option -L
       
	   ```g++ ClientApp.cpp -o Client -L [Directory where .a file is present] -lNameOfLib```
       ```./Client```
   
2.  Dynamic Linking  
    A] Creation
    command to create a shared library
    $ g++ -c -fPIC -Wall NameOfLib.cpp
    
    After that .o file will be generated, then create .so using
    $ g++ -shared -o libNameOfLib.so NameOfLib.o
    
    Now libNameOfLib.so file will be generated

    B] Usage
    $ g++ -Wall -o Client ClientApp.cpp libNameOfLib.so

    It will generate executable named as Client
   

## Windows

1. Static Linking
    
    A] Creation
    command to create a static library
    $ g++ -c NameOfLib.cpp
    $ ar -rcv libNameOfLib.lib NameOfLib.o
    
    After this NameOfLib.lib i.e static library will get generated
    
    B] Usage
    Command to use static library
    a. $ g++ ClientApp.cpp -o Client.exe libNameOfLib.lib
       $ ./Client.exe

    b. You have to put .a file into standard libary then use following command
       $ g++ ClientApp.cpp -o Client.exe -lNameOfLib
       $ ./Client.exe
    
    c. If you want to give your own library path then use option -L
       $ g++ ClientApp.cpp -o Client.exe -L [Directory where .lib file is present] -lNameOfLib
       $ ./Client.exe  
   
2.  Dynamic Linking  
    
    A] Creation
    command to create a shared library
    $ g++ -c -fPIC -Wall NameOfLib.cpp
    
    After that .o file will be generated, then create .so using
    $ g++ -shared -o libNameOfLib.dll NameOfLib.o
    
    Now libNameOfLib.so file will be generated

    B] Usage
    $ g++ -Wall -o Client.exe ClientApp.cpp libNameOfLib.dll

    It will generate executable named as Client.exe