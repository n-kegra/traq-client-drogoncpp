#ifndef _ClipApi_H
#define _ClipApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ClipFolder.h"
#include "../models/ClippedMessage.h"
#include "../models/MessageClip.h"
#include "../models/PatchClipFolderRequest.h"
#include "../models/PostClipFolderMessageRequest.h"
#include "../models/PostClipFolderRequest.h"


namespace traQ {

class ClipApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ClipApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    ClipApi& setBearerToken(std::string _token) { this->bearer_token = _token; }
    ClipApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; }
    ClipApi& setApikey(std::string _apikey) { this->apikey = _apikey; }


    // メッセージをクリップフォルダに追加
    auto clipMessage(
        const std::string& _folderId, 
        const std::optional<PostClipFolderMessageRequest>& _postClipFolderMessageRequest
    ){
        Json::Value json;
        if(_postClipFolderMessageRequest.has_value()) {
            json["postClipFolderMessageRequest"] = (_postClipFolderMessageRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/clip-folders/{folderId}/messages";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_folderId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "folderId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "folderId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<ClippedMessage> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // クリップフォルダを作成
    auto createClipFolder(
        const std::optional<PostClipFolderRequest>& _postClipFolderRequest
    ){
        Json::Value json;
        if(_postClipFolderRequest.has_value()) {
            json["postClipFolderRequest"] = (_postClipFolderRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/clip-folders";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<ClipFolder> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // クリップフォルダを削除
    auto deleteClipFolder(
        const std::string& _folderId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/clip-folders/{folderId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_folderId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "folderId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "folderId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // クリップフォルダ情報を編集
    auto editClipFolder(
        const std::string& _folderId, 
        const std::optional<PatchClipFolderRequest>& _patchClipFolderRequest
    ){
        Json::Value json;
        if(_patchClipFolderRequest.has_value()) {
            json["patchClipFolderRequest"] = (_patchClipFolderRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/clip-folders/{folderId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_folderId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "folderId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "folderId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // クリップフォルダ情報を取得
    auto getClipFolder(
        const std::string& _folderId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/clip-folders/{folderId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_folderId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "folderId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "folderId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<ClipFolder> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // クリップフォルダのリストを取得
    auto getClipFolders(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/clip-folders";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<ClipFolder>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // フォルダ内のクリップのリストを取得
    auto getClips(
        const std::string& _folderId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _order
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/clip-folders/{folderId}/messages";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_folderId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "folderId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "folderId" "}"), serialized);
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
        
        if(_order.has_value()) {
            Json::Value jsonobj = (_order.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "order", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<ClippedMessage>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
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
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "messageId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<MessageClip>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // メッセージをクリップフォルダから除外
    auto unclipMessage(
        const std::string& _folderId, 
        const std::string& _messageId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/clip-folders/{folderId}/messages/{messageId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_folderId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "folderId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "folderId" "}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_messageId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "messageId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "messageId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif
