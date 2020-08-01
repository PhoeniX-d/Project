// CurlApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define CURL_STATICLIB
#include "curl/curl.h"
#include "json-c/json.h"
#include <stdio.h>
#include <stdlib.h>
#define BLOCKSIZE  4096

typedef struct json_object* PJOBJ;

/* Callback function for the data getting from response body */
static size_t body_callback(void* ptr, size_t size, size_t nmemb, void* stream)
{
  
    PJOBJ parsed_json;
    PJOBJ emailId;
    PJOBJ totalMsgs;
    PJOBJ totalThreads;
    PJOBJ historyId;

    const char* mail;
    int msgs, threads;
    unsigned long hid;

    parsed_json = json_tokener_parse((char*)ptr);

    json_object_object_get_ex(parsed_json, "emailAddress", &emailId);
    json_object_object_get_ex(parsed_json, "messagesTotal", &totalMsgs);
    json_object_object_get_ex(parsed_json, "threadsTotal", &totalThreads);
    json_object_object_get_ex(parsed_json, "historyId", &historyId);
    
    mail = json_object_get_string(emailId);
    msgs = json_object_get_int(totalMsgs);
    threads = json_object_get_int(totalThreads);
    hid = json_object_get_int(historyId);

    printf("EmailAdresss = %20s\n", mail);
    printf("TotalMessages = %10d\n", msgs);
    printf("Total Threads = %10d\n", threads);
    printf("History Id = %10d\n", hid);

    return size * nmemb;
}

 /*Callback function for the data getting from response header  */
static size_t header_callback(char* buffer, size_t size, size_t nitems, void* userdata)
{
    for (int i = 0; i < (size * nitems); i++)
    {
        printf("%c", buffer[i]);
    }
    return nitems * size;
}

int main(void)
{
    CURL* curl_handle;
    char HeaderData[BLOCKSIZE];
    char BodyData[BLOCKSIZE];

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/profile");
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, "ya29.a0AfH6SMAtkpef76fho3QW1P1DRJ61a94r-jZR26gP0uFFu-nFd8fZdQgPQWDf9aUw5ehTEowCvhqHuJDS6Kz7iAJIRY_k4acWgA9wIaTh3G1z-lv1UFb8rvukqvcR2MwTdl164ytiuNYdBEZ8qT0I2iv57HY1Mf2Uu2Y");
    
    /* send all headers to this function */
    curl_easy_setopt(curl_handle, CURLOPT_HEADERFUNCTION, header_callback);
    curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, &HeaderData);
   
    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, body_callback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&BodyData);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    return 0;
}
