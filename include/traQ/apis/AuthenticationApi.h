#ifndef TRAQ_AuthenticationApi_H
#define TRAQ_AuthenticationApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

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

    AuthenticationApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    AuthenticationApi& setBearerToken(std::string _token);
    AuthenticationApi& setBasicAuth(std::string _username, std::string _password);
    AuthenticationApi& setApikey(std::string _apikey);


    // 外部ログインアカウント一覧を取得
    std::vector<ExternalProviderUser>
    getMyExternalAccounts(
    );

    // 自分のログインセッションリストを取得
    std::vector<LoginSession>
    getMySessions(
    );

    // 外部ログインアカウントを紐付ける
    void
    linkExternalAccount(
        const std::optional<PostLinkExternalAccount>& _postLinkExternalAccount
    );

    // ログイン
    void
    login(
        const std::optional<std::string>& _redirect, 
        const std::optional<PostLoginRequest>& _postLoginRequest
    );

    // ログアウト
    void
    logout(
        const std::optional<std::string>& _redirect, 
        const std::optional<bool>& _all
    );

    // セッションを無効化
    void
    revokeMySession(
        const std::string& _sessionId
    );

    // 外部ログインアカウントの紐付けを解除
    void
    unlinkExternalAccount(
        const std::optional<PostUnlinkExternalAccount>& _postUnlinkExternalAccount
    );

};

}

#endif
