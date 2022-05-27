#include "TopicChangedEvent.h"

namespace traQAPI {

Json::Value TopicChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["before"] = (before);
    _json["after"] = (after);
    return _json;
}
TopicChangedEvent& TopicChangedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    before = _json["before"].as<std::string>();
    after = _json["after"].as<std::string>();
    return *this;
}

}
template <> traQAPI::TopicChangedEvent Json::Value::as<traQAPI::TopicChangedEvent>() const {
    return traQAPI::TopicChangedEvent(*this);
}
