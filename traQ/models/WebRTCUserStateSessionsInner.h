#ifndef TRAQ_WebRTCUserStateSessionsInner_H
#define TRAQ_WebRTCUserStateSessionsInner_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

struct WebRTCUserStateSessionsInner {
    std::string state;
    std::string sessionId;

    WebRTCUserStateSessionsInner() = default;
    operator Json::Value() const;
    WebRTCUserStateSessionsInner(const Json::Value& __value);

    Json::Value toJson() const;
    WebRTCUserStateSessionsInner& fromJson(const Json::Value& _json);
};

}
template <> traQApi::WebRTCUserStateSessionsInner Json::Value::as<traQApi::WebRTCUserStateSessionsInner>() const;

#endif
