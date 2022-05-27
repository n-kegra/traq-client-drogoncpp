#include "ExternalProviderUser.h"

namespace traQAPI {

Json::Value ExternalProviderUser::toJson() const {
    Json::Value _json;
    _json["providerName"] = (providerName);
    _json["linkedAt"] = (linkedAt);
    _json["externalName"] = (externalName);
    return _json;
}
ExternalProviderUser& ExternalProviderUser::fromJson(const Json::Value& _json) {
    providerName = _json["providerName"].as<std::string>();
    linkedAt = _json["linkedAt"].as<std::string>();
    externalName = _json["externalName"].as<std::string>();
    return *this;
}

}
template <> traQAPI::ExternalProviderUser Json::Value::as<traQAPI::ExternalProviderUser>() const {
    return traQAPI::ExternalProviderUser(*this);
}
