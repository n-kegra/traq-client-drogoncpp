#include <traQ/models/PostLinkExternalAccount.h>

namespace traQApi {

PostLinkExternalAccount::operator Json::Value() const {
    return this->toJson();
}
PostLinkExternalAccount::PostLinkExternalAccount(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostLinkExternalAccount Json::Value::as<traQApi::PostLinkExternalAccount>() const {
    return traQApi::PostLinkExternalAccount(*this);
};
