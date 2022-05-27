#ifndef _ChannelStatsUser_H
#define _ChannelStatsUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// チャンネル上の特定ユーザー統計情報
struct ChannelStatsUser {
    std::string id;
    int64_t messageCount;

    ChannelStatsUser() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelStatsUser(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChannelStatsUser& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ChannelStatsUser Json::Value::as<traQAPI::ChannelStatsUser>() const;

#endif
