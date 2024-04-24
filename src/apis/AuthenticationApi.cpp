#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include "../Helper.h"
#include <traQ/apis/AuthenticationApi.h>

#include <traQ/models/ExternalProviderUser.h>
#include <traQ/models/LoginSession.h>
#include <traQ/models/PostLinkExternalAccount.h>
#include <traQ/models/PostLoginRequest.h>
#include <traQ/models/PostUnlinkExternalAccount.h>


namespace traQApi {

AuthenticationApi::AuthenticationApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, m, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("AuthenticationApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

AuthenticationApi& AuthenticationApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
AuthenticationApi& AuthenticationApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
AuthenticationApi& AuthenticationApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


std::vector<ExternalProviderUser>
AuthenticationApi::getMyExternalAccounts(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/ex-accounts";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<ExternalProviderUser> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ExternalProviderUser>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


std::vector<LoginSession>
AuthenticationApi::getMySessions(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/sessions";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<LoginSession> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<LoginSession>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


void
AuthenticationApi::linkExternalAccount(
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

}


void
AuthenticationApi::login(
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
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "redirect", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

}


void
AuthenticationApi::logout(
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
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "redirect", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_all.has_value()) {
        Json::Value jsonobj = (_all.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "all", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

}


void
AuthenticationApi::revokeMySession(
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
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "sessionId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "sessionId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
AuthenticationApi::unlinkExternalAccount(
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

}


}
