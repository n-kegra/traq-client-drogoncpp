#include "GetNotifyCitation.h"

namespace traQAPI {

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
template <> traQAPI::GetNotifyCitation Json::Value::as<traQAPI::GetNotifyCitation>() const {
    return traQAPI::GetNotifyCitation(*this);
}
