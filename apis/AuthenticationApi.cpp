#include "AuthenticationApi.h"

namespace traQ {

auto AuthenticationApi::getMyExternalAccounts(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/ex-accounts";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<ExternalProviderUser>> response_object;

    if(response_json) {
        std::vector<ExternalProviderUser> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ExternalProviderUser>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto AuthenticationApi::getMySessions(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/sessions";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<LoginSession>> response_object;

    if(response_json) {
        std::vector<LoginSession> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<LoginSession>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto AuthenticationApi::linkExternalAccount(
    const std::optional<PostLinkExternalAccount>& _postLinkExternalAccount
){
    Json::Value json;
    if(_postLinkExternalAccount.has_value()) {
        json = (_postLinkExternalAccount.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/ex-accounts/link";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto AuthenticationApi::login(
    const std::optional<std::string>& _redirect, 
    const std::optional<PostLoginRequest>& _postLoginRequest
){
    Json::Value json;
    if(_postLoginRequest.has_value()) {
        json = (_postLoginRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/login";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_redirect.has_value()) {
        Json::Value jsonobj = (_redirect.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "redirect", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto AuthenticationApi::logout(
    const std::optional<std::string>& _redirect, 
    const std::optional<bool>& _all
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/logout";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_redirect.has_value()) {
        Json::Value jsonobj = (_redirect.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "redirect", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_all.has_value()) {
        Json::Value jsonobj = (_all.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "all", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto AuthenticationApi::revokeMySession(
    const std::string& _sessionId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/sessions/{sessionId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_sessionId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "sessionId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "sessionId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto AuthenticationApi::unlinkExternalAccount(
    const std::optional<PostUnlinkExternalAccount>& _postUnlinkExternalAccount
){
    Json::Value json;
    if(_postUnlinkExternalAccount.has_value()) {
        json = (_postUnlinkExternalAccount.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/ex-accounts/unlink";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}


}
