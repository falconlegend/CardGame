//
//  ViewController.cpp
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#include "ViewController.h"
#include "MainLayer.h"
#include "LobbyLayer.h"
#include "GameLayer.h"
#include "RoomLayer.h"

USING_NS_CC;

CViewController::CViewController(){

}

CViewController::~CViewController(){
    
}

void CViewController::init(){
    
    m_pkScene = Scene::create();
    
    m_AllUILayout.insert(std::pair<int, Node*>(EUIType::eS_Main ,CMainLayer::create("MainLayer.csb")));
    m_AllUILayout.insert(std::pair<int, Node*>(EUIType::eS_Lobby,CLobbyLayer::create("LobbyLayer.csb")));
    m_AllUILayout.insert(std::pair<int, Node*>(EUIType::eS_Room ,CRoomLayer::create("RoomLayer.csb")));
    m_AllUILayout.insert(std::pair<int, Node*>(EUIType::eS_Game ,CGameLayer::create("GameLayer.csb")));
    
    for (int i = 0; i < m_AllUILayout.size(); i++) {
        if (!m_AllUILayout[i])
            return;
        m_AllUILayout[i]->setVisible(false);
        m_pkScene->addChild(m_AllUILayout[i]);
    }
}

void CViewController::ShowMain(){
    m_AllUILayout[eS_Main]->setVisible(true);
}