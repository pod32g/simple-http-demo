#ifndef HTTP_H
#define HTTP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define USER_AGENT "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36"

// Struct to hold the memory buffer
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Function prototypes
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
char* http_request(const char *url, const char *method, const char *data, struct curl_slist *headers);

#endif // HTTP_H
