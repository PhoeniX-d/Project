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

// global declarations
typedef struct _memory
{
    LPSTR 	lpszResponse;
   	size_t  uSize;
}MEMORY, * PMEMORY;


void            UnreadMsgsParser(LPCSTR lpzBuffer, size_t uSize);
static size_t   UnreadCallback(void* ptr, size_t size, size_t nmemb, void* stream);
static size_t   MsgCallback(void* data, size_t size, size_t nmemb, void* userp);
void            UnreadGetData(LPCSTR lpczURL, LPCSTR lpczToken);
void            UnreadMsgData(LPSTR*, guint);
void            strcatX(PCHAR, LPSTR);


// entry point
int main(void)
{
    LPCSTR lpczURL = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages?q=is%3Aunread";
    LPCSTR lpczToken = "ya29.a0AfH6SMD-TB55Pjoq3qMtKQifnF8PDIfQFZeqdTfNfAnLb5-ujEusVJTSr9AocaeUIJXu8cpf1kSGdGIHi6kMg-u3RgPuHnNYaFfcHeo9PxFGH-0Wa8I-1shRheIEG2yPKTOTcxQwABMNnNHyFlBSfrIgA3aN9RAWF64";
    UnreadGetData(lpczURL, lpczToken);
    return 0;
}

void strcatX(PCHAR pcSrc, LPSTR lpszDest)
{
    if ((pcSrc == NULL) || (lpszDest == NULL))
    {
        return;
    }
    while (*pcSrc != '\0')
    {
        pcSrc++;
    }
    while (*lpszDest != '\0')
    {
        *pcSrc = *lpszDest;
        pcSrc++;
        lpszDest++;
    }
    *pcSrc = '\0';
}

static size_t MsgCallback(void* data, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    PMEMORY pmMem = (PMEMORY)userp;

    char* ptr = (char*)realloc(pmMem->lpszResponse, pmMem->uSize + realsize + 1);
    if (ptr == NULL)
    {
        printf("Out of Memory!\n");
        return 0;
    }

    pmMem->lpszResponse = ptr;
    memcpy( (void*)&(pmMem->lpszResponse[pmMem->uSize]), data, realsize);
    pmMem->uSize = pmMem->uSize + realsize;
    pmMem->lpszResponse[pmMem->uSize] = 0;

    return realsize;
}

void UnreadGetData(LPCSTR lpczURL, LPCSTR lpczToken)
{
    CURL* curl_handle;
    CHAR lpzBody[BLOCKSIZE];

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, lpczURL);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, lpczToken);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, UnreadCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&lpzBody);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
}

void UnreadMsgData(LPSTR* lpzId, guint iArrLen)
{
    CURL* curl_handle;
    MEMORY mChunk;
    FILE* fpData = NULL;
    guint i = 0;
    mChunk.uSize = 0;
    mChunk.lpszResponse = NULL;
    PCHAR pcTemp = NULL;
    
    CHAR cURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages/";
    LPCSTR lpczToken = "ya29.a0AfH6SMD-TB55Pjoq3qMtKQifnF8PDIfQFZeqdTfNfAnLb5-ujEusVJTSr9AocaeUIJXu8cpf1kSGdGIHi6kMg-u3RgPuHnNYaFfcHeo9PxFGH-0Wa8I-1shRheIEG2yPKTOTcxQwABMNnNHyFlBSfrIgA3aN9RAWF64";
    pcTemp = (PCHAR)malloc(sizeof(char) * strlen(cURL));

    if ((fpData = fopen("body.out", "wb")) == NULL)
    {
        fclose(fpData);
        return;
    }

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();
  
    strcpy(pcTemp, cURL);
    strcatX(pcTemp, lpzId[i]);

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, pcTemp);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, lpczToken);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, MsgCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&mChunk);

    /* get it */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

}

/* Callback function for the data getting from response body */
static size_t UnreadCallback(void* ptr, size_t size, size_t nmemb, void* stream)
{
    UnreadMsgsParser((LPCSTR)ptr, size * nmemb);
    return size * nmemb;
}

void UnreadMsgsParser(LPCSTR lpzBuffer, size_t uSize)
{
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    LPSTR* lpzId = NULL;

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
            lpzId = (PCHAR*)malloc(sizeof(PCHAR) * iArrLen);
            JsonObject* jobj;
            for (i = 0; i < iArrLen; i++)
            {
                lpzId[i] = (PCHAR)malloc(sizeof(CHAR) * 16);
                jobj = json_array_get_object_element(array, i);
                lpzId[i] = (LPSTR)json_object_get_string_member(jobj, "id");
                cout << lpzId[i] << endl;
            }
        }
    }
    UnreadMsgData(lpzId, iArrLen);
    g_object_unref(parser);
}