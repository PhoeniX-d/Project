// Macros
#define CURL_STATICLIB
#define BLOCKSIZE       4096
#define STRINGSIZE        32
#define URLSIZE          256
#define TOKENSIZE        256
#define BUFFER           256
#define SUCCESS         TRUE
#define FAILURE        FALSE

// Headers
#include <curl.h>
#include <json-glib/json-glib.h>
#include <glib-object.h>
#include <json-glib/json-parser.h>
#include <glib.h>
#include <gobject/gobject.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

using namespace std;

CHAR szAccessToken[BUFFER] = { '\0' };

/* structure for contents of URL*/
typedef struct _memory
{
    PCHAR   pcList;
    size_t  uLsize;
}MEMORY, * PMEMORY;

/* class MailMonitor */
class MailMonitor
{
private:
    MEMORY  chunk;
public:
    /* Get Access Token */
    BOOL GetAccessToken();

    /* Unread Msgs List Parser Function */
    BOOL UnreadListParser(PCHAR, size_t);

    /* Unread Msgs Content Parser Function */
    BOOL UnreadContentParser(PCHAR, size_t);

    /* Callback function for getting unread msg list to parse */
    static size_t ListCallback(void* ptr, size_t size, size_t nmemb, void* stream);

    /* callback function for getting encoded unread msgs contents */
    static size_t ContentCallback(void* ptr, size_t size, size_t nmemb, void* stream);

    /* curl APIs for getting unread msgs list */
    BOOL UnreadGetList(PMEMORY, PCHAR);

    /* curl APIs for getting unread msgs contents*/
    BOOL UnreadGetContent(const PCHAR, const PCHAR, int);

    /* Performs base64 decoding for type: text/plain */
    CHAR* Base64Decode(PCHAR);
};

////////////////////////////////////////////////////////////////////
//
//  Name            :GetAccessToken
//  Input           :PCHAR
//  Returns         :void
//  Description     :This function will get Access Token through IPC
//  Author          :Pranav Choudhary  
//  Last Modified   :26 Sept 2020
//
////////////////////////////////////////////////////////////////////
BOOL MailMonitor::GetAccessToken()
{
    //cout << "Inside GetAccessToken()" << endl;
    HANDLE          hFile;
    SYSTEMTIME      stCurr;
    CHAR            szFileTime[20] = { '\0' };
    CHAR            szTemp[20] = { '\0' };
    CHAR            szPipedata[BUFFER] = { '\0' };
    DWORD           dwWritten = 0;
    DWORD           dwRead = 0;
    DWORD           dwBytesToReadPD = sizeof(szPipedata);
    DWORD           dwBytesToReadAT = sizeof(szAccessToken);
    LPCSTR          pipeName = "\\\\.\\pipe\\MyWindowsNamedPipe";
    int             iDurationCurr = 0, iDurationFile = 0;
    int             iTime[6] = { 0 }, i = 0;
    CHAR* szToken;

    GetLocalTime(&stCurr);
    hFile = CreateFile(TEXT("temp.tmp"), (GENERIC_READ | GENERIC_WRITE), FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        cout << "Unable to create / open such file\n";
    }
    if (ReadFile(hFile, szFileTime, sizeof(szFileTime) - 1, &dwRead, NULL) == FALSE)
    {
        cout << "Unable to Read time" << endl;
    }
    if (ReadFile(hFile, szAccessToken, sizeof(szAccessToken), &dwRead, NULL) == FALSE)
    {
        cout << "Unable to Read accesstoken" << endl;
    }
    CloseHandle(hFile);
    GetLocalTime(&stCurr);
    iDurationCurr = stCurr.wHour * 3600 + stCurr.wMinute * 60 + stCurr.wSecond;

    if (strlen(szFileTime) != 0 || strlen(szAccessToken) != 0)
    {
        /* get the first token */
        szToken = strtok(szFileTime, ":");

        /* walk through other tokens */
        while (szToken != NULL)
        {
            iTime[i] = atoi(szToken);
            szToken = strtok(NULL, ":");
            i++;
        }
        iDurationFile = iTime[3] * 3600 + iTime[4] * 60 + iTime[5];
    }
    if (((iDurationCurr - iDurationFile) >= 3500 && (iTime[0] == stCurr.wDay)) ||
        ((iTime[0] < stCurr.wDay) || (iTime[1] < stCurr.wMonth)))
    {
        STARTUPINFO             si;
        PROCESS_INFORMATION     pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        //Create Named Pipe with given name.
        HANDLE hPipe = CreateNamedPipeA(
            pipeName,
            PIPE_ACCESS_DUPLEX,
            (PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT),
            PIPE_UNLIMITED_INSTANCES,
            BUFFER,
            BUFFER,
            0,
            NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            printf("Pipe Creation Failed\n\n");
            return -1;
        }
        if (CreateProcess
        (
            L"Tokens2.exe",
            NULL,           // no Command line args
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi)            // Pointer to PROCESS_INFORMATION structure
            == FALSE)
        {
            printf("CreateProcess failed (%d).\n", GetLastError());
            return -1;
        }
        // Wait until child process exits.
        WaitForSingleObject(pi.hProcess, INFINITE);
        // Close process  handles. 
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        if (ConnectNamedPipe(hPipe, NULL) == FALSE)
        {
            printf("Wait for client connection failed. Error Code %08X.\n", GetLastError());
        }
        // Get Access token
        if (ReadFile(hPipe, szPipedata, dwBytesToReadPD, &dwRead, NULL) == FALSE)
        {
            cout << "Unable to read data from Pipe" << endl;
        }
        FlushFileBuffers(hPipe);
        DisconnectNamedPipe(hPipe);
        CloseHandle(hPipe);
        GetLocalTime(&stCurr);
        //iDurationCurr = stCurr.wHour * 3600 + stCurr.wMinute * 60 + stCurr.wSecond;
        sprintf_s(szTemp, "%2d:%2d:%4d:%2d:%2d:%2d", stCurr.wDay, stCurr.wMonth, stCurr.wYear, stCurr.wHour, stCurr.wMinute, stCurr.wSecond);
        hFile = CreateFile(TEXT("temp.tmp"), (GENERIC_READ | GENERIC_WRITE), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            cout << "Unable to create / open such file\n";
        }
        WriteFile(hFile, szTemp, (DWORD)strlen(szTemp), &dwWritten, NULL);
        WriteFile(hFile, szPipedata, (DWORD)strlen(szPipedata), &dwWritten, NULL);
        CloseHandle(hFile);
        strcpy_s(szAccessToken, szPipedata);
    }
    SetFileAttributesA("temp.tmp", FILE_ATTRIBUTE_HIDDEN);
    cout << szAccessToken << endl;
    return SUCCESS;
    //cout << "End of GetAccessToken()" << endl;
}

