#include <traQ/models/PinAddedEvent.h>
#include "../Helper.h"

namespace traQApi {

PinAddedEvent::operator Json::Value() const {
    return this->toJson();
}
PinAddedEvent::PinAddedEvent(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PinAddedEvent Json::Value::as<traQApi::PinAddedEvent>() const {
    return traQApi::PinAddedEvent(*this);
};
