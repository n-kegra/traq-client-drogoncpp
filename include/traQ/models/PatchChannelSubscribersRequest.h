#ifndef TRAQ_PatchChannelSubscribersRequest_H
#define TRAQ_PatchChannelSubscribersRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <vector>

namespace traQApi {

// チャンネル購読者編集リクエスト
struct PatchChannelSubscribersRequest {
    std::vector<std::string> on;
    std::vector<std::string> off;

    PatchChannelSubscribersRequest() = default;
    operator Json::Value() const;
    PatchChannelSubscribersRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchChannelSubscribersRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchChannelSubscribersRequest Json::Value::as<traQApi::PatchChannelSubscribersRequest>() const;

#endif
