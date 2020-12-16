
// Entry Point Function File

#include "StrLib.h"

int main()
{
    Strings sObj;
    CHAR szInput[2][MAXLEN] = {'\0'};
    CHAR szString1[MAXLEN * 2] = {'\0'};
    CHAR szString2[MAXLEN * 2] = {'\0'};
    CHAR command[MAXLEN * 2] = {'\0'};    
    int iRet = 0, iN = 0, iCount = 0;
    CHAR iFlag = 0;
    BOOL bRet = FALSE, bRunning = TRUE;

    while (bRunning)
    {
        fflush(stdin);
        strcpy_s(command, "");
        strcpy_s(szString1, "");
        strcpy_s(szString2, "");
        cout << "\n\nStrLib : > "; 

        fgets(command, 80, stdin);
        
        iCount = sscanf(command, "%s %s", szInput[0], szInput[1]);
        if (iCount == 1)
        {
            if (sObj.StriCmp(szInput[0], "clear") == 0)
            {
                system("cls");
            }
            else if (sObj.StriCmp(szInput[0], "exit") == 0)
            {
                cout << "Terminating StrLib...." << endl;
                bRunning = FALSE;
            }
            else if (sObj.StriCmp(szInput[0], "help") == 0)
            {
                sObj.Help();
            }
            else if (sObj.StriCmp(szInput[0], "strlen") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.StrLen(szString1);
                cout << "Length of string\t\t:" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "strlwr") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrLwr(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strupr") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrUpr(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strtgl") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrTgl(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strtglrev") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrTglRev(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strrev") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrRev(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strfirstcap") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrFirstCap(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "ispldrm") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                bRet = sObj.IsPldrm(szString1);
                if (bRet == TRUE)
                {
                    cout << "Palidrome String";
                }
                else
                {
                    cout << "Not Palindrome string";
                }
            }
            else if (sObj.StriCmp(szInput[0], "isipldrm") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                bRet = sObj.IsiPldrm(szString1);
                if (bRet == TRUE)
                {
                    cout << "Palidrome String";
                }
                else
                {
                    cout << "Not Palindrome string";
                }
            }
            else if (sObj.StriCmp(szInput[0], "wordcnt") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.WordCnt(szString1);
                cout << "Word Count is:\t" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "wordrev") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.WordRev(szString1);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "maxoccur") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.MaxOccur(szString1);
            }
            else if (sObj.StriCmp(szInput[0], "CHARscnt") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.CharsCnt(szString1);
            }
            else if (sObj.StriCmp(szInput[0], "countlwr") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.CountLwr(szString1);
                cout << "Count of lower letters\t:" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "countupr") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.CountUpr(szString1);
                cout << "Count of upper letters\t:" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "countspecial") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.CountSpecials(szString1);
                cout << "Count of special letters\t:" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "countspace") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.CountSpace(szString1);
                cout << "Count of spaces\t:" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "strcpy") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpy(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strcpycap") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpyCap(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strcpycapx") == 0)
            {
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpyCapX(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strcpylwr") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpyLwr(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strcpylwrx") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpyLwrX(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strcpytgl") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpyTgl(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strcpyrev") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrCpyRev(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strtrimcpy") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrTrimCpy(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strtrimcpyx") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                sObj.StrTrimCpyX(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "largestw") == 0)
            {
               cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = sObj.LargestWord(szString1);
                cout << "Length of Largest word is:\t" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "strcat") == 0)
            {
                cout << "Enter string 1\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                sObj.StrCat(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strcataltr") == 0)
            {
                cout << "Enter string 1\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t:";
                getchar();
                scanf(" %[^\n]", szString2);
                sObj.StrCatAltr(szString1, szString2);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strcatrev") == 0)
            {
            cout << "Enter string 1\t:";
            scanf(" %[^\n]", szString1);
            getchar();
            cout << "Enter string 2\t:";
            getchar();
            scanf(" %[^\n]", szString2);
            sObj.StrCatRev(szString1, szString2);
            cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strcmp") == 0)
            {
                cout << "Enter string 1\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                iRet = sObj.StrCmp(szString1, szString2);
                if (iRet == 0)
                {
                    cout << "Equal Strings";
                }
                else
                {
                    cout << "Unequal Strings";
                }
            }
            else if (sObj.StriCmp(szInput[0], "stricmp") == 0)
            {
                cout << "Enter string 1\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                iRet = sObj.StriCmp(szString1, szString2);
                if (iRet == 0)
                {
                    cout << "Equal Strings";
                }
                else
                {
                    cout << "Unequal Strings";
                }
            }
            else if (sObj.StriCmp(szInput[0], "strset") == 0)
            {
                CHAR ch;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter CHAR\t:";
                scanf(" %c", &ch);
                getchar();
                sObj.StrSet(szString1, ch);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strnset") == 0)
            {
                CHAR ch;
                int iN;
                
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter CHAR\t:";
                scanf(" %c", &ch);
                getchar();
                cout << "Enter no. of CHARacters\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter pos(0 - First, 1 - Last)\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNSet(szString1, ch, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "isagrm") == 0)
            {
                cout << "Enter string 1\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                bRet = sObj.IsAgrm(szString1, szString2);
                if (bRet == TRUE)
                {
                    cout << "Both Strings are Anagram";
                }
                else
                {
                    cout << "Both Strings are Not Anagram";
                }
            }
            else if (sObj.StriCmp(szInput[0], "strchr") == 0)
            {
                CHAR ch;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter CHAR\t:";
                scanf(" %c", &ch);
                getchar();
                sObj.StrChr(szString1, ch);
                cout << "First Ocuurance at index\t:" << iRet;
            }
            else if (sObj.StriCmp(szInput[0], "strrchr") == 0)
            {
                CHAR ch;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter CHAR\t:";
                scanf(" %c", &ch);
                getchar();
                iRet = sObj.StrrChr(szString1, ch);
                cout << "Last Ocuurance at index\t:" << iRet;
            }

            else if (sObj.StriCmp(szInput[0], "strnlwr") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string\t\t\t:";
                scanf("%[^\n]", szString1);
                getchar();
                cout << "Enter no. of CHARacters\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter pos(0 - First, 1 - Last)\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNLwr(szString1, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strnupr") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter no. of CHARacters\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter pos(0 - First, 1 - Last)\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNUpr(szString1, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strntgl") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter no. of CHARacters\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter pos(0 - First, 1 - Last)\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNTgl(szString1, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strnrev") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter no. of CHARacters \t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter pos(0 - First, 1 - Last)\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNRev(szString1, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strrangerev") == 0)
            {
                int iS = 0, iE = 0, iFlag = 0;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter start\t:";
                scanf("%d", &iS);
                getchar();
                cout << "Enter end\t:";
                scanf("%d", &iE);
                getchar();
                sObj.StrRangeRev(szString1, iS, iE);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strncpy") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter no. of CHARacters\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter end\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNCpy(szString1, szString2, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString2;
            }
            else if (sObj.StriCmp(szInput[0], "strncat") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string 1\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t\t\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                cout << "Enter no. of CHARacters\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter end\t:";
                scanf("%d", &iFlag);
                getchar();
                sObj.StrNCat(szString1, szString2, iN, iFlag);
                cout << "Output\t\t\t\t:" << szString1;
            }
            else if (sObj.StriCmp(szInput[0], "strncmp") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string 1\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t\t\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                cout << "Enter no. of CHARacters\t\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter end\t\t\t:";
                scanf("%d", &iFlag);
                getchar();
                iRet = sObj.StrNCmp(szString1, szString2, iN, iFlag);
                if (iRet == 0)
                {
                    cout << "Equal Strings";
                }
                else
                {
                    cout << "Unequal Strngs";
                }
            }
            else if (sObj.StriCmp(szInput[0], "strincmp") == 0)
            {
                int iN = 0, iFlag = 0;
                cout << "Enter string 1\t\t\t:";
                scanf(" %[^\n]", szString1);
                getchar();
                cout << "Enter string 2\t\t\t:";
                scanf(" %[^\n]", szString2);
                getchar();
                cout << "Enter no. of characters\t\t:";
                scanf("%d", &iN);
                getchar();
                cout << "Enter end\t\t\t:";
                scanf("%d", &iFlag);
                getchar();
                iRet = sObj.StriNCmp(szString1, szString2, iN, iFlag);
                if (iRet == 0)
                {
                    cout << "Equal Strings";
                }
                else
                {
                    cout << "Unequal Strngs";
                }
            }
            else
            {
                cout << "Please enter valid command (or type \'help\')";
            }
        }
        else if(iCount == 2)
        {
            if (sObj.StriCmp(szInput[0], "man") == 0)
            {
                sObj.ManPage(szInput[1]);
            }
        }
        else
        {
            cout << "Please enter valid command (or type \'help\')";
        }
    }
    return 0;
}

/////////////////////////////// End of StrLibMain.cpp ///////////////////////////////////////////