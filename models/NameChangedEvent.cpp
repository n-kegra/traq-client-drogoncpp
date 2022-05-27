#include "NameChangedEvent.h"

namespace traQAPI {

Json::Value NameChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["before"] = (before);
    _json["after"] = (after);
    return _json;
}
NameChangedEvent& NameChangedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    before = _json["before"].as<std::string>();
    after = _json["after"].as<std::string>();
    return *this;
}

}
template <> traQAPI::NameChangedEvent Json::Value::as<traQAPI::NameChangedEvent>() const {
    return traQAPI::NameChangedEvent(*this);
}
