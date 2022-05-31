#ifndef TRAQ_PatchUserTagRequest_H
#define TRAQ_PatchUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーのタグの編集リクエスト
struct PatchUserTagRequest {
    bool isLocked;

    PatchUserTagRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchUserTagRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["isLocked"] = (isLocked);
        return _json;
    }
    PatchUserTagRequest& fromJson(const Json::Value& _json) {
        isLocked = _json["isLocked"].as<bool>();
        return *this;
    }
};

}
template <> inline traQApi::PatchUserTagRequest Json::Value::as<traQApi::PatchUserTagRequest>() const {
    return traQApi::PatchUserTagRequest(*this);
};

#endif
