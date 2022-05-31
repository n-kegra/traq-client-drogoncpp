#ifndef TRAQ_Channel_H
#define TRAQ_Channel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

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
        _json["children"] = __Helper::toJson(children);
        return _json;
    }
    Channel& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        parentId = _json["parentId"].as<std::string>();
        archived = _json["archived"].as<bool>();
        force = _json["force"].as<bool>();
        topic = _json["topic"].as<std::string>();
        name = _json["name"].as<std::string>();
        for (auto _it = _json["children"].begin(); _it != _json["children"].end(); _it++) {
            children.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::Channel Json::Value::as<traQApi::Channel>() const {
    return traQApi::Channel(*this);
};

#endif
