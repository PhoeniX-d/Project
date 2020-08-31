// Library File
/*
*   Program containing all string library functions
*/

#include "StrLib.h"

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLen
//  Input       :const char*
//  Returns     :int
//  Description :computes length of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::StrLen(const char *cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return -1;
    }
    int iLen = 0;
    while(*cSrc != '\0' && *cSrc != '\n')
    {
        iLen++;
        cSrc++;
    }
    return iLen;
}// end of StrLen

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLwr
//  Input       :char*
//  Returns     :void
//  Description :converts lower case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrLwr(char* cSrc)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
	}
	while(*cSrc !='\0'  && *cSrc != '\n')
	{
		if((*cSrc >= 'A') && (*cSrc <= 'Z'))
		{
			*cSrc = *cSrc + 32;
		}
		cSrc++;
	}
}// end of StrLwr

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNLwr
//  Input       :const char*, int, char
//  Returns     :void
//  Description :convert into lower case the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNLwr(char* cSrc, int iN, char cFlag)
{
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }
    
    if (cFlag == FIRST)
    {
        while(*cSrc !='\0'  && *cSrc != '\n' && iN != 0)
        {
            if((*cSrc >= 'A') && (*cSrc <= 'Z'))
            {
                *cSrc = *cSrc + 32;
            }
            cSrc++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        char *cEnd = cSrc;
        while(*(cEnd + 1) != '\0'  && *(cEnd + 1) != '\n')
        {
            cEnd++;
        }
        do
        {
            if((*cEnd >= 'A') && (*cEnd <= 'Z'))
            {
                *cEnd = *cEnd + 32;
            }
            cEnd--;
            iN--;
        } while (cEnd != (cSrc - 1) && iN != 0);
    }
}// end of StrNLwr

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrUpr
//  Input       :const char*
//  Returns     :void
//  Description :converts upper case entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrUpr(char* cSrc)
{
    if(NULL == cSrc)
    {
       cout << "Invalid Input\n" ;
    }
    while(*cSrc !='\0'  && *cSrc != '\n')
    {
        if((*cSrc >= 'a') && (*cSrc <= 'z'))
        {
            *cSrc = *cSrc - 32;
        }
        cSrc++;
    }
}// end of StrUpr

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNUpr
//  Input       :char*, int, char
//  Returns     :void
//  Description :converts upper case entered string upto N
//  Author      :Pranav Choudhary
//  Date        :25 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNUpr(char* cSrc, int iN, char cFlag)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
	}
    if(iN < 0)
    {
        iN = -iN;
    }
    if(cFlag == FIRST)
    {
        while(*cSrc !='\0' && iN != 0  && *cSrc != '\n')
        {
            if((*cSrc >= 'a') && (*cSrc <= 'z'))
            {
                *cSrc = *cSrc - 32;
            }
            cSrc++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        char *cEnd = cSrc;
        while(*(cEnd + 1) != '\0'  && *(cEnd + 1) != '\n')
        {
            cEnd++;
        }
        do
        {
            if((*cEnd >= 'a') && (*cEnd <= 'z'))
            {
                *cEnd = *cEnd - 32;
            }
            cEnd--;
            iN--;
        } while (cEnd != (cSrc - 1) && iN != 0);
    }
}// end of StrNUpr

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrTgl
//  Input       :const char*
//  Returns     :void
//  Description :Toggle case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrTgl(char* cSrc)
{
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
    }
    while(*cSrc !='\0'  && *cSrc != '\n')
    {
        if((*cSrc >= 'A') && (*cSrc <= 'Z'))
        {
            *cSrc = *cSrc + 32;
        }
        else if((*cSrc >= 'a') && (*cSrc <= 'z'))
        {
            *cSrc = *cSrc - 32;
        }
        cSrc++;
    }

}// end of StrTgl

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrTglRev
//  Input       :char*
//  Returns     :void
//  Description :reverse the contents of that string by toggling the case
//  Author      :Pranav Choudhary
//  Date        :28 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrTglRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    char *cStart = cSrc;
    char *cEnd = cSrc;
    char cTemp = '\0';

    while(*cEnd != '\0' && *cEnd != '\n')
    {
        if(*cEnd >= 'a' && *cEnd <= 'z')
        {
            *cEnd = *cEnd - 32;
        }
        else if(*cEnd >= 'A' && *cEnd <= 'Z')
        {
            *cEnd = *cEnd + 32;
        }
        cEnd++;
    }
    cEnd--;
    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cStart++;
        cEnd--;
    }
}// end of StrTglRev

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNTgl
//  Input       :const char*
//  Returns     :void
//  Description :Toggle case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNTgl(char* cSrc, int iN, char cFlag)
{
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
    }
    
    if(iN < 0)
    {
        iN = -iN;
    }

    if(cFlag == FIRST)
    {
        while(*cSrc !='\0'  && *cSrc != '\n' && iN != 0)
        {
            if((*cSrc >= 'A') && (*cSrc <= 'Z'))
            {
                *cSrc = *cSrc + 32;
            }
            else if((*cSrc >= 'a') && (*cSrc <= 'z'))
            {
                *cSrc = *cSrc - 32;
            }
            cSrc++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        char *cEnd = cSrc;
        while(*(cEnd + 1) != '\0'  && *(cEnd + 1) != '\n')
        {
            cEnd++;
        }

        do
        {
            if((*cEnd >= 'A') && (*cEnd <= 'Z'))
            {
                *cEnd = *cEnd + 32;
            }
            else if((*cEnd >= 'a') && (*cEnd<= 'z'))
            {
                *cEnd = *cEnd - 32;
            }
            cEnd--;
            iN--;
        } while ((cSrc - 1) != cEnd && iN != 0);
    }

}// end of StrNTgl

