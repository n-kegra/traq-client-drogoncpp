#include "PinRemovedEvent.h"

namespace traQ {

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
template <> traQ::PinRemovedEvent Json::Value::as<traQ::PinRemovedEvent>() const {
    return traQ::PinRemovedEvent(*this);
}
