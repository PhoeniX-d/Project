/* How to Use Explicit Linking to Load Dll, Here Loading of DLL is performed by the Programmer */

/* Step 1 : Include Header file containing Declarations */
#include "Strlibdll.h"

/* 
*	Create a function pointer , Here I Have typedefed funtion pointer
*	Function pointer is created for one of the functions declared in 
*	StrLibdll.h file. You can choose any of the functions
*/
typedef int  (*pfnStrLen)(const char*);
/* 
*	Now We Have our type pfnStrLen i.e pointer to such a function which returns int 
*	and accept const char* as parameter, Here thing is this type can be reused with any
*	function which matches above declaration
*/

// Entry point function 
int main()
{
	/* Create variable of pfnStrLen */
	pfnStrLen pfnToLen = NULL;

	/* 
	*	To Load Library we have to use LoadLibrary API which returns HMODULE
	*	So declare HMODULE variable 
	*/
	
	HMODULE hdll = NULL;
	int iRet = 0;
	CHAR szS1[MAXLEN] = { '\0' };
	CHAR szS2[MAXLEN] = { '\0' };

	printf("Enter the string 1\t:");
	scanf("%[^\n]", szS1);

	/*
	*	Now Call LoadLibrary API which accept Name of our library 
	*	Here LoadLibray will search our library in following path
	*	1. A.For 32bit DLL in Directory C:\Windows\SysWOW64
		   B.For 64bit DLL in Directory C:\Windows\system32
	*	2. Where your .exe will generate i.e. Debug or x64 directory of this project
	*	3. Direcotory which is there in Environment variable path
	*	4. Windows Directory
	*	DLL Gets loaded in process address space at place where it gets free memory
	*/
	
	hdll = LoadLibrary(TEXT("StrLibDll.dll"));
	if (hdll == NULL)		/* Check load is Successull or not its MUST */
	{
		printf("Error while LoadLibrary : %d\n", GetLastError());
		return (1);
	}
	
	/* After successull loading , now we have to get address of our required Function form
	*	that loaded dll using GetProcAddress()
	*/
	
	pfnToLen = (pfnStrLen)GetProcAddress(hdll, "StrLen");
	
	/* Now we have address of function in our pfnToLen variable , simply call that function */
	iRet = pfnToLen(szS1);
	printf("Length of String is\t:%d", iRet);
	
	/* Most important we MUST free our loaded dll from Process's address space */
	FreeLibrary(hdll);
	return (0);
}