#include "StampStats.h"

namespace traQ {

Json::Value StampStats::toJson() const {
    Json::Value _json;
    _json["count"] = (count);
    _json["totalCount"] = (totalCount);
    return _json;
}
StampStats& StampStats::fromJson(const Json::Value& _json) {
    count = _json["count"].as<int64_t>();
    totalCount = _json["totalCount"].as<int64_t>();
    return *this;
}

}
template <> traQ::StampStats Json::Value::as<traQ::StampStats>() const {
    return traQ::StampStats(*this);
}
