#ifndef TRAQ_StampPalette_H
#define TRAQ_StampPalette_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

// スタンプパレット情報
struct StampPalette {
    std::string id;
    std::string name;
    std::vector<std::string> stamps;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string description;

    StampPalette() = default;
    operator Json::Value() const;
    StampPalette(const Json::Value& __value);

    Json::Value toJson() const;
    StampPalette& fromJson(const Json::Value& _json);
};

}
template <> traQApi::StampPalette Json::Value::as<traQApi::StampPalette>() const;

#endif
