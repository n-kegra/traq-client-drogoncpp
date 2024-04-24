#include <traQ/models/PatchUserGroupRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchUserGroupRequest::operator Json::Value() const {
    return this->toJson();
}
PatchUserGroupRequest::PatchUserGroupRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PatchUserGroupRequest Json::Value::as<traQApi::PatchUserGroupRequest>() const {
    return traQApi::PatchUserGroupRequest(*this);
};
