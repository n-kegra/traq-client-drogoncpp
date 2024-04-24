#include <traQ/models/PatchMeRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchMeRequest::operator Json::Value() const {
    return this->toJson();
}
PatchMeRequest::PatchMeRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PatchMeRequest::toJson() const {
    Json::Value _json;
    _json["displayName"] = (displayName);
    _json["twitterId"] = (twitterId);
    _json["bio"] = (bio);
    _json["homeChannel"] = (homeChannel);
    return _json;
}
PatchMeRequest& PatchMeRequest::fromJson(const Json::Value& _json) {
    displayName = _json["displayName"].as<std::string>();
    twitterId = _json["twitterId"].as<std::string>();
    bio = _json["bio"].as<std::string>();
    homeChannel = _json["homeChannel"].as<std::string>();
    return *this;
}

}
template <> traQApi::PatchMeRequest Json::Value::as<traQApi::PatchMeRequest>() const {
    return traQApi::PatchMeRequest(*this);
};