////////////////////////////////////////////////////////////
//
//  Name        :StrCat
//  Input       :char*, const char*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCat(char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while(*cStr1 != '\0'  && *cStr1 != '\n')
    {
        cStr1++;
    }
    while(*cStr2 != '\0'  && *cStr2 != '\n')
    {
        *cStr1 = *cStr2;
        cStr2++;
        cStr1++;
    }
    *cStr1 = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCatRev
//  Input       :char*, const char*
//  Returns     :void
//  Description :concate 2nd string to first in reverse
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCatRev(char* cDest, const char* cSrc)
{
    if(cDest == NULL || cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    const char *cEnd = cSrc;

    while(*cDest != '\0' && *cDest != '\n')
    {
        cDest++;
    }
    while(*(cEnd + 1) != '\0' && *(cEnd + 1) != '\n')
    {
        cEnd++;
    }

    while(cEnd != (cSrc - 1))
    {
        *cDest = *cEnd;
        cEnd--;
        cDest++;
    }
    *cDest = '\0';
}// end of StrCatRev

////////////////////////////////////////////////////////////
//
//  Name        :StrCatAltr
//  Input       :char*, const char*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCatAltr(const char* cSrc, char* cDest)
{
    if(cDest == NULL || cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cDest != '\0' && *cDest != '\n')
    {
        cDest++;
    }
    while(*cSrc != '\0' && *cSrc != '\n')
    {
        *cDest = *cSrc;
        if (*(cSrc + 1) == '\0' && *(cSrc + 1) != '\n')
        {
            cDest++;
            break;
        }
        cSrc = cSrc + 2;           
        cDest++;
    }
    *cDest = '\0';
}// end of StrCatAltr

////////////////////////////////////////////////////////////
//
//  Name        :StrNCat
//  Input       :char*, char*, int, char
//  Returns     :void
//  Description :append N characters of second string after
//               first string(Implement strncat())
//  Author      :Pranav Choudhary
//  Date        :25 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrNCat(char* cStr1, const char* cStr2, int iN, char cFlag)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }
    while(*cStr1 != '\0'  && *cStr1 != '\n')
    {
        cStr1++;
    }
    if(cFlag == FIRST)
    {
        while(*cStr2 != '\0' && iN != 0  && *cStr2 != '\n')
        {
            *cStr1 = *cStr2;
            cStr2++;
            cStr1++;
            iN--;
        }
        *cStr1 = '\0';
    }
    else if(cFlag == LAST)
    {
        const char *cEnd = cStr2;        
        while(*(cEnd + 1) != '\0'  && *(cEnd + 1) != '\n')
        {
            cEnd++;
        }

        do
        {
            *cStr1 = *cEnd;
            cEnd--;
            cStr1++;
            iN--;
        } while ((cStr2 - 1) != cEnd && iN != 0);
        *cStr1 = '\0';
    }

}// end of StrNCat

////////////////////////////////////////////////////////////
//
//  Name        :StrCpy
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpy(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        *cDest = *cSrc;
        cSrc++;
        cDest++;
    }
    *cDest = '\0';
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :StrNCpy
//  Input       :const char*, char*, int
//  Returns     :void
//  Description :copy source string's N chars into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////
void Strings::StrNCpy(const char* cSrc, char* cDest, int iN, char cFlag)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    if(iN < 0)
        iN = -iN;

    if(cFlag == FIRST)
    {
        while(*cSrc != '\0' && iN != 0 && *cSrc != '\n')
        {
            *cDest = *cSrc;
            cSrc++;
            cDest++;
            iN--;
        }
        *cDest = '\0';
    }
    else if(cFlag == LAST)
    {
        const char *cEnd = cSrc;
        while(*(cEnd + 1) != '\0' && *(cEnd + 1 ) != '\n')
        {
            cEnd++;
        }
        while(iN != 1)
        {
            cEnd--;
            iN--;
        }
        while (*cEnd != '\0' && *cEnd != '\n')
        {
            *cDest = *cEnd;
            cEnd++;
            cDest++;
        } 
        *cDest = '\0';
    }

}// end of StrNCpy

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyCap
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy capital letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpyCap(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}// end of StrCpyCap

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyCapX
//  Input       :const char*, char*
//  Returns     :void
//  Description :convert small letters to capital letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrCpyCapX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc - 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }        
        cSrc++;
    }
    *cDest = '\0';
}// end of StrCpyCapX

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyLwr
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy lower letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpyLwr(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}// end of StrCpyLwr

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyLwrX
//  Input       :const char*, char*
//  Returns     :void
//  Description :convert capital letters to small letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrCpyLwrX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc + 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }        
        cSrc++;
    }
    *cDest = '\0';
}// end of StrCpyLwrX

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyRev
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//               in reverse
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpyRev(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    int iCnt = 0;
    while(*cSrc != '\0' && *cSrc != '\n')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while(iCnt != 0)
    {
        *cDest = *cSrc;
        cSrc--;
        cDest++;
        iCnt--;
    }
    *cDest = '\0';
}// end of StrCpyRev

