#ifndef _GetClient200Response_H
#define _GetClient200Response_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Client.h"
#include "../models/OAuth2ClientDetail.h"
#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQ {

struct GetClient200Response {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;
    std::string callbackUrl;
    std::string secret;

    GetClient200Response() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    GetClient200Response(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    GetClient200Response& fromJson(const Json::Value& _json);
};

}
template <> traQ::GetClient200Response Json::Value::as<traQ::GetClient200Response>() const;

#endif
