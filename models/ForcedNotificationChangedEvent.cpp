#include "ForcedNotificationChangedEvent.h"

namespace traQ {

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
template <> traQ::ForcedNotificationChangedEvent Json::Value::as<traQ::ForcedNotificationChangedEvent>() const {
    return traQ::ForcedNotificationChangedEvent(*this);
}
