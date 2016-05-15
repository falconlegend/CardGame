//
//  Loby.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef Loby_h
#define Loby_h

#include "RoomEntity.h"

class CCharacter;
class CGame;
class CLoby : public IRoomEntity<CLoby>{
public:
    
    CLoby() = delete;
    
    /**
     * @brief 建構式
     * @param 大廳物件ＩＤ
     * @param 大廳名稱
     * @param 可加入玩家上限 (預設 200人)
     * @param 可創造房間上限 (預設 100間)
     */
    CLoby(int _ID, const char* _GivenName, unsigned int _PlayerLimit = 200, unsigned int _RoomLimit = 100) :
    IRoomEntity(IEntity::eLoby, _ID, _GivenName, _PlayerLimit), m_nRoomLimit(_RoomLimit) {};
   
    /**
     * @brief 複製行為
     */
    CLoby(CLoby* Loby);
    
    virtual ~CLoby();
    virtual void init();
    
public:
    
    /*
     * @brief 玩家創造房間
     */
    void CreateRoom(CGame* _game);
    
    /*
     * @brief 玩家刪除房間
     */
    void DeleteRoom(CGame* _game);
    
    /*
     * @brief 玩家離開大廳
     */
    void Join(CCharacter* _entityID);
    
    /*
     * @brief 玩家離開大廳
     */
    void Leave(CCharacter* _entityID);
    
    /*
     * @brief 改變狀態
     */
    bool SetState(ERoomState _state);
    
    /*
     * @brief 設定旗標
     */
    bool SetFlag (ERoomFlag  _state);
    
    /*
     * @brief 檢查大廳內的遊戲房是否已滿
     */
    bool IsGameFull(){return  m_kRoomList.size() >= m_nRoomLimit;};
    
protected:

    typedef std::vector<IEntity*> RoomVec;
    
    CC_SYNTHESIZE_READONLY(RoomVec, m_kRoomList, RoomList);
    CC_SYNTHESIZE_READONLY(unsigned int, m_nRoomLimit, RoomLimit);
};

#endif /* Loby_h */
