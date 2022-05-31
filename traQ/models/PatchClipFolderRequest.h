#ifndef TRAQ_PatchClipFolderRequest_H
#define TRAQ_PatchClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        return _json;
    }
    PatchClipFolderRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PatchClipFolderRequest Json::Value::as<traQApi::PatchClipFolderRequest>() const {
    return traQApi::PatchClipFolderRequest(*this);
};

#endif
