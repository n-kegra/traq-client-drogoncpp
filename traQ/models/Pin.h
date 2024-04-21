#ifndef TRAQ_Pin_H
#define TRAQ_Pin_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>

namespace traQApi {

// ピン情報(メッセージ本体付き)
struct Pin {
    std::string userId;
    std::string pinnedAt;
    Message message;

    Pin() = default;
    operator Json::Value() const;
    Pin(const Json::Value& __value);

    Json::Value toJson() const;
    Pin& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Pin Json::Value::as<traQApi::Pin>() const;

#endif
