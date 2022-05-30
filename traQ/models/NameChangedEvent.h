#ifndef TRAQ_NameChangedEvent_H
#define TRAQ_NameChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// チャンネル名変更イベント
struct NameChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

    NameChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    NameChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    NameChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::NameChangedEvent Json::Value::as<traQApi::NameChangedEvent>() const;

#endif