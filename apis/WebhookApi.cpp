#include "WebhookApi.h"

namespace traQ {

auto WebhookApi::changeWebhookIcon(
    const std::string& _webhookId, 
    const drogon::UploadFile& _file
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/webhooks/{webhookId}/icon";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto WebhookApi::createWebhook(
    const std::optional<PostWebhookRequest>& _postWebhookRequest
){
    Json::Value json;
    if(_postWebhookRequest.has_value()) {
        json = (_postWebhookRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/webhooks";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<Webhook> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto WebhookApi::deleteWebhook(
    const std::string& _webhookId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/webhooks/{webhookId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto WebhookApi::editWebhook(
    const std::string& _webhookId, 
    const std::optional<PatchWebhookRequest>& _patchWebhookRequest
){
    Json::Value json;
    if(_patchWebhookRequest.has_value()) {
        json = (_patchWebhookRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/webhooks/{webhookId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto WebhookApi::getWebhook(
    const std::string& _webhookId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/webhooks/{webhookId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<Webhook> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto WebhookApi::getWebhookIcon(
    const std::string& _webhookId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/webhooks/{webhookId}/icon";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<drogon::UploadFile> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto WebhookApi::getWebhookMessages(
    const std::string& _webhookId, 
    const std::optional<int32_t>& _limit, 
    const std::optional<int32_t>& _offset, 
    const std::optional<std::string>& _since, 
    const std::optional<std::string>& _until, 
    const std::optional<bool>& _inclusive, 
    const std::optional<std::string>& _order
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/webhooks/{webhookId}/messages";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    if(_limit.has_value()) {
        Json::Value jsonobj = (_limit.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "limit", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_offset.has_value()) {
        Json::Value jsonobj = (_offset.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "offset", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_since.has_value()) {
        Json::Value jsonobj = (_since.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "since", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_until.has_value()) {
        Json::Value jsonobj = (_until.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "until", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_inclusive.has_value()) {
        Json::Value jsonobj = (_inclusive.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "inclusive", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_order.has_value()) {
        Json::Value jsonobj = (_order.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "order", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<Message>> response_object;

    if(response_json) {
        std::vector<Message> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<Message>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto WebhookApi::getWebhooks(
    const std::optional<bool>& _all
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/webhooks";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_all.has_value()) {
        Json::Value jsonobj = (_all.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "all", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<Webhook>> response_object;

    if(response_json) {
        std::vector<Webhook> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<Webhook>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto WebhookApi::postWebhook(
    const std::string& _webhookId, 
    const std::optional<std::string>& _xTRAQSignature, 
    const std::optional<std::string>& _xTRAQChannelId, 
    const std::optional<int32_t>& _embed, 
    const std::optional<std::string>& _body
){
    Json::Value json;
    if(_body.has_value()) {
        json = (_body.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/webhooks/{webhookId}";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_webhookId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "webhookId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "webhookId" "\\}"), serialized);
    }
    
    if(_xTRAQSignature.has_value()) {
        Json::Value jsonobj = (_xTRAQSignature.value());
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "xTRAQSignature", jsonobj);
        req->addHeader("xTRAQSignature", serialized);
    }
    
    if(_xTRAQChannelId.has_value()) {
        Json::Value jsonobj = (_xTRAQChannelId.value());
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "xTRAQChannelId", jsonobj);
        req->addHeader("xTRAQChannelId", serialized);
    }
    
    if(_embed.has_value()) {
        Json::Value jsonobj = (_embed.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "embed", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}


}
