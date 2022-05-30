#include <traQ/models/ChannelEvent.h>

namespace traQApi {

Json::Value ChannelEvent::toJson() const {
    Json::Value _json;
    _json["type"] = (type);
    _json["datetime"] = (datetime);
    _json["detail"] = (detail.toJson());
    return _json;
}
ChannelEvent& ChannelEvent::fromJson(const Json::Value& _json) {
    type = _json["type"].as<std::string>();
    datetime = _json["datetime"].as<std::string>();
    detail.fromJson(_json["detail"]);
    return *this;
}

}
template <> traQApi::ChannelEvent Json::Value::as<traQApi::ChannelEvent>() const {
    return traQApi::ChannelEvent(*this);
}