////////////////////////////////////////////////////////////
//
//  Name        :StrTrimCpy
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrTrimCpy(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc != ' ')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}// end of StrTrimCpy

////////////////////////////////////////////////////////////
//
//  Name        :StrTrimCpyX
//  Input       :const char*, char*
//  Returns     :void
//  Description :function that removes extra spaces
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrTrimCpyX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc == ' ')
		{
			while((*cSrc == ' ' || *cSrc == '\t') && (*cSrc != '\0') && *cSrc != '\n')
			{
				cSrc++;
			}
		}
		else
		{
			while(*cSrc != ' ' && *cSrc != '\0' && *cSrc != '\n')
			{
				*cDest=*cSrc;
				cSrc++;
				cDest++;
			}
			*cDest=*cSrc;
			cDest++;		
		}
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyTgl
//  Input       :const char*, char*
//  Returns     :void
//  Description :toggle letters from source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrCpyTgl(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0' && *cSrc != '\n')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc - 32;
            cDest++;
        }
        else if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc + 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }      
        cSrc++;
    }
    *cDest = '\0';
}// end of StrCpyTgl

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrRev
//  Input       :char*
//  Returns     :void
//  Description :Reverses entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*(cEnd + 1) != '\0' && *(cEnd + 1) != '\n')
    {
        cEnd++;
    }

    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}// end of StrRev

//////////////////////////////////////////////////////////////////////
//
//  Name        :FirstCharCap
//  Input       :char *
//  Returns     :void
//  Description :replace each occurrence of first character of 
//               each word into capital case
//  Author      :Pranav Choudhary
//  Date        :29 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrFirstCap(char *cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cStr != '\0' && *cStr != '\0')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0') && (*cStr != '\0'))
			{
				cStr++;
			}
		}
		else
		{
            if(*cStr >= 'a' && *cStr <= 'z')
            {
                *cStr = *cStr - 32;
            }
			while(*cStr != ' ' && *cStr != '\0' && (*cStr != '\0'))
			{
                cStr++;
            }
        }
        cStr++; 
    }
}// end of StrFirstCap

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNRev
//  Input       :char*, int
//  Returns     :void
//  Description :reverse the string till first N characters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNRev(char* cSrc, int iN, char cFlag)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;
    
    if(cFlag == FIRST)
    {
        while(*cEnd != '\0' && iN != 1 && *cEnd != '\n')
        {
            iN--;
            cEnd++;
        }

        if(iN != 1)
            cEnd--;

        while(cStart < cEnd)
        {
            cTemp = *cStart;
            *cStart = *cEnd;
            *cEnd = cTemp;
            cEnd--;
            cStart++;
        }
    }
    else if(cFlag == LAST)
    {
        cStart = cSrc;
        cEnd = NULL;

        while(*(cStart + 1) != '\0' && *(cStart + 1) != '\n')
        {
            cStart++;
        }
        cEnd = cStart;

        while(iN != 0 && cEnd != cSrc)
        {
            iN--;
            cEnd--;
        }

        while(cStart > cEnd)
        {
            cTemp = *cStart;
            *cStart = *cEnd;
            *cEnd = cTemp;
            cEnd++;
            cStart--;
        }
    }
}// end of StrNRev

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrRangeRev
//  Input       :char*, int, int
//  Returns     :void
//  Description :reverse the string in that range without
//               taking another string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrRangeRev(char* cSrc, int iS, int iE)
{
    if(iS < 0)
    {
        iS = -iS;
    }
    if(iE < 0)
    {
        iE = -iE;
    }
    if(cSrc == NULL || iS >= iE || StrLen(cSrc) < iS || StrLen(cSrc) < iE)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    if(iS == 0)
    {
        cStart = cSrc + iS;
    }
    else
    {
        cStart = cSrc + (iS - 1);
    }    
    cEnd = cSrc + (iE - 1);

    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}// end of StrRangeRev

////////////////////////////////////////////////////////////
//
//  Name        :StrCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :compare 2 strings
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StrCmp(const char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }

    while(*cStr1 == *cStr2)
    {
        if(*cStr1 == '\0' || *cStr1 == '\n')
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}

