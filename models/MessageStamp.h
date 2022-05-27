#ifndef _MessageStamp_H
#define _MessageStamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["stampId"] = (stampId);
        _json["count"] = (count);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    MessageStamp& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        stampId = _json["stampId"].as<std::string>();
        count = _json["count"].as<int32_t>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::MessageStamp Json::Value::as<traQ::MessageStamp>() const { return traQ::MessageStamp(*this); }

#endif
