#include <traQ/models/MyUserDetail.h>
#include "../Helper.h"

namespace traQApi {

MyUserDetail::operator Json::Value() const {
    return this->toJson();
}
MyUserDetail::MyUserDetail(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value MyUserDetail::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["bio"] = (bio);
    _json["groups"] = __Helper::toJson(groups);
    _json["tags"] = __Helper::toJson(tags);
    _json["updatedAt"] = (updatedAt);
    _json["lastOnline"] = (lastOnline);
    _json["twitterId"] = (twitterId);
    _json["name"] = (name);
    _json["displayName"] = (displayName);
    _json["iconFileId"] = (iconFileId);
    _json["bot"] = (bot);
    _json["state"] = (state);
    _json["permissions"] = __Helper::toJson(permissions);
    _json["homeChannel"] = (homeChannel);
    return _json;
}
MyUserDetail& MyUserDetail::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    bio = _json["bio"].as<std::string>();
    for (auto _it = _json["groups"].begin(); _it != _json["groups"].end(); _it++) {
        groups.emplace_back((*_it).as<std::string>());    
    }
    for (auto _it = _json["tags"].begin(); _it != _json["tags"].end(); _it++) {
        tags.emplace_back((*_it));    
    }
    updatedAt = _json["updatedAt"].as<std::string>();
    lastOnline = _json["lastOnline"].as<std::string>();
    twitterId = _json["twitterId"].as<std::string>();
    name = _json["name"].as<std::string>();
    displayName = _json["displayName"].as<std::string>();
    iconFileId = _json["iconFileId"].as<std::string>();
    bot = _json["bot"].as<bool>();
    state = _json["state"].as<UserAccountState>();
    for (auto _it = _json["permissions"].begin(); _it != _json["permissions"].end(); _it++) {
        permissions.emplace_back((*_it).as<UserPermission>());    
    }
    homeChannel = _json["homeChannel"].as<std::string>();
    return *this;
}

}
template <> traQApi::MyUserDetail Json::Value::as<traQApi::MyUserDetail>() const {
    return traQApi::MyUserDetail(*this);
};
