#ifndef _PutNotifyCitationRequest_H
#define _PutNotifyCitationRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// メッセージ引用通知設定リクエスト
struct PutNotifyCitationRequest {
    bool notifyCitation;

    PutNotifyCitationRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PutNotifyCitationRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["notifyCitation"] = (notifyCitation);
        return _json;
    }
    PutNotifyCitationRequest& fromJson(const Json::Value& _json) {
        notifyCitation = _json["notifyCitation"].as<bool>();
        return *this;
    }
};

}
template <> traQ::PutNotifyCitationRequest Json::Value::as<traQ::PutNotifyCitationRequest>() const { return traQ::PutNotifyCitationRequest(*this); }

#endif
