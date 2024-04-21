#include <traQ/models/PostUserGroupRequest.h>

namespace traQApi {

PostUserGroupRequest::operator Json::Value() const {
    return this->toJson();
}
PostUserGroupRequest::PostUserGroupRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PostUserGroupRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["type"] = (type);
    return _json;
}
PostUserGroupRequest& PostUserGroupRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    type = _json["type"].as<std::string>();
    return *this;
}

}
template <> traQApi::PostUserGroupRequest Json::Value::as<traQApi::PostUserGroupRequest>() const {
    return traQApi::PostUserGroupRequest(*this);
};
