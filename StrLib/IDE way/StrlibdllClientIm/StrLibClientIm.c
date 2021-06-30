
// Entry Point Function File
#include "Strlibdll.h"

int main()
{
    CHAR szInput[2][MAXLEN] = { '\0' };
    CHAR szString1[MAXLEN * 3] = { '\0' };
    CHAR szString2[MAXLEN * 3] = { '\0' };
    CHAR command[MAXLEN] = { '\0' };
    int iRet = 0, iN = 0, iCount = 0;
    CHAR iFlag = 0;
    BOOL bRet = FALSE, bRunning = TRUE, bFlag = FALSE;

    while (bRunning)
    {
        fflush(stdin);
        strcpy(command, "");
        strcpy(szString1, "");
        strcpy(szString2, "");

        printf("\n\nStrLib : > ");
        fgets(command, MAXLEN, stdin);
        iCount = sscanf(command, "%s %s", szInput[0], szInput[1]);
        if (iCount == 1)
        {
            if (StriCmp(szInput[0], "clear") == 0)
            {
                system("cls");
            }
            else if (StriCmp(szInput[0], "exit") == 0)
            {
                printf("Terminating StrLib ...\n");
                bRunning = FALSE;
            }
            else if (StriCmp(szInput[0], "help") == 0)
            {
                Help();
            }
            else if (StriCmp(szInput[0], "strlen") == 0)
            {
                printf("Enter string\t\t:");
                scanf("%[^\n]", szString1);
                getchar();
                iRet = StrLen(szString1);
                printf("Length of string\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "strlwr") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrLwr(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strupr") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrUpr(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strtgl") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrTgl(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strtglrev") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrTglRev(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strrev") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrRev(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strfirstcap") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrFirstCap(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "ispldrm") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                bRet = IsPldrm(szString1);
                if (bRet == TRUE)
                {
                    printf("Palidrome String");
                }
                else
                {
                    printf("Not Palindrome string");
                }
            }
            else if (StriCmp(szInput[0], "isipldrm") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                bRet = IsiPldrm(szString1);
                if (bRet == TRUE)
                {
                    printf("Palidrome String");
                }
                else
                {
                    printf("Not Palindrome string");
                }
            }
            else if (StriCmp(szInput[0], "wordcnt") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = WordCnt(szString1);
                printf("Word Count is\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "wordrev") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                WordRev(szString1);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "maxoccur") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                MaxOccur(szString1);
            }
            else if (StriCmp(szInput[0], "charscnt") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                CharsCnt(szString1);
            }
            else if (StriCmp(szInput[0], "countlwr") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = CountLwr(szString1);
                printf("Count of lower letters\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "countupr") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = CountUpr(szString1);
                printf("Count of upper letters\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "countspecial") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = CountSpecials(szString1);
                printf("Count of special letters\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "countspace") == 0)
            {
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = CountSpace(szString1);
                printf("Count of spaces\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "strcpy") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpy(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strcpycap") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpyCap(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strcpycapx") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpyCapX(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strcpylwr") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpyLwr(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strcpylwrx") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpyLwrX(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strcpytgl") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpyTgl(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strcpyrev") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrCpyRev(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strtrimcpy") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrTrimCpy(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strtrimcpyx") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                StrTrimCpyX(szString1, szString2);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "largestw") == 0)
            {
                printf("Enter string \t:");
                scanf(" %[^\n]", szString1);
                getchar();
                iRet = LargestWord(szString1);
                printf("Length of Largest word is\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "strcat") == 0)
            {
                printf("Enter string 1\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                StrCat(szString1, szString2);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strcataltr") == 0)
            {
                printf("Enter string 1\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                StrCatAltr(szString1, szString2);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strcatrev") == 0)
            {
                printf("Enter string 1\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                StrCatRev(szString1, szString2);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strcmp") == 0)
            {
                printf("Enter string 1\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                iRet = StrCmp(szString1, szString2);
                if (iRet == 0)
                {
                    printf("Equal Strings");
                }
                else
                {
                    printf("Unequal Strings");
                }
            }
            else if (StriCmp(szInput[0], "stricmp") == 0)
            {
                printf("Enter string 1\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                iRet = StriCmp(szString1, szString2);
                if (iRet == 0)
                {
                    printf("Equal Strings");
                }
                else
                {
                    printf("Unequal Strings");
                }
            }
            else if (StriCmp(szInput[0], "strset") == 0)
            {
                CHAR ch;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter char\t:");
                scanf(" %c", &ch);
                getchar();
                StrSet(szString1, ch);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strnset") == 0)
            {
                CHAR ch;
                
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter char\t:");
                scanf(" %c", &ch);
                getchar();
                printf("Enter pos(0 - First, 1 - Last)\t:");
                scanf("%c", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                StrNSet(szString1, ch, iN, bFlag);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "isagrm") == 0)
            {
                printf("Enter string 1\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                bRet = IsAgrm(szString1, szString2);
                if (bRet == TRUE)
                {
                    printf("Both Strings are Anagram");
                }
                else
                {
                    printf("Both Strings are Not Anagram");
                }
            }
            else if (StriCmp(szInput[0], "strchr") == 0)
            {
                CHAR ch;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter char\t\t:");
                scanf(" %c", &ch);
                getchar();
                StrChr(szString1, ch);
                printf("First Ocuurance at index\t:%d", iRet);
            }
            else if (StriCmp(szInput[0], "strrchr") == 0)
            {
                CHAR ch;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter char\t:");
                scanf(" %c", &ch);
                getchar();
                iRet = StrrChr(szString1, ch);
                printf("Last Ocuurance at index\t:%d", iRet);
            }

            else if (StriCmp(szInput[0], "strnlwr") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string\t\t:");
                scanf("%[^\n]", szString1);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter pos(0 - First, 1 - Last)\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                StrNLwr(szString1, iN, bFlag);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strnupr") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter pos(0 - First, 1 - Last)\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                StrNUpr(szString1, iN, bFlag);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strntgl") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter pos(0 - First, 1 - Last)\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                StrNTgl(szString1, iN, bFlag);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strnrev") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter no. of characters \t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter pos(0 - First, 1 - Last)\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                StrNRev(szString1, iN, bFlag);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strrangerev") == 0)
            {
                int iS = 0, iE = 0;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter start\t\t:");
                scanf("%d", &iS);
                getchar();
                printf("Enter end\t\t:");
                scanf("%d", &iE);
                getchar();
                StrRangeRev(szString1, iS, iE);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strncpy") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter end\t\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                StrNCpy(szString1, szString2, iN, bFlag);
                printf("Output\t\t\t:%s", szString2);
            }
            else if (StriCmp(szInput[0], "strncat") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter end\t\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                StrNCat(szString1, szString2, iN, bFlag);
                printf("Output\t\t\t:%s", szString1);
            }
            else if (StriCmp(szInput[0], "strncmp") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string 1\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                printf("Enter end\t\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                iRet = StrNCmp(szString1, szString2, iN, bFlag);
                if (iRet == 0)
                {
                    printf("Equal Strings");
                }
                else
                {
                    printf("Unequal Strngs");
                }
            }
            else if (StriCmp(szInput[0], "strincmp") == 0)
            {
                int iN = 0, iFlag = 0;
                printf("Enter string 1\t\t:");
                scanf(" %[^\n]", szString1);
                getchar();
                printf("Enter string 2\t\t:");
                scanf(" %[^\n]", szString2);
                getchar();
                printf("Enter no. of characters\t:");
                scanf("%d", &iN);
                getchar();
                printf("Enter end\t\t:");
                scanf("%d", &iFlag);
                if (iFlag == 1)
                    bFlag = TRUE;
                getchar();
                iRet = StriNCmp(szString1, szString2, iN, bFlag);
                if (iRet == 0)
                {
                    printf("Equal Strings");
                }
                else
                {
                    printf("Unequal Strngs");
                }
            }
            else
            {
                printf("Please enter valid command (or type \'help\')");
            }
        }
        else if (iCount == 2)
        {
            if (StriCmp(szInput[0], "man") == 0)
            {
                ManPage(szInput[1]);
            }
        }
        else
        {
            printf("Please enter valid command (or type \'help\')");
        }
    }
    return 0;
}