/////////////////////////////////////////////////////////////////
//
//  Name            :UnreadGetList
//  Input           :PCHAR
//  Returns         :void
//  Description     :This function will get list of IDs of Unread
//                   new msgs from mailbox
//  Author          :Pranav Choudhary  
//  Last Modified   :2 Sept 2020
//
/////////////////////////////////////////////////////////////////
BOOL MailMonitor::UnreadGetList(PMEMORY pmChunk, PCHAR pcURL)
{
    //cout << "Inside UnreadGetList()" << endl;
    if (pmChunk == NULL && pcURL == NULL)
    {
        cout << "Invalid Inputs for UnreadGetList()\n";
        return FAILURE;
    }
    CURL* curl_handle;

    pmChunk->pcList = NULL;
    pmChunk->uLsize = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();
    
    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, pcURL);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    
    /* Authenrication performed here */
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, szAccessToken);
    
    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, ListCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)pmChunk);
    
    /* get it! */
    curl_easy_perform(curl_handle);
    
    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
    //cout << "End of UnreadGetList()" << endl;
    return SUCCESS;
}

/////////////////////////////////////////////////////////////////
//
//  Name            :ListCallback
//  Input           :void*, size_t, size_t, void*
//  Returns         :size_t
//  Description     :This function used by UnreadGetList() as its
//                   callback for parsing purpose
//  Author          :Pranav Choudhary  
//  Last Modified   :2 Sept 2020
//
/////////////////////////////////////////////////////////////////
size_t MailMonitor::ListCallback(void* data, size_t size, size_t nmemb, void* stream)
{
    size_t realuLsize = size * nmemb;
    PMEMORY mem = (PMEMORY)stream;

    PCHAR ptr = (PCHAR)realloc(mem->pcList, mem->uLsize + realuLsize + 1);
    if (ptr == NULL)
    {
        printf("Out of Memory!\n");
        return 0;
    }

    mem->pcList = ptr;
    memcpy((void*)&(mem->pcList[mem->uLsize]), data, realuLsize);
    mem->uLsize = mem->uLsize + realuLsize;
    mem->pcList[mem->uLsize] = 0;
    return realuLsize;
}

/////////////////////////////////////////////////////////////////
//
//  Name            :ContentCallback
//  Input           :void*, size_t, size_t, void*
//  Returns         :size_t
//  Description     :This function used by UnreadGetContent() as its
//                   callback for dumping contents
//  Author          :Pranav Choudhary  
//  Last Modified   :2 Sept 2020
//
/////////////////////////////////////////////////////////////////
size_t MailMonitor::ContentCallback(void* ptr, size_t size, size_t nmemb, void* stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
    return written;
}

