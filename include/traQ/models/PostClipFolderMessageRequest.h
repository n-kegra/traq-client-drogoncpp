#ifndef TRAQ_PostClipFolderMessageRequest_H
#define TRAQ_PostClipFolderMessageRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// クリップ追加リクエスト
struct PostClipFolderMessageRequest {
    std::string messageId;

    PostClipFolderMessageRequest() = default;
    operator Json::Value() const;
    PostClipFolderMessageRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostClipFolderMessageRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostClipFolderMessageRequest Json::Value::as<traQApi::PostClipFolderMessageRequest>() const;

#endif
