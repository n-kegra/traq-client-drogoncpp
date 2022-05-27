#ifndef _OgpApi_H
#define _OgpApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Ogp.h"


namespace traQ {

class OgpApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    OgpApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    OgpApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    OgpApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    OgpApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // OGP情報を取得
    auto getOgp(
        const std::string& _url
    );


};

}

#endif
