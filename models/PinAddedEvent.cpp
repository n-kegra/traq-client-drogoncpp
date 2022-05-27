#include "PinAddedEvent.h"

namespace traQ {

Json::Value PinAddedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["messageId"] = (messageId);
    return _json;
}
PinAddedEvent& PinAddedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    messageId = _json["messageId"].as<std::string>();
    return *this;
}

}
template <> traQ::PinAddedEvent Json::Value::as<traQ::PinAddedEvent>() const {
    return traQ::PinAddedEvent(*this);
}
