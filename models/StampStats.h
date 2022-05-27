#ifndef _StampStats_H
#define _StampStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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
template <> traQAPI::StampStats Json::Value::as<traQAPI::StampStats>() const;

#endif
