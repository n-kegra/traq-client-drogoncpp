#ifndef _PostStampPaletteRequest_H
#define _PostStampPaletteRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <set>
#include <vector>

namespace traQ {

// スタンプパレット作成リクエスト
struct PostStampPaletteRequest {
    std::set<std::string> stamps;
    std::string name;
    std::string description;

    operator Json::Value() const {
        return this->toJson();
    }
    PostStampPaletteRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["stamps"] = Helper::toJson(stamps);
        _json["name"] = (name);
        _json["description"] = (description);
        return _json;
    }
    PostStampPaletteRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        stamps = _json["stamps"].as<std::set<std::string>>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}

#endif
