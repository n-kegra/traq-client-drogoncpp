#ifndef TRAQ_ChannelStatsUser_H
#define TRAQ_ChannelStatsUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// チャンネル上の特定ユーザー統計情報
struct ChannelStatsUser {
    std::string id;
    int64_t messageCount;

    ChannelStatsUser() = default;
    operator Json::Value() const;
    ChannelStatsUser(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelStatsUser& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelStatsUser Json::Value::as<traQApi::ChannelStatsUser>() const;

#endif
