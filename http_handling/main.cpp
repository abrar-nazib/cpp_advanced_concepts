#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>

// Callback function to handle response data
static size_t WriteCallBack(void *contents, size_t size, size_t nmemb,
                            void *userp) {

                                
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

// GET Request Example
void perform_get_requst() {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init(); // Initialize a session

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.restful-api.dev/objects");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "Get request failed: " << curl_easy_strerror(res) << "\n";
    } else {
      std::cout << "Get response: " << readBuffer << "\n";
    }
    curl_easy_cleanup(curl);
  }
}

int main() {
  perform_get_requst();
  return 0;
}