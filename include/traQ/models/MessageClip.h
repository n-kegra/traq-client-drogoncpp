#ifndef TRAQ_MessageClip_H
#define TRAQ_MessageClip_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// メッセージクリップ
struct MessageClip {
    std::string folderId;
    std::string clippedAt;

    MessageClip() = default;
    operator Json::Value() const;
    MessageClip(const Json::Value& __value);

    Json::Value toJson() const;
    MessageClip& fromJson(const Json::Value& _json);
};

}
template <> traQApi::MessageClip Json::Value::as<traQApi::MessageClip>() const;

#endif
