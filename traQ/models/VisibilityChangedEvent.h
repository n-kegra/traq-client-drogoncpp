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
    operator Json::Value() const {
        return this->toJson();
    }
    VisibilityChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["visibility"] = (visibility);
        return _json;
    }
    VisibilityChangedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        visibility = _json["visibility"].as<bool>();
        return *this;
    }
};

}
template <> inline traQApi::VisibilityChangedEvent Json::Value::as<traQApi::VisibilityChangedEvent>() const {
    return traQApi::VisibilityChangedEvent(*this);
};

#endif
