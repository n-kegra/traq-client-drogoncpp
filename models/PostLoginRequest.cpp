#include "PostLoginRequest.h"

namespace traQAPI {

Json::Value PostLoginRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["password"] = (password);
    return _json;
}
PostLoginRequest& PostLoginRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    password = _json["password"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostLoginRequest Json::Value::as<traQAPI::PostLoginRequest>() const {
    return traQAPI::PostLoginRequest(*this);
}
