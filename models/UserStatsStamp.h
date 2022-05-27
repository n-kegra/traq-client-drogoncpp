#ifndef _UserStatsStamp_H
#define _UserStatsStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーの特定スタンプ統計情報
struct UserStatsStamp {
    std::string id;
    int64_t count;
    int64_t total;

    UserStatsStamp() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserStatsStamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserStatsStamp& fromJson(const Json::Value& _json);
};

}
template <> traQ::UserStatsStamp Json::Value::as<traQ::UserStatsStamp>() const;

#endif
