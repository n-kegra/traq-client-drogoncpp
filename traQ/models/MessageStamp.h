#ifndef TRAQ_MessageStamp_H
#define TRAQ_MessageStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// メッセージに押されたスタンプ
struct MessageStamp {
    std::string userId;
    std::string stampId;
    int32_t count;
    std::string createdAt;
    std::string updatedAt;

    MessageStamp() = default;
    operator Json::Value() const;
    MessageStamp(const Json::Value& __value);

    Json::Value toJson() const;
    MessageStamp& fromJson(const Json::Value& _json);
};

}
template <> traQApi::MessageStamp Json::Value::as<traQApi::MessageStamp>() const;

#endif
