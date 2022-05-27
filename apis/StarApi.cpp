#include "StarApi.h"

namespace traQ {

auto StarApi::addMyStar(
    const std::optional<PostStarRequest>& _postStarRequest
){
    Json::Value json;
    if(_postStarRequest.has_value()) {
        json = (_postStarRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/stars";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto StarApi::getMyStars(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/stars";
    
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

auto StarApi::removeMyStar(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/stars/{channelId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}


}
