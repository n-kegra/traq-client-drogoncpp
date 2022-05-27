#ifndef _ChannelStatsStamp_H
#define _ChannelStatsStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// チャンネル上の特定スタンプ統計情報
struct ChannelStatsStamp {
    std::string id;
    int64_t count;
    int64_t total;

    ChannelStatsStamp() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelStatsStamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChannelStatsStamp& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChannelStatsStamp Json::Value::as<traQ::ChannelStatsStamp>() const;

#endif
