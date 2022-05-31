#ifndef TRAQ_PatchStampPaletteRequest_H
#define TRAQ_PatchStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <set>
#include <vector>

namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        _json["stamps"] = __Helper::toJson(stamps);
        return _json;
    }
    PatchStampPaletteRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
            stamps.emplace((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::PatchStampPaletteRequest Json::Value::as<traQApi::PatchStampPaletteRequest>() const {
    return traQApi::PatchStampPaletteRequest(*this);
};

#endif
