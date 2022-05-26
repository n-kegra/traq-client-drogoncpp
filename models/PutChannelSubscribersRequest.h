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

    operator Json::Value() const {
        return this->toJson();
    }
    PutChannelSubscribersRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["on"] = Helper::toJson(on);
        return _json;
    }
    PutChannelSubscribersRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        on = _json["on"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif
