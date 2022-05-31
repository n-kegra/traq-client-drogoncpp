#ifndef TRAQ_ClipFolder_H
#define TRAQ_ClipFolder_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// クリップフォルダ情報
struct ClipFolder {
    std::string id;
    std::string name;
    std::string createdAt;
    std::string ownerId;
    std::string description;

    ClipFolder() = default;
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
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        ownerId = _json["ownerId"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ClipFolder Json::Value::as<traQApi::ClipFolder>() const {
    return traQApi::ClipFolder(*this);
};

#endif
