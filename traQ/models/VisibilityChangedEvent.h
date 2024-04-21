#ifndef TRAQ_VisibilityChangedEvent_H
#define TRAQ_VisibilityChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// チャンネル可視状態変更イベント
struct VisibilityChangedEvent {
    std::string userId;
    bool visibility;

    VisibilityChangedEvent() = default;
    operator Json::Value() const;
    VisibilityChangedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    VisibilityChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::VisibilityChangedEvent Json::Value::as<traQApi::VisibilityChangedEvent>() const;

#endif
