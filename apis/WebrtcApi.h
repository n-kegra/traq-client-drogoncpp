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

namespace traQAPI {

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
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/webrtc/state";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<WebRTCUserState>> response_object;

        if(response_json) {
            std::vector<WebRTCUserState> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<WebRTCUserState>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // Skyway用認証API
    auto postWebRTCAuthenticate(
        const std::optional<PostWebRTCAuthenticateRequest>& _postWebRTCAuthenticateRequest
    ){
        Json::Value json;
        if(_postWebRTCAuthenticateRequest.has_value()) {
            json = (_postWebRTCAuthenticateRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/webrtc/authenticate";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<WebRTCAuthenticateResult> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


};

}

#endif
