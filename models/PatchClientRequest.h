#ifndef _PatchClientRequest_H
#define _PatchClientRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// OAuth2クライアント情報変更リクエスト
struct PatchClientRequest {
    std::string name;
    std::string description;
    std::string callbackUrl;
    std::string developerId;

    operator Json::Value() const {
        return this->toJson();
    }
    PatchClientRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        _json["callbackUrl"] = (callbackUrl);
        _json["developerId"] = (developerId);
        return _json;
    }
    PatchClientRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        callbackUrl = _json["callbackUrl"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        return *this;
    }
};

}

#endif
