#include "ActivityApi.h"

namespace traQ {

auto ActivityApi::getActivityTimeline(
    const std::optional<int32_t>& _limit, 
    const std::optional<bool>& _all, 
    const std::optional<bool>& _perChannel
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/activity/timeline";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_limit.has_value()) {
        Json::Value jsonobj = (_limit.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "limit", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_all.has_value()) {
        Json::Value jsonobj = (_all.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "all", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_perChannel.has_value()) {
        Json::Value jsonobj = (_perChannel.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "perChannel", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<ActivityTimelineMessage>> response_object;

    if(response_json) {
        std::vector<ActivityTimelineMessage> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ActivityTimelineMessage>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto ActivityApi::getOnlineUsers(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/activity/onlines";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<std::string>> response_object;

    if(response_json) {
        std::vector<std::string> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<std::string>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}


}
