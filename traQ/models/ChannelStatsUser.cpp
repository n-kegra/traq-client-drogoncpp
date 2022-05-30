#include <traQ/models/ChannelStatsUser.h>

namespace traQApi {

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
template <> traQApi::ChannelStatsUser Json::Value::as<traQApi::ChannelStatsUser>() const {
    return traQApi::ChannelStatsUser(*this);
}
