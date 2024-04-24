#include <traQ/models/UserStatsStamp.h>
#include "../Helper.h"

namespace traQApi {

UserStatsStamp::operator Json::Value() const {
    return this->toJson();
}
UserStatsStamp::UserStatsStamp(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::UserStatsStamp Json::Value::as<traQApi::UserStatsStamp>() const {
    return traQApi::UserStatsStamp(*this);
};
