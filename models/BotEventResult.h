#ifndef _BotEventResult_H
#define _BotEventResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// イベント配送結果
struct BotEventResult {
    enum class Value {
        eok,
        eng,
        ene,
        edp,
        Unknown,
    } value;
    BotEventResult() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    BotEventResult(const Json::Value& __value) {
        this->fromJson(__value);
    }
    BotEventResult(const Value __value) : value(__value) {}

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eok:
            return Json::Value("ok");
        case Value::eng:
            return Json::Value("ng");
        case Value::ene:
            return Json::Value("ne");
        case Value::edp:
            return Json::Value("dp");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    BotEventResult& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "ok") {
            this->value = Value::eok;
        } else
        if (s == "ng") {
            this->value = Value::eng;
        } else
        if (s == "ne") {
            this->value = Value::ene;
        } else
        if (s == "dp") {
            this->value = Value::edp;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::BotEventResult Json::Value::as<traQ::BotEventResult>() const { return traQ::BotEventResult(*this); }

#endif
