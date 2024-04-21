#ifndef TRAQ_PostStampPaletteRequest_H
#define TRAQ_PostStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <set>

namespace traQApi {

// スタンプパレット作成リクエスト
struct PostStampPaletteRequest {
    std::set<std::string> stamps;
    std::string name;
    std::string description;

    PostStampPaletteRequest() = default;
    operator Json::Value() const;
    PostStampPaletteRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostStampPaletteRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostStampPaletteRequest Json::Value::as<traQApi::PostStampPaletteRequest>() const;

#endif
