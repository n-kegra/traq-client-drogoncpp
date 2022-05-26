#ifndef _MyUserDetail_H
#define _MyUserDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserAccountState.h"
#include "../models/UserPermission.h"
#include "../models/UserTag.h"
#include <vector>

namespace traQ {

// 自分のユーザー詳細情報
struct MyUserDetail {
    std::string id;
    std::string bio;
    std::vector<std::string> groups;
    std::vector<UserTag> tags;
    std::string updatedAt;
    std::string lastOnline;
    std::string twitterId;
    std::string name;
    std::string displayName;
    std::string iconFileId;
    bool bot;
    UserAccountState state;
    std::vector<UserPermission> permissions;
    std::string homeChannel;

    operator Json::Value() const {
        return this->toJson();
    }
    MyUserDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["bio"] = (bio);
        _json["groups"] = Helper::toJson(groups);
        _json["tags"] = Helper::toJson(tags);
        _json["updatedAt"] = (updatedAt);
        _json["lastOnline"] = (lastOnline);
        _json["twitterId"] = (twitterId);
        _json["name"] = (name);
        _json["displayName"] = (displayName);
        _json["iconFileId"] = (iconFileId);
        _json["bot"] = (bot);
        _json["state"] = (state);
        _json["permissions"] = Helper::toJson(permissions);
        _json["homeChannel"] = (homeChannel);
        return _json;
    }
    MyUserDetail& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        bio = _json["bio"].as<std::string>();
        groups = _json["groups"].as<std::vector<std::string>>();
        tags = _json["tags"].as<std::vector<UserTag>>();
        updatedAt = _json["updatedAt"].as<std::string>();
        lastOnline = _json["lastOnline"].as<std::string>();
        twitterId = _json["twitterId"].as<std::string>();
        name = _json["name"].as<std::string>();
        displayName = _json["displayName"].as<std::string>();
        iconFileId = _json["iconFileId"].as<std::string>();
        bot = _json["bot"].as<bool>();
        state = _json["state"].as<UserAccountState>();
        permissions = _json["permissions"].as<std::vector<UserPermission>>();
        homeChannel = _json["homeChannel"].as<std::string>();
        return *this;
    }
};

}

#endif
