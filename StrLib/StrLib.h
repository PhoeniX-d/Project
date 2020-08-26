
#include<iostream>
#include<stdio.h>

#define MAXLEN          20
#define ERROR         -999
#define IN               1
#define OUT              0
#define MAX_CHAR       127
#define FIRST            0
#define LAST             1

using namespace std;

// Strings class
class Strings
{
    public:
        int  StrLen(const char*);
        void StrLwr(char*);
        void StrNLwr(char*, int, char);
        void StrUpr(char*);
        void StrNUpr(char*, int, char);
        void StrTgl(char*);
        void StrNTgl(char*, int, char);
        void StrCat(char*, const char*);
        void StrNCat(char*, const char*, int, char);
        void StrCpy(const char*, char*);
        void StrNCpy(const char*, char*, int, char);
        void StrCpyCap(const char*, char*);
        void StrCpyCapX(const char*, char*);
        void StrCpyLwr(const char*, char*);
        void StrCpyLwrX(const char*, char*);
        void StrCpySpace(const char*, char*);
        void StrCpyRev(const char*, char*);
        void StrCpyTgl(const char*, char*);
        void StrRev(char*);
        void StrNRev(char*, int, char);
        void StrRangeRev(char*, int, int);
        int  StrCmp(const char*, const char*);
        int  StriCmp(const char*, const char*);
        int  StrNCmp(const char*, const char*, int, char);
        int  StriNCmp(const char*, const char*, int, char);
        void StrSet(char*, char);
        void StrNSet(char*, char, int, char);
        bool IsPldrm(const char *);
        bool IsiPldrm(const char *);
        bool IsAgrm(const char *, const char *);
        int  WordCnt(const char*);
        void WordRev(char*);
        void MaxOccur(const char*);
        int  FirstOccur(const char *, char);
        int  LastOccur(const char *, char);
        void CharsCnt(const char *);
        int  CountLwr(const char *);
        int  CountUpr(const char *);
        int  CountSpace(const char *);
        int  CountSpecials(const char *);
};
