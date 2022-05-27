#include "VersionFlags.h"

namespace traQ {

Json::Value VersionFlags::toJson() const {
    Json::Value _json;
    _json["externalLogin"] = Helper::toJson(externalLogin);
    _json["signUpAllowed"] = (signUpAllowed);
    return _json;
}
VersionFlags& VersionFlags::fromJson(const Json::Value& _json) {
    for (auto _it = _json["externalLogin"].begin(); _it != _json["externalLogin"].end(); _it++) {
        externalLogin.emplace_back((*_it).as<std::string>());    
    }
    signUpAllowed = _json["signUpAllowed"].as<bool>();
    return *this;
}

}
template <> traQ::VersionFlags Json::Value::as<traQ::VersionFlags>() const {
    return traQ::VersionFlags(*this);
}
