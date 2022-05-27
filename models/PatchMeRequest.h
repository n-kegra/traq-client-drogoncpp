#ifndef _PatchMeRequest_H
#define _PatchMeRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// 自分のユーザー情報変更リクエスト
struct PatchMeRequest {
    std::string displayName;
    std::string twitterId;
    std::string bio;
    std::string homeChannel;

    PatchMeRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchMeRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchMeRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PatchMeRequest Json::Value::as<traQ::PatchMeRequest>() const;

#endif
