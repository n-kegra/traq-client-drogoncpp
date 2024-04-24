#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include "../Helper.h"
#include <traQ/apis/BotApi.h>

#include <traQ/models/Bot.h>
#include <traQ/models/BotDetail.h>
#include <traQ/models/BotEventLog.h>
#include <traQ/models/BotTokens.h>
#include <traQ/models/BotUser.h>
#include <traQ/models/GetBot200Response.h>
#include <traQ/models/PatchBotRequest.h>
#include <traQ/models/PostBotActionJoinRequest.h>
#include <traQ/models/PostBotActionLeaveRequest.h>
#include <traQ/models/PostBotRequest.h>


namespace traQApi {

BotApi::BotApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, m, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("BotApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

BotApi& BotApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
BotApi& BotApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
BotApi& BotApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


void
BotApi::activateBot(
    const std::string& _botId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/bots/{botId}/actions/activate";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
BotApi::changeBotIcon(
    const std::string& _botId, 
    const drogon::UploadFile& _file
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/bots/{botId}/icon";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
BotApi::connectBotWS(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/bots/ws";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


BotDetail
BotApi::createBot(
    const std::optional<PostBotRequest>& _postBotRequest
){
    Json::Value json;
    if(_postBotRequest.has_value()) {
        json = (_postBotRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/bots";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return BotDetail(*response_json);
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


void
BotApi::deleteBot(
    const std::string& _botId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/bots/{botId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
BotApi::editBot(
    const std::string& _botId, 
    const std::optional<PatchBotRequest>& _patchBotRequest
){
    Json::Value json;
    if(_patchBotRequest.has_value()) {
        json = (_patchBotRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/bots/{botId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


GetBot200Response
BotApi::getBot(
    const std::string& _botId, 
    const std::optional<bool>& _detail
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/bots/{botId}";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    if(_detail.has_value()) {
        Json::Value jsonobj = (_detail.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "detail", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return GetBot200Response(*response_json);
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


drogon::HttpResponsePtr
BotApi::getBotIcon(
    const std::string& _botId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/bots/{botId}/icon";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        return response;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


std::vector<BotEventLog>
BotApi::getBotLogs(
    const std::string& _botId, 
    const std::optional<int32_t>& _limit, 
    const std::optional<int32_t>& _offset
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/bots/{botId}/logs";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    if(_limit.has_value()) {
        Json::Value jsonobj = (_limit.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "limit", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_offset.has_value()) {
        Json::Value jsonobj = (_offset.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "offset", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<BotEventLog> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<BotEventLog>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


std::vector<Bot>
BotApi::getBots(
    const std::optional<bool>& _all
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/bots";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_all.has_value()) {
        Json::Value jsonobj = (_all.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "all", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<Bot> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<Bot>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


std::vector<BotUser>
BotApi::getChannelBots(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/channels/{channelId}/bots";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<BotUser> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<BotUser>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


void
BotApi::inactivateBot(
    const std::string& _botId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/bots/{botId}/actions/inactivate";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
BotApi::letBotJoinChannel(
    const std::string& _botId, 
    const std::optional<PostBotActionJoinRequest>& _postBotActionJoinRequest
){
    Json::Value json;
    if(_postBotActionJoinRequest.has_value()) {
        json = (_postBotActionJoinRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/bots/{botId}/actions/join";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
BotApi::letBotLeaveChannel(
    const std::string& _botId, 
    const std::optional<PostBotActionLeaveRequest>& _postBotActionLeaveRequest
){
    Json::Value json;
    if(_postBotActionLeaveRequest.has_value()) {
        json = (_postBotActionLeaveRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/bots/{botId}/actions/leave";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


BotTokens
BotApi::reissueBot(
    const std::string& _botId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/bots/{botId}/actions/reissue";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_botId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "botId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "botId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return BotTokens(*response_json);
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


}
