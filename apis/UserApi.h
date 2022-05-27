#ifndef _UserApi_H
#define _UserApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/DMChannel.h"
#include "../models/Message.h"
#include "../models/PatchUserRequest.h"
#include "../models/PatchUserTagRequest.h"
#include "../models/PostMessageRequest.h"
#include "../models/PostUserRequest.h"
#include "../models/PostUserTagRequest.h"
#include "../models/PutUserPasswordRequest.h"
#include "../models/User.h"
#include "../models/UserDetail.h"
#include "../models/UserStats.h"
#include "../models/UserTag.h"


namespace traQ {

class UserApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    UserApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    UserApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    UserApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    UserApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // ユーザーにタグを追加
    auto addUserTag(
        const std::string& _userId, 
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );


    // ユーザーのアイコン画像を変更します
    auto changeUserIcon(
        const std::string& _userId, 
        const drogon::UploadFile& _file
    );


    // ユーザーのパスワードを変更
    auto changeUserPassword(
        const std::string& _userId, 
        const std::optional<PutUserPasswordRequest>& _putUserPasswordRequest
    );


    // ユーザーを登録
    auto createUser(
        const std::optional<PostUserRequest>& _postUserRequest
    );


    // ユーザー情報を変更
    auto editUser(
        const std::string& _userId, 
        const std::optional<PatchUserRequest>& _patchUserRequest
    );


    // ユーザーのタグを編集
    auto editUserTag(
        const std::string& _userId, 
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );


    // ダイレクトメッセージのリストを取得
    auto getDirectMessages(
        const std::string& _userId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );


    // ユーザー詳細情報を取得
    auto getUser(
        const std::string& _userId
    );


    // DMチャンネル情報を取得
    auto getUserDMChannel(
        const std::string& _userId
    );


    // ユーザーのアイコン画像を取得
    auto getUserIcon(
        const std::string& _userId
    );


    // ユーザー統計情報を取得
    auto getUserStats(
        const std::string& _userId
    );


    // ユーザーのタグリストを取得
    auto getUserTags(
        const std::string& _userId
    );


    // ユーザーのリストを取得
    auto getUsers(
        const std::optional<bool>& _includeSuspended, 
        const std::optional<std::string>& _name
    );


    // ダイレクトメッセージを送信
    auto postDirectMessage(
        const std::string& _userId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );


    // ユーザーからタグを削除します
    auto removeUserTag(
        const std::string& _userId, 
        const std::string& _tagId
    );


};

}

#endif
