#include "PostUnlinkExternalAccount.h"

namespace traQ {

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
template <> traQ::PostUnlinkExternalAccount Json::Value::as<traQ::PostUnlinkExternalAccount>() const {
    return traQ::PostUnlinkExternalAccount(*this);
}
