#ifndef _StarApi_H
#define _StarApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/PostStarRequest.h"


namespace traQ {

class StarApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    StarApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    StarApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    StarApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    StarApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // チャンネルをスターに追加
    auto addMyStar(
        const std::optional<PostStarRequest>& _postStarRequest
    );


    // スターチャンネルリストを取得
    auto getMyStars(
    );


    // チャンネルをスターから削除します
    auto removeMyStar(
        const std::string& _channelId
    );


};

}

#endif
