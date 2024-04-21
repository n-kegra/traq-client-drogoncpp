#include <traQ/models/ChildCreatedEvent.h>

namespace traQApi {

ChildCreatedEvent::operator Json::Value() const {
    return this->toJson();
}
ChildCreatedEvent::ChildCreatedEvent(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ChildCreatedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["channelId"] = (channelId);
    return _json;
}
ChildCreatedEvent& ChildCreatedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    return *this;
}

}
template <> traQApi::ChildCreatedEvent Json::Value::as<traQApi::ChildCreatedEvent>() const {
    return traQApi::ChildCreatedEvent(*this);
};
