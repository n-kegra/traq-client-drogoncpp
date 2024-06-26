#ifndef TRAQ_WebRTCAuthenticateResult_H
#define TRAQ_WebRTCAuthenticateResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// skyway用認証リクエストリザルト
struct WebRTCAuthenticateResult {
    std::string peerId;
    int32_t ttl;
    int64_t timestamp;
    std::string authToken;

    WebRTCAuthenticateResult() = default;
    operator Json::Value() const;
    WebRTCAuthenticateResult(const Json::Value& __value);

    Json::Value toJson() const;
    WebRTCAuthenticateResult& fromJson(const Json::Value& _json);
};

}
template <> traQApi::WebRTCAuthenticateResult Json::Value::as<traQApi::WebRTCAuthenticateResult>() const;

#endif
