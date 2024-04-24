#ifndef TRAQ_Channel_H
#define TRAQ_Channel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <vector>

namespace traQApi {

// チャンネル
struct Channel {
    std::string id;
    std::string parentId;
    bool archived;
    bool force;
    std::string topic;
    std::string name;
    std::vector<std::string> children;

    Channel() = default;
    operator Json::Value() const;
    Channel(const Json::Value& __value);

    Json::Value toJson() const;
    Channel& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Channel Json::Value::as<traQApi::Channel>() const;

#endif
