#ifndef _BotApi_H
#define _BotApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Bot.h"
#include "../models/BotDetail.h"
#include "../models/BotEventLog.h"
#include "../models/BotTokens.h"
#include "../models/BotUser.h"
#include "../models/GetBot200Response.h"
#include "../models/PatchBotRequest.h"
#include "../models/PostBotActionJoinRequest.h"
#include "../models/PostBotActionLeaveRequest.h"
#include "../models/PostBotRequest.h"


namespace traQAPI {

class BotApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    BotApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    BotApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    BotApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    BotApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // BOTをアクティベート
    auto activateBot(
        const std::string& _botId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/bots/{botId}/actions/activate";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOTのアイコン画像を変更
    auto changeBotIcon(
        const std::string& _botId, 
        const drogon::UploadFile& _file
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Put);

        std::string endpoint_path = "/bots/{botId}/icon";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // WebSocket Mode BOT用通知ストリームに接続します
    auto connectBotWS(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/bots/ws";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOTを作成
    auto createBot(
        const std::optional<PostBotRequest>& _postBotRequest
    ){
        Json::Value json;
        if(_postBotRequest.has_value()) {
            json = (_postBotRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/bots";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<BotDetail> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // BOTを削除
    auto deleteBot(
        const std::string& _botId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/bots/{botId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOT情報を変更
    auto editBot(
        const std::string& _botId, 
        const std::optional<PatchBotRequest>& _patchBotRequest
    ){
        Json::Value json;
        if(_patchBotRequest.has_value()) {
            json = (_patchBotRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/bots/{botId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOT情報を取得
    auto getBot(
        const std::string& _botId, 
        const std::optional<bool>& _detail
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/bots/{botId}";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        if(_detail.has_value()) {
            Json::Value jsonobj = (_detail.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "detail", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<GetBot200Response> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // BOTのアイコン画像を取得
    auto getBotIcon(
        const std::string& _botId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/bots/{botId}/icon";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<drogon::UploadFile> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // BOTのイベントログを取得
    auto getBotLogs(
        const std::string& _botId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/bots/{botId}/logs";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        if(_limit.has_value()) {
            Json::Value jsonobj = (_limit.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "limit", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_offset.has_value()) {
            Json::Value jsonobj = (_offset.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "offset", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<BotEventLog>> response_object;

        if(response_json) {
            std::vector<BotEventLog> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<BotEventLog>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // BOTリストを取得
    auto getBots(
        const std::optional<bool>& _all
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/bots";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        if(_all.has_value()) {
            Json::Value jsonobj = (_all.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "all", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<Bot>> response_object;

        if(response_json) {
            std::vector<Bot> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<Bot>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // チャンネル参加中のBOTのリストを取得
    auto getChannelBots(
        const std::string& _channelId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/channels/{channelId}/bots";
        
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
        std::optional<std::vector<BotUser>> response_object;

        if(response_json) {
            std::vector<BotUser> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<BotUser>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // BOTをインアクティベート
    auto inactivateBot(
        const std::string& _botId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/bots/{botId}/actions/inactivate";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOTをチャンネルに参加させる
    auto letBotJoinChannel(
        const std::string& _botId, 
        const std::optional<PostBotActionJoinRequest>& _postBotActionJoinRequest
    ){
        Json::Value json;
        if(_postBotActionJoinRequest.has_value()) {
            json = (_postBotActionJoinRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/bots/{botId}/actions/join";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOTをチャンネルから退出させる
    auto letBotLeaveChannel(
        const std::string& _botId, 
        const std::optional<PostBotActionLeaveRequest>& _postBotActionLeaveRequest
    ){
        Json::Value json;
        if(_postBotActionLeaveRequest.has_value()) {
            json = (_postBotActionLeaveRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/bots/{botId}/actions/leave";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // BOTのトークンを再発行
    auto reissueBot(
        const std::string& _botId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/bots/{botId}/actions/reissue";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_botId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "botId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<BotTokens> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


};

}

#endif
