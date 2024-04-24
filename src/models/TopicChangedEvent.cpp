#include <traQ/models/TopicChangedEvent.h>
#include "../Helper.h"

namespace traQApi {

TopicChangedEvent::operator Json::Value() const {
    return this->toJson();
}
TopicChangedEvent::TopicChangedEvent(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::TopicChangedEvent Json::Value::as<traQApi::TopicChangedEvent>() const {
    return traQApi::TopicChangedEvent(*this);
};
