#ifndef TRAQ_UserTagApi_H
#define TRAQ_UserTagApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/PatchUserTagRequest.h>
#include <traQ/models/PostUserTagRequest.h>
#include <traQ/models/Tag.h>
#include <traQ/models/UserTag.h>


namespace traQApi {

class UserTagApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    UserTagApi(std::string _baseurl_host, std::string _baseurl_path);
    
    UserTagApi& setBearerToken(std::string _token);
    UserTagApi& setBasicAuth(std::string _username, std::string _password);
    UserTagApi& setApikey(std::string _apikey);


    // 自分にタグを追加
    UserTag
    addMyUserTag(
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );

    // ユーザーにタグを追加
    UserTag
    addUserTag(
        const std::string& _userId, 
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );

    // 自分のタグを編集
    void
    editMyUserTag(
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );

    // ユーザーのタグを編集
    void
    editUserTag(
        const std::string& _userId, 
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );

    // 自分のタグリストを取得
    std::vector<UserTag>
    getMyUserTags(
    );

    // タグ情報を取得
    Tag
    getTag(
        const std::string& _tagId
    );

    // ユーザーのタグリストを取得
    std::vector<UserTag>
    getUserTags(
        const std::string& _userId
    );

    // 自分からタグを削除します
    void
    removeMyUserTag(
        const std::string& _tagId
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
