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

    Json::Value toJson() const {
        Json::Value _json;
        _json["on"] = Helper::toJson(on);
        return _json;
    }
    PutChannelSubscribersRequest& fromJson(const Json::Value& _json) {
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> traQ::PutChannelSubscribersRequest Json::Value::as<traQ::PutChannelSubscribersRequest>() const { return traQ::PutChannelSubscribersRequest(*this); }

#endif
