#ifndef _WebRTCUserStateSessionsInner_H
#define _WebRTCUserStateSessionsInner_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

struct WebRTCUserStateSessionsInner {
    std::string state;
    std::string sessionId;

    operator Json::Value() const {
        return this->toJson();
    }
    WebRTCUserStateSessionsInner(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["state"] = (state);
        _json["sessionId"] = (sessionId);
        return _json;
    }
    WebRTCUserStateSessionsInner& fromJson(const Json::Value& _json) {
        Json::Value _json;
        state = _json["state"].as<std::string>();
        sessionId = _json["sessionId"].as<std::string>();
        return *this;
    }
};

}

#endif
