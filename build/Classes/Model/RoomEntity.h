//
//  RoomEntity.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef RoomEntity_h
#define RoomEntity_h

#include "Entity.h"

/*
 * @breif Abstart interface of all room type Entity, inheirted form IEntity. (e.g. Lobby, Gameroom)
 */
template <class T>
class IRoomEntity : public IEntity{
public:
    enum ERoomState{
        eRoomNone,
        eRoomPrepare,       // 房間準備中
        eRoomWait,          // 等待玩家加入
        eRoomReady,         // 所有玩家完成準備狀態
        eRoomStart,         // 遊戲進行中
        eRoomPause,         // 若有連線失敗情形情或是網路不穩定 房間可以暫停（有限制回覆秒數）
        eRoomEnd,           // 遊戲結束，發獎與重置
    };
    
    // 這邊介紹一下房間類型，這些狀態可以套用大廳或是單一房間，效果不會堆疊
    enum ERoomFlag{
        eRoomNewbie     = 0x0000000000000001,     //< 新手保護  （在思考需求什麼樣類型加成）
        eRoomDoubleCoin = 0x0000000000000002,     //< 雙倍金幣房
        eRoomDoubleExp  = 0x0000000000000004,     //< 雙倍經驗房
        eRoomGambleMode = 0x0000000000000008,     //< 賭注模式   (除了系統給的貨幣之外，玩家可以而外賭注)
    };
    
public:
    static T* create(int _id, const char* _GivenName, unsigned int _CharLimit){
        T* pInstance = new T(_id, _GivenName, _CharLimit);
        pInstance->init();
        return pInstance;
    };
    
    IRoomEntity()
    : IEntity(), m_GivenName(0), m_nCharLimit(0),m_nFlag(0){m_kCharList.clear();};
    
    IRoomEntity(EEntityType _type, int _id, const char* _GivenName, unsigned int _CharLimit)
    : IEntity(_id, _type), m_GivenName(_GivenName), m_nCharLimit(_CharLimit), m_nFlag(0){m_kCharList.clear();};
    
    virtual ~IRoomEntity(){};
    
    virtual void init() = 0;
    
public:
    
    /*
     * @brief 回傳目前房間狀態。
     */
    inline int GetState(){return m_nState;};
    
    /*
     * @brief 屬性檢查，有些屬性可能不會適合所有房型，所以可以在子類別中擋下來。
     */
    inline int GetFlag(){return m_nFlag;};
    
    /*
     * @brief 房間是否滿房
     */
    inline bool IsFull(){return m_kCharList.size() >= m_nCharLimit;};
    
    /*
     * @brief 房間是否鎖定
     */
    inline bool IsLock(){return m_bLock;};
    
public:
    // 房間功能基本操作 (由子類別實作)
    virtual void Join(IEntity* _entity) = 0;
    virtual void Leave(IEntity* _entity) = 0;
    virtual bool SetFlag(ERoomFlag _state) = 0;
    virtual bool SetState(ERoomState _state) = 0;
    virtual bool SetLock(bool _lock) = 0;
    
protected:
    typedef std::vector<IEntity*> CharVec;
    
    cocos2d::Timer* m_pkTime;
    ERoomState      m_nState = eRoomNone;
    bool            m_bLock = false;
    
    CC_SYNTHESIZE         (const char* , m_GivenName   , GivenName);    //< 遊戲房間名稱
    CC_SYNTHESIZE_READONLY(CharVec     , m_kCharList , CharList);       //< 目前玩家數量
    CC_SYNTHESIZE_READONLY(unsigned int, m_nCharLimit, CharLimit);      //< 上限玩家數量
    CC_SYNTHESIZE_READONLY(int         , m_nFlag       , Flag);         //< 房間狀態旗標
};

#endif /* RoomEntity_h */
