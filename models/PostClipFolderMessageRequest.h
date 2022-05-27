#ifndef _PostClipFolderMessageRequest_H
#define _PostClipFolderMessageRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// クリップ追加リクエスト
struct PostClipFolderMessageRequest {
    std::string messageId;

    PostClipFolderMessageRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostClipFolderMessageRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostClipFolderMessageRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostClipFolderMessageRequest Json::Value::as<traQAPI::PostClipFolderMessageRequest>() const;

#endif
