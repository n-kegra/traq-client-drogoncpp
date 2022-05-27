#ifndef _PostClipFolderRequest_H
#define _PostClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::PostClipFolderRequest Json::Value::as<traQ::PostClipFolderRequest>() const;

#endif