//////////////////////////////////////////////////////////////////////
//
//  Name            :UnreadListParser
//  Input           :PCHAR, size_t
//  Returns         :void
//  Description     :This function will parse list of unread msgs IDs
//  Author          :Pranav Choudhary  
//  Last Modified   :5 Sept 2020
//
//////////////////////////////////////////////////////////////////////
BOOL MailMonitor::UnreadListParser(PCHAR szBuffer, size_t uSize)
{
    //cout << "Inside UnreadListParser " << endl;
    if (szBuffer == NULL)
    {
        cout << "Invalid Inputs for UnreadListParser()\n";
        return FAILURE;
    }
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    CHAR* szId = new CHAR[STRINGSIZE];
    CHAR cURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages/";
    CHAR cTemp[URLSIZE] = { '\0' };

    json_parser_load_from_data(parser, szBuffer, uSize, NULL);
    root = json_parser_get_root(parser);
    if (JSON_NODE_HOLDS_OBJECT(root))
    {
        JsonObject* object;
        object = json_node_get_object(root);

        if (json_object_has_member(object, "messages"))
        {
            JsonArray* array = json_object_get_array_member(object, "messages");
            iArrLen = json_array_get_length(array);
            JsonObject* jobj;

            for (i = 0; i < iArrLen; i++)
            {
                jobj = json_array_get_object_element(array, i);
                szId = (PCHAR)json_object_get_string_member(jobj, "id");

                /* makeing URL that will fetch contents from messages */
                strcpy(cTemp, cURL);
                strcat(cTemp, szId);

                /* after getting URL call curl APIs to get data */
                UnreadGetList(&chunk, cTemp);
                //UnreadGetContent(cTemp, szId, i);
                /* after data fetched parse that data */
                UnreadContentParser(chunk.pcList, chunk.uLsize);

                _strset(cTemp, '\0');
                _strset(szId, '\0');
                memset((void*)chunk.pcList, 0, chunk.uLsize);
                 /* loop until all unread msgs in mail box are finished */
            }
        }
    }
    g_object_unref(parser);
    //cout << "end of UnreadListParser " << endl;
    return SUCCESS;    
}

