#include "PostUserGroupRequest.h"

namespace traQ {

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
template <> traQ::PostUserGroupRequest Json::Value::as<traQ::PostUserGroupRequest>() const {
    return traQ::PostUserGroupRequest(*this);
}
