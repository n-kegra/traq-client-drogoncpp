#include "PostLinkExternalAccount.h"

namespace traQ {

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
template <> traQ::PostLinkExternalAccount Json::Value::as<traQ::PostLinkExternalAccount>() const {
    return traQ::PostLinkExternalAccount(*this);
}
