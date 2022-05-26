#ifndef __HELPER_H
#define __HELPER_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <vector>
#include <map>

namespace traQ {

namespace Helper {
    enum class SerializeStyle {
        simple,
        label,
        matrix,
        form,
        pipeDelimited,
        spaceDelimited,
    };

    std::string serialize(SerializeStyle style, const std::string name, const Json::Value& value);
    std::vector<std::string>&& serialize_explode(SerializeStyle style, const std::string name, const Json::Value& value);
    std::string serialize_collect(SerializeStyle style, std::vector<std::string> strs);
    template<class T>
    Json::Value toJson(const std::vector<T>& obj){
        Json::Value jsonobj;
        for(const auto& item : obj){
            jsonobj.append(item);
        }
        return jsonobj;
    }
    template<class T>
    Json::Value toJson(const std::map<std::string, T>& obj){
        Json::Value jsonobj;
        for(const auto& [key, item] : obj){
            jsonobj[key] = item;
        }
        return jsonobj;
    }
};

}

#endif
