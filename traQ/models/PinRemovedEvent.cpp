#include <traQ/models/PinRemovedEvent.h>

namespace traQApi {

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
template <> traQApi::PinRemovedEvent Json::Value::as<traQApi::PinRemovedEvent>() const {
    return traQApi::PinRemovedEvent(*this);
}
