#ifndef TRAQ_MessageClip_H
#define TRAQ_MessageClip_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// メッセージクリップ
struct MessageClip {
    std::string folderId;
    std::string clippedAt;

    MessageClip() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    MessageClip(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["folderId"] = (folderId);
        _json["clippedAt"] = (clippedAt);
        return _json;
    }
    MessageClip& fromJson(const Json::Value& _json) {
        folderId = _json["folderId"].as<std::string>();
        clippedAt = _json["clippedAt"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::MessageClip Json::Value::as<traQApi::MessageClip>() const {
    return traQApi::MessageClip(*this);
};

#endif
