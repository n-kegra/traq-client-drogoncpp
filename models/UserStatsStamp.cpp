#include "UserStatsStamp.h"

namespace traQ {

Json::Value UserStatsStamp::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["count"] = (count);
    _json["total"] = (total);
    return _json;
}
UserStatsStamp& UserStatsStamp::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    count = _json["count"].as<int64_t>();
    total = _json["total"].as<int64_t>();
    return *this;
}

}
template <> traQ::UserStatsStamp Json::Value::as<traQ::UserStatsStamp>() const {
    return traQ::UserStatsStamp(*this);
}
