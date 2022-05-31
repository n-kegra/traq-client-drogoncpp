#ifndef TRAQ_SubscribersChangedEvent_H
#define TRAQ_SubscribersChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

// 購読者変更イベント
struct SubscribersChangedEvent {
    std::string userId;
    std::vector<std::string> on;
    std::vector<std::string> off;

    SubscribersChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    SubscribersChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["on"] = __Helper::toJson(on);
        _json["off"] = __Helper::toJson(off);
        return _json;
    }
    SubscribersChangedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        for (auto _it = _json["off"].begin(); _it != _json["off"].end(); _it++) {
            off.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::SubscribersChangedEvent Json::Value::as<traQApi::SubscribersChangedEvent>() const {
    return traQApi::SubscribersChangedEvent(*this);
};

#endif
