#ifndef _PatchStampRequest_H
#define _PatchStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// スタンプ情報変更リクエスト
struct PatchStampRequest {
    std::string name;
    std::string creatorId;

    PatchStampRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchStampRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchStampRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PatchStampRequest Json::Value::as<traQAPI::PatchStampRequest>() const;

#endif
