#include "PatchUserRequest.h"

namespace traQ {

Json::Value PatchUserRequest::toJson() const {
    Json::Value _json;
    _json["displayName"] = (displayName);
    _json["twitterId"] = (twitterId);
    _json["state"] = (state);
    _json["role"] = (role);
    return _json;
}
PatchUserRequest& PatchUserRequest::fromJson(const Json::Value& _json) {
    displayName = _json["displayName"].as<std::string>();
    twitterId = _json["twitterId"].as<std::string>();
    state = _json["state"].as<UserAccountState>();
    role = _json["role"].as<std::string>();
    return *this;
}

}
template <> traQ::PatchUserRequest Json::Value::as<traQ::PatchUserRequest>() const {
    return traQ::PatchUserRequest(*this);
}
