#include <traQ/models/PostUserRequest.h>

namespace traQApi {

PostUserRequest::operator Json::Value() const {
    return this->toJson();
}
PostUserRequest::PostUserRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PostUserRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["password"] = (password);
    return _json;
}
PostUserRequest& PostUserRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    password = _json["password"].as<std::string>();
    return *this;
}

}
template <> traQApi::PostUserRequest Json::Value::as<traQApi::PostUserRequest>() const {
    return traQApi::PostUserRequest(*this);
};