////////////////////////////////////////////////////////////
//
//  Name        :StriCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :compare 2 strings case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StriCmp(const char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
   
    while(*cStr1 != '\0' && *cStr2 != '\0')
    {
        if((*cStr1 != *cStr2) && (*cStr1 != *cStr2 + 32) && (*cStr1 != *cStr2 - 32))
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrNCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :Implementation of strncmp()
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StrNCmp(const char* cStr1, const char* cStr2, int iN, char cFlag)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    const char *cEnd1 = cStr1;
    const char *cEnd2 = cStr2;

    if(iN < 0)
    {
        iN = -iN;
    }
    if(cFlag == FIRST)
    {
        while(*cEnd1 == *cEnd2 && iN != 0)
        {
            if((*cEnd1 == '\0' || *cEnd1 == '\n') && iN != 0)
            {
                break;
            }
            cEnd1++;
            cEnd2++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        while(*(cEnd1 + 1) != '\0' && *(cEnd1 + 1) != '\n')
        {
            cEnd1++;
        }
        while(*(cEnd2 + 1) != '\0' && *(cEnd2 + 1)  != '\n')
        {
            cEnd2++;
        }

        while (*cEnd1 == *cEnd2 && iN != 0)
        {
            if(*cEnd1 == *cStr1 && iN != 0)
            {
                break;
            }
            cEnd1--;
            cEnd2--;
            iN--;
        }
    }
    if (*cEnd1 == *cEnd2)
        return 0;
    else
        return *cEnd1 - *cEnd2;

}// end of StrNCmp()

////////////////////////////////////////////////////////////
//
//  Name        :StriNCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :Implementation of strncmp()
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StriNCmp(const char* cStr1, const char* cStr2, int iN, char cFlag)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }

    const char *cEnd1 = cStr1;
    const char *cEnd2 = cStr2;

    if(iN < 0)
    {
        iN = -iN;
    }

    if(cFlag == FIRST)
    {
        while(*cEnd1 != '\0' && *cEnd2 != '\0' && *cEnd1 != '\n' && *cEnd2 != '\n' && iN != 0)
        {
            if((*cEnd1 != *cEnd2) && (*cEnd1 != *cEnd2 + 32) && (*cEnd1 != *cEnd2 - 32) && iN != 0)
            {
                break;
            }
            cEnd1++;
            cEnd2++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        while(*(cEnd1 + 1) != '\0' && *(cEnd1 + 1) != '\n')
        {
            cEnd1++;
        }
        while(*(cEnd2 + 1) != '\0' && *(cEnd2 + 1) != '\n')
        {
            cEnd2++;
        }

        while (*cEnd1 == *cEnd2 && iN != 0)
        {
            if((*cEnd1 != *cStr1) && (*cEnd1 != *cStr1 + 32) && (*cEnd1 != *cStr1 - 32) && iN != 0)
            {
                break;
            }
            cEnd1--;
            cEnd2--;
            iN--;
        }
    }
    if (*cEnd1 == *cEnd2)
        return 0;
    else
        return *cEnd1- *cEnd2;

}// end of StrNCmp()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrSet
//  Input       :char*, char
//  Returns     :void
//  Description :sets all characters in string to a specific character
//               (Implement strset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrSet(char *cSrc, char ch)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while(*cSrc != '\0' && *cSrc != '\n')
    {
        *cSrc = ch;
        cSrc++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNSet
//  Input       :char*, char
//  Returns     :void
//  Description :sets first N characters in string to a specific 
//               character (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNSet(char *cSrc, char ch, int iN, char cFlag)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }
    if(cFlag == FIRST)
    {
        while(*cSrc != '\0' && *cSrc != '\n'  && iN != 0)
        {
            *cSrc = ch;
            cSrc++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        char *cEnd = cSrc;
        while (*(cEnd + 1) != '\0')
        {
            cEnd++;
        }
        do
        {
            *cEnd = ch;
            cEnd--;
            iN--;
        } while (cEnd != (cSrc - 1) && iN != 0);
    }

}// end of StrNSet

//////////////////////////////////////////////////////////////////////
//
//  Name        :WordCnt
//  Input       :const char *
//  Returns     :int
//  Description :count words in given string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::WordCnt(const char *cStr)
{
    int iCnt = 0;
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
       
    while(*cStr != '\0' && *cStr != '\n')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0') && (*cStr != '\n'))
			{
				cStr++;
			}
		}
		else
		{
			while(*cStr != ' ' && *cStr != '\0' && *cStr != '\n' )
			{
                cStr++;
            }
            iCnt++;
        }
        cStr++; 
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :WordRev
//  Input       :char*
//  Returns     :void
//  Description :reverse words from that string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::WordRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        cEnd = cStart;
        while(*cEnd != ' ' && *cEnd != '\0')
        {
            cEnd++;
        }
        cSrc = cEnd;
        cEnd--;

        while(cStart < cEnd)
        {
            cTemp = *cStart;
            *cStart = *cEnd;
            *cEnd = cTemp;
            
            cEnd--;
            cStart++;
        }
        cStart = cSrc + 1;
    }    
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :MaxOccur
//  Input       :const char *
//  Returns     :void
//  Description :find maximum occurring character in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::MaxOccur(const char *cSrc)
{
    int iChars[MAX_CHAR] = {0}, i = 0, iMax = 0;
    char ch = '\0';
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while (*cSrc != '\0'  && *cSrc != '\n')
    {
        iChars[*cSrc]++;
        cSrc++;
    }
    iMax = iChars[0];
    for (i = 0; i < MAX_CHAR; i++)
    {
        if(i != 32)
        {
            if(iMax < iChars[i])
            {
                iMax = iChars[i];
                ch = i;
            }
        }
    }

    cout << "Max occuring char \'" << ch << "\' with occurance " << iMax << endl;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of first occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::FirstOccur(const char *cSrc, char ch)
{
    int iCnt = -1;
    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        if(*cSrc == ch)
        {
            iCnt++;
            break;
        }
        iCnt++;
        cSrc++;
    }
    if(*cSrc == '\0'  && *cSrc != '\n')
        return -1;
    else
        return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of last occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::LastOccur(const char *cSrc, char ch)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return -1;
    }
    int iCnt = 0;
    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while(iCnt != -1)
    {
        if(*cSrc == ch)
        {
            iCnt--;
            break;
        }
        iCnt--;
        cSrc--;
    }
    if(iCnt == -1)
        return -1;
    else
        return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsPldrm
