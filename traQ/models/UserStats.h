#ifndef TRAQ_UserStats_H
#define TRAQ_UserStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/UserStatsStamp.h>
#include <vector>

namespace traQApi {

// ユーザー統計情報
struct UserStats {
    int64_t totalMessageCount;
    std::vector<UserStatsStamp> stamps;
    std::string datetime;

    UserStats() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["totalMessageCount"] = (totalMessageCount);
        _json["stamps"] = __Helper::toJson(stamps);
        _json["datetime"] = (datetime);
        return _json;
    }
    UserStats& fromJson(const Json::Value& _json) {
        totalMessageCount = _json["totalMessageCount"].as<int64_t>();
        for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
            stamps.emplace_back((*_it));    
        }
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::UserStats Json::Value::as<traQApi::UserStats>() const {
    return traQApi::UserStats(*this);
};

#endif
