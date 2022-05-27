#ifndef _UserTagApi_H
#define _UserTagApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/PatchUserTagRequest.h"
#include "../models/PostUserTagRequest.h"
#include "../models/Tag.h"
#include "../models/UserTag.h"


namespace traQAPI {

class UserTagApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    UserTagApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    UserTagApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    UserTagApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    UserTagApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // 自分にタグを追加
    auto addMyUserTag(
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    ){
        Json::Value json;
        if(_postUserTagRequest.has_value()) {
            json = (_postUserTagRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/users/me/tags";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserTag> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーにタグを追加
    auto addUserTag(
        const std::string& _userId, 
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    ){
        Json::Value json;
        if(_postUserTagRequest.has_value()) {
            json = (_postUserTagRequest.value());
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
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserTag> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分のタグを編集
    auto editMyUserTag(
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    ){
        Json::Value json;
        if(_patchUserTagRequest.has_value()) {
            json = (_patchUserTagRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/users/me/tags/{tagId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
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
            json = (_patchUserTagRequest.value());
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
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // 自分のタグリストを取得
    auto getMyUserTags(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/me/tags";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<UserTag>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserTag> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserTag>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // タグ情報を取得
    auto getTag(
        const std::string& _tagId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/tags/{tagId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<Tag> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
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
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<UserTag>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserTag> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserTag>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分からタグを削除します
    auto removeMyUserTag(
        const std::string& _tagId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/users/me/tags/{tagId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
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
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_tagId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif
