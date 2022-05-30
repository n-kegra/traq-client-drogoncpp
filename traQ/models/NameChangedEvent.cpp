#include <traQ/models/NameChangedEvent.h>

namespace traQApi {

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
template <> traQApi::NameChangedEvent Json::Value::as<traQApi::NameChangedEvent>() const {
    return traQApi::NameChangedEvent(*this);
}
