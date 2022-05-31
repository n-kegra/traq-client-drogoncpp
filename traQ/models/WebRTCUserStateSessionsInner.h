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
        state = _json["state"].as<std::string>();
        sessionId = _json["sessionId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::WebRTCUserStateSessionsInner Json::Value::as<traQApi::WebRTCUserStateSessionsInner>() const {
    return traQApi::WebRTCUserStateSessionsInner(*this);
};

#endif
