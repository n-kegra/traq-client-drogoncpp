#ifndef TRAQ_FileApi_H
#define TRAQ_FileApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/FileInfo.h>
#include <traQ/models/ThumbnailType.h>


namespace traQApi {

class FileApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    FileApi(std::string _baseurl_host, std::string _baseurl_path);
    
    FileApi& setBearerToken(std::string _token);
    FileApi& setBasicAuth(std::string _username, std::string _password);
    FileApi& setApikey(std::string _apikey);


    // ファイルを削除
    void
    deleteFile(
        const std::string& _fileId
    );

    // ファイルをダウンロード
    drogon::HttpResponsePtr
    getFile(
        const std::string& _fileId, 
        const std::optional<int32_t>& _dl
    );

    // ファイルメタを取得
    FileInfo
    getFileMeta(
        const std::string& _fileId
    );

    // ファイルメタのリストを取得
    std::vector<FileInfo>
    getFiles(
        const std::optional<std::string>& _channelId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order, 
        const std::optional<bool>& _mine
    );

    // サムネイル画像を取得
    drogon::HttpResponsePtr
    getThumbnailImage(
        const std::string& _fileId, 
        const std::optional<ThumbnailType>& _type
    );

    // ファイルをアップロード
    FileInfo
    postFile(
        const drogon::UploadFile& _file, 
        const std::string& _channelId
    );

};

}

#endif
