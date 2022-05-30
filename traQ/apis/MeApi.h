#ifndef TRAQ_MeApi_H
#define TRAQ_MeApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ActiveOAuth2Token.h>
#include <traQ/models/ExternalProviderUser.h>
#include <traQ/models/GetNotifyCitation.h>
#include <traQ/models/LoginSession.h>
#include <traQ/models/MyChannelViewState.h>
#include <traQ/models/MyUserDetail.h>
#include <traQ/models/PatchMeRequest.h>
#include <traQ/models/PatchUserTagRequest.h>
#include <traQ/models/PostLinkExternalAccount.h>
#include <traQ/models/PostMyFCMDeviceRequest.h>
#include <traQ/models/PostStarRequest.h>
#include <traQ/models/PostUnlinkExternalAccount.h>
#include <traQ/models/PostUserTagRequest.h>
#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include <traQ/models/PutMyPasswordRequest.h>
#include <traQ/models/PutNotifyCitationRequest.h>
#include <traQ/models/StampHistoryEntry.h>
#include <traQ/models/UnreadChannel.h>
#include <traQ/models/UserSettings.h>
#include <traQ/models/UserSubscribeState.h>
#include <traQ/models/UserTag.h>


namespace traQApi {

class MeApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    MeApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    MeApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    MeApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    MeApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // チャンネルをスターに追加
    auto addMyStar(
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


    // 自分にタグを追加
    auto addMyUserTag(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分のアイコン画像を変更
    auto changeMyIcon(
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


    // メッセージ引用通知の設定情報を変更
    auto changeMyNotifyCitation(
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


    // 自分のパスワードを変更
    auto changeMyPassword(
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


    // 自分のユーザー情報を変更
    auto editMe(
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


    // 自分のタグを編集
    auto editMyUserTag(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // 自分のユーザー詳細を取得
    auto getMe(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分のチャンネル購読状態を取得
    auto getMyChannelSubscriptions(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserSubscribeState> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserSubscribeState>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 外部ログインアカウント一覧を取得
    auto getMyExternalAccounts(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<ExternalProviderUser> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<ExternalProviderUser>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分のアイコン画像を取得
    auto getMyIcon(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // メッセージ引用通知の設定情報を取得
    auto getMyNotifyCitation(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // QRコードを取得
    auto getMyQRCode(
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
            constexpr auto style = __Helper::SerializeStyle::form;
            auto serialized_list = __Helper::serialize_explode(style, "token", jsonobj);
            query_strs.assign(serialized_list.begin(), serialized_list.end());
        }
        
        req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<drogon::UploadFile> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分のログインセッションリストを取得
    auto getMySessions(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<LoginSession> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<LoginSession>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スタンプ履歴を取得
    auto getMyStampHistory(
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

        auto response_json = response->getJsonObject();
        std::optional<std::vector<StampHistoryEntry>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<StampHistoryEntry> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<StampHistoryEntry>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // スターチャンネルリストを取得
    auto getMyStars(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<std::string> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<std::string>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 有効トークンのリストを取得
    auto getMyTokens(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<ActiveOAuth2Token> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<ActiveOAuth2Token>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 未読チャンネルを取得
    auto getMyUnreadChannels(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UnreadChannel> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UnreadChannel>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自分のタグリストを取得
    auto getMyUserTags(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<UserTag> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<UserTag>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 自身のチャンネル閲覧状態一覧を取得
    auto getMyViewStates(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<MyChannelViewState> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<MyChannelViewState>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // ユーザー設定を取得
    auto getUserSettings(
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

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            response_object.emplace(*response_json);
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // 外部ログインアカウントを紐付ける
    auto linkExternalAccount(
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


    // チャンネルを既読にする
    auto readChannel(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "channelId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // FCMデバイスを登録
    auto registerFCMDevice(
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


    // チャンネルをスターから削除します
    auto removeMyStar(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "channelId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // 自分からタグを削除します
    auto removeMyUserTag(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "tagId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tagId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // セッションを無効化
    auto revokeMySession(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "sessionId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "sessionId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // トークンの認可を取り消す
    auto revokeMyToken(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "tokenId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "tokenId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // チャンネル購読レベルを設定
    auto setChannelSubscribeLevel(
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
            constexpr auto style = __Helper::SerializeStyle::simple;
            auto serialized = __Helper::serialize(style, "channelId", jsonobj);
            endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);


        return std::forward_as_tuple(result, response);
    }


    // 外部ログインアカウントの紐付けを解除
    auto unlinkExternalAccount(
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


};

}

#endif
