#include <traQ/models/ChannelStatsStamp.h>

namespace traQApi {

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
template <> traQApi::ChannelStatsStamp Json::Value::as<traQApi::ChannelStatsStamp>() const {
    return traQApi::ChannelStatsStamp(*this);
}
