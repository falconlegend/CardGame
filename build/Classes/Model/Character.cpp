//
//  Character.cpp
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//

#include "Character.h"

CCharacter::~CCharacter(){
    
}

void CCharacter::init(){
    CCLOGINFO("Create CChar id[%d] name[%s] RoundWins[%d], RoundLost[%d]", m_ID, m_GivenName, m_nRoundWins, m_nRoundLost);
}