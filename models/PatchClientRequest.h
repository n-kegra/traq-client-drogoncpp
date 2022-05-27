#ifndef _PatchClientRequest_H
#define _PatchClientRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// OAuth2クライアント情報変更リクエスト
struct PatchClientRequest {
    std::string name;
    std::string description;
    std::string callbackUrl;
    std::string developerId;

    PatchClientRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchClientRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchClientRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PatchClientRequest Json::Value::as<traQAPI::PatchClientRequest>() const;

#endif