//  Input       :const char*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
bool Strings::IsPldrm(const char* cSrc)
{
    const char *cStart = NULL;
    const char *cEnd = NULL;

    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return false;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0'  && *(cEnd + 1) != '\n')
    {
        cEnd++;
    }
    while(cStart < cEnd)
    {
        if(*cStart != *cEnd)
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if(cStart >= cEnd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Name        :IsiPldrm
//  Input       :const char*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////////
bool Strings::IsiPldrm(const char* cSrc)
{
    const char *cStart = NULL;
    const char *cEnd = NULL;

    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return false;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0'  && *(cEnd + 1) != '\n')
    {
        cEnd++;
    }
    while(cStart < cEnd)
    {
        if( (*cStart != *cEnd) && (*cStart != *cEnd + 32) && (*cStart != *cEnd - 32) )
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if(cStart >= cEnd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CharsCnt
//  Input       :const char *
//  Returns     :void
//  Description :count total number of alphabets,
//               digits and special characters in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::CharsCnt(const char *cSrc)
{
    int iA = 0, iSp = 0, iD = 0, iW = 0, iState = OUT;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while (*cSrc != '\0'  && *cSrc != '\n')
    {
        if(*cSrc == ' ')
        {
            iState = OUT;
        }
        else if(iState == OUT)
        {   
            iState = IN;
            iW++;
        }
        if(*cSrc >= 'A' && *cSrc <= 'Z' || *cSrc >= 'a' && *cSrc <= 'z')
        {
            iA++;
        }
        else if(*cSrc >= '0' && *cSrc <= '9')
        {
            iD++;
        }
        else
        {
            iSp++;
        }       
        cSrc++;
    }
    cout << "Alphabets\t:" << iA << endl;
    cout << "Digits\t:" << iD << endl;
    cout << "Special\t:" << iSp << endl;
    cout << "Words\t:" << iW << endl;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountUpr
//  Input       :const char *
//  Returns     :int
//  Description :count capital letters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountUpr(const char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        if (*cSrc >= 'A' && *cSrc <= 'Z')
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountLwr
//  Input       :const char *
//  Returns     :int
//  Description :count small letters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountLwr(const char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////
//
//  Name        :IsAgrm
//  Input       :const char*, const char*
//  Returns     :BOOL
//  Description :check whether given strings are Anagram strings or not.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////
bool Strings::IsAgrm(const char* cStr1, const char* cStr2)
{
    char cChars[MAX_CHAR] = {0};
    int i = 0;
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return false;
    }

    while(*cStr1 != '\0'  && *cStr1 != '\n' && *cStr2 != '\0'  && *cStr2 != '\n')
    {
        cChars[*cStr1]++;
        cChars[*cStr2]--;
        cStr1++;
        cStr2++;
    }
    if((*cStr1 == '\0'  && *cStr2 == '\0') || (*cStr2 != '\n'  && *cStr2 != '\n' ))
    {
       for (i = 0; i < MAX_CHAR; i++)
        {
            if(cChars[i] != 0)
            {
                break;
            }
        }
    }
    if(i == MAX_CHAR)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of IsAgrm

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountSpecials
//  Input       :const char *
//  Returns     :int
//  Description :count special characters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountSpecials(const char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        if ( !(*cSrc >= 'a' && *cSrc <= 'z') && 
             !(*cSrc >= 'A' && *cSrc <= 'Z') && 
             !(*cSrc >= '0' && *cSrc <= '9'))
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
} // end of CountSpecials

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountSpace
//  Input       :const char*
//  Returns     :int
//  Description :compute space in the entered string
//  Author      :Pranav Choudhary
//  Date        :26 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountSpace(const char *cSrc)
{
    int iCnt = 0;
    while(*cSrc != '\0'  && *cSrc != '\n')
    {
        if(*cSrc == 32)
        {
            iCnt++;
        }
        cSrc++;
    }
    return iCnt;
}// end of CountSpace

//////////////////////////////////////////////////////////////////////
//
//  Name        :LargestWord
//  Input       :const char *
//  Returns     :int
//  Description :program which accept string from user and return 
//               length of largest word
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::LargestWord(const char *cStr)
{
    int iMax = 0 ,i = 0 ,iCnt = 0;

    if(cStr == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }

    while(*cStr != '\0' && *cStr != '\n')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && *cStr != '\0' && *cStr != '\n')
			{
				cStr++;
			}
		}
		else
		{
			while(*cStr != ' ' && *cStr != '\0' && *cStr != '\n')
			{
                iCnt++;
                cStr++;
            }					
		}
        if(iCnt > iMax)
        {
            iMax = iCnt;
        }
        iCnt = 0;
        cStr++; 
    }
    return iMax;
}

////////////////////////////////////////////////////////////////////
//
//  Name        :ManPage
//  Input       :const char*, const char*
//  Returns     :void
//  Description :Man Page for commands
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////////////
void Strings::ManPage(const char* cCmd)
{
    if(StriCmp(cCmd, "strlen") == 0)
    {
        cout << "Description     :Computes length of enterd string\n";
        cout << "Usage           :strlen Input_String\n";
    }
    else if(StriCmp(cCmd, "man") == 0)
    {
        cout << "Description     :Displays how to use command\n";
        cout << "Usage           :man Input_Command\n";
    }
    else if(StriCmp(cCmd, "strlwr") == 0)
    {
        cout << "Description     :converts entire string into lower case\n";
        cout << "Usage           :strlwr Input_String\n";
    }
    else if(StriCmp(cCmd, "strupr") == 0)
    {
        cout << "Description     :converts entire string into upper case\n";
        cout << "Usage           :strupr Input_String\n";
    }
    else if(StriCmp(cCmd, "strnlwr") == 0)
    {
        cout << "Description     :converts string into lower case\n";
        cout << "                 if Flag = 0, then first N characters are converted\n";
        cout << "                 if Flag = 1, then last N characters are converted\n";
        cout << "Usage           :strnlwr Input_String  N   Flag\n";
    }
    else if(StriCmp(cCmd, "strnupr") == 0)
    {
        cout << "Description     :converts string into upper case\n";
        cout << "                 if Flag = 0, then first N characters are converted\n";
        cout << "                 if Flag = 1, then last N characters are converted\n";
        cout << "Usage           :strnupr Input_String  N    Flag\n";
    }
    else if(StriCmp(cCmd, "strtgl") == 0)
    {
        cout << "Description     :toggles characters in string\n";
        cout << "Usage           :strtgl Input_String\n";
    }
    else if(StriCmp(cCmd, "strntgl") == 0)
    {
        cout << "Description     :toggles characters in string\n";
        cout << "                 if Flag = 0, then first N characters are toggled\n";
        cout << "                 if Flag = 1, then last N characters are toggled\n";
        cout << "Usage           :strntgl Input_String  N    Flag\n";
    }
    else if(StriCmp(cCmd, "strtglrev") == 0)
    {
        cout << "Description     :toggles characters in string in reverse\n";
        cout << "Usage           :strtglrev Input_String\n";
    }
    else if(StriCmp(cCmd, "strcat") == 0)
    {
        cout << "Description     :concatinates src string into destination\n";
        cout << "Usage           :strcat Input_String1  Input_String2\n";
    }
    else if(StriCmp(cCmd, "strcataltr") == 0)
    {
        cout << "Description     :concatinates alternative chars from src string into destination\n";
        cout << "Usage           :strcataltr Input_String1  Input_String2\n";
    }
    else if(StriCmp(cCmd, "strcatrev") == 0)
    {
        cout << "Description     :concatinates src string into destination in reverse\n";
        cout << "Usage           :strcatrev Input_String1  Input_String2\n";
    }
    else if(StriCmp(cCmd, "strncat") == 0)
    {
        cout << "Description     :concatinates src string into destination\n";
        cout << "                 if Flag = 0, then first N characters are concatinated\n";
        cout << "                 if Flag = 1, then last N characters are concatinated\n";
        cout << "Usage           :strncat Input_String1  Input_String2  N   Flag\n";
    }
    else if(StriCmp(cCmd, "strcpy") == 0)
    {
        cout << "Description     :copies src string into destination\n";
        cout << "Usage           :strcpy Input_String\n";
    }
    else if(StriCmp(cCmd, "strfirstcap") == 0)
    {
        cout << "Description     :capitalize each words first character\n";
        cout << "Usage           :strfirstcap Input_String\n";
    }
    else if(StriCmp(cCmd, "strncpy") == 0)
    {
        cout << "Description     :copies src string into destination\n";
        cout << "                 if Flag = 0, then first N characters are copied\n";
        cout << "                 if Flag = 1, then last N characters are copied\n";
        cout << "Usage           :strncpy Input_String  N   Flag\n";
    }
    else if(StriCmp(cCmd, "strcpycap") == 0)
    {
        cout << "Description     :copies capitals chars from src string into destination\n";
        cout << "Usage           :strcpycap Input_String\n";
    }
    else if(StriCmp(cCmd, "strcpycapx") == 0)
    {
        cout << "Description     :copies capitals chars from src string into destination by toggling case\n";
        cout << "Usage           :strcpycapx Input_String\n";
    }
    else if(StriCmp(cCmd, "strcpylwr") == 0)
    {
        cout << "Description     :copies lower chars from src string into destination\n";
        cout << "Usage           :strcpylwr Input_String\n";
    }
    else if(StriCmp(cCmd, "strcpylwrx") == 0)
    {
        cout << "Description     :copies lower chars from src string into destination by toggling case\n";
        cout << "Usage           :strcpylwrx Input_String\n";
    }
    else if(StriCmp(cCmd, "strtrimcpy") == 0)
    {
        cout << "Description     :copies src string into destination without spaces\n";
        cout << "Usage           :strtrimcpy Input_String\n";
    }
    else if(StriCmp(cCmd, "strtrimcpyx") == 0)
    {
        cout << "Description     :copies src string into destination by removing extra spaces\n";
        cout << "Usage           :strtrimcpyx Input_String\n";
    }
    else if(StriCmp(cCmd, "strcpytgl") == 0)
    {
        cout << "Description     :copies src string into destination by toggling case\n";
        cout << "Usage           :strcpytgl Input_String\n";
    }
    else if(StriCmp(cCmd, "strcpyrev") == 0)
    {
        cout << "Description     :copies src string into destination in reverse\n";
        cout << "Usage           :strcpyrev Input_String\n";
    }
    else if(StriCmp(cCmd, "strrev") == 0)
    {
        cout << "Description     :reverses string\n";
        cout << "Usage           :strrev Input_String\n";
    }
    else if(StriCmp(cCmd, "strnrev") == 0)
    {
        cout << "Description     :reverses string\n";
        cout << "                 if Flag = 0, then first N characters are reversed\n";
        cout << "                 if Flag = 1, then last N characters are reversed\n";
        cout << "Usage           :strnrev Input_String   N  Flag\n";
    }
    else if(StriCmp(cCmd, "strrangerev") == 0)
    {
        cout << "Description     :reverses string in given range\n";
        cout << "Usage           :strrangerev Input_String   start  end\n";
    }
    else if(StriCmp(cCmd, "strcmp") == 0)
    {
        cout << "Description     :compares two strings\n";
        cout << "Usage           :strcmp Input_String1  Input_String2\n";
    }
    else if(StriCmp(cCmd, "stricmp") == 0)
    {
        cout << "Description     :compares two strings witout considering case\n";
        cout << "Usage           :stricmp Input_String1  Input_String2\n";
    }
    else if(StriCmp(cCmd, "strncmp") == 0)
    {
        cout << "Description     :compares two strings\n";
        cout << "                 if Flag = 0, then first N characters are compared\n";
        cout << "                 if Flag = 1, then last N characters are compared\n";
        cout << "Usage           :strncmp Input_String1 Input_String2   N\n";
    }
    else if(StriCmp(cCmd, "strincmp") == 0)
    {
        cout << "Description     :compares two strings witout considering case\n";
        cout << "                 if Flag = 0, then first N characters are compared\n";
        cout << "                 if Flag = 1, then last N characters are compared\n";
        cout << "Usage           :strincmp Input_String1 Input_String2   N  Flag\n";
    }
    else if(StriCmp(cCmd, "strset") == 0)
    {
        cout << "Description     :set characters in string with specified character\n";
        cout << "Usage           :strset Input_String1  char\n";
    }
    else if(StriCmp(cCmd, "strnset") == 0)
    {
        cout << "Description     :set N characters in string with specified character\n";
        cout << "                 if Flag = 0, then first N characters are set\n";
        cout << "                 if Flag = 1, then last N characters are set\n";
        cout << "Usage           :strnset Input_String1  char   N   Flag\n";
    }
    else if(StriCmp(cCmd, "ispldrm") == 0)
    {
        cout << "Description     :checks string is Palindrome or not\n";
        cout << "Usage           :ispldrm Input_String\n";
    }
    else if(StriCmp(cCmd, "isipldrm") == 0)
    {
        cout << "Description     :checks string is Palindrome or not witout considering case\n";
        cout << "Usage           :isipldrm Input_String\n";
    }
    else if(StriCmp(cCmd, "isagrm") == 0)
    {
        cout << "Description     :checks strings are Anagram or not\n";
        cout << "Usage           :isagrm Input_String1 Input_String2\n";
    }
    else if(StriCmp(cCmd, "wordcnt") == 0)
    {
        cout << "Description     :counts words in string\n";
        cout << "Usage           :wordcnt Input_String\n";
    }
    else if(StriCmp(cCmd, "wordrev") == 0)
    {
        cout << "Description     :reverse each word in string\n";
        cout << "Usage           :wordrev Input_String\n";
    }
    else if(StriCmp(cCmd, "maxoccur") == 0)
    {
        cout << "Description     :counts maximum occuring character in string\n";
        cout << "Usage           :maxoccur Input_String\n";
    }
    else if(StriCmp(cCmd, "firstoccur") == 0)
    {
        cout << "Description     :find first position of character in string\n";
        cout << "Usage           :firstoccur Input_String   char\n";
    }
    else if(StriCmp(cCmd, "lastoccur") == 0)
    {
        cout << "Description     :find last position of character in string\n";
        cout << "Usage           :lastoccur Input_String   char\n";
    }
    else if(StriCmp(cCmd, "charscnt") == 0)
    {
        cout << "Description     :counts total alphabets, digits, special characters, words in string\n";
        cout << "Usage           :charscnt Input_String\n";
    }
    else if(StriCmp(cCmd, "countlwr") == 0)
    {
        cout << "Description     :counts lower characters in string\n";
        cout << "Usage           :countlwr Input_String\n";
    }
    else if(StriCmp(cCmd, "countupr") == 0)
    {
        cout << "Description     :counts upper characters in string\n";
        cout << "Usage           :countupr Input_String\n";
    }
    else if(StriCmp(cCmd, "countspace") == 0)
    {
        cout << "Description     :counts spaces characters in string\n";
        cout << "Usage           :countspace Input_String\n";
    }
    else if(StriCmp(cCmd, "countspecial") == 0)
    {
        cout << "Description     :counts special characters in string\n";
        cout << "Usage           :countspecial Input_String\n";
    }
    else if(StriCmp(cCmd, "largestw") == 0)
    {
        cout << "Description     :computes legth of largest word in string\n";
        cout << "Usage           :largestw Input_String\n";
    } 
}// end of ManPage

////////////////////////////////////////////////////////////////////
//
//  Name        :ManPage
//  Input       :const char*, const char*
//  Returns     :void
//  Description :Man Page for commands
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////////////
void Strings::Help()
{
    cout << "help\n" <<endl;
    cout << "To Use        :type \'command<space>InP1<tab>InP2<tab>InP3<tab>InP4<Enter key>\'\n\n";
    cout << "ManPage       :type \'man man\' - to see more" << endl;
    cout << "StrLen        :type \'man strlen\' - to see more" << endl;
    cout << "StrLwr        :type \'man strlwr\' - to see more" << endl;
    cout << "StrNLwr       :type \'man strnlwr\' - to see more" << endl;
    cout << "StrUpr        :type \'man strupr\' - to see more" << endl;
    cout << "StrNUpr       :type \'man strnupr\' - to see more" << endl;
    cout << "StrTgl        :type \'man strtgl\' - to see more" << endl;
    cout << "StrNTgl       :type \'man strntgl\' - to see more" << endl;
    cout << "StrTglRev     :type \'man strtglrev\' - to see more" << endl;
    cout << "StrCat        :type \'man strcat\' - to see more" << endl;
    cout << "StrNCat       :type \'man strncat\' - to see more" << endl;
    cout << "StrCatAltr    :type \'man strcataltr\' - to see more" << endl;
    cout << "StrCatRev     :type \'man strcatrev\' - to see more" << endl;
    cout << "StrCpy        :type \'man strcpy\' - to see more" << endl;
    cout << "StrCpyRev     :type \'man strcpyrev\' - to see more" << endl;
    cout << "StrCpyTgl     :type \'man strcpytgl\' - to see more" << endl;
    cout << "StrTrimCpy    :type \'man strtrimcpy\' - to see more" << endl;
    cout << "StrTrimCpyX   :type \'man strtrimcpyx\' - to see more" << endl;
    cout << "StrNCpy       :type \'man strncpy\' - to see more" << endl;
    cout << "StrCpyCap     :type \'man strcpycap\' - to see more" << endl;
    cout << "StrCpyCapX    :type \'man strcpycapx\' - to see more" << endl;
    cout << "StrCpyLwr     :type \'man strcpylwr\' - to see more" << endl;
    cout << "StrCpyLwrX    :type \'man strcpylwrx\' - to see more" << endl;
    cout << "StrRev        :type \'man strrev\' - to see more" << endl;
    cout << "StrNRev       :type \'man strnrev\' - to see more" << endl;
    cout << "StrRangeRev   :type \'man strrangerev\' - to see more" << endl;
    cout << "StrFirstCap   :type \'man strfirstcap\' - to see more" << endl;
    cout << "StrCmp        :type \'man strcmp\' - to see more" << endl;
    cout << "StriCmp       :type \'man stricmp\' - to see more" << endl;
    cout << "StrNCmp       :type \'man strncmp\' - to see more" << endl;
    cout << "StriNCmp      :type \'man strincmp\' - to see more" << endl;
    cout << "StrSet        :type \'man strset\' - to see more" << endl;
    cout << "StrNSet       :type \'man strnset\' - to see more" << endl;
    cout << "IsPldrm       :type \'man ispldrm\' - to see more" << endl;
    cout << "IsiPldrm      :type \'man isipldrm\' - to see more" << endl;
    cout << "IsAgrm        :type \'man isagrm\' - to see more" << endl;
    cout << "WordCnt       :type \'man wordcnt\' - to see more" << endl;
    cout << "WordRev       :type \'man wordrev\' - to see more" << endl;
    cout << "MaxOccur      :type \'man maxoccur\' - to see more" << endl;
    cout << "FirstOccur    :type \'man firstoccur\' - to see more" << endl;
    cout << "LastOccur     :type \'man lastoccur\' - to see more" << endl;
    cout << "CharsCnt      :type \'man charscount\' - to see more" << endl;
    cout << "CountLwr      :type \'man countlwr\' - to see more" << endl;
    cout << "CountUpr      :type \'man countupr\' - to see more" << endl;
    cout << "CountSpace    :type \'man countspace\' - to see more" << endl;
    cout << "CountSpecials :type \'man countspecial\' - to see more" << endl;
    cout << "LargestWord   :type \'man largestw\' - to see more" << endl;
}