#ifndef _PatchChannelSubscribersRequest_H
#define _PatchChannelSubscribersRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// チャンネル購読者編集リクエスト
struct PatchChannelSubscribersRequest {
    std::vector<std::string> on;
    std::vector<std::string> off;

    PatchChannelSubscribersRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchChannelSubscribersRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchChannelSubscribersRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PatchChannelSubscribersRequest Json::Value::as<traQ::PatchChannelSubscribersRequest>() const;

#endif
