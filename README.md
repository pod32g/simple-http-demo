
# HTTP Requests in C with libcurl

This project demonstrates how to perform HTTP GET, POST, PUT, and DELETE requests in C using the `libcurl` library. The project includes reusable functions for each HTTP verb.

## Warning

**This project is for educational purposes only and is not intended to be used in production environments. Use it at your own risk.**

## Prerequisites

Make sure you have `libcurl` installed on your system. You can install it using your package manager.

- **On Debian-based systems (e.g., Ubuntu):**

  ```sh
  sudo apt-get install libcurl4-openssl-dev
  ```

- **On macOS using Homebrew:**

  ```sh
  brew install curl
  ```

- **On Fedora:**

  ```sh
  sudo dnf install libcurl-devel
  ```

## Project Structure

- `http.c`: Contains the main function and the HTTP request functions.
- `verbs.c`: Contains separated implementations of the most basic HTTP verbs.

## Functions

### http_request

A generic function to perform an HTTP request.

```c
char* http_request(const char *url, const char *method, const char *data, struct curl_slist *headers);
```

- `url`: The URL to send the request to.
- `method`: The HTTP method (e.g., "GET", "POST", "PUT", "DELETE").
- `data`: The data to send in the request body (for POST and PUT requests).
- `headers`: The list of custom headers.

### http_get

Performs an HTTP GET request.

```c
char* http_get(const char *url, struct curl_slist *headers);
```

- `url`: The URL to send the request to.
- `headers`: The list of custom headers.

### http_post

Performs an HTTP POST request.

```c
char* http_post(const char *url, const char *data, struct curl_slist *headers);
```

- `url`: The URL to send the request to.
- `data`: The data to send in the request body.
- `headers`: The list of custom headers.

### http_put

Performs an HTTP PUT request.

```c
char* http_put(const char *url, const char *data, struct curl_slist *headers);
```

- `url`: The URL to send the request to.
- `data`: The data to send in the request body.
- `headers`: The list of custom headers.

### http_delete

Performs an HTTP DELETE request.

```c
char* http_delete(const char *url, struct curl_slist *headers);
```

- `url`: The URL to send the request to.
- `headers`: The list of custom headers.

## Example

```c
int main(void) {
    const char *url = "http://www.example.com";
    const char *json_data = "{"key1":"value1","key2":"value2"}";

    // Create custom headers
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer YOUR_ACCESS_TOKEN");

    // Example usage for GET request
    char *get_response = http_get(url, headers);
    if (get_response) {
        printf("GET Response data: %s\n", get_response);
        free(get_response);
    } else {
        printf("Failed to get data from %s\n", url);
    }

    // Example usage for POST request
    char *post_response = http_post(url, json_data, headers);
    if (post_response) {
        printf("POST Response data: %s\n", post_response);
        free(post_response);
    } else {
        printf("Failed to post data to %s\n", url);
    }

    // Example usage for PUT request
    char *put_response = http_put(url, json_data, headers);
    if (put_response) {
        printf("PUT Response data: %s\n", put_response);
        free(put_response);
    } else {
        printf("Failed to put data to %s\n", url);
    }

    // Example usage for DELETE request
    char *delete_response = http_delete(url, headers);
    if (delete_response) {
        printf("DELETE Response data: %s\n", delete_response);
        free(delete_response);
    } else {
        printf("Failed to delete data from %s\n", url);
    }

    curl_slist_free_all(headers);

    return 0;
}
```

## License

This project is licensed under the MIT License.

