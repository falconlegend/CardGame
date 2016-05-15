//
//  Entity.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef Entity_h
#define Entity_h

#include <stdio.h>
#include "cocos2d.h"

/*
 * @breif Abstart interface of all in game Entity, inheirted form cocos2d::Ref.
 */
class IEntity : public cocos2d::Ref{
public:
    enum EEntityType{
        eNone,
        eLoby,
        eRoom,
        eChar,
    };
public:
    IEntity() : m_ID(0), m_UserData(0), m_UserObject(0), m_Type(eNone){};
    IEntity(int _id, EEntityType _type) : m_ID(_id), m_UserData(0), m_UserObject(0), m_Type(_type){};
    ~IEntity(){};
    
protected:
    typedef unsigned int EntityID;
    typedef unsigned int EntityType;
    
    CC_SYNTHESIZE_READONLY(EntityID     , m_ID        , ID        );
    CC_SYNTHESIZE_READONLY(EntityType   , m_Type      , Type      );
    CC_SYNTHESIZE         (void*        , m_UserData  , UserData  );
    CC_SYNTHESIZE         (cocos2d::Ref*, m_UserObject, UserObject);
};


#endif /* Entity_h */
