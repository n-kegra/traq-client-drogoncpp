#include "VisibilityChangedEvent.h"

namespace traQAPI {

Json::Value VisibilityChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["visibility"] = (visibility);
    return _json;
}
VisibilityChangedEvent& VisibilityChangedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    visibility = _json["visibility"].as<bool>();
    return *this;
}

}
template <> traQAPI::VisibilityChangedEvent Json::Value::as<traQAPI::VisibilityChangedEvent>() const {
    return traQAPI::VisibilityChangedEvent(*this);
}
