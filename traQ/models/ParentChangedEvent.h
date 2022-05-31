#ifndef TRAQ_ParentChangedEvent_H
#define TRAQ_ParentChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 親チャンネル変更イベント
struct ParentChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

    ParentChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ParentChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["before"] = (before);
        _json["after"] = (after);
        return _json;
    }
    ParentChangedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        before = _json["before"].as<std::string>();
        after = _json["after"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ParentChangedEvent Json::Value::as<traQApi::ParentChangedEvent>() const {
    return traQApi::ParentChangedEvent(*this);
};

#endif
