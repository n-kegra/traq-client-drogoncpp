#ifndef _AuthenticationApi_H
#define _AuthenticationApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ExternalProviderUser.h"
#include "../models/LoginSession.h"
#include "../models/PostLinkExternalAccount.h"
#include "../models/PostLoginRequest.h"
#include "../models/PostUnlinkExternalAccount.h"


namespace traQ {

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
    );


    // 自分のログインセッションリストを取得
    auto getMySessions(
    );


    // 外部ログインアカウントを紐付ける
    auto linkExternalAccount(
        const std::optional<PostLinkExternalAccount>& _postLinkExternalAccount
    );


    // ログイン
    auto login(
        const std::optional<std::string>& _redirect, 
        const std::optional<PostLoginRequest>& _postLoginRequest
    );


    // ログアウト
    auto logout(
        const std::optional<std::string>& _redirect, 
        const std::optional<bool>& _all
    );


    // セッションを無効化
    auto revokeMySession(
        const std::string& _sessionId
    );


    // 外部ログインアカウントの紐付けを解除
    auto unlinkExternalAccount(
        const std::optional<PostUnlinkExternalAccount>& _postUnlinkExternalAccount
    );


};

}

#endif
