#ifndef _MessageClip_H
#define _MessageClip_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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

    Json::Value toJson() const;
    MessageClip& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::MessageClip Json::Value::as<traQAPI::MessageClip>() const;

#endif
