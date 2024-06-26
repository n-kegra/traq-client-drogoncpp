#include <traQ/models/UserSettings.h>
#include "../Helper.h"

namespace traQApi {

UserSettings::operator Json::Value() const {
    return this->toJson();
}
UserSettings::UserSettings(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::UserSettings Json::Value::as<traQApi::UserSettings>() const {
    return traQApi::UserSettings(*this);
};
