#ifndef TRAQ_PatchMeRequest_H
#define TRAQ_PatchMeRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 自分のユーザー情報変更リクエスト
struct PatchMeRequest {
    std::string displayName;
    std::string twitterId;
    std::string bio;
    std::string homeChannel;

    PatchMeRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchMeRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["displayName"] = (displayName);
        _json["twitterId"] = (twitterId);
        _json["bio"] = (bio);
        _json["homeChannel"] = (homeChannel);
        return _json;
    }
    PatchMeRequest& fromJson(const Json::Value& _json) {
        displayName = _json["displayName"].as<std::string>();
        twitterId = _json["twitterId"].as<std::string>();
        bio = _json["bio"].as<std::string>();
        homeChannel = _json["homeChannel"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PatchMeRequest Json::Value::as<traQApi::PatchMeRequest>() const {
    return traQApi::PatchMeRequest(*this);
};

#endif
