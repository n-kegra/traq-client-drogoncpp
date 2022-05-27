#include "MeApi.h"

namespace traQ {

auto MeApi::addMyStar(
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

auto MeApi::addMyUserTag(
    const std::optional<PostUserTagRequest>& _postUserTagRequest
){
    Json::Value json;
    if(_postUserTagRequest.has_value()) {
        json = (_postUserTagRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/tags";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<UserTag> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::changeMyIcon(
    const drogon::UploadFile& _file
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/users/me/icon";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::changeMyNotifyCitation(
    const std::optional<PutNotifyCitationRequest>& _putNotifyCitationRequest
){
    Json::Value json;
    if(_putNotifyCitationRequest.has_value()) {
        json = (_putNotifyCitationRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/users/me/settings/notify-citation";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::changeMyPassword(
    const std::optional<PutMyPasswordRequest>& _putMyPasswordRequest
){
    Json::Value json;
    if(_putMyPasswordRequest.has_value()) {
        json = (_putMyPasswordRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/users/me/password";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::editMe(
    const std::optional<PatchMeRequest>& _patchMeRequest
){
    Json::Value json;
    if(_patchMeRequest.has_value()) {
        json = (_patchMeRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/users/me";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::editMyUserTag(
    const std::string& _tagId, 
    const std::optional<PatchUserTagRequest>& _patchUserTagRequest
){
    Json::Value json;
    if(_patchUserTagRequest.has_value()) {
        json = (_patchUserTagRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Patch);

    std::string endpoint_path = "/users/me/tags/{tagId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_tagId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::getMe(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<MyUserDetail> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyChannelSubscriptions(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/subscriptions";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<UserSubscribeState>> response_object;

    if(response_json) {
        std::vector<UserSubscribeState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserSubscribeState>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyExternalAccounts(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/ex-accounts";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<ExternalProviderUser>> response_object;

    if(response_json) {
        std::vector<ExternalProviderUser> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ExternalProviderUser>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyIcon(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/icon";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
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

auto MeApi::getMyNotifyCitation(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/settings/notify-citation";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<GetNotifyCitation> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyQRCode(
    const std::optional<bool>& _token
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/qr-code";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_token.has_value()) {
        Json::Value jsonobj = (_token.value());
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "token", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<drogon::UploadFile> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMySessions(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/sessions";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<LoginSession>> response_object;

    if(response_json) {
        std::vector<LoginSession> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<LoginSession>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyStampHistory(
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
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "limit", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<StampHistoryEntry>> response_object;

    if(response_json) {
        std::vector<StampHistoryEntry> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<StampHistoryEntry>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyStars(
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

auto MeApi::getMyTokens(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/tokens";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<ActiveOAuth2Token>> response_object;

    if(response_json) {
        std::vector<ActiveOAuth2Token> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ActiveOAuth2Token>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyUnreadChannels(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/unread";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<UnreadChannel>> response_object;

    if(response_json) {
        std::vector<UnreadChannel> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UnreadChannel>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyUserTags(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/tags";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<UserTag>> response_object;

    if(response_json) {
        std::vector<UserTag> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<UserTag>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getMyViewStates(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/view-states";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<std::vector<MyChannelViewState>> response_object;

    if(response_json) {
        std::vector<MyChannelViewState> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<MyChannelViewState>());    
        }
        response_object.emplace(std::move(tmp));
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::getUserSettings(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/settings";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<UserSettings> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}

auto MeApi::linkExternalAccount(
    const std::optional<PostLinkExternalAccount>& _postLinkExternalAccount
){
    Json::Value json;
    if(_postLinkExternalAccount.has_value()) {
        json = (_postLinkExternalAccount.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/ex-accounts/link";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::readChannel(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/unread/{channelId}";
    
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

auto MeApi::registerFCMDevice(
    const std::optional<PostMyFCMDeviceRequest>& _postMyFCMDeviceRequest
){
    Json::Value json;
    if(_postMyFCMDeviceRequest.has_value()) {
        json = (_postMyFCMDeviceRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/fcm-device";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::removeMyStar(
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

auto MeApi::removeMyUserTag(
    const std::string& _tagId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/tags/{tagId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_tagId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "tagId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::revokeMySession(
    const std::string& _sessionId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/sessions/{sessionId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_sessionId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "sessionId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "sessionId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::revokeMyToken(
    const std::string& _tokenId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/tokens/{tokenId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_tokenId);
        constexpr auto style = Helper::SerializeStyle::simple;
        auto serialized = Helper::serialize(style, "tokenId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tokenId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}

auto MeApi::setChannelSubscribeLevel(
    const std::string& _channelId, 
    const std::optional<PutChannelSubscribeLevelRequest>& _putChannelSubscribeLevelRequest
){
    Json::Value json;
    if(_putChannelSubscribeLevelRequest.has_value()) {
        json = (_putChannelSubscribeLevelRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Put);

    std::string endpoint_path = "/users/me/subscriptions/{channelId}";
    
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

auto MeApi::unlinkExternalAccount(
    const std::optional<PostUnlinkExternalAccount>& _postUnlinkExternalAccount
){
    Json::Value json;
    if(_postUnlinkExternalAccount.has_value()) {
        json = (_postUnlinkExternalAccount.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/ex-accounts/unlink";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);


    return std::forward_as_tuple(result, response);
}


}
