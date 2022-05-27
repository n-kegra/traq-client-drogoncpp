#ifndef _PatchStampPaletteRequest_H
#define _PatchStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <set>
#include <vector>

namespace traQ {

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
        _json["stamps"] = Helper::toJson(stamps);
        return _json;
    }
    PatchStampPaletteRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            stamps.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> traQ::PatchStampPaletteRequest Json::Value::as<traQ::PatchStampPaletteRequest>() const { return traQ::PatchStampPaletteRequest(*this); }

#endif
