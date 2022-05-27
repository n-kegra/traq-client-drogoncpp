#ifndef _Oauth2Api_H
#define _Oauth2Api_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ActiveOAuth2Token.h"
#include "../models/GetClient200Response.h"
#include "../models/OAuth2Client.h"
#include "../models/OAuth2ClientDetail.h"
#include "../models/OAuth2Prompt.h"
#include "../models/OAuth2ResponseType.h"
#include "../models/OAuth2Token.h"
#include "../models/PatchClientRequest.h"
#include "../models/PostClientRequest.h"


namespace traQAPI {

class Oauth2Api {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    Oauth2Api(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    Oauth2Api& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    Oauth2Api& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    Oauth2Api& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // OAuth2クライアントを作成
    auto createClient(
        const std::optional<PostClientRequest>& _postClientRequest
    ){
        Json::Value json;
        if(_postClientRequest.has_value()) {
            json = (_postClientRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/clients";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<OAuth2ClientDetail> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // OAuth2クライアントを削除
    auto deleteClient(
        const std::string& _clientId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/clients/{clientId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_clientId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "clientId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "clientId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // OAuth2クライアント情報を変更
    auto editClient(
        const std::string& _clientId, 
        const std::optional<PatchClientRequest>& _patchClientRequest
    ){
        Json::Value json;
        if(_patchClientRequest.has_value()) {
            json = (_patchClientRequest.value());
        }
        auto req = drogon::HttpRequest::newHttpJsonRequest(json);
        req->setMethod(drogon::HttpMethod::Patch);

        std::string endpoint_path = "/clients/{clientId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_clientId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "clientId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "clientId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // OAuth2クライアント情報を取得
    auto getClient(
        const std::string& _clientId, 
        const std::optional<bool>& _detail
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/clients/{clientId}";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_clientId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "clientId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "clientId" "\\}"), serialized);
        }
        
        if(_detail.has_value()) {
            Json::Value jsonobj = (_detail.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "detail", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<GetClient200Response> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // OAuth2クライアントのリストを取得
    auto getClients(
        const std::optional<bool>& _all
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/clients";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        if(_all.has_value()) {
            Json::Value jsonobj = (_all.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "all", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<OAuth2Client>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<OAuth2Client> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<OAuth2Client>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 有効トークンのリストを取得
    auto getMyTokens(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/users/me/tokens";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<ActiveOAuth2Token>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<ActiveOAuth2Token> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<ActiveOAuth2Token>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // OAuth2 認可エンドポイント
    auto getOAuth2Authorize(
        const std::string& _clientId, 
        const std::optional<OAuth2ResponseType>& _responseType, 
        const std::optional<std::string>& _redirectUri, 
        const std::optional<std::string>& _scope, 
        const std::optional<std::string>& _state, 
        const std::optional<std::string>& _codeChallenge, 
        const std::optional<std::string>& _codeChallengeMethod, 
        const std::optional<std::string>& _nonce, 
        const std::optional<OAuth2Prompt>& _prompt
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/oauth2/authorize";
        std::vector<std::string> query_strs;
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_clientId);
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "clientId", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_responseType.has_value()) {
            Json::Value jsonobj = (_responseType.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "responseType", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_redirectUri.has_value()) {
            Json::Value jsonobj = (_redirectUri.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "redirectUri", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_scope.has_value()) {
            Json::Value jsonobj = (_scope.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "scope", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_state.has_value()) {
            Json::Value jsonobj = (_state.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "state", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_codeChallenge.has_value()) {
            Json::Value jsonobj = (_codeChallenge.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "codeChallenge", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_codeChallengeMethod.has_value()) {
            Json::Value jsonobj = (_codeChallengeMethod.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "codeChallengeMethod", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_nonce.has_value()) {
            Json::Value jsonobj = (_nonce.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "nonce", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        if(_prompt.has_value()) {
            Json::Value jsonobj = (_prompt.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized_list = Helper::serialize_explode(style, "prompt", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // OAuth2 認可エンドポイント
    auto postOAuth2Authorize(
        const std::string& _clientId, 
        const std::optional<OAuth2ResponseType>& _responseType, 
        const std::optional<std::string>& _redirectUri, 
        const std::optional<std::string>& _scope, 
        const std::optional<std::string>& _state, 
        const std::optional<std::string>& _codeChallenge, 
        const std::optional<std::string>& _codeChallengeMethod, 
        const std::optional<std::string>& _nonce, 
        const std::optional<OAuth2Prompt>& _prompt
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/oauth2/authorize";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_clientId);
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "clientId", jsonobj);
            req->setParameter("clientId", serialized);
        }
        
        if(_responseType.has_value()) {
            Json::Value jsonobj = (_responseType.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "responseType", jsonobj);
            req->setParameter("responseType", serialized);
        }
        
        if(_redirectUri.has_value()) {
            Json::Value jsonobj = (_redirectUri.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "redirectUri", jsonobj);
            req->setParameter("redirectUri", serialized);
        }
        
        if(_scope.has_value()) {
            Json::Value jsonobj = (_scope.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "scope", jsonobj);
            req->setParameter("scope", serialized);
        }
        
        if(_state.has_value()) {
            Json::Value jsonobj = (_state.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "state", jsonobj);
            req->setParameter("state", serialized);
        }
        
        if(_codeChallenge.has_value()) {
            Json::Value jsonobj = (_codeChallenge.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "codeChallenge", jsonobj);
            req->setParameter("codeChallenge", serialized);
        }
        
        if(_codeChallengeMethod.has_value()) {
            Json::Value jsonobj = (_codeChallengeMethod.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "codeChallengeMethod", jsonobj);
            req->setParameter("codeChallengeMethod", serialized);
        }
        
        if(_nonce.has_value()) {
            Json::Value jsonobj = (_nonce.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "nonce", jsonobj);
            req->setParameter("nonce", serialized);
        }
        
        if(_prompt.has_value()) {
            Json::Value jsonobj = (_prompt.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "prompt", jsonobj);
            req->setParameter("prompt", serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // OAuth2 認可承諾API
    auto postOAuth2AuthorizeDecide(
        const std::string& _submit
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/oauth2/authorize/decide";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_submit);
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "submit", jsonobj);
            req->setParameter("submit", serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // OAuth2 トークンエンドポイント
    auto postOAuth2Token(
        const std::string& _grantType, 
        const std::optional<std::string>& _code, 
        const std::optional<std::string>& _redirectUri, 
        const std::optional<std::string>& _clientId, 
        const std::optional<std::string>& _codeVerifier, 
        const std::optional<std::string>& _username, 
        const std::optional<std::string>& _password, 
        const std::optional<std::string>& _scope, 
        const std::optional<std::string>& _refreshToken, 
        const std::optional<std::string>& _clientSecret
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/oauth2/token";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_grantType);
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "grantType", jsonobj);
            req->setParameter("grantType", serialized);
        }
        
        if(_code.has_value()) {
            Json::Value jsonobj = (_code.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "code", jsonobj);
            req->setParameter("code", serialized);
        }
        
        if(_redirectUri.has_value()) {
            Json::Value jsonobj = (_redirectUri.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "redirectUri", jsonobj);
            req->setParameter("redirectUri", serialized);
        }
        
        if(_clientId.has_value()) {
            Json::Value jsonobj = (_clientId.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "clientId", jsonobj);
            req->setParameter("clientId", serialized);
        }
        
        if(_codeVerifier.has_value()) {
            Json::Value jsonobj = (_codeVerifier.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "codeVerifier", jsonobj);
            req->setParameter("codeVerifier", serialized);
        }
        
        if(_username.has_value()) {
            Json::Value jsonobj = (_username.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "username", jsonobj);
            req->setParameter("username", serialized);
        }
        
        if(_password.has_value()) {
            Json::Value jsonobj = (_password.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "password", jsonobj);
            req->setParameter("password", serialized);
        }
        
        if(_scope.has_value()) {
            Json::Value jsonobj = (_scope.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "scope", jsonobj);
            req->setParameter("scope", serialized);
        }
        
        if(_refreshToken.has_value()) {
            Json::Value jsonobj = (_refreshToken.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "refreshToken", jsonobj);
            req->setParameter("refreshToken", serialized);
        }
        
        if(_clientSecret.has_value()) {
            Json::Value jsonobj = (_clientSecret.value());
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "clientSecret", jsonobj);
            req->setParameter("clientSecret", serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<OAuth2Token> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // トークンの認可を取り消す
    auto revokeMyToken(
        const std::string& _tokenId
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Delete);

        std::string endpoint_path = "/users/me/tokens/{tokenId}";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_tokenId);
            constexpr auto style = Helper::SerializeStyle::simple;
            auto serialized = Helper::serialize(style, "tokenId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tokenId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // OAuth2 トークン無効化エンドポイント
    auto revokeOAuth2Token(
        const std::string& _token
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Post);

        std::string endpoint_path = "/oauth2/revoke";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        {
            Json::Value jsonobj = (_token);
            constexpr auto style = Helper::SerializeStyle::form;
            auto serialized = Helper::serialize(style, "token", jsonobj);
            req->setParameter("token", serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


};

}

#endif
