#ifndef _WebRTCAuthenticateResult_H
#define _WebRTCAuthenticateResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// skyway用認証リクエストリザルト
struct WebRTCAuthenticateResult {
    std::string peerId;
    int32_t ttl;
    int64_t timestamp;
    std::string authToken;

    WebRTCAuthenticateResult() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    WebRTCAuthenticateResult(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["peerId"] = (peerId);
        _json["ttl"] = (ttl);
        _json["timestamp"] = (timestamp);
        _json["authToken"] = (authToken);
        return _json;
    }
    WebRTCAuthenticateResult& fromJson(const Json::Value& _json) {
        peerId = _json["peerId"].as<std::string>();
        ttl = _json["ttl"].as<int32_t>();
        timestamp = _json["timestamp"].as<int64_t>();
        authToken = _json["authToken"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::WebRTCAuthenticateResult Json::Value::as<traQ::WebRTCAuthenticateResult>() const { return traQ::WebRTCAuthenticateResult(*this); }

#endif
