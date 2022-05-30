#include <traQ/models/UserGroupMember.h>

namespace traQApi {

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
template <> traQApi::UserGroupMember Json::Value::as<traQApi::UserGroupMember>() const {
    return traQApi::UserGroupMember(*this);
}
