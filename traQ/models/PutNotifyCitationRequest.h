#ifndef TRAQ_PutNotifyCitationRequest_H
#define TRAQ_PutNotifyCitationRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// メッセージ引用通知設定リクエスト
struct PutNotifyCitationRequest {
    bool notifyCitation;

    PutNotifyCitationRequest() = default;
    operator Json::Value() const;
    PutNotifyCitationRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PutNotifyCitationRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PutNotifyCitationRequest Json::Value::as<traQApi::PutNotifyCitationRequest>() const;

#endif
