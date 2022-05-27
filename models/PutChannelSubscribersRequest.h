#ifndef _PutChannelSubscribersRequest_H
#define _PutChannelSubscribersRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// 通知をオンにするユーザーのUUID配列
struct PutChannelSubscribersRequest {
    std::vector<std::string> on;

    PutChannelSubscribersRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PutChannelSubscribersRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PutChannelSubscribersRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PutChannelSubscribersRequest Json::Value::as<traQ::PutChannelSubscribersRequest>() const;

#endif
