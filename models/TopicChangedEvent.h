#ifndef _TopicChangedEvent_H
#define _TopicChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// トピック変更イベント
struct TopicChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

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
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        before = _json["before"].as<std::string>();
        after = _json["after"].as<std::string>();
        return *this;
    }
};

}

#endif
