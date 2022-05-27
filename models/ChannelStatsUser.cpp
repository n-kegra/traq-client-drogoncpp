#include "ChannelStatsUser.h"

namespace traQAPI {

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
template <> traQAPI::ChannelStatsUser Json::Value::as<traQAPI::ChannelStatsUser>() const {
    return traQAPI::ChannelStatsUser(*this);
}
