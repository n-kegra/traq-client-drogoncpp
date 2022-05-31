#ifndef TRAQ_PostStampPaletteRequest_H
#define TRAQ_PostStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <set>
#include <vector>

namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["stamps"] = __Helper::toJson(stamps);
        _json["name"] = (name);
        _json["description"] = (description);
        return _json;
    }
    PostStampPaletteRequest& fromJson(const Json::Value& _json) {
        for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
            stamps.emplace((*_it).as<std::string>());    
        }
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostStampPaletteRequest Json::Value::as<traQApi::PostStampPaletteRequest>() const {
    return traQApi::PostStampPaletteRequest(*this);
};

#endif
