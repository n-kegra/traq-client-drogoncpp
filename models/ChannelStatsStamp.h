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

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelStatsStamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["count"] = (count);
        _json["total"] = (total);
        return _json;
    }
    ChannelStatsStamp& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        count = _json["count"].as<int64_t>();
        total = _json["total"].as<int64_t>();
        return *this;
    }
};

}

#endif
