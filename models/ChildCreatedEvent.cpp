#include "ChildCreatedEvent.h"

namespace traQAPI {

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
template <> traQAPI::ChildCreatedEvent Json::Value::as<traQAPI::ChildCreatedEvent>() const {
    return traQAPI::ChildCreatedEvent(*this);
}
