#include "http.c"

char* http_get(const char *url, struct curl_slist *headers) {
    return http_request(url, "GET", NULL, headers);
}

char* http_post(const char *url, const char *data, struct curl_slist *headers) {
    return http_request(url, "POST", data, headers);
}

char* http_put(const char *url, const char *data, struct curl_slist *headers) {
    return http_request(url, "PUT", data, headers);
}

char* http_delete(const char *url, struct curl_slist *headers) {
    return http_request(url, "DELETE", NULL, headers);
}
