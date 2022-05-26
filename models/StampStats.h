#ifndef _StampStats_H
#define _StampStats_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// スタンプ統計情報
struct StampStats {
    int64_t count;
    int64_t totalCount;

    operator Json::Value() const {
        return this->toJson();
    }
    StampStats(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["count"] = (count);
        _json["totalCount"] = (totalCount);
        return _json;
    }
    StampStats& fromJson(const Json::Value& _json) {
        Json::Value _json;
        count = _json["count"].as<int64_t>();
        totalCount = _json["totalCount"].as<int64_t>();
        return *this;
    }
};

}

#endif
