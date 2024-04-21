#include <traQ/models/VersionFlags.h>

namespace traQApi {

VersionFlags::operator Json::Value() const {
    return this->toJson();
}
VersionFlags::VersionFlags(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value VersionFlags::toJson() const {
    Json::Value _json;
    _json["externalLogin"] = __Helper::toJson(externalLogin);
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
template <> traQApi::VersionFlags Json::Value::as<traQApi::VersionFlags>() const {
    return traQApi::VersionFlags(*this);
};
