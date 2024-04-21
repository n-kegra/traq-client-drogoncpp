#ifndef TRAQ_StarApi_H
#define TRAQ_StarApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/PostStarRequest.h>


namespace traQApi {

class StarApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    StarApi(std::string _baseurl_host, std::string _baseurl_path);
    
    StarApi& setBearerToken(std::string _token);
    StarApi& setBasicAuth(std::string _username, std::string _password);
    StarApi& setApikey(std::string _apikey);


    // チャンネルをスターに追加
    void
    addMyStar(
        const std::optional<PostStarRequest>& _postStarRequest
    );

    // スターチャンネルリストを取得
    std::vector<std::string>
    getMyStars(
    );

    // チャンネルをスターから削除します
    void
    removeMyStar(
        const std::string& _channelId
    );

};

}

#endif
