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

    ChannelStats() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChannelStats& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChannelStats Json::Value::as<traQ::ChannelStats>() const;

#endif
