#include "UserSettings.h"

namespace traQAPI {

Json::Value UserSettings::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["notifyCitation"] = (notifyCitation);
    return _json;
}
UserSettings& UserSettings::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    notifyCitation = _json["notifyCitation"].as<bool>();
    return *this;
}

}
template <> traQAPI::UserSettings Json::Value::as<traQAPI::UserSettings>() const {
    return traQAPI::UserSettings(*this);
}
