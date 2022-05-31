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
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["totalMessageCount"] = (totalMessageCount);
        _json["stamps"] = __Helper::toJson(stamps);
        _json["users"] = __Helper::toJson(users);
        _json["datetime"] = (datetime);
        return _json;
    }
    ChannelStats& fromJson(const Json::Value& _json) {
        totalMessageCount = _json["totalMessageCount"].as<int64_t>();
        for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
            stamps.emplace_back((*_it));    
        }
        for (auto _it = _json["users"].begin(); _it != _json["users"].end(); _it++) {
            users.emplace_back((*_it));    
        }
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ChannelStats Json::Value::as<traQApi::ChannelStats>() const {
    return traQApi::ChannelStats(*this);
};

#endif
