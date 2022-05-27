#include "UserGroupMember.h"

namespace traQ {

Json::Value UserGroupMember::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["role"] = (role);
    return _json;
}
UserGroupMember& UserGroupMember::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    role = _json["role"].as<std::string>();
    return *this;
}

}
template <> traQ::UserGroupMember Json::Value::as<traQ::UserGroupMember>() const {
    return traQ::UserGroupMember(*this);
}
