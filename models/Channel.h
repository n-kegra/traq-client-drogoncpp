#ifndef _Channel_H
#define _Channel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// チャンネル
struct Channel {
    std::string id;
    std::string parentId;
    bool archived;
    bool force;
    std::string topic;
    std::string name;
    std::vector<std::string> children;

    operator Json::Value() const {
        return this->toJson();
    }
    Channel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["parentId"] = (parentId);
        _json["archived"] = (archived);
        _json["force"] = (force);
        _json["topic"] = (topic);
        _json["name"] = (name);
        _json["children"] = Helper::toJson(children);
        return _json;
    }
    Channel& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        parentId = _json["parentId"].as<std::string>();
        archived = _json["archived"].as<bool>();
        force = _json["force"].as<bool>();
        topic = _json["topic"].as<std::string>();
        name = _json["name"].as<std::string>();
        children = _json["children"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif
