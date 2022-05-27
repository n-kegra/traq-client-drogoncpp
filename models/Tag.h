#ifndef _Tag_H
#define _Tag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQAPI {

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

    Json::Value toJson() const;
    Tag& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Tag Json::Value::as<traQAPI::Tag>() const;

#endif
