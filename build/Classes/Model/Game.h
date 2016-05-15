//
//  Game.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef Game_h
#define Game_h

#include "RoomEntity.h"
class CCharacter;
class CGame : public IRoomEntity<CGame>{
public:
    
    CGame() = delete;
    
    /**
     * @brief 建構式
     * @param 房間物件ＩＤ
     * @param 房間名稱
     * @param 玩家上限 (預設 2)
     * @param 每回合時間 (預設 15)
     */
    CGame(int _ID, const char* _GivenName, unsigned int _PlayerLimit = 2, unsigned int _RoundTime = 15) :
    IRoomEntity(IEntity::eRoom, _ID, _GivenName, _PlayerLimit), m_nRoundTime(_RoundTime) {};
    
    virtual ~CGame();
    
    virtual void init();
public:
    
    /*
     * @brief 開始遊戲
     */
    void Start();
    
    /*
     * @brief 暫停遊戲
     */
    void Pause();
    
    /*
     * @brief 玩家加入房間
     */
    void Join(CCharacter* _entity);
    
    /*
     * @brief 玩家離開房間
     */
    void Leave(CCharacter* _entity);
    
    /*
     * @brief 改變狀態
     */
    bool SetState(ERoomState _state);
    
    /*
     * @brief 設定旗標
     */
    bool SetFlag (ERoomFlag  _state);
protected:
    CC_SYNTHESIZE_READONLY(unsigned int , m_nRoundTime, RoundTime);
};

#endif /* Game_h */
