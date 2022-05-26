#ifndef _PatchClipFolderRequest_H
#define _PatchClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// クリップフォルダ情報編集リクエスト
struct PatchClipFolderRequest {
    std::string name;
    std::string description;

    operator Json::Value() const {
        return this->toJson();
    }
    PatchClipFolderRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        return _json;
    }
    PatchClipFolderRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}

#endif
