#include "ChannelTopic.h"

namespace traQAPI {

Json::Value ChannelTopic::toJson() const {
    Json::Value _json;
    _json["topic"] = (topic);
    return _json;
}
ChannelTopic& ChannelTopic::fromJson(const Json::Value& _json) {
    topic = _json["topic"].as<std::string>();
    return *this;
}

}
template <> traQAPI::ChannelTopic Json::Value::as<traQAPI::ChannelTopic>() const {
    return traQAPI::ChannelTopic(*this);
}
