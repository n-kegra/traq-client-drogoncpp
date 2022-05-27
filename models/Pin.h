#ifndef _Pin_H
#define _Pin_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"

namespace traQAPI {

// ピン情報(メッセージ本体付き)
struct Pin {
    std::string userId;
    std::string pinnedAt;
    Message message;

    Pin() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Pin(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    Pin& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Pin Json::Value::as<traQAPI::Pin>() const;

#endif
