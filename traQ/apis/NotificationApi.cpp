#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <traQ/Helper.h>
#include "NotificationApi.h"

#include <traQ/models/MyChannelViewState.h>
#include <traQ/models/PatchChannelSubscribersRequest.h>
#include <traQ/models/PostMyFCMDeviceRequest.h>
#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include <traQ/models/PutChannelSubscribersRequest.h>
#include <traQ/models/UnreadChannel.h>
#include <traQ/models/UserSubscribeState.h>


namespace traQApi {

NotificationApi::NotificationApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("NotificationApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

NotificationApi& NotificationApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
NotificationApi& NotificationApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
NotificationApi& NotificationApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


void
NotificationApi::editChannelSubscribers(
    const std::string& _channelId, 
    const std::optional<PatchChannelSubscribersRequest>& _patchChannelSubscribersRequest
){
    Json::Value json;
    if(_patchChannelSubscribersRequest.has_value()) {
        json = (_patchChannelSubscribersRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/channels/{channelId}/subscribers";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


std::vector<std::string>
NotificationApi::getChannelSubscribers(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/channels/{channelId}/subscribers";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<std::string> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<std::string>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<UserSubscribeState>
NotificationApi::getMyChannelSubscriptions(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/subscriptions";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<UserSubscribeState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserSubscribeState>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<UnreadChannel>
NotificationApi::getMyUnreadChannels(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/unread";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<UnreadChannel> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UnreadChannel>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<MyChannelViewState>
NotificationApi::getMyViewStates(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/view-states";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<MyChannelViewState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<MyChannelViewState>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


void
NotificationApi::readChannel(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/unread/{channelId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
NotificationApi::registerFCMDevice(
    const std::optional<PostMyFCMDeviceRequest>& _postMyFCMDeviceRequest
){
    Json::Value json;
    if(_postMyFCMDeviceRequest.has_value()) {
        json = (_postMyFCMDeviceRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/fcm-device";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
NotificationApi::setChannelSubscribeLevel(
    const std::string& _channelId, 
    const std::optional<PutChannelSubscribeLevelRequest>& _putChannelSubscribeLevelRequest
){
    Json::Value json;
    if(_putChannelSubscribeLevelRequest.has_value()) {
        json = (_putChannelSubscribeLevelRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/users/me/subscriptions/{channelId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
NotificationApi::setChannelSubscribers(
    const std::string& _channelId, 
    const std::optional<PutChannelSubscribersRequest>& _putChannelSubscribersRequest
){
    Json::Value json;
    if(_putChannelSubscribersRequest.has_value()) {
        json = (_putChannelSubscribersRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/channels/{channelId}/subscribers";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
NotificationApi::ws(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/ws";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


}
