#include "UnreadChannel.h"

namespace traQ {

Json::Value UnreadChannel::toJson() const {
    Json::Value _json;
    _json["channelId"] = (channelId);
    _json["count"] = (count);
    _json["noticeable"] = (noticeable);
    _json["since"] = (since);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
UnreadChannel& UnreadChannel::fromJson(const Json::Value& _json) {
    channelId = _json["channelId"].as<std::string>();
    count = _json["count"].as<int32_t>();
    noticeable = _json["noticeable"].as<bool>();
    since = _json["since"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQ::UnreadChannel Json::Value::as<traQ::UnreadChannel>() const {
    return traQ::UnreadChannel(*this);
}
