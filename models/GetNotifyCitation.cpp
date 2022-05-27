#include "GetNotifyCitation.h"

namespace traQ {

Json::Value GetNotifyCitation::toJson() const {
    Json::Value _json;
    _json["notifyCitation"] = (notifyCitation);
    return _json;
}
GetNotifyCitation& GetNotifyCitation::fromJson(const Json::Value& _json) {
    notifyCitation = _json["notifyCitation"].as<bool>();
    return *this;
}

}
template <> traQ::GetNotifyCitation Json::Value::as<traQ::GetNotifyCitation>() const {
    return traQ::GetNotifyCitation(*this);
}
