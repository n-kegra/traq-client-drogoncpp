#ifndef TRAQ_TopicChangedEvent_H
#define TRAQ_TopicChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// トピック変更イベント
struct TopicChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

    TopicChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    TopicChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["before"] = (before);
        _json["after"] = (after);
        return _json;
    }
    TopicChangedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        before = _json["before"].as<std::string>();
        after = _json["after"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::TopicChangedEvent Json::Value::as<traQApi::TopicChangedEvent>() const {
    return traQApi::TopicChangedEvent(*this);
};

#endif
