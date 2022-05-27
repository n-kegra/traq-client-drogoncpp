#include "PinRemovedEvent.h"

namespace traQAPI {

Json::Value PinRemovedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["messageId"] = (messageId);
    return _json;
}
PinRemovedEvent& PinRemovedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    messageId = _json["messageId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PinRemovedEvent Json::Value::as<traQAPI::PinRemovedEvent>() const {
    return traQAPI::PinRemovedEvent(*this);
}
