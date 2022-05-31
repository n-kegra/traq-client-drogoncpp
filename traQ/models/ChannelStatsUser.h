#ifndef TRAQ_ChannelStatsUser_H
#define TRAQ_ChannelStatsUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["messageCount"] = (messageCount);
        return _json;
    }
    ChannelStatsUser& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        messageCount = _json["messageCount"].as<int64_t>();
        return *this;
    }
};

}
template <> inline traQApi::ChannelStatsUser Json::Value::as<traQApi::ChannelStatsUser>() const {
    return traQApi::ChannelStatsUser(*this);
};

#endif
