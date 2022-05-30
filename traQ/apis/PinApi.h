#ifndef TRAQ_PinApi_H
#define TRAQ_PinApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/MessagePin.h>
#include <traQ/models/Pin.h>


namespace traQApi {

class PinApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    PinApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    PinApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    PinApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    PinApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // ピン留めする
    auto createPin(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/messages/{messageId}/pin";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<MessagePin> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // チャンネルピンのリストを取得
    auto getChannelPins(
        const std::string& _channelId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/channels/{channelId}/pins";
        
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
        std::optional<std::vector<Pin>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<Pin> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<Pin>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ピン留めを取得
    auto getPin(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/messages/{messageId}/pin";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<MessagePin> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ピン留めを外す
    auto removePin(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/messages/{messageId}/pin";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif
