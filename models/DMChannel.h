#ifndef _DMChannel_H
#define _DMChannel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::DMChannel Json::Value::as<traQ::DMChannel>() const;

#endif
