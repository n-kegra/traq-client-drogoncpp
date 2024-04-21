#ifndef TRAQ_PostUserTagRequest_H
#define TRAQ_PostUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザータグ追加リクエスト
struct PostUserTagRequest {
    std::string tag;

    PostUserTagRequest() = default;
    operator Json::Value() const;
    PostUserTagRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostUserTagRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostUserTagRequest Json::Value::as<traQApi::PostUserTagRequest>() const;

#endif
