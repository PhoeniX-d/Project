// Header File

#include<Windows.h>
#include<iostream>
#include<stdio.h>

#define MAXLEN          40
#define ERROR           -1
#define IN               1
#define OUT              0
#define MAX_CHAR       127
#define FIRST            0
#define LAST             1
#define TRUE             1
#define FALSE            0

using namespace std;

// Strings class
class Strings
{
    public:
        void ManPage(const char*);
        void Help();
        int  StrLen(const char*);
        void StrLwr(char*);
        void StrNLwr(char*, int, char);
        void StrUpr(char*);
        void StrNUpr(char*, int, char);
        void StrTgl(char*);
        void StrNTgl(char*, int, char);
        void StrTglRev(char*);
        void StrCat(char*, const char*);
        void StrCatAltr(const char*, char*);
        void StrCatRev(char*, const char*);
        void StrNCat(char*, const char*, int, char);
        void StrCpy(const char*, char*);
        void StrNCpy(const char*, char*, int, char);
        void StrCpyCap(const char*, char*);
        void StrCpyCapX(const char*, char*);
        void StrCpyLwr(const char*, char*);
        void StrCpyLwrX(const char*, char*);
        void StrTrimCpy(const char*, char*);
        void StrTrimCpyX(const char*, char*);
        void StrCpyRev(const char*, char*);
        void StrCpyTgl(const char*, char*);
        void StrRev(char*);
        void StrFirstCap(char*);
        void StrNRev(char*, int, char);
        void StrRangeRev(char*, int, int);
        int  StrCmp(const char*, const char*);
        int  StriCmp(const char*, const char*);
        int  StrNCmp(const char*, const char*, int, char);
        int  StriNCmp(const char*, const char*, int, char);
        void StrSet(char*, char);
        void StrNSet(char*, char, int, char);
        BOOL IsPldrm(const char *);
        BOOL IsiPldrm(const char *);
        BOOL IsAgrm(const char *, const char *);
        int  WordCnt(const char*);
        void WordRev(char*);
        void MaxOccur(const char*);
        int  StrChr(const char *, char);
        int  StrrChr(const char *, char);
        void CharsCnt(const char *);
        int  CountLwr(const char *);
        int  CountUpr(const char *);
        int  CountSpace(const char *);
        int  CountSpecials(const char *);
        int  LargestWord(const char *);
};

/////////////////////////////// End of StrLib.h ///////////////////////////////////////////