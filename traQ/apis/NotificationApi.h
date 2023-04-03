#ifndef TRAQ_NotificationApi_H
#define TRAQ_NotificationApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/MyChannelViewState.h>
#include <traQ/models/PatchChannelSubscribersRequest.h>
#include <traQ/models/PostMyFCMDeviceRequest.h>
#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include <traQ/models/PutChannelSubscribersRequest.h>
#include <traQ/models/UnreadChannel.h>
#include <traQ/models/UserSubscribeState.h>


namespace traQApi {

class NotificationApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    NotificationApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    NotificationApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    NotificationApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    NotificationApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // チャンネルの通知購読者を編集
    auto editChannelSubscribers(
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


        return std::make_tuple(result, std::move(response));
    }


    // チャンネルの通知購読者のリストを取得
    auto getChannelSubscribers(
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

        auto response_json = response->getJsonObject();
        std::optional<std::vector<std::string>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<std::string> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<std::string>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // 自分のチャンネル購読状態を取得
    auto getMyChannelSubscriptions(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserSubscribeState> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserSubscribeState>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // 未読チャンネルを取得
    auto getMyUnreadChannels(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UnreadChannel> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UnreadChannel>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // 自身のチャンネル閲覧状態一覧を取得
    auto getMyViewStates(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<MyChannelViewState> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<MyChannelViewState>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // チャンネルを既読にする
    auto readChannel(
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


        return std::make_tuple(result, std::move(response));
    }


    // FCMデバイスを登録
    auto registerFCMDevice(
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


        return std::make_tuple(result, std::move(response));
    }


    // チャンネル購読レベルを設定
    auto setChannelSubscribeLevel(
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


        return std::make_tuple(result, std::move(response));
    }


    // チャンネルの通知購読者を設定
    auto setChannelSubscribers(
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


        return std::make_tuple(result, std::move(response));
    }


    // WebSocket通知ストリームに接続します
    auto ws(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/ws";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::make_tuple(result, std::move(response));
    }


};

}

#endif
