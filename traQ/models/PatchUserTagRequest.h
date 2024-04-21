#ifndef TRAQ_PatchUserTagRequest_H
#define TRAQ_PatchUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーのタグの編集リクエスト
struct PatchUserTagRequest {
    bool isLocked;

    PatchUserTagRequest() = default;
    operator Json::Value() const;
    PatchUserTagRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchUserTagRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchUserTagRequest Json::Value::as<traQApi::PatchUserTagRequest>() const;

#endif
