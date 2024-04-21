#ifndef TRAQ_PostClipFolderRequest_H
#define TRAQ_PostClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// クリップフォルダ作成リクエスト
struct PostClipFolderRequest {
    std::string name;
    std::string description;

    PostClipFolderRequest() = default;
    operator Json::Value() const;
    PostClipFolderRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostClipFolderRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostClipFolderRequest Json::Value::as<traQApi::PostClipFolderRequest>() const;

#endif
