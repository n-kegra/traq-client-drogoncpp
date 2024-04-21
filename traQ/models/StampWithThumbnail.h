#ifndef TRAQ_StampWithThumbnail_H
#define TRAQ_StampWithThumbnail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ情報とサムネイルの有無
struct StampWithThumbnail {
    std::string id;
    std::string name;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string fileId;
    bool isUnicode;
    bool hasThumbnail;

    StampWithThumbnail() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    StampWithThumbnail(const Json::Value& __value) {
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
        _json["hasThumbnail"] = (hasThumbnail);
        return _json;
    }
    StampWithThumbnail& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        creatorId = _json["creatorId"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        fileId = _json["fileId"].as<std::string>();
        isUnicode = _json["isUnicode"].as<bool>();
        hasThumbnail = _json["hasThumbnail"].as<bool>();
        return *this;
    }
};

}
template <> inline traQApi::StampWithThumbnail Json::Value::as<traQApi::StampWithThumbnail>() const {
    return traQApi::StampWithThumbnail(*this);
};

#endif
