//
//  Game.cpp
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#include "Game.h"
#include "Character.h"

CGame::~CGame(){
    
}

void CGame::init(){
    CCLOGINFO("Create CGame id[%d] name[%s] player_count[%lu], player_limit[%d]", m_ID, m_GivenName, m_kCharList.size(), m_nCharLimit);
}

void CGame::Start(){
    
    // 檢查是否滿人
    if (!IsFull())
        return;

}

void CGame::Pause(){
    m_pkTime->cancel();
}

void CGame::Join(CCharacter *_entity){
    
    // 檢查玩家是否已在房間裡
    CharVec::iterator it = std::find(m_kCharList.begin(), m_kCharList.end(), _entity);
    if (it != m_kCharList.end())
        return;
    
    // 檢查房間是否滿人
    if (IsFull())
        return;
    
    // 檢查房間是否上鎖
    if (IsLock())
        return;
    
    
    m_kCharList.push_back(_entity);
}

void CGame::Leave(CCharacter *_entity){
    
    // 檢查玩家是否在房間裡
    CharVec::iterator it = std::find(m_kCharList.begin(), m_kCharList.end(), _entity);
    if (it == m_kCharList.end())
        return;
    
    m_kCharList.erase(it);
}

bool CGame::SetFlag(IRoomEntity<CGame>::ERoomFlag _state){
    switch (_state) {
        case IRoomEntity<CGame>::eRoomNewbie:       m_nFlag &= eRoomNewbie;     return true;
        case IRoomEntity<CGame>::eRoomDoubleCoin:   m_nFlag &= eRoomDoubleCoin; return true;
        case IRoomEntity<CGame>::eRoomDoubleExp:    m_nFlag &= eRoomDoubleExp;  return true;
        case IRoomEntity<CGame>::eRoomGambleMode:   m_nFlag &= eRoomDoubleExp;  return true;
    }
    return true;
}

bool CGame::SetState(IRoomEntity<CGame>::ERoomState _state){
    switch (_state) {
        case IRoomEntity<CGame>::eRoomNone:    m_nState = eRoomNone;     return false;
        case IRoomEntity<CGame>::eRoomPrepare: m_nState = eRoomPrepare;  return true;
        case IRoomEntity<CGame>::eRoomWait:    m_nState = eRoomWait;     return true;
        case IRoomEntity<CGame>::eRoomReady:   m_nState = eRoomReady;    return true;
        case IRoomEntity<CGame>::eRoomStart:   m_nState = eRoomStart;    return true;
        case IRoomEntity<CGame>::eRoomPause:   m_nState = eRoomPause;    return true;
        case IRoomEntity<CGame>::eRoomEnd:     m_nState = eRoomEnd;      return true;
    }
    return true;
}