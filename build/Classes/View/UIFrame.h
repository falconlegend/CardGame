//
//  UIFrame.h
//  build
//
//  Created by Deflinhec on 2016/5/15.
//
//

#ifndef UIFrame_h
#define UIFrame_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"


/**
 * @brief Interface of csb file
 */

template<class T>
class IUIFrame : public cocos2d::Node{
public:
    static cocos2d::Node* create(const char* _csbfile){
        T* temp = new T();
        temp->m_pkNode = cocos2d::CSLoader::createNode(_csbfile);
        CCASSERT(temp->m_pkNode, "Load csb file failed");
        temp->init(temp->m_pkNode);
        return temp->m_pkNode;
    }
    
    /**
     * @brief Hook childs and component
     */
    virtual void init(cocos2d::Node* _node) = 0;
    
    void IGetNode(cocos2d::Node* _node, const char* _name) {
        _node = m_pkNode->getChildByName<cocos2d::Node*>(_name);
        CCASSERT(_node, "Load child failed");
    }
    
    void IGetBtn(cocos2d::ui::Button* _btn, const char* _name){
        _btn = m_pkNode->getChildByName<cocos2d::ui::Button*>(_name);
        CCASSERT(_btn, "Load child failed");
    }

    cocos2d::Node* m_pkNode;
};

#endif /* UIFrame_h */
