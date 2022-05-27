#ifndef _PostClipFolderRequest_H
#define _PostClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// クリップフォルダ作成リクエスト
struct PostClipFolderRequest {
    std::string name;
    std::string description;

    PostClipFolderRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostClipFolderRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostClipFolderRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostClipFolderRequest Json::Value::as<traQAPI::PostClipFolderRequest>() const;

#endif
