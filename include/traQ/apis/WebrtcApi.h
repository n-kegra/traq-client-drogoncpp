#ifndef TRAQ_WebrtcApi_H
#define TRAQ_WebrtcApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/PostWebRTCAuthenticateRequest.h>
#include <traQ/models/WebRTCAuthenticateResult.h>
#include <traQ/models/WebRTCUserState.h>

namespace traQApi {

class WebrtcApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    WebrtcApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    WebrtcApi& setBearerToken(std::string _token);
    WebrtcApi& setBasicAuth(std::string _username, std::string _password);
    WebrtcApi& setApikey(std::string _apikey);


    // WebRTC状態を取得
    std::vector<WebRTCUserState>
    getWebRTCState(
    );

    // Skyway用認証API
    WebRTCAuthenticateResult
    postWebRTCAuthenticate(
        const std::optional<PostWebRTCAuthenticateRequest>& _postWebRTCAuthenticateRequest
    );

};

}

#endif
