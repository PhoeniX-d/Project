// Library File
/*
*   Program containing all string library functions
*/
#include "Strllibdll.h"

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
int StrLen(const char* cSrc)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }
    int iLen = 0;
    while (*cSrc != '\0')
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
void StrLwr(char* cSrc)
{
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    while (*cSrc != '\0')
    {
        if ((*cSrc >= 'A') && (*cSrc <= 'Z'))
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
void StrNLwr(char* cSrc, int iN, BOOL bFlag)
{
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    if (iN < 0)
    {
        iN = -iN;
    }

    if (bFlag == FALSE)
    {
        while (*cSrc != '\0' && iN != 0)
        {
            if ((*cSrc >= 'A') && (*cSrc <= 'Z'))
            {
                *cSrc = *cSrc + 32;
            }
            cSrc++;
            iN--;
        }
    }
    else if (bFlag == TRUE)
    {
        char* cEnd = cSrc;
        while (*(cEnd + 1) != '\0')
        {
            cEnd++;
        }
        do
        {
            if ((*cEnd >= 'A') && (*cEnd <= 'Z'))
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
void StrUpr(char* cSrc)
{
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    while (*cSrc != '\0')
    {
        if ((*cSrc >= 'a') && (*cSrc <= 'z'))
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
void StrNUpr(char* cSrc, int iN, BOOL bFlag)
{
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    if (iN < 0)
    {
        iN = -iN;
    }
    if (bFlag == FALSE)
    {
        while (*cSrc != '\0' && iN != 0)
        {
            if ((*cSrc >= 'a') && (*cSrc <= 'z'))
            {
                *cSrc = *cSrc - 32;
            }
            cSrc++;
            iN--;
        }
    }
    else if (bFlag == TRUE)
    {
        char* cEnd = cSrc;
        while (*(cEnd + 1) != '\0')
        {
            cEnd++;
        }
        do
        {
            if ((*cEnd >= 'a') && (*cEnd <= 'z'))
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
void StrTgl(char* cSrc)
{
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    while (*cSrc != '\0')
    {
        if ((*cSrc >= 'A') && (*cSrc <= 'Z'))
        {
            *cSrc = *cSrc + 32;
        }
        else if ((*cSrc >= 'a') && (*cSrc <= 'z'))
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
void StrTglRev(char* cSrc)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    char* cStart = cSrc;
    char* cEnd = cSrc;
    char cTemp = '\0';

    while (*cEnd != '\0')
    {
        if (*cEnd >= 'a' && *cEnd <= 'z')
        {
            *cEnd = *cEnd - 32;
        }
        else if (*cEnd >= 'A' && *cEnd <= 'Z')
        {
            *cEnd = *cEnd + 32;
        }
        cEnd++;
    }
    cEnd--;
    while (cStart < cEnd)
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
void StrNTgl(char* cSrc, int iN, BOOL bFlag)
{
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
    }

    if (iN < 0)
    {
        iN = -iN;
    }

    if (bFlag == FALSE)
    {
        while (*cSrc != '\0' && iN != 0)
        {
            if ((*cSrc >= 'A') && (*cSrc <= 'Z'))
            {
                *cSrc = *cSrc + 32;
            }
            else if ((*cSrc >= 'a') && (*cSrc <= 'z'))
            {
                *cSrc = *cSrc - 32;
            }
            cSrc++;
            iN--;
        }
    }
    else if (bFlag == TRUE)
    {
        char* cEnd = cSrc;
        while (*(cEnd + 1) != '\0')
        {
            cEnd++;
        }

        do
        {
            if ((*cEnd >= 'A') && (*cEnd <= 'Z'))
            {
                *cEnd = *cEnd + 32;
            }
            else if ((*cEnd >= 'a') && (*cEnd <= 'z'))
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
void StrCat(char* cStr1, const char* cStr2)
{
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cStr1 != '\0')
    {
        cStr1++;
    }
    while (*cStr2 != '\0')
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
//  Description :concate 2nd string to FALSE in reverse
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCatRev(char* cDest, const char* cSrc)
{
    if (cDest == NULL || cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    const char* cEnd = cSrc;

    while (*cDest != '\0')
    {
        cDest++;
    }
    while (*(cEnd + 1) != '\0')
    {
        cEnd++;
    }

    while (cEnd != (cSrc - 1))
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
void StrCatAltr(const char* cSrc, char* cDest)
{
    if (cDest == NULL || cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cDest != '\0')
    {
        cDest++;
    }
    while (*cSrc != '\0')
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
//  Input       :char*, char*, int, char
//  Returns     :void
//  Description :append N characters of second string after
//               FALSE string(Implement strncat())
//  Author      :Pranav Choudhary
//  Date        :25 August 2020
//
////////////////////////////////////////////////////////////
void StrNCat(char* cStr1, const char* cStr2, int iN, BOOL bFlag)
{
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if (iN < 0)
    {
        iN = -iN;
    }
    while (*cStr1 != '\0')
    {
        cStr1++;
    }
    if (bFlag == FALSE)
    {
        while (*cStr2 != '\0' && iN != 0)
        {
            *cStr1 = *cStr2;
            cStr2++;
            cStr1++;
            iN--;
        }
        *cStr1 = '\0';
    }
    else if (bFlag == TRUE)
    {
        const char* cEnd = cStr2;
        while (*(cEnd + 1) != '\0')
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
void StrCpy(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
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
void StrNCpy(const char* cSrc, char* cDest, int iN, BOOL bFlag)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if (iN < 0)
        iN = -iN;

    if (bFlag == FALSE)
    {
        while (*cSrc != '\0' && iN != 0)
        {
            *cDest = *cSrc;
            cSrc++;
            cDest++;
            iN--;
        }
        *cDest = '\0';
    }
    else if (bFlag == TRUE)
    {
        const char* cEnd = cSrc;
        while (*(cEnd + 1) != '\0')
        {
            cEnd++;
        }
        while (iN != 1)
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
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy capital letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCpyCap(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
    {
        if (*cSrc >= 'A' && *cSrc <= 'Z')
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
void StrCpyCapX(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
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
void StrCpyLwr(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
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
void StrCpyLwrX(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
    {
        if (*cSrc >= 'A' && *cSrc <= 'Z')
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
void StrCpyRev(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    int iCnt = 0;
    while (*cSrc != '\0')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while (iCnt != 0)
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
void StrTrimCpy(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
    {
        if (*cSrc != ' ')
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
void StrTrimCpyX(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        if (*cSrc == ' ')
        {
            while ((*cSrc == ' ' || *cSrc == '\t') && (*cSrc != '\0'))
            {
                cSrc++;
            }
        }
        else
        {
            while (*cSrc != ' ' && *cSrc != '\0')
            {
                *cDest = *cSrc;
                cSrc++;
                cDest++;
            }
            *cDest = *cSrc;
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
void StrCpyTgl(const char* cSrc, char* cDest)
{
    if (cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cSrc != '\0')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc - 32;
            cDest++;
        }
        else if (*cSrc >= 'A' && *cSrc <= 'Z')
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
void StrRev(char* cSrc)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    char cTemp = '\0';
    char* cStart = cSrc;
    char* cEnd = cSrc;

    while (*(cEnd + 1) != '\0')
    {
        cEnd++;
    }

    while (cStart < cEnd)
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
//  Name        :StrFirstCap
//  Input       :char *
//  Returns     :void
//  Description :replace each occurrence of FALSE character of 
//               each word into capital case
//  Author      :Pranav Choudhary
//  Date        :29 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrFirstCap(char* cStr)
{
    if (NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    while (*cStr != '\0' && *cStr != '\0')
    {
        if (*cStr == ' ')
        {
            while ((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0') && (*cStr != '\0'))
            {
                cStr++;
            }
        }
        else
        {
            if (*cStr >= 'a' && *cStr <= 'z')
            {
                *cStr = *cStr - 32;
            }
            while (*cStr != ' ' && *cStr != '\0' && (*cStr != '\0'))
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
//  Description :reverse the string till FALSE N characters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNRev(char* cSrc, int iN, BOOL bFlag)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if (iN < 0)
    {
        iN = -iN;
    }

    char cTemp = '\0';
    char* cStart = cSrc;
    char* cEnd = cSrc;

    if (bFlag == FALSE)
    {
        while (*cEnd != '\0' && iN != 1)
        {
            iN--;
            cEnd++;
        }

        if (iN != 1)
            cEnd--;

        while (cStart < cEnd)
        {
            cTemp = *cStart;
            *cStart = *cEnd;
            *cEnd = cTemp;
            cEnd--;
            cStart++;
        }
    }
    else if (bFlag == TRUE)
    {
        cStart = cSrc;
        cEnd = NULL;

        while (*(cStart + 1) != '\0')
        {
            cStart++;
        }
        cEnd = cStart;

        while (iN != 0 && cEnd != cSrc)
        {
            iN--;
            cEnd--;
        }

        while (cStart > cEnd)
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
void StrRangeRev(char* cSrc, int iS, int iE)
{
    if (iS < 0)
    {
        iS = -iS;
    }
    if (iE < 0)
    {
        iE = -iE;
    }
    if (cSrc == NULL || iS >= iE || StrLen(cSrc) < iS || StrLen(cSrc) < iE)
    {
        printf("Invalid Input\n");
        return;
    }

    char cTemp = '\0';
    char* cStart = cSrc;
    char* cEnd = cSrc;

    if (iS == 0)
    {
        cStart = cSrc + iS;
    }
    else
    {
        cStart = cSrc + (iS - 1);
    }
    cEnd = cSrc + (iE - 1);

    while (cStart < cEnd)
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
int StrCmp(const char* cStr1, const char* cStr2)
{
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }
    if (StrLen(cStr1) != StrLen(cStr2))
    {
        return -1;
    }
    while (*cStr1 == *cStr2)
    {
        if (*cStr1 == '\0')
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if (*cStr1 == *cStr2)
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
int StriCmp(const char* cStr1, const char* cStr2)
{
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }
    if (StrLen(cStr1) != StrLen(cStr2))
    {
        return -1;
    }
    while (*cStr1 != '\0' && *cStr2 != '\0')
    {
        if ((*cStr1 != *cStr2) && (*cStr1 != *cStr2 + 32) && (*cStr1 != *cStr2 - 32))
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if (*cStr1 == *cStr2)
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
int StrNCmp(const char* cStr1, const char* cStr2, int iN, BOOL bFlag)
{
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }

    const char* cEnd1 = cStr1;
    const char* cEnd2 = cStr2;

    if (iN < 0)
    {
        iN = -iN;
    }
    if (bFlag == FALSE)
    {
        while (*cEnd1 == *cEnd2 && iN != 0)
        {
            if (*cEnd1 == '\0' && iN != 0)
            {
                break;
            }
            cEnd1++;
            cEnd2++;
            iN--;
        }
    }
    else if (bFlag == TRUE)
    {
        while (*(cEnd1 + 1) != '\0')
        {
            cEnd1++;
        }
        while (*(cEnd2 + 1) != '\0' && *(cEnd2 + 1) != '\n')
        {
            cEnd2++;
        }

        while (*cEnd1 == *cEnd2 && iN != 0)
        {
            if (*cEnd1 == *cStr1 && iN != 0)
            {
                break;
            }
            cEnd1--;
            cEnd2--;
            iN--;
        }
    }
    if (*cEnd1 == *cEnd2 || iN == 0)
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
int StriNCmp(const char* cStr1, const char* cStr2, int iN, BOOL bFlag)
{
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }

    const char* cEnd1 = cStr1;
    const char* cEnd2 = cStr2;

    if (iN < 0)
    {
        iN = -iN;
    }

    if (bFlag == FALSE)
    {
        while (*cEnd1 != '\0' && *cEnd2 != '\0' && *cEnd1 != '\n' && *cEnd2 != '\n' && iN != 0)
        {
            if ((*cEnd1 != *cEnd2) && (*cEnd1 != *cEnd2 + 32) && (*cEnd1 != *cEnd2 - 32) && iN != 0)
            {
                break;
            }
            cEnd1++;
            cEnd2++;
            iN--;
        }
    }
    else if (bFlag == TRUE)
    {
        while (*(cEnd1 + 1) != '\0')
        {
            cEnd1++;
        }
        while (*(cEnd2 + 1) != '\0')
        {
            cEnd2++;
        }

        while (*cEnd1 == *cEnd2 && iN != 0)
        {
            if ((*cEnd1 != *cStr1) && (*cEnd1 != *cStr1 + 32) && (*cEnd1 != *cStr1 - 32) && iN != 0)
            {
                break;
            }
            cEnd1--;
            cEnd2--;
            iN--;
        }
    }
    if (*cEnd1 == *cEnd2 || iN == 0)
        return 0;
    else
        return *cEnd1 - *cEnd2;

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
void StrSet(char* cSrc, char ch)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
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
//  Description :sets FALSE N characters in string to a specific 
//               character (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNSet(char* cSrc, char ch, int iN, BOOL bFlag)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if (iN < 0)
    {
        iN = -iN;
    }
    if (bFlag == FALSE)
    {
        while (*cSrc != '\0' && iN != 0)
        {
            *cSrc = ch;
            cSrc++;
            iN--;
        }
    }
    else if (bFlag == TRUE)
    {
        char* cEnd = cSrc;
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
int WordCnt(const char* cStr)
{
    int iCnt = 0;
    if (NULL == cStr)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while (*cStr != '\0')
    {
        if (*cStr == ' ')
        {
            while ((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0'))
            {
                cStr++;
            }
        }
        else
        {
            while (*cStr != ' ' && *cStr != '\0')
            {
                cStr++;
            }
            iCnt++;
        }
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
void WordRev(char* cSrc)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    char cTemp = '\0';
    char* cStart = cSrc;
    char* cEnd = cSrc;

    while (*cSrc != '\0')
    {
        cEnd = cStart;
        while (*cEnd != ' ' && *cEnd != '\0')
        {
            cEnd++;
        }
        cSrc = cEnd;
        cEnd--;

        while (cStart < cEnd)
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
void MaxOccur(const char* cSrc)
{
    int iChars[_MAX_CHAR] = { 0 }, i = 0, iMax = 0;
    char ch = '\0';
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        iChars[*cSrc]++;
        cSrc++;
    }
    iMax = iChars[0];
    for (i = 0; i < _MAX_CHAR; i++)
    {
        if (i != 32)
        {
            if (iMax < iChars[i])
            {
                iMax = iChars[i];
                ch = i;
            }
        }
    }

    printf("Max occuring char \' %c \' with occurance %d", ch, iMax);
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :strchr
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of FALSE occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int StrChr(const char* cSrc, char ch)
{
    int iCnt = -1;
    while (*cSrc != '\0')
    {
        if (*cSrc == ch)
        {
            iCnt++;
            break;
        }
        iCnt++;
        cSrc++;
    }
    if (*cSrc == '\0')
        return -1;
    else
        return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrrChr
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of TRUE occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int StrrChr(const char* cSrc, char ch)
{
    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }
    int iCnt = 0;
    while (*cSrc != '\0')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while (iCnt != -1)
    {
        if (*cSrc == ch)
        {
            iCnt--;
            break;
        }
        iCnt--;
        cSrc--;
    }
    if (iCnt == -1)
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
BOOL IsPldrm(const char* cSrc)
{
    const char* cStart = NULL;
    const char* cEnd = NULL;

    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;

    while (*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while (cStart < cEnd)
    {
        if (*cStart != *cEnd)
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if (cStart >= cEnd)
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
//  Input       :const char*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////////
BOOL IsiPldrm(const char* cSrc)
{
    const char* cStart = NULL;
    const char* cEnd = NULL;

    if (cSrc == NULL)
    {
        printf("Invalid Input\n");
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;

    while (*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while (cStart < cEnd)
    {
        if ((*cStart != *cEnd) && (*cStart != *cEnd + 32) && (*cStart != *cEnd - 32))
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if (cStart >= cEnd)
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
//  Input       :const char *
//  Returns     :void
//  Description :count total number of alphabets,
//               digits and special characters in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void CharsCnt(const char* cSrc)
{
    int iA = 0, iSp = 0, iD = 0, iW = 0, iState = _OUT;
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        if (*cSrc == ' ')
        {
            iState = _OUT;
        }
        else if (iState == _OUT)
        {
            iState = _IN;
            iW++;
        }
        if (*cSrc >= 'A' && *cSrc <= 'Z' || *cSrc >= 'a' && *cSrc <= 'z')
        {
            iA++;
        }
        else if (*cSrc >= '0' && *cSrc <= '9')
        {
            iD++;
        }
        else
        {
            iSp++;
        }
        cSrc++;
    }
    printf("Alphabets\t:%d\n", iA);
    printf("Digits\t\t:%d\n", iD);
    printf("Special\t\t:%d\n", iSp);
    printf("Words\t\t:%d\n", iW);
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
int CountUpr(const char* cSrc)
{
    int iCnt = 0;
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }

    while (*cSrc != '\0')
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
int CountLwr(const char* cSrc)
{
    int iCnt = 0;
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }

    while (*cSrc != '\0')
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
BOOL IsAgrm(const char* cStr1, const char* cStr2)
{
    char cChars[_MAX_CHAR] = { 0 };
    int i = 0;
    if (cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return FALSE;
    }

    while (*cStr1 != '\0' && *cStr2 != '\0')
    {
        cChars[*cStr1]++;
        cChars[*cStr2]--;
        cStr1++;
        cStr2++;
    }
    if ((*cStr1 == '\0' && *cStr2 == '\0'))
    {
        for (i = 0; i < _MAX_CHAR; i++)
        {
            if (cChars[i] != 0)
            {
                break;
            }
        }
    }
    if (i == _MAX_CHAR)
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
//  Input       :const char *
//  Returns     :int
//  Description :count special characters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountSpecials(const char* cSrc)
{
    int iCnt = 0;
    if (NULL == cSrc)
    {
        printf("Invalid Input\n");
        return _ERROR;
    }

    while (*cSrc != '\0')
    {
        if (!(*cSrc >= 'a' && *cSrc <= 'z') &&
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
int CountSpace(const char* cSrc)
{
    int iCnt = 0;
    while (*cSrc != '\0')
    {
        if (*cSrc == 32)
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
int LargestWord(const char* cStr)
{
    int iMax = 0, i = 0, iCnt = 0;

    if (cStr == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }

    while (*cStr != '\0')
    {
        if (*cStr == ' ')
        {
            while ((*cStr == ' ' || *cStr == '\t') && *cStr != '\0')
            {
                cStr++;
            }
        }
        else
        {
            while (*cStr != ' ' && *cStr != '\0')
            {
                iCnt++;
                cStr++;
            }
        }
        if (iCnt > iMax)
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
void ManPage(const char* cCmd)
{
    if (StriCmp(cCmd, "strlen") == 0)
    {
        printf("Description     :Computes length of enterd string\n");
        printf("Usage           :strlen\n");
    }
    else if (StriCmp(cCmd, "help") == 0)
    {
        printf("Description     :Displays help menu\n");
        printf("Usage           :help\n");
    }
    else if (StriCmp(cCmd, "man") == 0)
    {
        printf("Description     :Displays how to use command\n");
        printf("Usage           :man Name_of_function\n");
    }
    else if (StriCmp(cCmd, "strlwr") == 0)
    {
        printf("Description     :converts entire string into lower case\n");
        printf("Usage           :strlwr\n");
    }
    else if (StriCmp(cCmd, "strupr") == 0)
    {
        printf("Description     :converts entire string into upper case\n");
        printf("Usage           :strupr\n");
    }
    else if (StriCmp(cCmd, "strnlwr") == 0)
    {
        printf("Description     :converts string into lower case\n");
        printf("                 if Flag = 0, then FALSE N characters are converted\n");
        printf("                 if Flag = 1, then TRUE N characters are converted\n");
        printf("Usage           :strnlwr\n");
    }
    else if (StriCmp(cCmd, "strnupr") == 0)
    {
        printf("Description     :converts string into upper case\n");
        printf("                 if Flag = 0, then FALSE N characters are converted\n");
        printf("                 if Flag = 1, then TRUE N characters are converted\n");
        printf("Usage           :strnupr\n");
    }
    else if (StriCmp(cCmd, "strtgl") == 0)
    {
        printf("Description     :toggles characters in string\n");
        printf("Usage           :strtgl\n");
    }
    else if (StriCmp(cCmd, "strntgl") == 0)
    {
        printf("Description     :toggles characters in string\n");
        printf("                 if Flag = 0, then FALSE N characters are toggled\n");
        printf("                 if Flag = 1, then TRUE N characters are toggled\n");
        printf("Usage           :strntgl\n");
    }
    else if (StriCmp(cCmd, "strtglrev") == 0)
    {
        printf("Description     :toggles characters in string in reverse\n");
        printf("Usage           :strtglrev\n");
    }
    else if (StriCmp(cCmd, "strcat") == 0)
    {
        printf("Description     :concatinates src string into destination\n");
        printf("Usage           :strcat\n");
    }
    else if (StriCmp(cCmd, "strcataltr") == 0)
    {
        printf("Description     :concatinates alternative chars from src string into destination\n");
        printf("Usage           :strcataltr\n");
    }
    else if (StriCmp(cCmd, "strcatrev") == 0)
    {
        printf("Description     :concatinates src string into destination in reverse\n");
        printf("Usage           :strcatrev\n");
    }
    else if (StriCmp(cCmd, "strncat") == 0)
    {
        printf("Description     :concatinates src string into destination\n");
        printf("                 if Flag = 0, then FALSE N characters are concatinated\n");
        printf("                 if Flag = 1, then TRUE N characters are concatinated\n");
        printf("Usage           :strncat\n");
    }
    else if (StriCmp(cCmd, "strcpy") == 0)
    {
        printf("Description     :copies src string into destination\n");
        printf("Usage           :strcpy\n");
    }
    else if (StriCmp(cCmd, "strFALSEcap") == 0)
    {
        printf("Description     :capitalize each words FALSE character\n");
        printf("Usage           :strFALSEcap\n");
    }
    else if (StriCmp(cCmd, "strncpy") == 0)
    {
        printf("Description     :copies src string into destination\n");
        printf("                 if Flag = 0, then FALSE N characters are copied\n");
        printf("                 if Flag = 1, then TRUE N characters are copied\n");
        printf("Usage           :strncpy\n");
    }
    else if (StriCmp(cCmd, "strcpycap") == 0)
    {
        printf("Description     :copies capitals chars from src string into destination\n");
        printf("Usage           :strcpycap\n");
    }
    else if (StriCmp(cCmd, "strcpycapx") == 0)
    {
        printf("Description     :copies capitals chars from src string into destination by toggling case\n");
        printf("Usage           :strcpycapx\n");
    }
    else if (StriCmp(cCmd, "strcpylwr") == 0)
    {
        printf("Description     :copies lower chars from src string into destination\n");
        printf("Usage           :strcpylwr\n");
    }
    else if (StriCmp(cCmd, "strcpylwrx") == 0)
    {
        printf("Description     :copies lower chars from src string into destination by toggling case\n");
        printf("Usage           :strcpylwrx\n");
    }
    else if (StriCmp(cCmd, "strtrimcpy") == 0)
    {
        printf("Description     :copies src string into destination without spaces\n");
        printf("Usage           :strtrimcpy\n");
    }
    else if (StriCmp(cCmd, "strtrimcpyx") == 0)
    {
        printf("Description     :copies src string into destination by removing extra spaces\n");
        printf("Usage           :strtrimcpyx\n");
    }
    else if (StriCmp(cCmd, "strcpytgl") == 0)
    {
        printf("Description     :copies src string into destination by toggling case\n");
        printf("Usage           :strcpytgl\n");
    }
    else if (StriCmp(cCmd, "strcpyrev") == 0)
    {
        printf("Description     :copies src string into destination in reverse\n");
        printf("Usage           :strcpyrev\n");
    }
    else if (StriCmp(cCmd, "strrev") == 0)
    {
        printf("Description     :reverses string\n");
        printf("Usage           :strrev\n");
    }
    else if (StriCmp(cCmd, "strnrev") == 0)
    {
        printf("Description     :reverses string\n");
        printf("                 if Flag = 0, then FALSE N characters are reversed\n");
        printf("                 if Flag = 1, then TRUE N characters are reversed\n");
        printf("Usage           :strnrev\n");
    }
    else if (StriCmp(cCmd, "strrangerev") == 0)
    {
        printf("Description     :reverses string in given range\n");
        printf("Usage           :strrangerev\n");
    }
    else if (StriCmp(cCmd, "strcmp") == 0)
    {
        printf("Description     :compares two strings\n");
        printf("Usage           :strcmp\n");
    }
    else if (StriCmp(cCmd, "stricmp") == 0)
    {
        printf("Description     :compares two strings witout considering case\n");
        printf("Usage           :stricmp\n");
    }
    else if (StriCmp(cCmd, "strncmp") == 0)
    {
        printf("Description     :compares two strings\n");
        printf("                 if Flag = 0, then FALSE N characters are compared\n");
        printf("                 if Flag = 1, then TRUE N characters are compared\n");
        printf("Usage           :strncmp\n");
    }
    else if (StriCmp(cCmd, "strincmp") == 0)
    {
        printf("Description     :compares two strings witout considering case\n");
        printf("                 if Flag = 0, then FALSE N characters are compared\n");
        printf("                 if Flag = 1, then TRUE N characters are compared\n");
        printf("Usage           :strincmp\n");
    }
    else if (StriCmp(cCmd, "strset") == 0)
    {
        printf("Description     :set characters in string with specified character\n");
        printf("Usage           :strset\n");
    }
    else if (StriCmp(cCmd, "strnset") == 0)
    {
        printf("Description     :set N characters in string with specified character\n");
        printf("                 if Flag = 0, then FALSE N characters are set\n");
        printf("                 if Flag = 1, then TRUE N characters are set\n");
        printf("Usage           :strnset\n");
    }
    else if (StriCmp(cCmd, "ispldrm") == 0)
    {
        printf("Description     :checks string is Palindrome or not\n");
        printf("Usage           :ispldrm\n");
    }
    else if (StriCmp(cCmd, "isipldrm") == 0)
    {
        printf("Description     :checks string is Palindrome or not witout considering case\n");
        printf("Usage           :isipldrm\n");
    }
    else if (StriCmp(cCmd, "isagrm") == 0)
    {
        printf("Description     :checks strings are Anagram or not\n");
        printf("Usage           :isagrm\n");
    }
    else if (StriCmp(cCmd, "wordcnt") == 0)
    {
        printf("Description     :counts words in string\n");
        printf("Usage           :wordcnt\n");
    }
    else if (StriCmp(cCmd, "wordrev") == 0)
    {
        printf("Description     :reverse each word in string\n");
        printf("Usage           :wordrev\n");
    }
    else if (StriCmp(cCmd, "maxoccur") == 0)
    {
        printf("Description     :counts maximum occuring character in string\n");
        printf("Usage           :maxoccur\n");
    }
    else if (StriCmp(cCmd, "strchr") == 0)
    {
        printf("Description     :find FALSE position of character in string\n");
        printf("Usage           :strchr\n");
    }
    else if (StriCmp(cCmd, "strrchr") == 0)
    {
        printf("Description     :find TRUE position of character in string\n");
        printf("Usage           :strrchr\n");
    }
    else if (StriCmp(cCmd, "charscnt") == 0)
    {
        printf("Description     :counts total alphabets, digits, special characters, words in string\n");
        printf("Usage           :charscnt\n");
    }
    else if (StriCmp(cCmd, "countlwr") == 0)
    {
        printf("Description     :counts lower characters in string\n");
        printf("Usage           :countlwr\n");
    }
    else if (StriCmp(cCmd, "countupr") == 0)
    {
        printf("Description     :counts upper characters in string\n");
        printf("Usage           :countupr\n");
    }
    else if (StriCmp(cCmd, "countspace") == 0)
    {
        printf("Description     :counts spaces characters in string\n");
        printf("Usage           :countspace\n");
    }
    else if (StriCmp(cCmd, "countspecial") == 0)
    {
        printf("Description     :counts special characters in string\n");
        printf("Usage           :countspecial\n");
    }
    else if (StriCmp(cCmd, "largestw") == 0)
    {
        printf("Description     :computes legth of largest word in string\n");
        printf("Usage           :largestw\n");
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
void Help()
{
    printf("help\n");
    printf("To Use        :type \'Name of function\'\n\n");
    printf("ManPage       :type \'man man\' - to see more\n");
    printf("StrLen        :type \'man strlen\' - to see more\n");
    printf("StrLwr        :type \'man strlwr\' - to see more\n");
    printf("StrNLwr       :type \'man strnlwr\' - to see more\n");
    printf("StrUpr        :type \'man strupr\' - to see more\n");
    printf("StrNUpr       :type \'man strnupr\' - to see more\n");
    printf("StrTgl        :type \'man strtgl\' - to see more\n");
    printf("StrNTgl       :type \'man strntgl\' - to see more\n");
    printf("StrTglRev     :type \'man strtglrev\' - to see more\n");
    printf("StrCat        :type \'man strcat\' - to see more\n");
    printf("StrNCat       :type \'man strncat\' - to see more\n");
    printf("StrCatAltr    :type \'man strcataltr\' - to see more\n");
    printf("StrCatRev     :type \'man strcatrev\' - to see more\n");
    printf("StrCpy        :type \'man strcpy\' - to see more\n");
    printf("StrCpyRev     :type \'man strcpyrev\' - to see more\n");
    printf("StrCpyTgl     :type \'man strcpytgl\' - to see more\n");
    printf("StrTrimCpy    :type \'man strtrimcpy\' - to see more\n");
    printf("StrTrimCpyX   :type \'man strtrimcpyx\' - to see more\n");
    printf("StrNCpy       :type \'man strncpy\' - to see more\n");
    printf("StrCpyCap     :type \'man strcpycap\' - to see more\n");
    printf("StrCpyCapX    :type \'man strcpycapx\' - to see more\n");
    printf("StrCpyLwr     :type \'man strcpylwr\' - to see more\n");
    printf("StrCpyLwrX    :type \'man strcpylwrx\' - to see more\n");
    printf("StrRev        :type \'man strrev\' - to see more\n");
    printf("StrNRev       :type \'man strnrev\' - to see more\n");
    printf("StrRangeRev   :type \'man strrangerev\' - to see more\n");
    printf("StrFALSECap   :type \'man strFALSEcap\' - to see more\n");
    printf("StrCmp        :type \'man strcmp\' - to see more\n");
    printf("StriCmp       :type \'man stricmp\' - to see more\n");
    printf("StrNCmp       :type \'man strncmp\' - to see more\n");
    printf("StriNCmp      :type \'man strincmp\' - to see more\n");
    printf("StrSet        :type \'man strset\' - to see more\n");
    printf("StrNSet       :type \'man strnset\' - to see more\n");
    printf("IsPldrm       :type \'man ispldrm\' - to see more\n");
    printf("IsiPldrm      :type \'man isipldrm\' - to see more\n");
    printf("IsAgrm        :type \'man isagrm\' - to see more\n");
    printf("WordCnt       :type \'man wordcnt\' - to see more\n");
    printf("WordRev       :type \'man wordrev\' - to see more\n");
    printf("MaxOccur      :type \'man maxoccur\' - to see more\n");
    printf("strchr        :type \'man strchr\' - to see more\n");
    printf("strrchr       :type \'man strrchr\' - to see more\n");
    printf("CharsCnt      :type \'man charscount\' - to see more\n");
    printf("CountLwr      :type \'man countlwr\' - to see more\n");
    printf("CountUpr      :type \'man countupr\' - to see more\n");
    printf("CountSpace    :type \'man countspace\' - to see more\n");
    printf("CountSpecials :type \'man countspecial\' - to see more\n");
    printf("LargestWord   :type \'man largestw\' - to see more\n");
}

////////////////////////////////////////// End Of File /////////////////////////////////////