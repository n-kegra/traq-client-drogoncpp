#include "UserTag.h"

namespace traQ {

Json::Value UserTag::toJson() const {
    Json::Value _json;
    _json["tagId"] = (tagId);
    _json["tag"] = (tag);
    _json["isLocked"] = (isLocked);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
UserTag& UserTag::fromJson(const Json::Value& _json) {
    tagId = _json["tagId"].as<std::string>();
    tag = _json["tag"].as<std::string>();
    isLocked = _json["isLocked"].as<bool>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQ::UserTag Json::Value::as<traQ::UserTag>() const {
    return traQ::UserTag(*this);
}
