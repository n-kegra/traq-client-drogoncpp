#include <traQ/models/UserSubscribeState.h>

namespace traQApi {

UserSubscribeState::operator Json::Value() const {
    return this->toJson();
}
UserSubscribeState::UserSubscribeState(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::UserSubscribeState Json::Value::as<traQApi::UserSubscribeState>() const {
    return traQApi::UserSubscribeState(*this);
};
