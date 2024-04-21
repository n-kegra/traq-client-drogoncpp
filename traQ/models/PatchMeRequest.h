#ifndef TRAQ_PatchMeRequest_H
#define TRAQ_PatchMeRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 自分のユーザー情報変更リクエスト
struct PatchMeRequest {
    std::string displayName;
    std::string twitterId;
    std::string bio;
    std::string homeChannel;

    PatchMeRequest() = default;
    operator Json::Value() const;
    PatchMeRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchMeRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchMeRequest Json::Value::as<traQApi::PatchMeRequest>() const;

#endif
