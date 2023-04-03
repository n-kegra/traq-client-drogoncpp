#ifndef TRAQ_MessageApi_H
#define TRAQ_MessageApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>
#include <traQ/models/MessageClip.h>
#include <traQ/models/MessagePin.h>
#include <traQ/models/MessageSearchResult.h>
#include <traQ/models/MessageStamp.h>
#include <traQ/models/PostMessageRequest.h>
#include <traQ/models/PostMessageStampRequest.h>


namespace traQApi {

class MessageApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    MessageApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    MessageApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    MessageApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    MessageApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // スタンプを押す
    auto addMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId, 
        const std::optional<PostMessageStampRequest>& _postMessageStampRequest
    ){
        Json::Value json;
        if(_postMessageStampRequest.has_value()) {
            json = (_postMessageStampRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/messages/{messageId}/stamps/{stampId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::make_tuple(result, std::move(response));
    }


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

        return std::make_tuple(result, std::move(response), response_object);
    }


    // メッセージを削除
    auto deleteMessage(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/messages/{messageId}";
        
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


        return std::make_tuple(result, std::move(response));
    }


    // メッセージを編集
    auto editMessage(
        const std::string& _messageId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    ){
        Json::Value json;
        if(_postMessageRequest.has_value()) {
            json = (_postMessageRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Put);

        std::string endpoint_path = "/messages/{messageId}";
        
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


        return std::make_tuple(result, std::move(response));
    }


    // ダイレクトメッセージのリストを取得
    auto getDirectMessages(
        const std::string& _userId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/{userId}/messages";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        if(_limit.has_value()) {
            Json::Value jsonobj = (_limit.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "limit", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_offset.has_value()) {
            Json::Value jsonobj = (_offset.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "offset", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_since.has_value()) {
            Json::Value jsonobj = (_since.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "since", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_until.has_value()) {
            Json::Value jsonobj = (_until.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "until", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_inclusive.has_value()) {
            Json::Value jsonobj = (_inclusive.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "inclusive", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_order.has_value()) {
            Json::Value jsonobj = (_order.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "order", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<Message>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<Message> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<Message>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // メッセージを取得
    auto getMessage(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/messages/{messageId}";
        
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
        std::optional<Message> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // 自分のクリップを取得
    auto getMessageClips(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/messages/{messageId}/clips";
        
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
        std::optional<std::vector<MessageClip>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<MessageClip> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<MessageClip>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // メッセージのスタンプリストを取得
    auto getMessageStamps(
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/messages/{messageId}/stamps";
        
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
        std::optional<std::vector<MessageStamp>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<MessageStamp> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<MessageStamp>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // チャンネルメッセージのリストを取得
    auto getMessages(
        const std::string& _channelId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/channels/{channelId}/messages";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_channelId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "channelId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
        }
        
        if(_limit.has_value()) {
            Json::Value jsonobj = (_limit.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "limit", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_offset.has_value()) {
            Json::Value jsonobj = (_offset.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "offset", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_since.has_value()) {
            Json::Value jsonobj = (_since.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "since", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_until.has_value()) {
            Json::Value jsonobj = (_until.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "until", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_inclusive.has_value()) {
            Json::Value jsonobj = (_inclusive.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "inclusive", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_order.has_value()) {
            Json::Value jsonobj = (_order.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "order", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<Message>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<Message> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<Message>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), response_object);
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

        return std::make_tuple(result, std::move(response), response_object);
    }


    // ダイレクトメッセージを送信
    auto postDirectMessage(
        const std::string& _userId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    ){
        Json::Value json;
        if(_postMessageRequest.has_value()) {
            json = (_postMessageRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/users/{userId}/messages";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<Message> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // チャンネルにメッセージを投稿
    auto postMessage(
        const std::string& _channelId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    ){
        Json::Value json;
        if(_postMessageRequest.has_value()) {
            json = (_postMessageRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/channels/{channelId}/messages";
        
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
        std::optional<Message> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


    // スタンプを消す
    auto removeMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/messages/{messageId}/stamps/{stampId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::make_tuple(result, std::move(response));
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


        return std::make_tuple(result, std::move(response));
    }


    // メッセージを検索
    auto searchMessages(
        const std::optional<std::string>& _word, 
        const std::optional<std::string>& _after, 
        const std::optional<std::string>& _before, 
        const std::optional<std::string>& _in, 
        const std::optional<std::string>& _to, 
        const std::optional<std::string>& _from, 
        const std::optional<std::string>& _citation, 
        const std::optional<bool>& _bot, 
        const std::optional<bool>& _hasURL, 
        const std::optional<bool>& _hasAttachments, 
        const std::optional<bool>& _hasImage, 
        const std::optional<bool>& _hasVideo, 
        const std::optional<bool>& _hasAudio, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _sort
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/messages";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        if(_word.has_value()) {
            Json::Value jsonobj = (_word.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "word", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_after.has_value()) {
            Json::Value jsonobj = (_after.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "after", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_before.has_value()) {
            Json::Value jsonobj = (_before.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "before", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_in.has_value()) {
            Json::Value jsonobj = (_in.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "in", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_to.has_value()) {
            Json::Value jsonobj = (_to.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "to", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_from.has_value()) {
            Json::Value jsonobj = (_from.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "from", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_citation.has_value()) {
            Json::Value jsonobj = (_citation.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "citation", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_bot.has_value()) {
            Json::Value jsonobj = (_bot.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "bot", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_hasURL.has_value()) {
            Json::Value jsonobj = (_hasURL.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "hasURL", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_hasAttachments.has_value()) {
            Json::Value jsonobj = (_hasAttachments.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "hasAttachments", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_hasImage.has_value()) {
            Json::Value jsonobj = (_hasImage.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "hasImage", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_hasVideo.has_value()) {
            Json::Value jsonobj = (_hasVideo.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "hasVideo", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_hasAudio.has_value()) {
            Json::Value jsonobj = (_hasAudio.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "hasAudio", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_limit.has_value()) {
            Json::Value jsonobj = (_limit.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "limit", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_offset.has_value()) {
            Json::Value jsonobj = (_offset.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "offset", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_sort.has_value()) {
            Json::Value jsonobj = (_sort.value());
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "sort", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<MessageSearchResult> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::make_tuple(result, std::move(response), response_object);
    }


};

}

#endif
