#ifndef _PostStampPaletteRequest_H
#define _PostStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <set>
#include <vector>

namespace traQAPI {

// スタンプパレット作成リクエスト
struct PostStampPaletteRequest {
    std::set<std::string> stamps;
    std::string name;
    std::string description;

    PostStampPaletteRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostStampPaletteRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostStampPaletteRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostStampPaletteRequest Json::Value::as<traQAPI::PostStampPaletteRequest>() const;

#endif
