// CurlApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define CURL_STATICLIB
#define BLOCKSIZE  4096

#include <curl.h>
#include <json-glib/json-glib.h>
#include <glib-object.h>
#include <json-glib/json-parser.h>
#include <glib.h>
#include <gobject/gobject.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

/* Callback function for the data getting from response body */
static size_t BodyCallback(void* ptr, size_t size, size_t nmemb, void* stream)
{
    LPCSTR lpzBuffer = (PCHAR)ptr;
    /*for (int i = 0; i < size * nmemb; i++)
    {
        cout << *(lpzBuffer + i);
    }*/
    //size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
      
    JsonParser* parser = json_parser_new();
    JsonNode* root;
   
    //GError* error = NULL;
    //JsonArray* array;
    const gchar* filename = "body.json";

    json_parser_load_from_file(parser, filename, NULL);
    root = json_parser_get_root(parser);
    if (JSON_NODE_HOLDS_OBJECT(root))
    {
        JsonObject* object;
        object = json_node_get_object(root);
        if (json_object_has_member(object, "messages"))
        {
           JsonArray* array = json_object_get_array_member(object, "messages");
        }
    }

    //array = json_node_get_array(root);
    /*
    LPCSTR lpzEmail;
    INT64 iMsgCnt;
    INT64 iThreadCnt;
    LPCSTR lpzHistoryId;
    json_parser_load_from_data(parser, lpzBuffer, size * nmemb, NULL);
    node = json_parser_get_root(parser);

    if (JSON_NODE_HOLDS_OBJECT(node))
    {
        object = json_node_get_object(node);

        lpzEmail = json_object_get_string_member(object, "emailAddress");
        iMsgCnt = json_object_get_int_member(object, "messagesTotal");
        iThreadCnt = json_object_get_int_member(object, "threadsTotal");
        lpzHistoryId = json_object_get_string_member(object, "historyId");

        cout << "Email:\t" << lpzEmail << endl;
        cout << "Message Count:\t" << iMsgCnt << endl;
        cout << "Thread Count:\t" << iThreadCnt << endl;
        cout << "History Id:\t" << lpzHistoryId << endl;  
    }
    */
   // g_object_unref(parser);
    return size * nmemb;
}

/*Callback function for the data getting from response header
static size_t header_callback(char* buffer, size_t size, size_t nitems, void* userdata)
{
    for (int i = 0; i < (size * nitems); i++)
    {
        printf("%c", buffer[i]);
    }
    return nitems * size;
}
*/
int main(void)
{
    CURL* curl_handle;
    char HeaderData[BLOCKSIZE];
    char BodyData[BLOCKSIZE * 3];
   /* static const char* bodyfilename = "body.json";
    FILE* bodyfile;*/
    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages");
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, "ya29.a0AfH6SMDHKK_hcSQtQL8RYgMBGDtdLqukctjBXCLg8I3KAzkaNhxyhzeuB-WMdTDnZ60o2RG7kX6xx82hwqGUB5v1LeN3nU2RpaINII0wxxzcjpdpOJiXnxdd9nbUUTjI6ylMyvHXoHmjXLqWe-1B02m1krVwfh_UXfI");

    /* send all headers to this function */
    /*curl_easy_setopt(curl_handle, CURLOPT_HEADERFUNCTION, header_callback);
    curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, &HeaderData);*/

    /* open the body file */
   /* bodyfile = fopen(bodyfilename, "wb");
    if (!bodyfile) {
        curl_easy_cleanup(curl_handle);
        fclose(bodyfile);
        return -1;
    }

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, BodyCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)BodyData);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    return 0;
}
