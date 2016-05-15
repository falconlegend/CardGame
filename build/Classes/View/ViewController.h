//
//  ViewController.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#ifndef ViewController_h
#define ViewController_h

#include <stdio.h>
#include "cocos2d.h"
#include "../definitions.h"

/*
 * @brief ViewController 負責顯示遊戲畫面，接收玩家輸入
 *        通常由 View ＆ Network 進行更新。
 */
class CViewController : public Singleton<CViewController>{
public:
    enum EUIType{
        eS_Main,
        eS_Game,
        eS_Lobby,
        eS_Room,
    };
public:
    CViewController();
    virtual ~CViewController();
    virtual void init();
    
    /**
     * @brief
     */
    void ShowMain();
    
protected:
    CC_SYNTHESIZE(cocos2d::Scene*, m_pkScene, MainScene);
    CC_SYNTHESIZE_READONLY(DDef::NodeMap, m_AllUILayout, LayerMap);
};

#endif /* ViewController_h */
