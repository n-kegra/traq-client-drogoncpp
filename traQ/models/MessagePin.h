#ifndef TRAQ_MessagePin_H
#define TRAQ_MessagePin_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["pinnedAt"] = (pinnedAt);
        return _json;
    }
    MessagePin& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        pinnedAt = _json["pinnedAt"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::MessagePin Json::Value::as<traQApi::MessagePin>() const {
    return traQApi::MessagePin(*this);
};

#endif
