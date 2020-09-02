// CurlApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Macros
#define CURL_STATICLIB
#define BLOCKSIZE       4096
#define SUCCESS            1
#define FAILURE            0

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
#include <cstdio>

using namespace std;

/* structure for contents of URL*/
typedef struct _memory {
    PCHAR pcList;
    size_t uLsize;
}MEMORY, * PMEMORY;

CHAR cToken[] = "ya29.a0AfH6SMALnIxYyDNgB0oAjDr3BKGJCBCjXd1wjpR-XW93mJv35orvW9Eiz4a6lm9GPwaJaYwT4xaLtAB4MOmGJ4b8vQmRWdiXKMeKpn9Dt5w5xTCnqUZ8NZphew6y_BGXvorbmEYtXsxic6asbU572QsBVeXU1SvAnnY";

/* class MailSort */
class MailSort
{
private:
    MEMORY chunk;
public:
    /* Unread Msgs List Parser Function */
    void UnreadMsgsParser(PCHAR, size_t);
    /* Callback function for getting unread msg list to parse */
    static size_t ListCallback(void* ptr, size_t size, size_t nmemb, void* stream);
    /* callback function for getting encoded unread msgs contents */
    static size_t ContentCallback(void* ptr, size_t size, size_t nmemb, void* stream);
    /* curl APIs for getting unread msgs list */
    void UnreadGetList(PCHAR);
    /* curl APIs for getting unread msgs contents*/
    void UnreadGetContent(const PCHAR, const PCHAR, int);
};

/////////////////////////////////////////////////////////////////
//
//  Name            :UnreadGetList
//  Input           :PCHAR
//  Returns         :void
//  Description     :This function will get list of IDs of Unread
//                  new msgs from mailbox
//  Author          :Pranav Choudhary  
//  Last Modified   :2 Sept 2020
//
/////////////////////////////////////////////////////////////////
void MailSort::UnreadGetList(PCHAR pcURL)
{
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
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, cToken);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, ListCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    UnreadMsgsParser(chunk.pcList, chunk.uLsize);
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
size_t MailSort:: ListCallback(void* data, size_t size, size_t nmemb, void* stream)
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
size_t MailSort::ContentCallback(void* ptr, size_t size, size_t nmemb, void* stream)
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
//  Last Modified   :2 Sept 2020
//
//////////////////////////////////////////////////////////////////////
void MailSort::UnreadMsgsParser(PCHAR lpzBuffer, size_t uSize)
{
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    CHAR* lpzId = new CHAR[20];
    CHAR cURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages/";
    CHAR cTemp[100] = { '\0' };
    //CHAR cTempURL[20][100];

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
                lpzId = (PCHAR)json_object_get_string_member(jobj, "id");
                strcpy(cTemp, cURL);
                strcat(cTemp, lpzId);
                UnreadGetContent(cTemp, lpzId, i);
                _strset(cTemp, '\0');
                _strset(lpzId, '\0');
            }
        }
    }
    g_object_unref(parser);
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
void MailSort::UnreadGetContent(const PCHAR pcURL, const PCHAR lpzId, int iCnt)
{
    CURL* curl_handle;
    CHAR cFileName[90] = { '\0' };
    sprintf_s(cFileName, "C://Users//Pranav//Desktop//Temp//UnreadFile_%s_%2d.json", lpzId, iCnt);
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
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, cToken);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, ContentCallback);

    /* open the body file */
    fp = fopen(cFileName, "wb");
    if (!fp)
    {
        cout << "Unable To open File\n";
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

// Entry point
int main(void)
{
    MailSort msObj;
    CHAR cUnreadURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages?q=is%3Aunread";
    msObj.UnreadGetList(cUnreadURL);
    return 0;
}