#include <traQ/models/UserDetail.h>

namespace traQApi {

UserDetail::operator Json::Value() const {
    return this->toJson();
}
UserDetail::UserDetail(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value UserDetail::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["state"] = (state);
    _json["bot"] = (bot);
    _json["iconFileId"] = (iconFileId);
    _json["displayName"] = (displayName);
    _json["name"] = (name);
    _json["twitterId"] = (twitterId);
    _json["lastOnline"] = (lastOnline);
    _json["updatedAt"] = (updatedAt);
    _json["tags"] = __Helper::toJson(tags);
    _json["groups"] = __Helper::toJson(groups);
    _json["bio"] = (bio);
    _json["homeChannel"] = (homeChannel);
    return _json;
}
UserDetail& UserDetail::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    state = _json["state"].as<UserAccountState>();
    bot = _json["bot"].as<bool>();
    iconFileId = _json["iconFileId"].as<std::string>();
    displayName = _json["displayName"].as<std::string>();
    name = _json["name"].as<std::string>();
    twitterId = _json["twitterId"].as<std::string>();
    lastOnline = _json["lastOnline"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    for (auto _it = _json["tags"].begin(); _it != _json["tags"].end(); _it++) {
        tags.emplace_back((*_it));    
    }
    for (auto _it = _json["groups"].begin(); _it != _json["groups"].end(); _it++) {
        groups.emplace_back((*_it).as<std::string>());    
    }
    bio = _json["bio"].as<std::string>();
    homeChannel = _json["homeChannel"].as<std::string>();
    return *this;
}

}
template <> traQApi::UserDetail Json::Value::as<traQApi::UserDetail>() const {
    return traQApi::UserDetail(*this);
};
