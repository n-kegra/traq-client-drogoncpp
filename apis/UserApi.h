#ifndef _UserApi_H
#define _UserApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/DMChannel.h"
#include "../models/Message.h"
#include "../models/PatchUserRequest.h"
#include "../models/PatchUserTagRequest.h"
#include "../models/PostMessageRequest.h"
#include "../models/PostUserRequest.h"
#include "../models/PostUserTagRequest.h"
#include "../models/PutUserPasswordRequest.h"
#include "../models/User.h"
#include "../models/UserDetail.h"
#include "../models/UserStats.h"
#include "../models/UserTag.h"


namespace traQ {

class UserApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    UserApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    UserApi& setBearerToken(std::string _token) { this->bearer_token = _token; }
    UserApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; }
    UserApi& setApikey(std::string _apikey) { this->apikey = _apikey; }


    // ユーザーにタグを追加
    auto addUserTag(
        const std::string& _userId, 
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    ){
        Json::Value json;
        if(_postUserTagRequest.has_value()) {
            json["postUserTagRequest"] = (_postUserTagRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/users/{userId}/tags";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserTag> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーのアイコン画像を変更します
    auto changeUserIcon(
        const std::string& _userId, 
        const drogon::UploadFile& _file
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Put);

        std::string endpoint_path = "/users/{userId}/icon";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーのパスワードを変更
    auto changeUserPassword(
        const std::string& _userId, 
        const std::optional<PutUserPasswordRequest>& _putUserPasswordRequest
    ){
        Json::Value json;
        if(_putUserPasswordRequest.has_value()) {
            json["putUserPasswordRequest"] = (_putUserPasswordRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Put);

        std::string endpoint_path = "/users/{userId}/password";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーを登録
    auto createUser(
        const std::optional<PostUserRequest>& _postUserRequest
    ){
        Json::Value json;
        if(_postUserRequest.has_value()) {
            json["postUserRequest"] = (_postUserRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/users";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserDetail> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザー情報を変更
    auto editUser(
        const std::string& _userId, 
        const std::optional<PatchUserRequest>& _patchUserRequest
    ){
        Json::Value json;
        if(_patchUserRequest.has_value()) {
            json["patchUserRequest"] = (_patchUserRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/users/{userId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーのタグを編集
    auto editUserTag(
        const std::string& _userId, 
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    ){
        Json::Value json;
        if(_patchUserTagRequest.has_value()) {
            json["patchUserTagRequest"] = (_patchUserTagRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/users/{userId}/tags/{tagId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "tagId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
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
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
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
        
        if(_since.has_value()) {
            Json::Value jsonobj = (_since.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "since", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_until.has_value()) {
            Json::Value jsonobj = (_until.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "until", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_inclusive.has_value()) {
            Json::Value jsonobj = (_inclusive.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "inclusive", jsonobj);
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
        std::optional<std::vector<Message>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザー詳細情報を取得
    auto getUser(
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/{userId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserDetail> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // DMチャンネル情報を取得
    auto getUserDMChannel(
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/{userId}/dm-channel";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<DMChannel> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーのアイコン画像を取得
    auto getUserIcon(
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/{userId}/icon";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
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


    // ユーザー統計情報を取得
    auto getUserStats(
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/{userId}/stats";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserStats> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーのタグリストを取得
    auto getUserTags(
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/{userId}/tags";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<UserTag>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーのリストを取得
    auto getUsers(
        const std::optional<bool>& _includeSuspended, 
        const std::optional<std::string>& _name
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        if(_includeSuspended.has_value()) {
            Json::Value jsonobj = (_includeSuspended.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "includeSuspended", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_name.has_value()) {
            Json::Value jsonobj = (_name.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "name", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<User>> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ダイレクトメッセージを送信
    auto postDirectMessage(
        const std::string& _userId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    ){
        Json::Value json;
        if(_postMessageRequest.has_value()) {
            json["postMessageRequest"] = (_postMessageRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/users/{userId}/messages";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<Message> response_object;

        if(response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーからタグを削除します
    auto removeUserTag(
        const std::string& _userId, 
        const std::string& _tagId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/users/{userId}/tags/{tagId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "userId" "}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("{" "tagId" "}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif
