#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <traQ/Helper.h>
#include "UserTagApi.h"

#include <traQ/models/PatchUserTagRequest.h>
#include <traQ/models/PostUserTagRequest.h>
#include <traQ/models/Tag.h>
#include <traQ/models/UserTag.h>


namespace traQApi {

UserTagApi::UserTagApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("UserTagApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

UserTagApi& UserTagApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
UserTagApi& UserTagApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
UserTagApi& UserTagApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


UserTag
UserTagApi::addMyUserTag(
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return UserTag(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


UserTag
UserTagApi::addUserTag(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return UserTag(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


void
UserTagApi::editMyUserTag(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
UserTagApi::editUserTag(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_tagId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


std::vector<UserTag>
UserTagApi::getMyUserTags(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/tags";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<UserTag> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserTag>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


Tag
UserTagApi::getTag(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return Tag(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<UserTag>
UserTagApi::getUserTags(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<UserTag> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserTag>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


void
UserTagApi::removeMyUserTag(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
UserTagApi::removeUserTag(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "userId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "userId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_tagId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


}
