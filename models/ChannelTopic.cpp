#include "ChannelTopic.h"

namespace traQ {

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
template <> traQ::ChannelTopic Json::Value::as<traQ::ChannelTopic>() const {
    return traQ::ChannelTopic(*this);
}
