#include "ChildCreatedEvent.h"

namespace traQ {

Json::Value ChildCreatedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["channelId"] = (channelId);
    return _json;
}
ChildCreatedEvent& ChildCreatedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    return *this;
}

}
template <> traQ::ChildCreatedEvent Json::Value::as<traQ::ChildCreatedEvent>() const {
    return traQ::ChildCreatedEvent(*this);
}
