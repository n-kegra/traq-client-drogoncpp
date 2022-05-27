#ifndef _WebrtcApi_H
#define _WebrtcApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/PostWebRTCAuthenticateRequest.h"
#include "../models/WebRTCAuthenticateResult.h"
#include "../models/WebRTCUserState.h"

namespace traQ {

class WebrtcApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    WebrtcApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    WebrtcApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    WebrtcApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    WebrtcApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // WebRTC状態を取得
    auto getWebRTCState(
    );


    // Skyway用認証API
    auto postWebRTCAuthenticate(
        const std::optional<PostWebRTCAuthenticateRequest>& _postWebRTCAuthenticateRequest
    );


};

}

#endif
