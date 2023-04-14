#ifndef TRAQ_AuthenticationApi_H
#define TRAQ_AuthenticationApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ExternalProviderUser.h>
#include <traQ/models/LoginSession.h>
#include <traQ/models/PostLinkExternalAccount.h>
#include <traQ/models/PostLoginRequest.h>
#include <traQ/models/PostUnlinkExternalAccount.h>


namespace traQApi {

class AuthenticationApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    AuthenticationApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    AuthenticationApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    AuthenticationApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    AuthenticationApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // 外部ログインアカウント一覧を取得
    auto getMyExternalAccounts(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<ExternalProviderUser> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<ExternalProviderUser>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), std::move(response_object));
    }


    // 自分のログインセッションリストを取得
    auto getMySessions(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<LoginSession> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<LoginSession>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::make_tuple(result, std::move(response), std::move(response_object));
    }


    // 外部ログインアカウントを紐付ける
    auto linkExternalAccount(
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


        return std::make_tuple(result, std::move(response));
    }


    // ログイン
    auto login(
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


        return std::make_tuple(result, std::move(response));
    }


    // ログアウト
    auto logout(
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


        return std::make_tuple(result, std::move(response));
    }


    // セッションを無効化
    auto revokeMySession(
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


        return std::make_tuple(result, std::move(response));
    }


    // 外部ログインアカウントの紐付けを解除
    auto unlinkExternalAccount(
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


        return std::make_tuple(result, std::move(response));
    }


};

}

#endif
