#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include "../Helper.h"
#include <traQ/apis/WebrtcApi.h>

#include <traQ/models/PostWebRTCAuthenticateRequest.h>
#include <traQ/models/WebRTCAuthenticateResult.h>
#include <traQ/models/WebRTCUserState.h>

namespace traQApi {

WebrtcApi::WebrtcApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, m, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("WebrtcApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

WebrtcApi& WebrtcApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
WebrtcApi& WebrtcApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
WebrtcApi& WebrtcApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


std::vector<WebRTCUserState>
WebrtcApi::getWebRTCState(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/webrtc/state";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<WebRTCUserState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<WebRTCUserState>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


WebRTCAuthenticateResult
WebrtcApi::postWebRTCAuthenticate(
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return WebRTCAuthenticateResult(*response_json);
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


}
