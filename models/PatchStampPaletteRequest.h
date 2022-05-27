#ifndef _PatchStampPaletteRequest_H
#define _PatchStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <set>
#include <vector>

namespace traQAPI {

// スタンプパレット情報変更リクエスト
struct PatchStampPaletteRequest {
    std::string name;
    std::string description;
    std::set<std::string> stamps;

    PatchStampPaletteRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchStampPaletteRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchStampPaletteRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PatchStampPaletteRequest Json::Value::as<traQAPI::PatchStampPaletteRequest>() const;

#endif
