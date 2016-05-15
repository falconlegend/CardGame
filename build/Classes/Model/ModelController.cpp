//
//  ModelController.cpp
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#include "ModelController.h"
#include "Utils.h"

CModelController::CModelController(){
    mAllCharData.clear();
    mAllGameData.clear();
    mAllLobyData.clear();
}

CModelController::~CModelController(){
    mAllCharData.clear();
    mAllGameData.clear();
    mAllLobyData.clear();
}

void CModelController::init(){

}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void CModelController::CreateMainCharData(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::UpdateMainCharAttr(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::AddCharData(cocos2d::network::WebSocket::Data& _data){

}

void CModelController::AddGameData(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::AddLobyData(cocos2d::network::WebSocket::Data& _data){

}

void CModelController::DelCharData(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::DelGameData(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::DelLobyData(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::UpdateLobyAttr(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::UpdateGameAttr(cocos2d::network::WebSocket::Data& _data){
    
}

void CModelController::UpdateCharAttr(cocos2d::network::WebSocket::Data& _data){
    
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool CModelController::save(bool _all){
    
    return true;
}

bool CModelController::VerifiyUserData(){
    bool         bIsDirty   = false;
    unsigned int nUserId    = 0;
    std::string  kName      = "";
    unsigned int nRoundwins = 0;
    unsigned int nRoundlost = 0;
    unsigned int nTimestamp = 0;
    
    // 完全沒有儲存紀錄的新玩家
    if (nUserId == 0 && nTimestamp == 0 && kName == ""){
        
        // 通知ViewController顯示玩家第一次登入介面，包含玩家名稱命名
        CCLOGINFO("No last saved data found.");
        bIsDirty  = true;
    }
    
    // 擁有儲存紀錄但登入用戶與上次不符
    if (nUserId != 0 && nUserId != mMainPlayerID){
        
        // 通知ViewController顯示玩家已有登陸紀錄，是否以現在的#define USERDB cocos2d::UserDefault::getInstance()

        bIsDirty = true;
    }
    
    // 擁有儲存紀錄但系統時間不符        處理作法：先創建玩家物件之後再去Server端 load 資料
    if (nTimestamp >= GET_CUR_TIME) {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(InvokeParam::LFSMainPlayerData);
        bIsDirty = true;
    }
    
    if (bIsDirty) {
        CCLOGINFO("Character id[%d] initialized.", mMainPlayerID);
    }
    
    return !bIsDirty;
    
}

void CModelController::LoadMainPlayerData(){
    
    //TODO: Get device uuid and append to mMainPlayerId;
    
    unsigned int   nUserId    = USERDB->getIntegerForKey(DBKEY::user_id   , 0);
    unsigned int   nRoundlost = USERDB->getIntegerForKey(DBKEY::round_lost, 0);
    unsigned int   nRoundwins = USERDB->getIntegerForKey(DBKEY::round_wins, 0);
    unsigned int   nTimestamp = USERDB->getFloatForKey(DBKEY::time_stamp, 0);
    std::string    kName      = USERDB->getStringForKey (DBKEY::given_name, "");
    
    if (!VerifiyUserData()) {
        return;
    }
    
    CCLOGINFO("Load last saved data id[%d] name[%s] roundlost[%d] roundwin[%d] timestamp[%d].",
              nUserId, kName.c_str(), nRoundlost, nRoundwins, nTimestamp);
    
    save();
}

const char* DBKEY::user_id = "user_id";
const char* DBKEY::given_name = "given_name";
const char* DBKEY::round_wins = "round_wins";
const char* DBKEY::round_lost = "round_lost";
const char* DBKEY::time_stamp = "time_stamp";