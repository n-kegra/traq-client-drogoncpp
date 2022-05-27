#ifndef _WebRTCUserStateSessionsInner_H
#define _WebRTCUserStateSessionsInner_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

struct WebRTCUserStateSessionsInner {
    std::string state;
    std::string sessionId;

    WebRTCUserStateSessionsInner() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    WebRTCUserStateSessionsInner(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    WebRTCUserStateSessionsInner& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::WebRTCUserStateSessionsInner Json::Value::as<traQAPI::WebRTCUserStateSessionsInner>() const;

#endif
