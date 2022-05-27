#include "PostUnlinkExternalAccount.h"

namespace traQAPI {

Json::Value PostUnlinkExternalAccount::toJson() const {
    Json::Value _json;
    _json["providerName"] = (providerName);
    return _json;
}
PostUnlinkExternalAccount& PostUnlinkExternalAccount::fromJson(const Json::Value& _json) {
    providerName = _json["providerName"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostUnlinkExternalAccount Json::Value::as<traQAPI::PostUnlinkExternalAccount>() const {
    return traQAPI::PostUnlinkExternalAccount(*this);
}
