#include <traQ/models/PatchMeRequest.h>

namespace traQApi {

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
}