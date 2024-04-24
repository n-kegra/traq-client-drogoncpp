#ifndef TRAQ_Oauth2Api_H
#define TRAQ_Oauth2Api_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/ActiveOAuth2Token.h>
#include <traQ/models/GetClient200Response.h>
#include <traQ/models/OAuth2Client.h>
#include <traQ/models/OAuth2ClientDetail.h>
#include <traQ/models/OAuth2Prompt.h>
#include <traQ/models/OAuth2ResponseType.h>
#include <traQ/models/OAuth2Token.h>
#include <traQ/models/PatchClientRequest.h>
#include <traQ/models/PostClientRequest.h>


namespace traQApi {

class Oauth2Api {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    Oauth2Api(std::string baseurl = "https://q.trap.jp/api/v3");
    
    Oauth2Api& setBearerToken(std::string _token);
    Oauth2Api& setBasicAuth(std::string _username, std::string _password);
    Oauth2Api& setApikey(std::string _apikey);


    // OAuth2クライアントを作成
    OAuth2ClientDetail
    createClient(
        const std::optional<PostClientRequest>& _postClientRequest
    );

    // OAuth2クライアントを削除
    void
    deleteClient(
        const std::string& _clientId
    );

    // OAuth2クライアント情報を変更
    void
    editClient(
        const std::string& _clientId, 
        const std::optional<PatchClientRequest>& _patchClientRequest
    );

    // OAuth2クライアント情報を取得
    GetClient200Response
    getClient(
        const std::string& _clientId, 
        const std::optional<bool>& _detail
    );

    // OAuth2クライアントのリストを取得
    std::vector<OAuth2Client>
    getClients(
        const std::optional<bool>& _all
    );

    // 有効トークンのリストを取得
    std::vector<ActiveOAuth2Token>
    getMyTokens(
    );

    // OAuth2 認可エンドポイント
    void
    getOAuth2Authorize(
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
    void
    postOAuth2Authorize(
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
    void
    postOAuth2AuthorizeDecide(
        const std::string& _submit
    );

    // OAuth2 トークンエンドポイント
    OAuth2Token
    postOAuth2Token(
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
    void
    revokeMyToken(
        const std::string& _tokenId
    );

    // OAuth2 トークン無効化エンドポイント
    void
    revokeOAuth2Token(
        const std::string& _token
    );

};

}

#endif
