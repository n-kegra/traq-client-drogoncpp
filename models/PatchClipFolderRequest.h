#ifndef _PatchClipFolderRequest_H
#define _PatchClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// クリップフォルダ情報編集リクエスト
struct PatchClipFolderRequest {
    std::string name;
    std::string description;

    PatchClipFolderRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchClipFolderRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchClipFolderRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PatchClipFolderRequest Json::Value::as<traQAPI::PatchClipFolderRequest>() const;

#endif
