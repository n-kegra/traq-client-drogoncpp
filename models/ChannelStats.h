#ifndef _ChannelStats_H
#define _ChannelStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelStatsStamp.h"
#include "../models/ChannelStatsUser.h"
#include <vector>

namespace traQ {

// チャンネル統計情報
struct ChannelStats {
    int64_t totalMessageCount;
    std::vector<ChannelStatsStamp> stamps;
    std::vector<ChannelStatsUser> users;
    std::string datetime;

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["totalMessageCount"] = (totalMessageCount);
        _json["stamps"] = Helper::toJson(stamps);
        _json["users"] = Helper::toJson(users);
        _json["datetime"] = (datetime);
        return _json;
    }
    ChannelStats& fromJson(const Json::Value& _json) {
        Json::Value _json;
        totalMessageCount = _json["totalMessageCount"].as<int64_t>();
        stamps = _json["stamps"].as<std::vector<ChannelStatsStamp>>();
        users = _json["users"].as<std::vector<ChannelStatsUser>>();
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}

#endif
