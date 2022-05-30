#ifndef TRAQ_StampStats_H
#define TRAQ_StampStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ統計情報
struct StampStats {
    int64_t count;
    int64_t totalCount;

    StampStats() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    StampStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    StampStats& fromJson(const Json::Value& _json);
};

}
template <> traQApi::StampStats Json::Value::as<traQApi::StampStats>() const;

#endif
