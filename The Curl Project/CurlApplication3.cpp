// CurlApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define CURL_STATICLIB
#define BLOCKSIZE       4096
#define SUCCESS            1
#define FAILURE            0

#include <curl.h>
#include <json-glib/json-glib.h>
#include <glib-object.h>
#include <json-glib/json-parser.h>
#include <glib.h>
#include <gobject/gobject.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

typedef struct memory {
    PCHAR pcList;
    size_t uLsize;
}MEMORY, *PMEMORY;

MEMORY chunk;

void            UnreadMsgsParser(PCHAR, size_t);
void            UnreadMsgData(PCHAR*, guint);
static size_t   UnreadCallback(void* ptr, size_t size, size_t nmemb, void* stream);
static size_t   MsgCallback(void* ptr, size_t size, size_t nmemb, void* stream);
void            UnreadGet(PCHAR, PCHAR);
void            UnreadGetData(PCHAR, PCHAR);

// entry point
int main(void)
{
    cout << "Inside main\n";
    CHAR cURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages?q=is%3Aunread";
    CHAR cToken[] = "ya29.a0AfH6SMACXVlLHlkMGVB8gvJru7sm7WFYhCM_DiSrHooiO1xkR2Nhkij2oDAMCmdEuYg1YVyqQQmgQ2nKKyo4ikqY5r5BG60k67_dRMNZzL9GDzkNbNEzz2f5X2UoH72Q0Vo_0KeK5v-1pHeifZLFbc3cwdRE7xW_E68";
    UnreadGet(cURL, cToken);
    UnreadMsgsParser(chunk.pcList, chunk.uLsize);
    return 0;
}

void UnreadGet(PCHAR pcURL, PCHAR pcToken)
{
    cout << "Inside unreadget\n";
    CURL* curl_handle;

    chunk.pcList = NULL;
    chunk.uLsize = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, pcURL);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, pcToken);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, UnreadCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
}

/* Callback function for the data getting from response body */
static size_t UnreadCallback(void* data, size_t size, size_t nmemb, void* stream)
{
    cout << "Inside callback\n";
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

static size_t MsgCallback(void* ptr, size_t size, size_t nmemb, void* stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
    return written;
}

void UnreadMsgsParser(PCHAR lpzBuffer, size_t uSize)
{
    cout << "Inside InreadMsgsParser\n";
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    CHAR *lpzId[20];
    json_parser_load_from_data(parser, lpzBuffer, uSize, NULL);
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
                lpzId[i] = (PCHAR)json_object_get_string_member(jobj, "id");
                //cout << lpzId[i] << endl;
            }
        }
    }
    g_object_unref(parser);
    UnreadMsgData(lpzId, iArrLen);
}

void UnreadMsgData(PCHAR* lpzId, guint iArrLen)
{
    cout << "Inside unreadMsgsData\n";
    UINT i = 0;
    CHAR cURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages/";
    CHAR cToken[] = "ya29.a0AfH6SMACXVlLHlkMGVB8gvJru7sm7WFYhCM_DiSrHooiO1xkR2Nhkij2oDAMCmdEuYg1YVyqQQmgQ2nKKyo4ikqY5r5BG60k67_dRMNZzL9GDzkNbNEzz2f5X2UoH72Q0Vo_0KeK5v-1pHeifZLFbc3cwdRE7xW_E68";
    CHAR cTemp[100] = { '\0' };

    for (i = 0; i < 1; i++)
    {
        strcpy(cTemp, cURL);
        strcat(cTemp, lpzId[i]);

        UnreadGetData(cTemp, cToken);
    
        //cout << chunk.pcList << endl;
        //cout << chunk.uLsize << endl;
    }
}

void UnreadGetData(PCHAR pcURL, PCHAR pcToken)
{
    CURL* curl_handle;
   
    const CHAR *cFname = "UnreadData.json";
   
    FILE *fp = NULL;
    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, pcURL);

    /* no progress meter please */
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, pcToken);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, MsgCallback);

    /* open the body file */
    fp = fopen(cFname, "a");
    if (!fp)
    {
        curl_easy_cleanup(curl_handle);
        return;
    }

    /* we want the body be written to this file handle instead of stdout */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* close the body file */
    fclose(fp);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
}