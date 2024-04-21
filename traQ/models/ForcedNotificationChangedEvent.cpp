#include <traQ/models/ForcedNotificationChangedEvent.h>

namespace traQApi {

ForcedNotificationChangedEvent::operator Json::Value() const {
    return this->toJson();
}
ForcedNotificationChangedEvent::ForcedNotificationChangedEvent(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ForcedNotificationChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["force"] = (force);
    return _json;
}
ForcedNotificationChangedEvent& ForcedNotificationChangedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    force = _json["force"].as<bool>();
    return *this;
}

}
template <> traQApi::ForcedNotificationChangedEvent Json::Value::as<traQApi::ForcedNotificationChangedEvent>() const {
    return traQApi::ForcedNotificationChangedEvent(*this);
};
