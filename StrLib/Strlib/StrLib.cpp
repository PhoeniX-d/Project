// Library File
/*
*   Program containing all string library functions
*/

#include "StrLib.h"

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLen
//  Input       :const CHAR*
//  Returns     :int
//  Description :computes length of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::StrLen(const CHAR* cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return -1;
    }
    int iLen = 0;
    while(*cSrc != '\0')
    {
        iLen++;
        cSrc++;
    }
    return iLen;
}// end of StrLen()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLwr
//  Input       :CHAR*
//  Returns     :void
//  Description :converts lower case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrLwr(CHAR* cSrc)
{
    if(NULL == cSrc)
	{
        cout << "Invalid Input\n";
        return;
	}
	while(*cSrc !='\0')
	{
		if((*cSrc >= 'A') && (*cSrc <= 'Z'))
		{
			*cSrc = *cSrc + 32;
		}
		cSrc++;
	}
}// end of StrLwr()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNLwr
//  Input       :const CHAR*, int, CHAR
//  Returns     :void
//  Description :convert into lower case the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNLwr(CHAR* cSrc, int iN, CHAR cFlag)
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
        while(*cSrc !='\0' && iN != 0)
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
        CHAR* cEnd = cSrc;
        while(*(cEnd + 1) != '\0')
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
}// end of StrNLwr()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrUpr
//  Input       :const CHAR*
//  Returns     :void
//  Description :converts upper case entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrUpr(CHAR* cSrc)
{
    if(NULL == cSrc)
    {
       cout << "Invalid Input\n" ;
       return;
    }
    while(*cSrc !='\0')
    {
        if((*cSrc >= 'a') && (*cSrc <= 'z'))
        {
            *cSrc = *cSrc - 32;
        }
        cSrc++;
    }
}// end of StrUpr()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNUpr
//  Input       :CHAR*, int, CHAR
//  Returns     :void
//  Description :converts upper case entered string upto N
//  Author      :Pranav Choudhary
//  Date        :25 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNUpr(CHAR* cSrc, int iN, CHAR cFlag)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
        return;
	}
    if(iN < 0)
    {
        iN = -iN;
    }
    if(cFlag == FIRST)
    {
        while(*cSrc !='\0' && iN != 0)
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
        CHAR* cEnd = cSrc;
        while(*(cEnd + 1) != '\0')
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
}// end of StrNUpr()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrTgl
//  Input       :const CHAR*
//  Returns     :void
//  Description :Toggle case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrTgl(CHAR* cSrc)
{
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return;

    }
    while(*cSrc !='\0')
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

}// end of StrTgl()

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrTglRev
//  Input       :CHAR*
//  Returns     :void
//  Description :reverse the contents of that string by toggling the case
//  Author      :Pranav Choudhary
//  Date        :28 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrTglRev(CHAR* cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n";
        return;
    }

    CHAR* cStart = cSrc;
    CHAR* cEnd = cSrc;
    CHAR cTemp = '\0';

    while(*cEnd != '\0')
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
}// end of StrTglRev()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNTgl
//  Input       :const CHAR*
//  Returns     :void
//  Description :Toggle case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNTgl(CHAR* cSrc, int iN, CHAR cFlag)
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

    if(cFlag == FIRST)
    {
        while(*cSrc !='\0' && iN != 0)
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
        CHAR* cEnd = cSrc;
        while(*(cEnd + 1) != '\0')
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

}// end of StrNTgl()

