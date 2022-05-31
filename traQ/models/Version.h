#ifndef TRAQ_Version_H
#define TRAQ_Version_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/VersionFlags.h>

namespace traQApi {

// バージョン・サーバーフラグ情報
struct Version {
    std::string revision;
    std::string version;
    VersionFlags flags;

    Version() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Version(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["revision"] = (revision);
        _json["version"] = (version);
        _json["flags"] = (flags.toJson());
        return _json;
    }
    Version& fromJson(const Json::Value& _json) {
        revision = _json["revision"].as<std::string>();
        version = _json["version"].as<std::string>();
        flags.fromJson(_json["flags"]);
        return *this;
    }
};

}
template <> inline traQApi::Version Json::Value::as<traQApi::Version>() const {
    return traQApi::Version(*this);
};

#endif
