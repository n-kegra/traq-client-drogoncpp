#include "Version.h"

namespace traQ {

Json::Value Version::toJson() const {
    Json::Value _json;
    _json["revision"] = (revision);
    _json["version"] = (version);
    _json["flags"] = (flags.toJson());
    return _json;
}
Version& Version::fromJson(const Json::Value& _json) {
    revision = _json["revision"].as<std::string>();
    version = _json["version"].as<std::string>();
    flags.fromJson(_json["flags"]);
    return *this;
}

}
template <> traQ::Version Json::Value::as<traQ::Version>() const {
    return traQ::Version(*this);
}
