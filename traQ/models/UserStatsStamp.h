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
    operator Json::Value() const {
        return this->toJson();
    }
    UserStatsStamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["count"] = (count);
        _json["total"] = (total);
        return _json;
    }
    UserStatsStamp& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        count = _json["count"].as<int64_t>();
        total = _json["total"].as<int64_t>();
        return *this;
    }
};

}
template <> inline traQApi::UserStatsStamp Json::Value::as<traQApi::UserStatsStamp>() const {
    return traQApi::UserStatsStamp(*this);
};

#endif
