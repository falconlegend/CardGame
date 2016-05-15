//
//  Character.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef Character_h
#define Character_h

#include <stdio.h>
#include "LifeEntity.h"

class CCharacter : public ILifeEntity<CCharacter>{
public:
    
    static CCharacter* create(EntityID _Id, EntityID _NodeID, const char* _GivenName, unsigned int wins, unsigned int lost){
        CCharacter* ch = new CCharacter(_Id, _NodeID, _GivenName, wins, lost);
        ch->init();
        return ch;
    };
    
    CCharacter(EntityID _ID, EntityID _NodeID, const char* _GivenName, unsigned int wins, unsigned int lost)
    : ILifeEntity(IEntity::eChar, _ID , _NodeID), m_GivenName(_GivenName), m_nRoundWins(wins), m_nRoundLost(lost){};
    
    virtual ~CCharacter();
    virtual void init();
public:
    
public:
    
    CC_SYNTHESIZE_READONLY(const char*, m_GivenName, Name);
    CC_SYNTHESIZE_READONLY(unsigned int, m_nRoundWins, RoundWins);
    CC_SYNTHESIZE_READONLY(unsigned int, m_nRoundLost, RoundLost);
    
};


#endif /* Character_h */
