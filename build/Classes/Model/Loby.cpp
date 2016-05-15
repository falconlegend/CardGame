//
//  Loby.cpp
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#include "Loby.h"
#include "Game.h"
#include "Character.h"

CLoby::~CLoby(){
    
}

void CLoby::init(){
    CCLOGINFO("Create CLoby id[%d] name[%s] player_count[%lu], player_limit[%d]", m_ID, m_GivenName, m_kCharList.size(), m_nCharLimit);
}

void CLoby::CreateRoom(CGame* _game){
    
    RoomVec::iterator it = std::find(m_kRoomList.begin(), m_kRoomList.end(), _game);
    if ((*it)->getID() != _game->getID())
        return;
    
    
}

void CLoby::DeleteRoom(CGame* _game){

}

void CLoby::Join(CCharacter *_entity){

    // 檢查玩家是否已在大廳裡
    CharVec::iterator it = std::find(m_kCharList.begin(), m_kCharList.end(), _entity);
    if (it != m_kCharList.end())
        return;
    
    // 檢查大廳是否滿人
    if (IsFull())
        return;
    
    // 檢查大廳是否上鎖
    if (IsLock())
        return;
    
    
    m_kRoomList.push_back(_entity);
}

void CLoby::Leave(CCharacter *_entity){
    
    // 檢查玩家是否在大廳裡
    RoomVec::iterator it = std::find(m_kRoomList.begin(), m_kRoomList.end(), _entity);
    if (it == m_kRoomList.end())
        return;
    
    m_kRoomList.erase(it);
}

bool CLoby::SetFlag(IRoomEntity<CLoby>::ERoomFlag _state){
    switch (_state) {
        case IRoomEntity<CLoby>::eRoomNewbie:       m_nFlag &= eRoomNewbie;     return true;
        case IRoomEntity<CLoby>::eRoomDoubleCoin:   m_nFlag &= eRoomDoubleCoin; return true;
        case IRoomEntity<CLoby>::eRoomDoubleExp:    m_nFlag &= eRoomDoubleExp;  return true;
        case IRoomEntity<CLoby>::eRoomGambleMode:                               return false;
    }
    return true;
}

bool CLoby::SetState(IRoomEntity<CLoby>::ERoomState _state){
    switch (_state) {
        case IRoomEntity<CGame>::eRoomNone:    m_nState = eRoomNone;     return false;
        case IRoomEntity<CGame>::eRoomPrepare: m_nState = eRoomPrepare;  return true;
        case IRoomEntity<CGame>::eRoomWait:    m_nState = eRoomWait;     return true;
        case IRoomEntity<CGame>::eRoomReady:   m_nState = eRoomNone;     return false;
        case IRoomEntity<CGame>::eRoomStart:   m_nState = eRoomNone;     return false;
        case IRoomEntity<CGame>::eRoomPause:   m_nState = eRoomNone;     return false;
        case IRoomEntity<CGame>::eRoomEnd:     m_nState = eRoomNone;     return false;
    }
    return true;
}