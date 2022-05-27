#include "WebrtcApi.h"

namespace traQ {

auto WebrtcApi::getWebRTCState(
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

auto WebrtcApi::postWebRTCAuthenticate(
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


}
