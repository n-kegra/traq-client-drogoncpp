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

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["userId"] = (userId);
        return _json;
    }
    DMChannel& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        userId = _json["userId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::DMChannel Json::Value::as<traQApi::DMChannel>() const {
    return traQApi::DMChannel(*this);
};

#endif
