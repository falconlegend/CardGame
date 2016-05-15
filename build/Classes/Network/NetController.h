//
//  NetController.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef NetController_h
#define NetController_h

#include <stdio.h>
#include "cocos2d.h"
#include "../definitions.h"
#include "PluginFacebook/PluginFacebook.h"
#include "network/WebSocket.h"

using namespace cocos2d::network;

/*
 * @brief NetController 負責處理網路通訊，接收伺服器端傳送的數據，與發送數據至伺服器端
 * 通知 Model & View 進行更新
 */

class CCharacter;
class CGame;
class CLoby;
class CNetBridge;
class CNetController : public Singleton<CNetController>, public sdkbox::FacebookListener, public WebSocket::Delegate{
public:
    CNetController();
    virtual ~CNetController();
    virtual void init();
    
    void RegisterEvent();
    
    /**
     * @brief The model that should be update.
     */
    void SetModelDelegate(CNetBridge* _delegate){m_pkModel = _delegate;};
    
    /**
     * @brief 連接至遊戲專用伺服器
     */
    void ConnectGameServer();
    
private:
    
    /****************************
     * Listening facebook event *
     ****************************/
    
    /**
     * @brief Facebook 用戶登入
     * @param bool 登入狀態
     * @param std::string 訊息
     * @return void
     */
    void onLogin(bool isLogin, const std::string& msg);
    
    /**
     * @brief Facebook 用戶分享成功
     * @param std::string 訊息
     * @return void
     */
    void onSharedSuccess(const std::string& message);
    
    /**
     * @brief Facebook 用戶分享失敗
     * @param std::string 訊息
     * @return void
     */
    void onSharedFailed(const std::string& message);
    
    /**
     * @brief Facebook 用戶分享取消
     * @return void
     */
    void onSharedCancel();
    
    void onAPI(const std::string& key, const std::string& jsonData);
    void onPermission(bool isLogin, const std::string& msg);
    void onFetchFriends(bool ok, const std::string& msg);
    void onRequestInvitableFriends( const sdkbox::FBInvitableFriendsInfo& friends );
    void onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg );
    void onInviteFriendsResult( bool result, const std::string& msg );
    void onGetUserInfo( const sdkbox::FBGraphUser& userInfo );
    
private:
    /*****************************
     * Listening websocket event *
     *****************************/
    
    /**
     * This function to be called after the client connection complete a handshake with the remote server.
     * This means that the WebSocket connection is ready to send and receive data.
     *
     * @param ws The WebSocket object connected
     */
    void onOpen(WebSocket* ws);
    
    /**
     * This function to be called when data has appeared from the server for the client connection.
     *
     * @param ws The WebSocket object connected.
     * @param data Data object for message.
     */
    void onMessage(WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
    
    /**
     * @brief 連接中的WebSocket物件從遠端關閉or無效的協定名稱同時_readyState為State::CLOSING將下乎叫此函示
     * @param 連接中的WebSocket物件
     */
    void onClose(WebSocket* ws);
    
    /**
     * @brief 若有以下情形將會呼叫此函式
     * 1. 客戶端連線失敗。
     * 2. 請求中的用戶無法與遠端伺服器達成協議。
     * 3. 無效的協定名稱同時_readyState為State::CONNECTING.
     * 4. when a socket descriptor needs to be removed from an external polling array. in is again the struct libwebsocket_pollargs containing the fd member to be removed. If you are using the internal polling loop, you can just ignore it and current _readyState is State::CONNECTING.
     *
     * @param ws The WebSocket object connected.
     * @param error WebSocket::ErrorCode enum,would be ErrorCode::TIME_OUT or ErrorCode::CONNECTION_FAILURE.
     */
    void onError(WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);

    
protected:
    
    CNetBridge* m_pkModel;
    
    cocos2d::network::WebSocket* m_pkWebsocket;
};
#endif /* NetController_h */
