#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <traQ/Helper.h>
#include "StampApi.h"

#include <traQ/models/MessageStamp.h>
#include <traQ/models/PatchStampPaletteRequest.h>
#include <traQ/models/PatchStampRequest.h>
#include <traQ/models/PostMessageStampRequest.h>
#include <traQ/models/PostStampPaletteRequest.h>
#include <traQ/models/Stamp.h>
#include <traQ/models/StampHistoryEntry.h>
#include <traQ/models/StampPalette.h>
#include <traQ/models/StampStats.h>
#include <traQ/models/StampWithThumbnail.h>


namespace traQApi {

StampApi::StampApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("StampApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

StampApi& StampApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
StampApi& StampApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
StampApi& StampApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


void
StampApi::addMessageStamp(
    const std::string& _messageId, 
    const std::string& _stampId, 
    const std::optional<PostMessageStampRequest>& _postMessageStampRequest
){
    Json::Value json;
    if(_postMessageStampRequest.has_value()) {
        json = (_postMessageStampRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/messages/{messageId}/stamps/{stampId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_messageId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "messageId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
StampApi::changeStampImage(
    const std::string& _stampId, 
    const drogon::UploadFile& _file
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/stamps/{stampId}/image";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


Stamp
StampApi::createStamp(
    const std::string& _name, 
    const drogon::UploadFile& _file
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/stamps";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_name);
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized = __Helper::serialize(style, "name", jsonobj);
        req->setParameter("name", serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return Stamp(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


StampPalette
StampApi::createStampPalette(
    const std::optional<PostStampPaletteRequest>& _postStampPaletteRequest
){
    Json::Value json;
    if(_postStampPaletteRequest.has_value()) {
        json = (_postStampPaletteRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/stamp-palettes";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return StampPalette(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


void
StampApi::deleteStamp(
    const std::string& _stampId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/stamps/{stampId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
StampApi::deleteStampPalette(
    const std::string& _paletteId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/stamp-palettes/{paletteId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_paletteId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "paletteId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "paletteId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
StampApi::editStamp(
    const std::string& _stampId, 
    const std::optional<PatchStampRequest>& _patchStampRequest
){
    Json::Value json;
    if(_patchStampRequest.has_value()) {
        json = (_patchStampRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/stamps/{stampId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


void
StampApi::editStampPalette(
    const std::string& _paletteId, 
    const std::optional<PatchStampPaletteRequest>& _patchStampPaletteRequest
){
    Json::Value json;
    if(_patchStampPaletteRequest.has_value()) {
        json = (_patchStampPaletteRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/stamp-palettes/{paletteId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_paletteId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "paletteId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "paletteId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


std::vector<MessageStamp>
StampApi::getMessageStamps(
    const std::string& _messageId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/messages/{messageId}/stamps";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_messageId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "messageId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<MessageStamp> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<MessageStamp>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<StampHistoryEntry>
StampApi::getMyStampHistory(
    const std::optional<int32_t>& _limit
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/stamp-history";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_limit.has_value()) {
        Json::Value jsonobj = (_limit.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "limit", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<StampHistoryEntry> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<StampHistoryEntry>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


Stamp
StampApi::getStamp(
    const std::string& _stampId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/stamps/{stampId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return Stamp(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


drogon::HttpResponsePtr
StampApi::getStampImage(
    const std::string& _stampId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/stamps/{stampId}/image";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        return response;
    } else {
        throw std::runtime_error("error");
    }
}


StampPalette
StampApi::getStampPalette(
    const std::string& _paletteId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/stamp-palettes/{paletteId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_paletteId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "paletteId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "paletteId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return StampPalette(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<StampPalette>
StampApi::getStampPalettes(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/stamp-palettes";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<StampPalette> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<StampPalette>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


StampStats
StampApi::getStampStats(
    const std::string& _stampId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/stamps/{stampId}/stats";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return StampStats(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


std::vector<StampWithThumbnail>
StampApi::getStamps(
    const std::optional<bool>& _includeUnicode, 
    const std::optional<std::string>& _type
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/stamps";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_includeUnicode.has_value()) {
        Json::Value jsonobj = (_includeUnicode.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "includeUnicode", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_type.has_value()) {
        Json::Value jsonobj = (_type.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "type", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<StampWithThumbnail> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<StampWithThumbnail>());    
        }
        return tmp;
    } else {
        throw std::runtime_error("error");
    }
}


void
StampApi::removeMessageStamp(
    const std::string& _messageId, 
    const std::string& _stampId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/messages/{messageId}/stamps/{stampId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_messageId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "messageId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
    }
    
    {
        Json::Value jsonobj = (_stampId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "stampId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "stampId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


}
