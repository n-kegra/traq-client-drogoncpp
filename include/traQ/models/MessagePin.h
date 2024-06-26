#ifndef TRAQ_MessagePin_H
#define TRAQ_MessagePin_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ピン情報
struct MessagePin {
    std::string userId;
    std::string pinnedAt;

    MessagePin() = default;
    operator Json::Value() const;
    MessagePin(const Json::Value& __value);

    Json::Value toJson() const;
    MessagePin& fromJson(const Json::Value& _json);
};

}
template <> traQApi::MessagePin Json::Value::as<traQApi::MessagePin>() const;

#endif
