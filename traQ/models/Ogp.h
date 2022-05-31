#ifndef TRAQ_Ogp_H
#define TRAQ_Ogp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/OgpMedia.h>
#include <vector>

namespace traQApi {

// OGPの情報
struct Ogp {
    std::string type;
    std::string title;
    std::string url;
    std::vector<OgpMedia> images;
    std::string description;
    std::vector<OgpMedia> videos;

    Ogp() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Ogp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["type"] = (type);
        _json["title"] = (title);
        _json["url"] = (url);
        _json["images"] = __Helper::toJson(images);
        _json["description"] = (description);
        _json["videos"] = __Helper::toJson(videos);
        return _json;
    }
    Ogp& fromJson(const Json::Value& _json) {
        type = _json["type"].as<std::string>();
        title = _json["title"].as<std::string>();
        url = _json["url"].as<std::string>();
        for (auto _it = _json["images"].begin(); _it != _json["images"].end(); _it++) {
            images.emplace_back((*_it));    
        }
        description = _json["description"].as<std::string>();
        for (auto _it = _json["videos"].begin(); _it != _json["videos"].end(); _it++) {
            videos.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> inline traQApi::Ogp Json::Value::as<traQApi::Ogp>() const {
    return traQApi::Ogp(*this);
};

#endif
