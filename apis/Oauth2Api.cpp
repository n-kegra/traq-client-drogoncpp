#include "Oauth2Api.h"

namespace traQ {

auto Oauth2Api::createClient(
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

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto Oauth2Api::deleteClient(
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

auto Oauth2Api::editClient(
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

auto Oauth2Api::getClient(
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

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto Oauth2Api::getClients(
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

    if(response_json) {
        std::vector<OAuth2Client> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<OAuth2Client>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto Oauth2Api::getMyTokens(
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

    if(response_json) {
        std::vector<ActiveOAuth2Token> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ActiveOAuth2Token>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto Oauth2Api::getOAuth2Authorize(
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

auto Oauth2Api::postOAuth2Authorize(
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

auto Oauth2Api::postOAuth2AuthorizeDecide(
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

auto Oauth2Api::postOAuth2Token(
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

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto Oauth2Api::revokeMyToken(
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

auto Oauth2Api::revokeOAuth2Token(
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


}