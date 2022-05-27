#include "NotificationApi.h"

namespace traQ {

auto NotificationApi::editChannelSubscribers(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto NotificationApi::getChannelSubscribers(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<std::string>> response_object;

    if(response_json) {
        std::vector<std::string> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<std::string>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto NotificationApi::getMyChannelSubscriptions(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/subscriptions";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<UserSubscribeState>> response_object;

    if(response_json) {
        std::vector<UserSubscribeState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserSubscribeState>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto NotificationApi::getMyUnreadChannels(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/unread";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<UnreadChannel>> response_object;

    if(response_json) {
        std::vector<UnreadChannel> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UnreadChannel>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto NotificationApi::getMyViewStates(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/view-states";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<MyChannelViewState>> response_object;

    if(response_json) {
        std::vector<MyChannelViewState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<MyChannelViewState>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto NotificationApi::readChannel(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto NotificationApi::registerFCMDevice(
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


    return std::forward_as_tuple(result, response);
}

auto NotificationApi::setChannelSubscribeLevel(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto NotificationApi::setChannelSubscribers(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto NotificationApi::ws(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/ws";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}


}
