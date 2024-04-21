#ifndef TRAQ_ChannelStats_H
#define TRAQ_ChannelStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelStatsStamp.h>
#include <traQ/models/ChannelStatsUser.h>
#include <vector>

namespace traQApi {

// チャンネル統計情報
struct ChannelStats {
    int64_t totalMessageCount;
    std::vector<ChannelStatsStamp> stamps;
    std::vector<ChannelStatsUser> users;
    std::string datetime;

    ChannelStats() = default;
    operator Json::Value() const;
    ChannelStats(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelStats& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelStats Json::Value::as<traQApi::ChannelStats>() const;

#endif
