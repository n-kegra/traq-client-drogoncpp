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
template <> inline traQApi::PutNotifyCitationRequest Json::Value::as<traQApi::PutNotifyCitationRequest>() const {
    return traQApi::PutNotifyCitationRequest(*this);
};

#endif
