#ifndef TRAQ_PublicApi_H
#define TRAQ_PublicApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/Version.h>


namespace traQApi {

class PublicApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    PublicApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    PublicApi& setBearerToken(std::string _token);
    PublicApi& setBasicAuth(std::string _username, std::string _password);
    PublicApi& setApikey(std::string _apikey);


    // ユーザーのアイコン画像を取得
    drogon::HttpResponsePtr
    getPublicUserIcon(
        const std::string& _username
    );

    // バージョンを取得
    Version
    getServerVersion(
    );

};

}

#endif
