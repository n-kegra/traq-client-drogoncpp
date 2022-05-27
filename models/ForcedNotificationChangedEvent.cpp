#include "ForcedNotificationChangedEvent.h"

namespace traQAPI {

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
template <> traQAPI::ForcedNotificationChangedEvent Json::Value::as<traQAPI::ForcedNotificationChangedEvent>() const {
    return traQAPI::ForcedNotificationChangedEvent(*this);
}
