#ifndef _FileApi_H
#define _FileApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/FileInfo.h"
#include "../models/ThumbnailType.h"


namespace traQ {

class FileApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    FileApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    FileApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    FileApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    FileApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // ファイルを削除
    auto deleteFile(
        const std::string& _fileId
    );


    // ファイルをダウンロード
    auto getFile(
        const std::string& _fileId, 
        const std::optional<int32_t>& _dl
    );


    // ファイルメタを取得
    auto getFileMeta(
        const std::string& _fileId
    );


    // ファイルメタのリストを取得
    auto getFiles(
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
    auto getThumbnailImage(
        const std::string& _fileId, 
        const std::optional<ThumbnailType>& _type
    );


    // ファイルをアップロード
    auto postFile(
        const drogon::UploadFile& _file, 
        const std::string& _channelId
    );


};

}

#endif
