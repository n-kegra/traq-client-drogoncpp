#ifndef _StampApi_H
#define _StampApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/MessageStamp.h"
#include "../models/PatchStampPaletteRequest.h"
#include "../models/PatchStampRequest.h"
#include "../models/PostMessageStampRequest.h"
#include "../models/PostStampPaletteRequest.h"
#include "../models/Stamp.h"
#include "../models/StampHistoryEntry.h"
#include "../models/StampPalette.h"
#include "../models/StampStats.h"


namespace traQ {

class StampApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    StampApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    StampApi& setBearerToken(std::string _token) { this->bearer_token = _token; }
    StampApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; }
    StampApi& setApikey(std::string _apikey) { this->apikey = _apikey; }


    // スタンプを押す
    auto addMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId, 
        const std::optional<PostMessageStampRequest>& _postMessageStampRequest
    ){
        Json::Value json;
        if(_postMessageStampRequest.has_value()) {
            json["postMessageStampRequest"] = (_postMessageStampRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/messages/{messageId}/stamps/{stampId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "messageId" "}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // スタンプ画像を変更
    auto changeStampImage(
        const std::string& _stampId, 
        const drogon::UploadFile& _file
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Put);

        std::string endpoint_path = "/stamps/{stampId}/image";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // スタンプを作成
    auto createStamp(
        const std::string& _name, 
        const drogon::UploadFile& _file
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/stamps";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_name);
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "name", jsonobj);
            req->setParameter("name", serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<Stamp> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプパレットを作成
    auto createStampPalette(
        const std::optional<PostStampPaletteRequest>& _postStampPaletteRequest
    ){
        Json::Value json;
        if(_postStampPaletteRequest.has_value()) {
            json["postStampPaletteRequest"] = (_postStampPaletteRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/stamp-palettes";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<StampPalette> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプを削除
    auto deleteStamp(
        const std::string& _stampId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/stamps/{stampId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // スタンプパレットを削除
    auto deleteStampPalette(
        const std::string& _paletteId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/stamp-palettes/{paletteId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_paletteId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "paletteId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "paletteId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // スタンプ情報を変更
    auto editStamp(
        const std::string& _stampId, 
        const std::optional<PatchStampRequest>& _patchStampRequest
    ){
        Json::Value json;
        if(_patchStampRequest.has_value()) {
            json["patchStampRequest"] = (_patchStampRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/stamps/{stampId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // スタンプパレットを編集
    auto editStampPalette(
        const std::string& _paletteId, 
        const std::optional<PatchStampPaletteRequest>& _patchStampPaletteRequest
    ){
        Json::Value json;
        if(_patchStampPaletteRequest.has_value()) {
            json["patchStampPaletteRequest"] = (_patchStampPaletteRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/stamp-palettes/{paletteId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_paletteId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "paletteId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "paletteId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
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
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "messageId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<MessageStamp>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプ履歴を取得
    auto getMyStampHistory(
        const std::optional<int32_t>& _limit
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/me/stamp-history";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        if(_limit.has_value()) {
            Json::Value jsonobj = (_limit.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "limit", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<StampHistoryEntry>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプ情報を取得
    auto getStamp(
        const std::string& _stampId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/stamps/{stampId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<Stamp> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプ画像を取得
    auto getStampImage(
        const std::string& _stampId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/stamps/{stampId}/image";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
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


    // スタンプパレットを取得
    auto getStampPalette(
        const std::string& _paletteId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/stamp-palettes/{paletteId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_paletteId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "paletteId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "paletteId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<StampPalette> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプパレットのリストを取得
    auto getStampPalettes(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/stamp-palettes";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<StampPalette>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプ統計情報を取得
    auto getStampStats(
        const std::string& _stampId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/stamps/{stampId}/stats";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<StampStats> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプリストを取得
    auto getStamps(
        const std::optional<bool>& _includeUnicode, 
        const std::optional<std::string>& _type
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/stamps";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        if(_includeUnicode.has_value()) {
            Json::Value jsonobj = (_includeUnicode.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "includeUnicode", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_type.has_value()) {
            Json::Value jsonobj = (_type.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "type", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<Stamp>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
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
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "messageId" "}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_stampId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "stampId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "stampId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif