#ifndef _ClipFolder_H
#define _ClipFolder_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// クリップフォルダ情報
struct ClipFolder {
    std::string id;
    std::string name;
    std::string createdAt;
    std::string ownerId;
    std::string description;

    operator Json::Value() const {
        return this->toJson();
    }
    ClipFolder(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["createdAt"] = (createdAt);
        _json["ownerId"] = (ownerId);
        _json["description"] = (description);
        return _json;
    }
    ClipFolder& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        ownerId = _json["ownerId"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}

#endif
