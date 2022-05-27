#include "UserStats.h"

namespace traQ {

Json::Value UserStats::toJson() const {
    Json::Value _json;
    _json["totalMessageCount"] = (totalMessageCount);
    _json["stamps"] = Helper::toJson(stamps);
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
template <> traQ::UserStats Json::Value::as<traQ::UserStats>() const {
    return traQ::UserStats(*this);
}
