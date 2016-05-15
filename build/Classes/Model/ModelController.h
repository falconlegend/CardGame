//
//  ModelController.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef ModelController_h
#define ModelController_h

#include <stdio.h>
#include "cocos2d.h"
#include "NetBridge.h"
#include "../definitions.h"
#include "Character.h"
#include "Loby.h"
#include "Game.h"


/*
 * @brief ModelController 負責存儲遊戲數據，諸如角色資料，大廳資料，房間資料
 *        通常由 View ＆ Network 進行更新。
 */
class CModelController : public Singleton<CModelController> , public CNetBridge{
public:
    CModelController();
    virtual ~CModelController();
    virtual void init();
    
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
    
    /*
     * @brief 如果玩家未採用facebook登入遊戲的話，呼叫此函式來載入local storage資料
     * @param 角色ＩＤ
     * @return void
     */
    void LoadMainPlayerData();
    
    
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
    
    /*
     * @brief 繼承 CNetBridge 更新本地玩家資料
     * @param Websocket::Data& _data 完整本機角色數據
     * @return 成功與否
     */
    void CreateMainCharData(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 更新本地玩家資料
     * @param Websocket::Data& _data 部分本機角色數據
     * @return 成功與否
     */
    void UpdateMainCharAttr(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 新增暫存中的數據
     * @param Websocket::Data& _data 完整大廳數據
     * @return 成功與否
     */
    void AddLobyData(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 新增暫存中的數據
     * @param Websocket::Data& _data 完整遊戲間數據
     * @return 成功與否
     */
    void AddGameData(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 新增暫存中的數據
     * @param Websocket::Data& _data 完整角色數據
     * @return 成功與否
     */
    void AddCharData(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 新增暫存中的數據
     * @param Websocket::Data& _data 部分角色數據
     * @return 成功與否
     */
    void UpdateCharAttr(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 新增暫存中的數據
     * @param Websocket::Data& _data
     * @return 成功與否
     */
    void UpdateGameAttr(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 新增暫存中的數據
     * @param Websocket::Data& _data
     * @return 成功與否
     */
    void UpdateLobyAttr(cocos2d::network::WebSocket::Data& _data);
    
    /*
     * @brief 繼承 CNetBridge 刪除暫存中的數據
     * @param 大廳物件
     * @return 成功與否
     */
    void DelLobyData(cocos2d::network::WebSocket::Data&);
    
    /*
     * @brief 繼承 CNetBridge 刪除暫存中的數據
     * @param 遊戲間物件
     * @return 成功與否
     */
    void DelGameData(cocos2d::network::WebSocket::Data&);
    
    /*
     * @brief 繼承 CNetBridge 刪除暫存中的數據
     * @param 角色物件
     * @return 成功與否
     */
    void DelCharData(cocos2d::network::WebSocket::Data&);
    

private:
    /*
     * @brief 儲存本地玩玩家資料至local storage
     * @param 全部儲存
     * @return 成功與否
     */
    bool save(bool _all = false);
    
    /*
     * @brief 驗證紀錄與暫存中的數據
     * @return 兩筆資料是否符合
     */
    bool VerifiyUserData();
    
protected:
    CC_SYNTHESIZE_READONLY(unsigned int, mMainPlayerID, MainPlayerID);  //<  本機玩家ID
    
    CC_SYNTHESIZE_READONLY(DDef::RefMap, mAllCharData, AllCharData);    //<  所有角色資料
    CC_SYNTHESIZE_READONLY(DDef::RefMap, mAllGameData, AllGameData);    //<  所有遊戲資料
    CC_SYNTHESIZE_READONLY(DDef::RefMap, mAllLobyData, AllLobyData);    //<  所有大廳資料
};

class DBKEY{
protected:
    static const char* user_id;          //< 用戶ＩＤ        （預設facebookid）
    static const char* given_name;       //< 用戶名稱
    static const char* round_wins;       //< 勝場次數總計
    static const char* round_lost;       //< 落敗次數總計
    static const char* time_stamp;       //< 最近一次儲存時間
    friend class CModelController;       //< 只允許在 CModelController 中存取。
};

#endif /* ModelController_h */
