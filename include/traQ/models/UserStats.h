#ifndef TRAQ_UserStats_H
#define TRAQ_UserStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/UserStatsStamp.h>
#include <vector>

namespace traQApi {

// ユーザー統計情報
struct UserStats {
    int64_t totalMessageCount;
    std::vector<UserStatsStamp> stamps;
    std::string datetime;

    UserStats() = default;
    operator Json::Value() const;
    UserStats(const Json::Value& __value);

    Json::Value toJson() const;
    UserStats& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserStats Json::Value::as<traQApi::UserStats>() const;

#endif
