#include "PostLinkExternalAccount.h"

namespace traQAPI {

Json::Value PostLinkExternalAccount::toJson() const {
    Json::Value _json;
    _json["providerName"] = (providerName);
    return _json;
}
PostLinkExternalAccount& PostLinkExternalAccount::fromJson(const Json::Value& _json) {
    providerName = _json["providerName"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostLinkExternalAccount Json::Value::as<traQAPI::PostLinkExternalAccount>() const {
    return traQAPI::PostLinkExternalAccount(*this);
}
