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

    Json::Value toJson() const;
    PutNotifyCitationRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PutNotifyCitationRequest Json::Value::as<traQ::PutNotifyCitationRequest>() const;

#endif
