#ifndef TRAQ_UserStatsStamp_H
#define TRAQ_UserStatsStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーの特定スタンプ統計情報
struct UserStatsStamp {
    std::string id;
    int64_t count;
    int64_t total;

    UserStatsStamp() = default;
    operator Json::Value() const;
    UserStatsStamp(const Json::Value& __value);

    Json::Value toJson() const;
    UserStatsStamp& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserStatsStamp Json::Value::as<traQApi::UserStatsStamp>() const;

#endif
