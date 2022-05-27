#ifndef _MessageStamp_H
#define _MessageStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// メッセージに押されたスタンプ
struct MessageStamp {
    std::string userId;
    std::string stampId;
    int32_t count;
    std::string createdAt;
    std::string updatedAt;

    MessageStamp() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    MessageStamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    MessageStamp& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::MessageStamp Json::Value::as<traQAPI::MessageStamp>() const;

#endif
