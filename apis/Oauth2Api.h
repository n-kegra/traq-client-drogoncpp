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


namespace traQ {

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
    );


    // OAuth2クライアントを削除
    auto deleteClient(
        const std::string& _clientId
    );


    // OAuth2クライアント情報を変更
    auto editClient(
        const std::string& _clientId, 
        const std::optional<PatchClientRequest>& _patchClientRequest
    );


    // OAuth2クライアント情報を取得
    auto getClient(
        const std::string& _clientId, 
        const std::optional<bool>& _detail
    );


    // OAuth2クライアントのリストを取得
    auto getClients(
        const std::optional<bool>& _all
    );


    // 有効トークンのリストを取得
    auto getMyTokens(
    );


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
    );


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
    );


    // OAuth2 認可承諾API
    auto postOAuth2AuthorizeDecide(
        const std::string& _submit
    );


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
    );


    // トークンの認可を取り消す
    auto revokeMyToken(
        const std::string& _tokenId
    );


    // OAuth2 トークン無効化エンドポイント
    auto revokeOAuth2Token(
        const std::string& _token
    );


};

}

#endif
