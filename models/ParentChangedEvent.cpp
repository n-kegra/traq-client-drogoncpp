#include "ParentChangedEvent.h"

namespace traQ {

Json::Value ParentChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["before"] = (before);
    _json["after"] = (after);
    return _json;
}
ParentChangedEvent& ParentChangedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    before = _json["before"].as<std::string>();
    after = _json["after"].as<std::string>();
    return *this;
}

}
template <> traQ::ParentChangedEvent Json::Value::as<traQ::ParentChangedEvent>() const {
    return traQ::ParentChangedEvent(*this);
}
