#ifndef TRAQ_ChannelStatsStamp_H
#define TRAQ_ChannelStatsStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// チャンネル上の特定スタンプ統計情報
struct ChannelStatsStamp {
    std::string id;
    int64_t count;
    int64_t total;

    ChannelStatsStamp() = default;
    operator Json::Value() const;
    ChannelStatsStamp(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelStatsStamp& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelStatsStamp Json::Value::as<traQApi::ChannelStatsStamp>() const;

#endif
