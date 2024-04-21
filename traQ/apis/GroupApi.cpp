#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <traQ/Helper.h>
#include "GroupApi.h"

#include <traQ/models/PatchGroupMemberRequest.h>
#include <traQ/models/PatchUserGroupRequest.h>
#include <traQ/models/PostUserGroupAdminRequest.h>
#include <traQ/models/PostUserGroupRequest.h>
#include <traQ/models/UserGroup.h>
#include <traQ/models/UserGroupMember.h>


namespace traQApi {

GroupApi::GroupApi(std::string baseurl)
{
    std::smatch m;
    std::regex_match(baseurl, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"));
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

GroupApi& GroupApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
GroupApi& GroupApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
GroupApi& GroupApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


void
GroupApi::addUserGroupAdmin(
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

}


void
GroupApi::addUserGroupMember(
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

}


void
GroupApi::changeUserGroupIcon(
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

}


UserGroup
GroupApi::createUserGroup(
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return UserGroup(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


void
GroupApi::deleteUserGroup(
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

}


void
GroupApi::editUserGroup(
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

}


void
GroupApi::editUserGroupMember(
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

}


UserGroup
GroupApi::getUserGroup(
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return UserGroup(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<std::string>
GroupApi::getUserGroupAdmins(
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<std::string> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<std::string>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<UserGroupMember>
GroupApi::getUserGroupMembers(
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<UserGroupMember> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserGroupMember>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<UserGroup>
GroupApi::getUserGroups(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/groups";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<UserGroup> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserGroup>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


void
GroupApi::removeUserGroupAdmin(
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

}


void
GroupApi::removeUserGroupMember(
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

}


}
