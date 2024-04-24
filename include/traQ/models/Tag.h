#ifndef TRAQ_Tag_H
#define TRAQ_Tag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <vector>

namespace traQApi {

// タグ情報
struct Tag {
    std::string id;
    std::string tag;
    std::vector<std::string> users;

    Tag() = default;
    operator Json::Value() const;
    Tag(const Json::Value& __value);

    Json::Value toJson() const;
    Tag& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Tag Json::Value::as<traQApi::Tag>() const;

#endif
