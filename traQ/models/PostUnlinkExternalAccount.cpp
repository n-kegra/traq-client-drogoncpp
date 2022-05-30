#include <traQ/models/PostUnlinkExternalAccount.h>

namespace traQApi {

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
template <> traQApi::PostUnlinkExternalAccount Json::Value::as<traQApi::PostUnlinkExternalAccount>() const {
    return traQApi::PostUnlinkExternalAccount(*this);
}
