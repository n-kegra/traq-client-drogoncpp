#ifndef TRAQ_OgpApi_H
#define TRAQ_OgpApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/Ogp.h>


namespace traQApi {

class OgpApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    OgpApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    OgpApi& setBearerToken(std::string _token);
    OgpApi& setBasicAuth(std::string _username, std::string _password);
    OgpApi& setApikey(std::string _apikey);


    // OGP情報のキャッシュを削除
    void
    deleteOgpCache(
        const std::string& _url
    );

    // OGP情報を取得
    Ogp
    getOgp(
        const std::string& _url
    );

};

}

#endif
