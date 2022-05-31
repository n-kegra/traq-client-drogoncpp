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
    operator Json::Value() const {
        return this->toJson();
    }
    PutChannelSubscribersRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["on"] = __Helper::toJson(on);
        return _json;
    }
    PutChannelSubscribersRequest& fromJson(const Json::Value& _json) {
        for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::PutChannelSubscribersRequest Json::Value::as<traQApi::PutChannelSubscribersRequest>() const {
    return traQApi::PutChannelSubscribersRequest(*this);
};

#endif
