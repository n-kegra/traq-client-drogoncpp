#ifndef _Stamp_H
#define _Stamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// スタンプ情報
struct Stamp {
    std::string id;
    std::string name;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string fileId;
    bool isUnicode;

    operator Json::Value() const {
        return this->toJson();
    }
    Stamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["creatorId"] = (creatorId);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        _json["fileId"] = (fileId);
        _json["isUnicode"] = (isUnicode);
        return _json;
    }
    Stamp& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        creatorId = _json["creatorId"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        fileId = _json["fileId"].as<std::string>();
        isUnicode = _json["isUnicode"].as<bool>();
        return *this;
    }
};

}

#endif
