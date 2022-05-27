#include "MyChannelViewState.h"

namespace traQ {

Json::Value MyChannelViewState::toJson() const {
    Json::Value _json;
    _json["key"] = (key);
    _json["channelId"] = (channelId);
    _json["state"] = (state);
    return _json;
}
MyChannelViewState& MyChannelViewState::fromJson(const Json::Value& _json) {
    key = _json["key"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    state = _json["state"].as<ChannelViewState>();
    return *this;
}

}
template <> traQ::MyChannelViewState Json::Value::as<traQ::MyChannelViewState>() const {
    return traQ::MyChannelViewState(*this);
}