//////////////////////////////////////////////////////////////////////
//
//  Name            :UnreadContentParser
//  Input           :PCHAR, size_t
//  Returns         :void
//  Description     :This function will parse list of unread msgs IDs
//  Author          :Pranav Choudhary  
//  Last Modified   :2 Sept 2020
//
//////////////////////////////////////////////////////////////////////
BOOL MailMonitor::UnreadContentParser(PCHAR szBuffer, size_t uSize)
{
    //cout << "Inside UnreadContentParser " << endl;
    if (szBuffer == NULL)
    {
        cout << "Invalid Inputs for UnreadListParser()\n";
        return FAILURE;
    }
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    CHAR* szTemp1 = new CHAR[STRINGSIZE];
    CHAR* szTemp2 = new CHAR[BLOCKSIZE];

    json_parser_load_from_data(parser, szBuffer, uSize, NULL);
    root = json_parser_get_root(parser);
    if (JSON_NODE_HOLDS_OBJECT(root))
    {
        JsonObject* object;
        object = json_node_get_object(root);
        if (json_object_has_member(object, "payload"))
        {
            JsonObject* object1;
            object1 = json_object_get_object_member(object, "payload");

            if (json_object_has_member(object1, "headers"))
            {
                JsonArray* array = json_object_get_array_member(object1, "headers");
                iArrLen = json_array_get_length(array);
                JsonObject* jobj;
                for (i = 0; i < iArrLen; i++)
                {
                    jobj = json_array_get_object_element(array, i);
                    szTemp1 = (PCHAR)json_object_get_string_member(jobj, "name");
                    if (strcmp(szTemp1, "Subject") == 0)
                    {
                        szTemp2 = (PCHAR)json_object_get_string_member(jobj, "value");
                        cout << "Subject\t\t:" << szTemp2 << endl;
                    }
                    if (strcmp(szTemp1, "From") == 0)
                    {
                        szTemp2 = (PCHAR)json_object_get_string_member(jobj, "value");
                        cout << "From\t\t:" << szTemp2 << endl;
                    }
                }
            }
            if (json_object_has_member(object1, "parts"))
            {
                JsonArray* array = json_object_get_array_member(object1, "parts");
                iArrLen = json_array_get_length(array);
                JsonObject* jobj, * jobj2;
                for (i = 0; i < iArrLen; i++)
                {
                    jobj = json_array_get_object_element(array, i);
                    szTemp1 = (PCHAR)json_object_get_string_member(jobj, "mimeType");
                    if (strcmp(szTemp1, "text/plain") == 0)
                    {
                        if (json_object_has_member(jobj, "body"))
                        {
                            jobj2 = json_object_get_object_member(jobj, "body");
                            if (json_object_has_member(jobj2, "data"))
                            {
                                szTemp2 = (PCHAR)json_object_get_string_member(jobj2, "data");
                                szTemp2 = Base64Decode(szTemp2);
                                cout << "Content\t\t:\n" << szTemp2 << endl;
                                cout << "---------------------------------------------------------------------------------------------------" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    g_object_unref(parser);
    //cout << "End of UnreadContentParser()" << endl;
    return SUCCESS;
}

/////////////////////////////////////////////////////////////////
//
//  Name            :UnreadGetContent
//  Input           :const PCHAR, const PCHAR, int
//  Returns         :void
//  Description     :This function will get encoded contents of
//                   unread mails
//  Author          :Pranav Choudhary  
//  Last Modified   :2 Sept 2020
//
/////////////////////////////////////////////////////////////////
BOOL MailMonitor::UnreadGetContent(const PCHAR pcURL, const PCHAR szId, int iCnt)
{
    //cout << "start of UnreadGetContent()" << endl;
    if (pcURL == NULL || szId == NULL)
    {
        cout << "Invalid Inputs for UnreadGetContent()\n";
        return FAILURE;
    }
    CURL* curl_handle;
    CHAR cFileName[90] = { '\0' };
    sprintf_s(cFileName, "C://Users//Pranav//Desktop//Temp//UnreadFile_%s_%2d.json", szId, iCnt);
    cout << "Dumping Data in " << cFileName << "...\n";
    FILE* fp = NULL;

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, pcURL);

    /* no progress meter please */
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, szAccessToken);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, ContentCallback);

    /* open the body file */
    fp = fopen(cFileName, "wb");
    if (!fp)
    {
        cout << "Unable To open File\n";
        curl_easy_cleanup(curl_handle);
        return FAILURE;
    }
    /* we want the body be written to this file handle instead of stdout */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* close the body file */
    fclose(fp);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
    //cout << "end of UnreadGetContent()" << endl;
    return SUCCESS;
}

/////////////////////////////////////////////////////////////////
//
//  Name            :Base64Decode
//  Input           :PCHAR
//  Returns         :void
//  Description     :This function decodes bas64 encoded data to
//                   '\0' terminated string
//  Author          :Pranav Choudhary  
//  Last Modified   :5 Sept 2020
//
/////////////////////////////////////////////////////////////////
CHAR* MailMonitor::Base64Decode(PCHAR szCipher)
{
    //cout << "start of Base64Decode()" << endl;
    if (szCipher == NULL)
    {
        cout << "Invalid Inputs for UnreadListParser()\n";
        return szCipher;
    }
    CHAR base_map[] = {
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                            'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                            'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                            'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
    };

    int iCount = 0;
    CHAR cBuffer[4];
    PCHAR szPlain = new CHAR[(strlen(szCipher) * 3 / 4)];
    if (szPlain == NULL)
    {
        cout << "Memory Allocation Failed\n";
        return szPlain;
    }
    int i = 0, iPlain = 0, k = 0;

    for (i = 0; szCipher[i] != '\0'; i++)
    {
        for (k = 0; k < 64 && (base_map[k] != szCipher[i]); k++)
            ;

        cBuffer[iCount++] = k;

        if (iCount == 4)
        {
            szPlain[iPlain++] = (cBuffer[0] << 2) + (cBuffer[1] >> 4);

            if (cBuffer[2] != 64)
            {
                szPlain[iPlain++] = (cBuffer[1] << 4) + (cBuffer[2] >> 2);
            }
            if (cBuffer[3] != 64)
            {
                szPlain[iPlain++] = (cBuffer[2] << 6) + cBuffer[3];
            }
            iCount = 0;
        }
    }
    *(szPlain + iPlain) = '\0';
    //cout << "End of Base64Parser()" << endl;
    return szPlain;
}

// Entry point
int main(void)
{
    MailMonitor mmObj;
    MEMORY pmChunk;

    mmObj.GetAccessToken();
    CHAR cUnreadURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages?q=is%3Aunread";
    mmObj.UnreadGetList(&pmChunk, cUnreadURL);
    //cout << pmChunk.pcList << endl;
    mmObj.UnreadListParser(pmChunk.pcList, pmChunk.uLsize);
    return 0;
}
