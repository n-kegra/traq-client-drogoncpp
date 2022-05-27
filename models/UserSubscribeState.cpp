#include "UserSubscribeState.h"

namespace traQ {

Json::Value UserSubscribeState::toJson() const {
    Json::Value _json;
    _json["channelId"] = (channelId);
    _json["level"] = (level);
    return _json;
}
UserSubscribeState& UserSubscribeState::fromJson(const Json::Value& _json) {
    channelId = _json["channelId"].as<std::string>();
    level = _json["level"].as<ChannelSubscribeLevel>();
    return *this;
}

}
template <> traQ::UserSubscribeState Json::Value::as<traQ::UserSubscribeState>() const {
    return traQ::UserSubscribeState(*this);
}
