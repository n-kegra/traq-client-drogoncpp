#ifndef TRAQ_ChildCreatedEvent_H
#define TRAQ_ChildCreatedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 子チャンネル作成イベント
struct ChildCreatedEvent {
    std::string userId;
    std::string channelId;

    ChildCreatedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChildCreatedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["channelId"] = (channelId);
        return _json;
    }
    ChildCreatedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ChildCreatedEvent Json::Value::as<traQApi::ChildCreatedEvent>() const {
    return traQApi::ChildCreatedEvent(*this);
};

#endif
