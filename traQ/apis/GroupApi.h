#ifndef TRAQ_GroupApi_H
#define TRAQ_GroupApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/PatchGroupMemberRequest.h>
#include <traQ/models/PatchUserGroupRequest.h>
#include <traQ/models/PostUserGroupAdminRequest.h>
#include <traQ/models/PostUserGroupRequest.h>
#include <traQ/models/UserGroup.h>
#include <traQ/models/UserGroupMember.h>


namespace traQApi {

class GroupApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    GroupApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    GroupApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    GroupApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    GroupApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // グループ管理者を追加
    auto addUserGroupAdmin(
        const std::string& _groupId, 
        const std::optional<PostUserGroupAdminRequest>& _postUserGroupAdminRequest
    ){
        Json::Value json;
        if(_postUserGroupAdminRequest.has_value()) {
            json = (_postUserGroupAdminRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/groups/{groupId}/admins";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // グループメンバーを追加
    auto addUserGroupMember(
        const std::string& _groupId, 
        const std::optional<UserGroupMember>& _userGroupMember
    ){
        Json::Value json;
        if(_userGroupMember.has_value()) {
            json = (_userGroupMember.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/groups/{groupId}/members";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーグループのアイコンを変更
    auto changeUserGroupIcon(
        const std::string& _groupId, 
        const drogon::UploadFile& _file
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Put);

        std::string endpoint_path = "/groups/{groupId}/icon";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーグループを作成
    auto createUserGroup(
        const std::optional<PostUserGroupRequest>& _postUserGroupRequest
    ){
        Json::Value json;
        if(_postUserGroupRequest.has_value()) {
            json = (_postUserGroupRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/groups";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserGroup> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーグループを削除
    auto deleteUserGroup(
        const std::string& _groupId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/groups/{groupId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーグループを編集
    auto editUserGroup(
        const std::string& _groupId, 
        const std::optional<PatchUserGroupRequest>& _patchUserGroupRequest
    ){
        Json::Value json;
        if(_patchUserGroupRequest.has_value()) {
            json = (_patchUserGroupRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/groups/{groupId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // グループメンバーを編集
    auto editUserGroupMember(
        const std::string& _groupId, 
        const std::string& _userId, 
        const std::optional<PatchGroupMemberRequest>& _patchGroupMemberRequest
    ){
        Json::Value json;
        if(_patchGroupMemberRequest.has_value()) {
            json = (_patchGroupMemberRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/groups/{groupId}/members/{userId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // ユーザーグループを取得
    auto getUserGroup(
        const std::string& _groupId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/groups/{groupId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<UserGroup> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // グループ管理者を取得
    auto getUserGroupAdmins(
        const std::string& _groupId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/groups/{groupId}/admins";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
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

        return std::forward_as_tuple(result, response, response_object);
    }


    // グループメンバーを取得
    auto getUserGroupMembers(
        const std::string& _groupId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/groups/{groupId}/members";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<UserGroupMember>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserGroupMember> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserGroupMember>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザーグループのリストを取得
    auto getUserGroups(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/groups";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<UserGroup>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserGroup> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserGroup>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // グループ管理者を削除
    auto removeUserGroupAdmin(
        const std::string& _groupId, 
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/groups/{groupId}/admins/{userId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // グループメンバーを削除
    auto removeUserGroupMember(
        const std::string& _groupId, 
        const std::string& _userId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/groups/{groupId}/members/{userId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_groupId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "groupId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
        }
        
        {
            Json::Value jsonobj = (_userId);
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "userId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif
