#ifndef _StampPalette_H
#define _StampPalette_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

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
    operator Json::Value() const {
        return this->toJson();
    }
    StampPalette(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    StampPalette& fromJson(const Json::Value& _json);
};

}
template <> traQ::StampPalette Json::Value::as<traQ::StampPalette>() const;

#endif
