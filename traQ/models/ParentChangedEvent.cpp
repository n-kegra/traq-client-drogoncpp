#include <traQ/models/ParentChangedEvent.h>

namespace traQApi {

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
template <> traQApi::ParentChangedEvent Json::Value::as<traQApi::ParentChangedEvent>() const {
    return traQApi::ParentChangedEvent(*this);
}
