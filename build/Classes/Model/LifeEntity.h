//
//  LifeEntity.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/14.
//
//

#ifndef LifeEntity_h
#define LifeEntity_h

#include "Entity.h"

/*
 * @breif Abstart interface of all life type Entity, inheirted form IEntity. (e.g. Character)
 */
template <class T>
class ILifeEntity : public IEntity{
public:
    
    static T* create(EntityID _Id, EntityID _NodeID){
        T* ch = new T(_Id, _NodeID);
        ch->init();
        return ch;
    };
    
    ILifeEntity() : IEntity(){};
    
    ILifeEntity(EEntityType _type, EntityID _Id, EntityID _NodeID) : IEntity(_ID, _type), m_nNodeID(_NodeID){};
    
    virtual ~ILifeEntity() {};
    
    virtual void init() = 0;
    
    CC_SYNTHESIZE_READONLY(EntityID, m_nNodeID, NodeID);
};


#endif /* LifeEntity_h */
