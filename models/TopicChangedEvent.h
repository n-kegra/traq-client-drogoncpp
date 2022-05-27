#ifndef _TopicChangedEvent_H
#define _TopicChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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

    Json::Value toJson() const;
    TopicChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::TopicChangedEvent Json::Value::as<traQAPI::TopicChangedEvent>() const;

#endif
