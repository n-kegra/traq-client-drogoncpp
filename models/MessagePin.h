#ifndef _MessagePin_H
#define _MessagePin_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ピン情報
struct MessagePin {
    std::string userId;
    std::string pinnedAt;

    MessagePin() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    MessagePin(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    MessagePin& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::MessagePin Json::Value::as<traQAPI::MessagePin>() const;

#endif
