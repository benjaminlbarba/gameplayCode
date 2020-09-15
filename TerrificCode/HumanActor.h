#pragma once

//#include "gameObject.h"
#include "ActorSupport.h"
#include "HumanActorFlags.h"
#include "Health.h"
#include <list>

const int MAX_FLAGS = 18;

/**
 * Parent class for all Human Actors.
 * Use Player class for player.
 * */
class HumanActor
{
    //group types together
    private: bool m_isPlayer; //keeping this because could be a quick way to check an actor as not being a player
    private: bool m_isEnemy; 
    private: list<Component*> componentList; //wasn't 100% sure on the use case for this.
    private: humanActorFlags m_flags; 

    protected: 
        string m_name;
        Position m_pos;
        Rotation m_rot; 
    
    public: 
        Actor* m_target;
        HumanActor(int startingHealth, bool isPlayer); 
        Health healthStat;
        string GetName();
        void setTarget(Actor* currentTarget);
        void setName(string myName);
        
        bool isPlayer();
        bool isEnemy();

        void setFlag(humanActorFlags flagToSet, bool set);
        bool checkForFlag(humanActorFlags flagToCheck);

};