#include "ChannelStatsUser.h"

namespace traQ {

Json::Value ChannelStatsUser::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["messageCount"] = (messageCount);
    return _json;
}
ChannelStatsUser& ChannelStatsUser::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    messageCount = _json["messageCount"].as<int64_t>();
    return *this;
}

}
template <> traQ::ChannelStatsUser Json::Value::as<traQ::ChannelStatsUser>() const {
    return traQ::ChannelStatsUser(*this);
}
