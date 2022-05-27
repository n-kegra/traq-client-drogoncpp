#include "ChannelEventDetail.h"

namespace traQ {

Json::Value ChannelEventDetail::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["before"] = (before);
    _json["after"] = (after);
    _json["on"] = Helper::toJson(on);
    _json["off"] = Helper::toJson(off);
    _json["messageId"] = (messageId);
    _json["visibility"] = (visibility);
    _json["force"] = (force);
    _json["channelId"] = (channelId);
    return _json;
}
ChannelEventDetail& ChannelEventDetail::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    before = _json["before"].as<std::string>();
    after = _json["after"].as<std::string>();
    for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
        on.emplace_back((*_it).as<std::string>());    
    }
    for (auto _it = _json["off"].begin(); _it != _json["off"].end(); _it++) {
        off.emplace_back((*_it).as<std::string>());    
    }
    messageId = _json["messageId"].as<std::string>();
    visibility = _json["visibility"].as<bool>();
    force = _json["force"].as<bool>();
    channelId = _json["channelId"].as<std::string>();
    return *this;
}

}
template <> traQ::ChannelEventDetail Json::Value::as<traQ::ChannelEventDetail>() const {
    return traQ::ChannelEventDetail(*this);
}
