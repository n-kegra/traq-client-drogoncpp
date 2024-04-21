#ifndef TRAQ_PutChannelSubscribersRequest_H
#define TRAQ_PutChannelSubscribersRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

// 通知をオンにするユーザーのUUID配列
struct PutChannelSubscribersRequest {
    std::vector<std::string> on;

    PutChannelSubscribersRequest() = default;
    operator Json::Value() const;
    PutChannelSubscribersRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PutChannelSubscribersRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PutChannelSubscribersRequest Json::Value::as<traQApi::PutChannelSubscribersRequest>() const;

#endif
