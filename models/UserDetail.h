#ifndef _UserDetail_H
#define _UserDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserAccountState.h"
#include "../models/UserTag.h"
#include <vector>

namespace traQ {

// ユーザー詳細情報
struct UserDetail {
    std::string id;
    UserAccountState state;
    bool bot;
    std::string iconFileId;
    std::string displayName;
    std::string name;
    std::string twitterId;
    std::string lastOnline;
    std::string updatedAt;
    std::vector<UserTag> tags;
    std::vector<std::string> groups;
    std::string bio;
    std::string homeChannel;

    operator Json::Value() const {
        return this->toJson();
    }
    UserDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
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
        _json["tags"] = Helper::toJson(tags);
        _json["groups"] = Helper::toJson(groups);
        _json["bio"] = (bio);
        _json["homeChannel"] = (homeChannel);
        return _json;
    }
    UserDetail& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        state = _json["state"].as<UserAccountState>();
        bot = _json["bot"].as<bool>();
        iconFileId = _json["iconFileId"].as<std::string>();
        displayName = _json["displayName"].as<std::string>();
        name = _json["name"].as<std::string>();
        twitterId = _json["twitterId"].as<std::string>();
        lastOnline = _json["lastOnline"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        tags = _json["tags"].as<std::vector<UserTag>>();
        groups = _json["groups"].as<std::vector<std::string>>();
        bio = _json["bio"].as<std::string>();
        homeChannel = _json["homeChannel"].as<std::string>();
        return *this;
    }
};

}

#endif
