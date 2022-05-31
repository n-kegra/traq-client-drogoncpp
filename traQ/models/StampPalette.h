#ifndef TRAQ_StampPalette_H
#define TRAQ_StampPalette_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

// スタンプパレット情報
struct StampPalette {
    std::string id;
    std::string name;
    std::vector<std::string> stamps;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string description;

    StampPalette() = default;
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
        _json["stamps"] = __Helper::toJson(stamps);
        _json["creatorId"] = (creatorId);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        _json["description"] = (description);
        return _json;
    }
    StampPalette& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
            stamps.emplace_back((*_it).as<std::string>());    
        }
        creatorId = _json["creatorId"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::StampPalette Json::Value::as<traQApi::StampPalette>() const {
    return traQApi::StampPalette(*this);
};

#endif
