#ifndef _UserTag_H
#define _UserTag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザータグ
struct UserTag {
    std::string tagId;
    std::string tag;
    bool isLocked;
    std::string createdAt;
    std::string updatedAt;

    operator Json::Value() const {
        return this->toJson();
    }
    UserTag(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["tagId"] = (tagId);
        _json["tag"] = (tag);
        _json["isLocked"] = (isLocked);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    UserTag& fromJson(const Json::Value& _json) {
        Json::Value _json;
        tagId = _json["tagId"].as<std::string>();
        tag = _json["tag"].as<std::string>();
        isLocked = _json["isLocked"].as<bool>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}

#endif
