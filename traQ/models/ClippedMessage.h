#ifndef TRAQ_ClippedMessage_H
#define TRAQ_ClippedMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>

namespace traQApi {

// クリップされたメッセージ
struct ClippedMessage {
    Message message;
    std::string clippedAt;

    ClippedMessage() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ClippedMessage(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["message"] = (message.toJson());
        _json["clippedAt"] = (clippedAt);
        return _json;
    }
    ClippedMessage& fromJson(const Json::Value& _json) {
        message.fromJson(_json["message"]);
        clippedAt = _json["clippedAt"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ClippedMessage Json::Value::as<traQApi::ClippedMessage>() const {
    return traQApi::ClippedMessage(*this);
};

#endif
