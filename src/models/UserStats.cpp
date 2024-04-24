#include <traQ/models/UserStats.h>
#include "../Helper.h"

namespace traQApi {

UserStats::operator Json::Value() const {
    return this->toJson();
}
UserStats::UserStats(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value UserStats::toJson() const {
    Json::Value _json;
    _json["totalMessageCount"] = (totalMessageCount);
    _json["stamps"] = __Helper::toJson(stamps);
    _json["datetime"] = (datetime);
    return _json;
}
UserStats& UserStats::fromJson(const Json::Value& _json) {
    totalMessageCount = _json["totalMessageCount"].as<int64_t>();
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace_back((*_it));    
    }
    datetime = _json["datetime"].as<std::string>();
    return *this;
}

}
template <> traQApi::UserStats Json::Value::as<traQApi::UserStats>() const {
    return traQApi::UserStats(*this);
};
