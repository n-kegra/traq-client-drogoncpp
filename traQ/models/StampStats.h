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

    Json::Value toJson() const {
        Json::Value _json;
        _json["count"] = (count);
        _json["totalCount"] = (totalCount);
        return _json;
    }
    StampStats& fromJson(const Json::Value& _json) {
        count = _json["count"].as<int64_t>();
        totalCount = _json["totalCount"].as<int64_t>();
        return *this;
    }
};

}
template <> inline traQApi::StampStats Json::Value::as<traQApi::StampStats>() const {
    return traQApi::StampStats(*this);
};

#endif
