#include "UserGroup.h"

namespace traQ {

Json::Value UserGroup::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["description"] = (description);
    _json["type"] = (type);
    _json["icon"] = (icon);
    _json["members"] = Helper::toJson(members);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["admins"] = Helper::toJson(admins);
    return _json;
}
UserGroup& UserGroup::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    type = _json["type"].as<std::string>();
    icon = _json["icon"].as<std::string>();
    for (auto _it = _json["members"].begin(); _it != _json["members"].end(); _it++) {
        members.emplace_back((*_it));    
    }
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    for (auto _it = _json["admins"].begin(); _it != _json["admins"].end(); _it++) {
        admins.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQ::UserGroup Json::Value::as<traQ::UserGroup>() const {
    return traQ::UserGroup(*this);
}
