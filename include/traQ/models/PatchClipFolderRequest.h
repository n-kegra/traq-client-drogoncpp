#ifndef TRAQ_PatchClipFolderRequest_H
#define TRAQ_PatchClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// クリップフォルダ情報編集リクエスト
struct PatchClipFolderRequest {
    std::string name;
    std::string description;

    PatchClipFolderRequest() = default;
    operator Json::Value() const;
    PatchClipFolderRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchClipFolderRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchClipFolderRequest Json::Value::as<traQApi::PatchClipFolderRequest>() const;

#endif
