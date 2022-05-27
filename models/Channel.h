#ifndef _Channel_H
#define _Channel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQAPI {

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
    operator Json::Value() const {
        return this->toJson();
    }
    Channel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    Channel& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Channel Json::Value::as<traQAPI::Channel>() const;

#endif
