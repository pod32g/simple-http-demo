#ifndef VERBS_H
#define VERBS_H

#include "http.h"

// Function declarations
char* http_get(const char *url, struct curl_slist *headers);
char* http_post(const char *url, const char *data, struct curl_slist *headers);
char* http_put(const char *url, const char *data, struct curl_slist *headers);
char* http_delete(const char *url, struct curl_slist *headers);
char* http_request(const char *url, const char *method, const char *data, struct curl_slist *headers);

#endif // HTTP_H
