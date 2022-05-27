#ifndef _Tag_H
#define _Tag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// タグ情報
struct Tag {
    std::string id;
    std::string tag;
    std::vector<std::string> users;

    Tag() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Tag(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["tag"] = (tag);
        _json["users"] = Helper::toJson(users);
        return _json;
    }
    Tag& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        tag = _json["tag"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            users.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> traQ::Tag Json::Value::as<traQ::Tag>() const { return traQ::Tag(*this); }

#endif
