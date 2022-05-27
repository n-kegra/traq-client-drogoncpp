#ifndef _MessageClip_H
#define _MessageClip_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::MessageClip Json::Value::as<traQ::MessageClip>() const { return traQ::MessageClip(*this); }

#endif
