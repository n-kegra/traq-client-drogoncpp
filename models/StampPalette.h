#ifndef _StampPalette_H
#define _StampPalette_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// スタンプパレット情報
struct StampPalette {
    std::string id;
    std::string name;
    std::vector<std::string> stamps;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string description;

    operator Json::Value() const {
        return this->toJson();
    }
    StampPalette(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["stamps"] = Helper::toJson(stamps);
        _json["creatorId"] = (creatorId);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        _json["description"] = (description);
        return _json;
    }
    StampPalette& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        stamps = _json["stamps"].as<std::vector<std::string>>();
        creatorId = _json["creatorId"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}

#endif
