#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include "../Helper.h"
#include <traQ/apis/FileApi.h>

#include <traQ/models/FileInfo.h>
#include <traQ/models/ThumbnailType.h>


namespace traQApi {

FileApi::FileApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, m, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("FileApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

FileApi& FileApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
FileApi& FileApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
FileApi& FileApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


void
FileApi::deleteFile(
    const std::string& _fileId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/files/{fileId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_fileId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "fileId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "fileId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


drogon::HttpResponsePtr
FileApi::getFile(
    const std::string& _fileId, 
    const std::optional<int32_t>& _dl
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/files/{fileId}";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_fileId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "fileId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "fileId" "\\}"), serialized);
    }
    
    if(_dl.has_value()) {
        Json::Value jsonobj = (_dl.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "dl", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

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


FileInfo
FileApi::getFileMeta(
    const std::string& _fileId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/files/{fileId}/meta";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_fileId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "fileId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "fileId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return FileInfo(*response_json);
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


std::vector<FileInfo>
FileApi::getFiles(
    const std::optional<std::string>& _channelId, 
    const std::optional<int32_t>& _limit, 
    const std::optional<int32_t>& _offset, 
    const std::optional<std::string>& _since, 
    const std::optional<std::string>& _until, 
    const std::optional<bool>& _inclusive, 
    const std::optional<std::string>& _order, 
    const std::optional<bool>& _mine
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/files";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_channelId.has_value()) {
        Json::Value jsonobj = (_channelId.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "channelId", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
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
    
    if(_since.has_value()) {
        Json::Value jsonobj = (_since.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "since", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_until.has_value()) {
        Json::Value jsonobj = (_until.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "until", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_inclusive.has_value()) {
        Json::Value jsonobj = (_inclusive.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "inclusive", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_order.has_value()) {
        Json::Value jsonobj = (_order.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "order", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_mine.has_value()) {
        Json::Value jsonobj = (_mine.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "mine", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<FileInfo> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<FileInfo>());    
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


drogon::HttpResponsePtr
FileApi::getThumbnailImage(
    const std::string& _fileId, 
    const std::optional<ThumbnailType>& _type
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/files/{fileId}/thumbnail";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_fileId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "fileId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "fileId" "\\}"), serialized);
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


FileInfo
FileApi::postFile(
    const drogon::UploadFile& _file, 
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/files";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        req->setParameter("channelId", serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return FileInfo(*response_json);
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