////////////////////////////////////////////////////////////
//
//  Name        :StrCat
//  Input       :CHAR*, const CHAR*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCat(CHAR* cStr1, const CHAR* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while(*cStr1 != '\0')
    {
        cStr1++;
    }
    while(*cStr2 != '\0')
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
//  Input       :CHAR*, const CHAR*
//  Returns     :void
//  Description :concate 2nd string to first in reverse
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCatRev(CHAR* cDest, const CHAR* cSrc)
{
    if(cDest == NULL || cSrc == NULL)
    {
        cout << "Invalid Input\n";
        return;
    }
    const CHAR* cEnd = cSrc;

    while(*cDest != '\0')
    {
        cDest++;
    }
    while(*(cEnd + 1) != '\0')
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
//  Input       :CHAR*, const CHAR*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCatAltr(const CHAR* cSrc, CHAR* cDest)
{
    if(cDest == NULL || cSrc == NULL)
    {
        cout << "Invalid Input\n";
        return;
    }
    while(*cDest != '\0')
    {
        cDest++;
    }
    while(*cSrc != '\0')
    {
        *cDest = *cSrc;
        if (*(cSrc + 1) == '\0')
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
//  Input       :CHAR*, CHAR*, int, CHAR
//  Returns     :void
//  Description :append N CHARacters of second string after
//               first string(Implement strncat())
//  Author      :Pranav Choudhary
//  Date        :25 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrNCat(CHAR* cStr1, const CHAR* cStr2, int iN, CHAR cFlag)
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
    while(*cStr1 != '\0')
    {
        cStr1++;
    }
    if(cFlag == FIRST)
    {
        while(*cStr2 != '\0' && iN != 0)
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
        const CHAR* cEnd = cStr2;        
        while(*(cEnd + 1) != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpy(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*, int
//  Returns     :void
//  Description :copy source string's N CHARs into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////
void Strings::StrNCpy(const CHAR* cSrc, CHAR* cDest, int iN, CHAR cFlag)
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
        while(*cSrc != '\0' && iN != 0)
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
        const CHAR* cEnd = cSrc;
        while(*(cEnd + 1) != '\0')
        {
            cEnd++;
        }
        while(iN != 1)
        {
            cEnd--;
            iN--;
        }
        while (*cEnd != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :copy capital letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpyCap(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :convert small letters to capital letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrCpyCapX(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :copy lower letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpyLwr(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :convert capital letters to small letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrCpyLwrX(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :copy source string into destination string
//               in reverse
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrCpyRev(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    int iCnt = 0;
    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrTrimCpy(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :function that removes extra spaces
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
////////////////////////////////////////////////////////////
void Strings::StrTrimCpyX(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cSrc != '\0')
    {
        if(*cSrc == ' ')
		{
			while((*cSrc == ' ' || *cSrc == '\t') && (*cSrc != '\0'))
			{
				cSrc++;
			}
		}
		else
		{
			while(*cSrc != ' ' && *cSrc != '\0')
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
//  Input       :const CHAR*, CHAR*
//  Returns     :void
//  Description :toggle letters from source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void Strings::StrCpyTgl(const CHAR* cSrc, CHAR* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }

    while(*cSrc != '\0')
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
//  Input       :CHAR*
//  Returns     :void
//  Description :Reverses entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrRev(CHAR* cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    CHAR cTemp = '\0';
    CHAR* cStart = cSrc;
    CHAR* cEnd = cSrc;

    while(*(cEnd + 1) != '\0' )
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
//  Name        :FirstCHARCap
//  Input       :CHAR* 
//  Returns     :void
//  Description :replace each occurrence of first CHARacter of 
//               each word into capital case
//  Author      :Pranav Choudhary
//  Date        :29 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrFirstCap(CHAR* cStr)
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
//  Input       :CHAR*, int
//  Returns     :void
//  Description :reverse the string till first N CHARacters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNRev(CHAR* cSrc, int iN, CHAR cFlag)
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

    CHAR cTemp = '\0';
    CHAR* cStart = cSrc;
    CHAR* cEnd = cSrc;
    
    if(cFlag == FIRST)
    {
        while(*cEnd != '\0' && iN != 1)
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

        while(*(cStart + 1) != '\0')
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
//  Input       :CHAR*, int, int
//  Returns     :void
//  Description :reverse the string in that range without
//               taking another string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrRangeRev(CHAR* cSrc, int iS, int iE)
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

    CHAR cTemp = '\0';
    CHAR* cStart = cSrc;
    CHAR* cEnd = cSrc;

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
//  Input       :const CHAR*, const CHAR*
//  Returns     :int
//  Description :compare 2 strings
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StrCmp(const CHAR* cStr1, const CHAR* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }

    while(*cStr1 == *cStr2)
    {
        if(*cStr1 == '\0')
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
//  Input       :const CHAR*, const CHAR*
//  Returns     :int
//  Description :compare 2 strings case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StriCmp(const CHAR* cStr1, const CHAR* cStr2)
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
//  Input       :const CHAR*, const CHAR*
//  Returns     :int
//  Description :Implementation of strncmp()
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StrNCmp(const CHAR* cStr1, const CHAR* cStr2, int iN, CHAR cFlag)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    const CHAR* cEnd1 = cStr1;
    const CHAR* cEnd2 = cStr2;

    if(iN < 0)
    {
        iN = -iN;
    }
    if(cFlag == FIRST)
    {
        while(*cEnd1 == *cEnd2 && iN != 0)
        {
            if(*cEnd1 == '\0' && iN != 0)
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
        while(*(cEnd1 + 1) != '\0' )
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
//  Input       :const CHAR*, const CHAR*
//  Returns     :int
//  Description :Implementation of strncmp()
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int Strings::StriNCmp(const CHAR* cStr1, const CHAR* cStr2, int iN, CHAR cFlag)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }

    const CHAR* cEnd1 = cStr1;
    const CHAR* cEnd2 = cStr2;

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
        while(*(cEnd1 + 1) != '\0' )
        {
            cEnd1++;
        }
        while(*(cEnd2 + 1) != '\0')
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
//  Input       :CHAR*, CHAR
//  Returns     :void
//  Description :sets all CHARacters in string to a specific CHARacter
//               (Implement strset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrSet(CHAR* cSrc, CHAR ch)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while(*cSrc != '\0')
    {
        *cSrc = ch;
        cSrc++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNSet
//  Input       :CHAR*, CHAR
//  Returns     :void
//  Description :sets first N CHARacters in string to a specific 
//               CHARacter (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::StrNSet(CHAR* cSrc, CHAR ch, int iN, CHAR cFlag)
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
        while(*cSrc != '\0'  && iN != 0)
        {
            *cSrc = ch;
            cSrc++;
            iN--;
        }
    }
    else if(cFlag == LAST)
    {
        CHAR* cEnd = cSrc;
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
//  Input       :const CHAR* 
//  Returns     :int
//  Description :count words in given string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::WordCnt(const CHAR* cStr)
{
    int iCnt = 0;
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
       
    while(*cStr != '\0')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0'))
			{
				cStr++;
			}
		}
		else
		{
			while(*cStr != ' ' && *cStr != '\0')
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
//  Input       :CHAR*
//  Returns     :void
//  Description :reverse words from that string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::WordRev(CHAR* cSrc)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    CHAR cTemp = '\0';
    CHAR* cStart = cSrc;
    CHAR* cEnd = cSrc;

    while(*cSrc != '\0')
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
//  Input       :const CHAR* 
//  Returns     :void
//  Description :find maximum occurring CHARacter in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::MaxOccur(const CHAR* cSrc)
{
    int iCHARs[MAX_CHAR] = {0}, i = 0, iMax = 0;
    CHAR ch = '\0';
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while (*cSrc != '\0')
    {
        iCHARs[*cSrc]++;
        cSrc++;
    }
    iMax = iCHARs[0];
    for (i = 0; i < MAX_CHAR; i++)
    {
        if(i != 32)
        {
            if(iMax < iCHARs[i])
            {
                iMax = iCHARs[i];
                ch = i;
            }
        }
    }

    cout << "Max occuring CHAR \'" << ch << "\' with occurance " << iMax << endl;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :strchr
//  Input       :const CHAR*, CHAR
//  Returns     :int
//  Description :return position of first occurance of entered 
//               CHAR in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::StrChr(const CHAR* cSrc, CHAR ch)
{
    int iCnt = -1;
    while(*cSrc != '\0')
    {
        if(*cSrc == ch)
        {
            iCnt++;
            break;
        }
        iCnt++;
        cSrc++;
    }
    if(*cSrc == '\0')
        return -1;
    else
        return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrrChr
//  Input       :const CHAR*, CHAR
//  Returns     :int
//  Description :return position of last occurance of entered 
//               CHAR in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::StrrChr(const CHAR* cSrc, CHAR ch)
{
    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return -1;
    }
    int iCnt = 0;
    while(*cSrc != '\0')
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
//  Input       :const CHAR*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL Strings::IsPldrm(const CHAR* cSrc)
{
    const CHAR* cStart = NULL;
    const CHAR* cEnd = NULL;

    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0')
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
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Name        :IsiPldrm
//  Input       :const CHAR*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////////
BOOL Strings::IsiPldrm(const CHAR* cSrc)
{
    const CHAR* cStart = NULL;
    const CHAR* cEnd = NULL;

    if(cSrc == NULL)
    {
        cout << "Invalid Input\n" ;
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0')
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
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CharsCnt
//  Input       :const CHAR* 
//  Returns     :void
//  Description :count total number of alphabets,
//               digits and special CHARacters in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void Strings::CharsCnt(const CHAR* cSrc)
{
    int iA = 0, iSp = 0, iD = 0, iW = 0, iState = OUT;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return;
    }
    while (*cSrc != '\0')
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
//  Input       :const CHAR* 
//  Returns     :int
//  Description :count capital letters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountUpr(const CHAR* cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    while(*cSrc != '\0')
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
//  Input       :const CHAR* 
//  Returns     :int
//  Description :count small letters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountLwr(const CHAR* cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    while(*cSrc != '\0')
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
//  Input       :const CHAR*, const CHAR*
//  Returns     :BOOL
//  Description :check whether given strings are Anagram strings or not.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////
BOOL Strings::IsAgrm(const CHAR* cStr1, const CHAR* cStr2)
{
    CHAR cCHARs[MAX_CHAR] = {0};
    int i = 0;
    if(cStr1 == NULL || cStr2 == NULL)
    {
        cout << "Invalid Input\n" ;
        return FALSE;
    }

    while(*cStr1 != '\0' && *cStr2 != '\0')
    {
        cCHARs[*cStr1]++;
        cCHARs[*cStr2]--;
        cStr1++;
        cStr2++;
    }
    if((*cStr1 == '\0'  && *cStr2 == '\0'))
    {
       for (i = 0; i < MAX_CHAR; i++)
        {
            if(cCHARs[i] != 0)
            {
                break;
            }
        }
    }
    if(i == MAX_CHAR)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}// end of IsAgrm

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountSpecials
//  Input       :const CHAR* 
//  Returns     :int
//  Description :count special CHARacters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountSpecials(const CHAR* cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        cout << "Invalid Input\n" ;
        return ERROR;
    }
    
    while(*cSrc != '\0')
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
//  Input       :const CHAR*
//  Returns     :int
//  Description :compute space in the entered string
//  Author      :Pranav Choudhary
//  Date        :26 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::CountSpace(const CHAR* cSrc)
{
    int iCnt = 0;
    while(*cSrc != '\0')
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
//  Input       :const CHAR* 
//  Returns     :int
//  Description :program which accept string from user and return 
//               length of largest word
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
//////////////////////////////////////////////////////////////////////
int Strings::LargestWord(const CHAR* cStr)
{
    int iMax = 0 ,i = 0 ,iCnt = 0;

    if(cStr == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }

    while(*cStr != '\0')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && *cStr != '\0')
			{
				cStr++;
			}
		}
		else
		{
			while(*cStr != ' ' && *cStr != '\0')
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
//  Input       :const CHAR*, const CHAR*
//  Returns     :void
//  Description :Man Page for commands
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////////////
void Strings::ManPage(const CHAR* cCmd)
{
    if(StriCmp(cCmd, "strlen") == 0)
    {
        cout << "Description     :Computes length of enterd string\n";
        cout << "Usage           :strlen\n";
    }
    else if(StriCmp(cCmd, "help") == 0)
    {
        cout << "Description     :Displays help menu\n";
        cout << "Usage           :help\n";
    }
    else if(StriCmp(cCmd, "man") == 0)
    {
        cout << "Description     :Displays how to use command\n";
        cout << "Usage           :man Name_of_function\n";
    }
    else if(StriCmp(cCmd, "strlwr") == 0)
    {
        cout << "Description     :converts entire string into lower case\n";
        cout << "Usage           :strlwr\n";
    }
    else if(StriCmp(cCmd, "strupr") == 0)
    {
        cout << "Description     :converts entire string into upper case\n";
        cout << "Usage           :strupr\n";
    }
    else if(StriCmp(cCmd, "strnlwr") == 0)
    {
        cout << "Description     :converts string into lower case\n";
        cout << "                 if Flag = 0, then first N CHARacters are converted\n";
        cout << "                 if Flag = 1, then last N CHARacters are converted\n";
        cout << "Usage           :strnlwr\n";
    }
    else if(StriCmp(cCmd, "strnupr") == 0)
    {
        cout << "Description     :converts string into upper case\n";
        cout << "                 if Flag = 0, then first N CHARacters are converted\n";
        cout << "                 if Flag = 1, then last N CHARacters are converted\n";
        cout << "Usage           :strnupr\n";
    }
    else if(StriCmp(cCmd, "strtgl") == 0)
    {
        cout << "Description     :toggles CHARacters in string\n";
        cout << "Usage           :strtgl\n";
    }
    else if(StriCmp(cCmd, "strntgl") == 0)
    {
        cout << "Description     :toggles CHARacters in string\n";
        cout << "                 if Flag = 0, then first N CHARacters are toggled\n";
        cout << "                 if Flag = 1, then last N CHARacters are toggled\n";
        cout << "Usage           :strntgl\n";
    }
    else if(StriCmp(cCmd, "strtglrev") == 0)
    {
        cout << "Description     :toggles CHARacters in string in reverse\n";
        cout << "Usage           :strtglrev\n";
    }
    else if(StriCmp(cCmd, "strcat") == 0)
    {
        cout << "Description     :concatinates src string into destination\n";
        cout << "Usage           :strcat\n";
    }
    else if(StriCmp(cCmd, "strcataltr") == 0)
    {
        cout << "Description     :concatinates alternative CHARs from src string into destination\n";
        cout << "Usage           :strcataltr\n";
    }
    else if(StriCmp(cCmd, "strcatrev") == 0)
    {
        cout << "Description     :concatinates src string into destination in reverse\n";
        cout << "Usage           :strcatrev\n";
    }
    else if(StriCmp(cCmd, "strncat") == 0)
    {
        cout << "Description     :concatinates src string into destination\n";
        cout << "                 if Flag = 0, then first N CHARacters are concatinated\n";
        cout << "                 if Flag = 1, then last N CHARacters are concatinated\n";
        cout << "Usage           :strncat\n";
    }
    else if(StriCmp(cCmd, "strcpy") == 0)
    {
        cout << "Description     :copies src string into destination\n";
        cout << "Usage           :strcpy\n";
    }
    else if(StriCmp(cCmd, "strfirstcap") == 0)
    {
        cout << "Description     :capitalize each words first CHARacter\n";
        cout << "Usage           :strfirstcap\n";
    }
    else if(StriCmp(cCmd, "strncpy") == 0)
    {
        cout << "Description     :copies src string into destination\n";
        cout << "                 if Flag = 0, then first N CHARacters are copied\n";
        cout << "                 if Flag = 1, then last N CHARacters are copied\n";
        cout << "Usage           :strncpy\n";
    }
    else if(StriCmp(cCmd, "strcpycap") == 0)
    {
        cout << "Description     :copies capitals CHARs from src string into destination\n";
        cout << "Usage           :strcpycap\n";
    }
    else if(StriCmp(cCmd, "strcpycapx") == 0)
    {
        cout << "Description     :copies capitals CHARs from src string into destination by toggling case\n";
        cout << "Usage           :strcpycapx\n";
    }
    else if(StriCmp(cCmd, "strcpylwr") == 0)
    {
        cout << "Description     :copies lower CHARs from src string into destination\n";
        cout << "Usage           :strcpylwr\n";
    }
    else if(StriCmp(cCmd, "strcpylwrx") == 0)
    {
        cout << "Description     :copies lower CHARs from src string into destination by toggling case\n";
        cout << "Usage           :strcpylwrx\n";
    }
    else if(StriCmp(cCmd, "strtrimcpy") == 0)
    {
        cout << "Description     :copies src string into destination without spaces\n";
        cout << "Usage           :strtrimcpy\n";
    }
    else if(StriCmp(cCmd, "strtrimcpyx") == 0)
    {
        cout << "Description     :copies src string into destination by removing extra spaces\n";
        cout << "Usage           :strtrimcpyx\n";
    }
    else if(StriCmp(cCmd, "strcpytgl") == 0)
    {
        cout << "Description     :copies src string into destination by toggling case\n";
        cout << "Usage           :strcpytgl\n";
    }
    else if(StriCmp(cCmd, "strcpyrev") == 0)
    {
        cout << "Description     :copies src string into destination in reverse\n";
        cout << "Usage           :strcpyrev\n";
    }
    else if(StriCmp(cCmd, "strrev") == 0)
    {
        cout << "Description     :reverses string\n";
        cout << "Usage           :strrev\n";
    }
    else if(StriCmp(cCmd, "strnrev") == 0)
    {
        cout << "Description     :reverses string\n";
        cout << "                 if Flag = 0, then first N CHARacters are reversed\n";
        cout << "                 if Flag = 1, then last N CHARacters are reversed\n";
        cout << "Usage           :strnrev\n";
    }
    else if(StriCmp(cCmd, "strrangerev") == 0)
    {
        cout << "Description     :reverses string in given range\n";
        cout << "Usage           :strrangerev\n";
    }
    else if(StriCmp(cCmd, "strcmp") == 0)
    {
        cout << "Description     :compares two strings\n";
        cout << "Usage           :strcmp\n";
    }
    else if(StriCmp(cCmd, "stricmp") == 0)
    {
        cout << "Description     :compares two strings witout considering case\n";
        cout << "Usage           :stricmp\n";
    }
    else if(StriCmp(cCmd, "strncmp") == 0)
    {
        cout << "Description     :compares two strings\n";
        cout << "                 if Flag = 0, then first N CHARacters are compared\n";
        cout << "                 if Flag = 1, then last N CHARacters are compared\n";
        cout << "Usage           :strncmp\n";
    }
    else if(StriCmp(cCmd, "strincmp") == 0)
    {
        cout << "Description     :compares two strings witout considering case\n";
        cout << "                 if Flag = 0, then first N CHARacters are compared\n";
        cout << "                 if Flag = 1, then last N CHARacters are compared\n";
        cout << "Usage           :strincmp\n";
    }
    else if(StriCmp(cCmd, "strset") == 0)
    {
        cout << "Description     :set CHARacters in string with specified CHARacter\n";
        cout << "Usage           :strset\n";
    }
    else if(StriCmp(cCmd, "strnset") == 0)
    {
        cout << "Description     :set N CHARacters in string with specified CHARacter\n";
        cout << "                 if Flag = 0, then first N CHARacters are set\n";
        cout << "                 if Flag = 1, then last N CHARacters are set\n";
        cout << "Usage           :strnset\n";
    }
    else if(StriCmp(cCmd, "ispldrm") == 0)
    {
        cout << "Description     :checks string is Palindrome or not\n";
        cout << "Usage           :ispldrm\n";
    }
    else if(StriCmp(cCmd, "isipldrm") == 0)
    {
        cout << "Description     :checks string is Palindrome or not witout considering case\n";
        cout << "Usage           :isipldrm\n";
    }
    else if(StriCmp(cCmd, "isagrm") == 0)
    {
        cout << "Description     :checks strings are Anagram or not\n";
        cout << "Usage           :isagrm\n";
    }
    else if(StriCmp(cCmd, "wordcnt") == 0)
    {
        cout << "Description     :counts words in string\n";
        cout << "Usage           :wordcnt\n";
    }
    else if(StriCmp(cCmd, "wordrev") == 0)
    {
        cout << "Description     :reverse each word in string\n";
        cout << "Usage           :wordrev\n";
    }
    else if(StriCmp(cCmd, "maxoccur") == 0)
    {
        cout << "Description     :counts maximum occuring CHARacter in string\n";
        cout << "Usage           :maxoccur\n";
    }
    else if(StriCmp(cCmd, "strchr") == 0)
    {
        cout << "Description     :find first position of CHARacter in string\n";
        cout << "Usage           :strchr\n";
    }
    else if(StriCmp(cCmd, "strrchr") == 0)
    {
        cout << "Description     :find last position of CHARacter in string\n";
        cout << "Usage           :strrchr\n";
    }
    else if(StriCmp(cCmd, "CharsCnt") == 0)
    {
        cout << "Description     :counts total alphabets, digits, special CHARacters, words in string\n";
        cout << "Usage           :CharsCnt\n";
    }
    else if(StriCmp(cCmd, "countlwr") == 0)
    {
        cout << "Description     :counts lower CHARacters in string\n";
        cout << "Usage           :countlwr\n";
    }
    else if(StriCmp(cCmd, "countupr") == 0)
    {
        cout << "Description     :counts upper CHARacters in string\n";
        cout << "Usage           :countupr\n";
    }
    else if(StriCmp(cCmd, "countspace") == 0)
    {
        cout << "Description     :counts spaces CHARacters in string\n";
        cout << "Usage           :countspace\n";
    }
    else if(StriCmp(cCmd, "countspecial") == 0)
    {
        cout << "Description     :counts special CHARacters in string\n";
        cout << "Usage           :countspecial\n";
    }
    else if(StriCmp(cCmd, "largestw") == 0)
    {
        cout << "Description     :computes legth of largest word in string\n";
        cout << "Usage           :largestw\n";
    } 
}// end of ManPage

////////////////////////////////////////////////////////////////////
//
//  Name        :ManPage
//  Input       :const CHAR*, const CHAR*
//  Returns     :void
//  Description :Man Page for commands
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////////////
void Strings::Help()
{
    cout << "help\n" <<endl;
    cout << "To Use        :type \'Name of function\'\n\n";
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
    cout << "strchr        :type \'man strchr\' - to see more" << endl;
    cout << "strrchr       :type \'man strrchr\' - to see more" << endl;
    cout << "CharsCnt      :type \'man CHARscount\' - to see more" << endl;
    cout << "CountLwr      :type \'man countlwr\' - to see more" << endl;
    cout << "CountUpr      :type \'man countupr\' - to see more" << endl;
    cout << "CountSpace    :type \'man countspace\' - to see more" << endl;
    cout << "CountSpecials :type \'man countspecial\' - to see more" << endl;
    cout << "LargestWord   :type \'man largestw\' - to see more" << endl;
}

/////////////////////////////// End of StrLib.cpp /////////////////////////////////////////// 