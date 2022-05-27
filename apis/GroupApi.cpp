#include "GroupApi.h"

namespace traQ {

auto GroupApi::addUserGroupAdmin(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::addUserGroupMember(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::changeUserGroupIcon(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::createUserGroup(
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

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto GroupApi::deleteUserGroup(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::editUserGroup(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::editUserGroupMember(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_userId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::getUserGroup(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<UserGroup> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto GroupApi::getUserGroupAdmins(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<std::string>> response_object;

    if(response_json) {
        std::vector<std::string> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<std::string>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto GroupApi::getUserGroupMembers(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<UserGroupMember>> response_object;

    if(response_json) {
        std::vector<UserGroupMember> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserGroupMember>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto GroupApi::getUserGroups(
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

    if(response_json) {
        std::vector<UserGroup> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserGroup>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto GroupApi::removeUserGroupAdmin(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_userId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto GroupApi::removeUserGroupMember(
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
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "groupId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "groupId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_userId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}


}
