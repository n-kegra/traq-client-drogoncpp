#include <traQ/models/NameChangedEvent.h>

namespace traQApi {

NameChangedEvent::operator Json::Value() const {
    return this->toJson();
}
NameChangedEvent::NameChangedEvent(const Json::Value& __value) {
    this->fromJson(__value);
}

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
};
