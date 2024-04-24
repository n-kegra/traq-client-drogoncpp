#ifndef TRAQ_TopicChangedEvent_H
#define TRAQ_TopicChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// トピック変更イベント
struct TopicChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

    TopicChangedEvent() = default;
    operator Json::Value() const;
    TopicChangedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    TopicChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::TopicChangedEvent Json::Value::as<traQApi::TopicChangedEvent>() const;

#endif
