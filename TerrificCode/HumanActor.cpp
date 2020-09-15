#include "HumanActor.h"

HumanActor::HumanActor(int startingHealth, bool isPlayer = false):
     healthStat(startingHealth, MAX_HEALTH),
     m_isPlayer(isPlayer)
    {
        m_flags = HUM_ACTOR_DEFAULT;
    }

// Member functions definitions
string HumanActor::GetName() { 	
    return m_name;
};

void HumanActor::setName(string myName){
    m_name = myName;
}

// -- other useful functions// ...
bool HumanActor::isPlayer(){
    return m_isPlayer;
}

bool HumanActor::isEnemy(){
    return m_isEnemy;
}

void HumanActor::setTarget(Actor* currentTarget){
    m_target = currentTarget;
}

void HumanActor::setFlag(humanActorFlags flagToSet, bool set){
    if (set){
        m_flags = m_flags | flagToSet;
    }
    else{
        m_flags = m_flags & ~flagToSet;
    }
}

bool HumanActor::checkForFlag(humanActorFlags flagToCheck){
    return m_flags & flagToCheck;
}