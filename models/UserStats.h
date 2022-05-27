#ifndef _UserStats_H
#define _UserStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserStatsStamp.h"
#include <vector>

namespace traQAPI {

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

    Json::Value toJson() const;
    UserStats& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::UserStats Json::Value::as<traQAPI::UserStats>() const;

#endif
