#ifndef TRAQ_DMChannel_H
#define TRAQ_DMChannel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ダイレクトメッセージチャンネル
struct DMChannel {
    std::string id;
    std::string userId;

    DMChannel() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    DMChannel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    DMChannel& fromJson(const Json::Value& _json);
};

}
template <> traQApi::DMChannel Json::Value::as<traQApi::DMChannel>() const;

#endif