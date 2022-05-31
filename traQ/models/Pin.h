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
    operator Json::Value() const {
        return this->toJson();
    }
    Pin(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["pinnedAt"] = (pinnedAt);
        _json["message"] = (message.toJson());
        return _json;
    }
    Pin& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        pinnedAt = _json["pinnedAt"].as<std::string>();
        message.fromJson(_json["message"]);
        return *this;
    }
};

}
template <> inline traQApi::Pin Json::Value::as<traQApi::Pin>() const {
    return traQApi::Pin(*this);
};

#endif
