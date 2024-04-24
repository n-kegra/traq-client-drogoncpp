#include <traQ/models/PostLoginRequest.h>
#include "../Helper.h"

namespace traQApi {

PostLoginRequest::operator Json::Value() const {
    return this->toJson();
}
PostLoginRequest::PostLoginRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostLoginRequest Json::Value::as<traQApi::PostLoginRequest>() const {
    return traQApi::PostLoginRequest(*this);
};
