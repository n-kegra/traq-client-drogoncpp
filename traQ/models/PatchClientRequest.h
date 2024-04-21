#ifndef TRAQ_PatchClientRequest_H
#define TRAQ_PatchClientRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// OAuth2クライアント情報変更リクエスト
struct PatchClientRequest {
    std::string name;
    std::string description;
    std::string callbackUrl;
    std::string developerId;

    PatchClientRequest() = default;
    operator Json::Value() const;
    PatchClientRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchClientRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchClientRequest Json::Value::as<traQApi::PatchClientRequest>() const;

#endif
