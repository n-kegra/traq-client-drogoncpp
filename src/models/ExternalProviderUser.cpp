#include <traQ/models/ExternalProviderUser.h>
#include "../Helper.h"

namespace traQApi {

ExternalProviderUser::operator Json::Value() const {
    return this->toJson();
}
ExternalProviderUser::ExternalProviderUser(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::ExternalProviderUser Json::Value::as<traQApi::ExternalProviderUser>() const {
    return traQApi::ExternalProviderUser(*this);
};
