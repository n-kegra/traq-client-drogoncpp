#include "PatchUserGroupRequest.h"

namespace traQ {

Json::Value PatchUserGroupRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["type"] = (type);
    return _json;
}
PatchUserGroupRequest& PatchUserGroupRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    type = _json["type"].as<std::string>();
    return *this;
}

}
template <> traQ::PatchUserGroupRequest Json::Value::as<traQ::PatchUserGroupRequest>() const {
    return traQ::PatchUserGroupRequest(*this);
}
