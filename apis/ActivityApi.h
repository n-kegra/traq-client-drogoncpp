#ifndef _ActivityApi_H
#define _ActivityApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ActivityTimelineMessage.h"


namespace traQ {

class ActivityApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ActivityApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    ActivityApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    ActivityApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    ActivityApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // アクテビティタイムラインを取得
    auto getActivityTimeline(
        const std::optional<int32_t>& _limit, 
        const std::optional<bool>& _all, 
        const std::optional<bool>& _perChannel
    );


    // オンラインユーザーリストを取得
    auto getOnlineUsers(
    );


};

}

#endif
