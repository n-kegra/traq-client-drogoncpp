#ifndef TRAQ_ActivityApi_H
#define TRAQ_ActivityApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/ActivityTimelineMessage.h>


namespace traQApi {

class ActivityApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ActivityApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    ActivityApi& setBearerToken(std::string _token);
    ActivityApi& setBasicAuth(std::string _username, std::string _password);
    ActivityApi& setApikey(std::string _apikey);


    // アクテビティタイムラインを取得
    std::vector<ActivityTimelineMessage>
    getActivityTimeline(
        const std::optional<int32_t>& _limit, 
        const std::optional<bool>& _all, 
        const std::optional<bool>& _perChannel
    );

    // オンラインユーザーリストを取得
    std::vector<std::string>
    getOnlineUsers(
    );

};

}

#endif
