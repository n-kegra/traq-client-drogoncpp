#ifndef TRAQ_PatchStampPaletteRequest_H
#define TRAQ_PatchStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <set>

namespace traQApi {

// スタンプパレット情報変更リクエスト
struct PatchStampPaletteRequest {
    std::string name;
    std::string description;
    std::set<std::string> stamps;

    PatchStampPaletteRequest() = default;
    operator Json::Value() const;
    PatchStampPaletteRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchStampPaletteRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchStampPaletteRequest Json::Value::as<traQApi::PatchStampPaletteRequest>() const;

#endif
