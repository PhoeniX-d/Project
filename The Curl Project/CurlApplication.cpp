// CurlApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Macros
#define CURL_STATICLIB
#define BLOCKSIZE       4096
#define STRINGSIZE        32
#define URLSIZE          150
#define TOKENSIZE        180

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

/* structure for contents of URL*/
typedef struct _memory {
    PCHAR pcList;
    size_t uLsize;
}MEMORY, * PMEMORY;

CHAR cToken[TOKENSIZE] = "ya29.a0AfH6SMAgl2B2NbZJ3o6uyikhhqS2a4qasTqhsEgP6EyRDKlUEsFaKMrvJFpgYAI03Fzod2yUTJeptH3wnwVHFmqquUBKuX8vvejsRR1WaJDAPTIvEzJ1qjzIMugEuweIsTnMp4-wJz6WkeUJgMCqY5os7CjcKxWHl4J3";

/* class MailSort */
class MailSort
{
private:

    MEMORY chunk;
public:

    /* Unread Msgs List Parser Function */
    void UnreadListParser(PCHAR, size_t);

    /* Unread Msgs Content Parser Function */
    void UnreadContentParser(PCHAR, size_t);

    /* Callback function for getting unread msg list to parse */
    static size_t ListCallback(void* ptr, size_t size, size_t nmemb, void* stream);

    /* callback function for getting encoded unread msgs contents */
    static size_t ContentCallback(void* ptr, size_t size, size_t nmemb, void* stream);

    /* curl APIs for getting unread msgs list */
    void UnreadGetList(PMEMORY, PCHAR);

    /* curl APIs for getting unread msgs contents*/
    void UnreadGetContent(const PCHAR, const PCHAR, int);

    /* Performs base64 decoding for type: text/plain */
    CHAR* Base64Decode(PCHAR);
};

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
void MailSort::UnreadGetList(PMEMORY pmChunk, PCHAR pcURL)
{
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
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, cToken);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, ListCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)pmChunk);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

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
//  Last Modified   :5 Sept 2020
//
//////////////////////////////////////////////////////////////////////
void MailSort::UnreadListParser(PCHAR lpzBuffer, size_t uSize)
{
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    CHAR* lpzId = new CHAR[STRINGSIZE];
    CHAR cURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages/";
    CHAR cTemp[URLSIZE] = { '\0' };

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
                
                /* makeing URL that will fetch contents from messages */
                strcpy(cTemp, cURL);
                strcat(cTemp, lpzId);

                /* after getting URL call curl APIs to get data */
                UnreadGetList(&chunk, cTemp);

                /* after data fetched parse that data */
                UnreadContentParser(chunk.pcList, chunk.uLsize);

                _strset(cTemp, '\0');
                _strset(lpzId, '\0');
                memset((void*)chunk.pcList, 0, chunk.uLsize);
                /* loop until all unread msgs in mail box are finished */
            }
        }
    }
    g_object_unref(parser);
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
void MailSort::UnreadContentParser(PCHAR lpzBuffer, size_t uSize)
{
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    CHAR* lpzTemp1 = new CHAR[STRINGSIZE];
    CHAR* lpzTemp2 = new CHAR[BLOCKSIZE];

    json_parser_load_from_data(parser, lpzBuffer, uSize, NULL);
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
                    lpzTemp1 = (PCHAR)json_object_get_string_member(jobj, "name");
                    if (strcmp(lpzTemp1, "Subject") == 0)
                    {
                        lpzTemp2 = (PCHAR)json_object_get_string_member(jobj, "value");
                        cout << "Subject\t\t:" << lpzTemp2 << endl;
                    }
                    if (strcmp(lpzTemp1, "From") == 0)
                    {
                        lpzTemp2 = (PCHAR)json_object_get_string_member(jobj, "value");
                        cout << "From\t\t:" << lpzTemp2 << endl;
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
                    lpzTemp1 = (PCHAR)json_object_get_string_member(jobj, "mimeType");
                    if (strcmp(lpzTemp1, "text/plain") == 0)
                    {
                        if (json_object_has_member(jobj, "body"))
                        {
                            jobj2 = json_object_get_object_member(jobj, "body");
                            if (json_object_has_member(jobj2, "data"))
                            {
                                lpzTemp2 = (PCHAR)json_object_get_string_member(jobj2, "data");
                                lpzTemp2 = Base64Decode(lpzTemp2);
                                cout << "Content\t\t:\n" << lpzTemp2 << endl;
                                cout << "---------------------------------------------------------------------------------------------------" << endl;
                            }
                        }
                    }
                }
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
CHAR* MailSort::Base64Decode(PCHAR lpzCipher)
{
    CHAR base_map[] = { 
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                            'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                            'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                            'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' 
                        };

    int iCount = 0;
    CHAR cBuffer[4];
    PCHAR lpzPlain = (PCHAR)malloc(strlen(lpzCipher) * 3 / 4 );
    if (lpzPlain == NULL)
    {
        cout << "Memory Allocation Failed\n";
        return lpzPlain;
    }    
    int i = 0, iPlain = 0, k = 0;

    for (i = 0; lpzCipher[i] != '\0'; i++)
    {
        for (k = 0; k < 64 && (base_map[k] != lpzCipher[i]); k++)
            ;
        
        cBuffer[iCount++] = k;
        
        if (iCount == 4)
        {
            lpzPlain[iPlain++] = (cBuffer[0] << 2) + (cBuffer[1] >> 4);

            if (cBuffer[2] != 64)
            {
                lpzPlain[iPlain++] = (cBuffer[1] << 4) + (cBuffer[2] >> 2);
            }
            if (cBuffer[3] != 64)
            {
                lpzPlain[iPlain++] = (cBuffer[2] << 6) + cBuffer[3];
            }
            iCount = 0;
        }
    }
    *(lpzPlain + iPlain) = '\0';
    return lpzPlain;
}
// Entry point
int main(void)
{
    MailSort msObj;
    MEMORY pmChunk;

    CHAR cUnreadURL[] = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages?q=is%3Aunread";
    msObj.UnreadGetList(&pmChunk, cUnreadURL);
    msObj.UnreadListParser(pmChunk.pcList, pmChunk.uLsize);
    
    return 0;
}