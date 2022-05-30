#include <traQ/models/ChannelTopic.h>

namespace traQApi {

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
template <> traQApi::ChannelTopic Json::Value::as<traQApi::ChannelTopic>() const {
    return traQApi::ChannelTopic(*this);
}
