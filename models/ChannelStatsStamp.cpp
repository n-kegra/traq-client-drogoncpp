#include "ChannelStatsStamp.h"

namespace traQ {

Json::Value ChannelStatsStamp::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["count"] = (count);
    _json["total"] = (total);
    return _json;
}
ChannelStatsStamp& ChannelStatsStamp::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    count = _json["count"].as<int64_t>();
    total = _json["total"].as<int64_t>();
    return *this;
}

}
template <> traQ::ChannelStatsStamp Json::Value::as<traQ::ChannelStatsStamp>() const {
    return traQ::ChannelStatsStamp(*this);
}
