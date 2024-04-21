#ifndef TRAQ_PatchStampRequest_H
#define TRAQ_PatchStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ情報変更リクエスト
struct PatchStampRequest {
    std::string name;
    std::string creatorId;

    PatchStampRequest() = default;
    operator Json::Value() const;
    PatchStampRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchStampRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchStampRequest Json::Value::as<traQApi::PatchStampRequest>() const;

#endif
