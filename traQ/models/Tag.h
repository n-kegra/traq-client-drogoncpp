#ifndef TRAQ_Tag_H
#define TRAQ_Tag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

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
        _json["users"] = __Helper::toJson(users);
        return _json;
    }
    Tag& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        tag = _json["tag"].as<std::string>();
        for (auto _it = _json["users"].begin(); _it != _json["users"].end(); _it++) {
            users.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::Tag Json::Value::as<traQApi::Tag>() const {
    return traQApi::Tag(*this);
};

#endif
