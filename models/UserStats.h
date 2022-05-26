#ifndef _UserStats_H
#define _UserStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserStatsStamp.h"
#include <vector>

namespace traQ {

// ユーザー統計情報
struct UserStats {
    int64_t totalMessageCount;
    std::vector<UserStatsStamp> stamps;
    std::string datetime;

    operator Json::Value() const {
        return this->toJson();
    }
    UserStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["totalMessageCount"] = (totalMessageCount);
        _json["stamps"] = Helper::toJson(stamps);
        _json["datetime"] = (datetime);
        return _json;
    }
    UserStats& fromJson(const Json::Value& _json) {
        Json::Value _json;
        totalMessageCount = _json["totalMessageCount"].as<int64_t>();
        stamps = _json["stamps"].as<std::vector<UserStatsStamp>>();
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}

#endif
