#ifndef TRAQ_UserApi_H
#define TRAQ_UserApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/DMChannel.h>
#include <traQ/models/Message.h>
#include <traQ/models/PatchUserRequest.h>
#include <traQ/models/PatchUserTagRequest.h>
#include <traQ/models/PostMessageRequest.h>
#include <traQ/models/PostUserRequest.h>
#include <traQ/models/PostUserTagRequest.h>
#include <traQ/models/PutUserPasswordRequest.h>
#include <traQ/models/User.h>
#include <traQ/models/UserDetail.h>
#include <traQ/models/UserStats.h>
#include <traQ/models/UserTag.h>


namespace traQApi {

class UserApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    UserApi(std::string _baseurl_host, std::string _baseurl_path);
    
    UserApi& setBearerToken(std::string _token);
    UserApi& setBasicAuth(std::string _username, std::string _password);
    UserApi& setApikey(std::string _apikey);


    // ユーザーにタグを追加
    UserTag
    addUserTag(
        const std::string& _userId, 
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );

    // ユーザーのアイコン画像を変更します
    void
    changeUserIcon(
        const std::string& _userId, 
        const drogon::UploadFile& _file
    );

    // ユーザーのパスワードを変更
    void
    changeUserPassword(
        const std::string& _userId, 
        const std::optional<PutUserPasswordRequest>& _putUserPasswordRequest
    );

    // ユーザーを登録
    UserDetail
    createUser(
        const std::optional<PostUserRequest>& _postUserRequest
    );

    // ユーザー情報を変更
    void
    editUser(
        const std::string& _userId, 
        const std::optional<PatchUserRequest>& _patchUserRequest
    );

    // ユーザーのタグを編集
    void
    editUserTag(
        const std::string& _userId, 
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );

    // ダイレクトメッセージのリストを取得
    std::vector<Message>
    getDirectMessages(
        const std::string& _userId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );

    // ユーザー詳細情報を取得
    UserDetail
    getUser(
        const std::string& _userId
    );

    // DMチャンネル情報を取得
    DMChannel
    getUserDMChannel(
        const std::string& _userId
    );

    // ユーザーのアイコン画像を取得
    drogon::HttpResponsePtr
    getUserIcon(
        const std::string& _userId
    );

    // ユーザー統計情報を取得
    UserStats
    getUserStats(
        const std::string& _userId
    );

    // ユーザーのタグリストを取得
    std::vector<UserTag>
    getUserTags(
        const std::string& _userId
    );

    // ユーザーのリストを取得
    std::vector<User>
    getUsers(
        const std::optional<bool>& _includeSuspended, 
        const std::optional<std::string>& _name
    );

    // ダイレクトメッセージを送信
    Message
    postDirectMessage(
        const std::string& _userId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );

    // ユーザーからタグを削除します
    void
    removeUserTag(
        const std::string& _userId, 
        const std::string& _tagId
    );

};

}

#endif
