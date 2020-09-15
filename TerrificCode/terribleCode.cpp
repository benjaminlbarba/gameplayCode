//add missing libraries
#include "ActorSupport.h" //just prevents compiler errors
#include <string>

using namespace std;

class GameObject {
    virtual string GetName() = 0;
};

class HumanActor : public GameObject {
public:
    bool m_isPlayer;
    bool m_isEnemy;
    bool m_isAlly; //redundant.  Or if neutral state desirable should use ENUM bitmask instead of boolean
    char m_name[2049]; //2049 should be a const char (no "magic numbers") - this could also just be a string
    
    Component* m_componentList; //called list, but only a single pointer component here
    int m_componentCount; //not needed, can just get .size() of list, can create a support wrapper for that if needed

    bool m_flags[18]; //use bitmaks, not boolean array

    double m_x, m_y, m_z; //should be a position vector
    signed char m_yaw, m_pitch, m_roll; //should be a rotation vector.  Why signed char?

    /**TODO: I understand these are pointers to actors external to the humanActor
     *      m_parent: why would the actor have to keep track of what platform it is on?
     *          That should be handled by collision system, so would just remove from here.
     *      m_platform: what would a parent of an actor be in this situation?
     *      m_target: probably the actor the current actor is shooting at
     * 
     *      Choosing to remove first two as they should be handled by separate systems or utility functions that take in
     *      the Actors in question as two separate parameters, e.g., isFacingPlatform(Actor1, Actor2)
     * */
    Actor *m_parent, m_platform, m_target;

    //can create a health system
    int m_hitPoints; //hitpoints used here, health and damage used below.  Should use consistent terminology.
    int m_maxHitPoints; //side note: wasn't sure about this m_ convention for member variabbles.

    // -- other useful variables
    /**
     * TODO: Hard to determine what other variables we'd add without more context on the game.
     * **/
    
    // -- return the debug name for the actor
    string GetName() { return m_name; }
    
    // -- apply the amount of damage to an actor and return remaining HP
    int ApplyDamage(float dmg) { return m_hitPoints - dmg; }
    
    // -- heal player by one point and return the new HP
    int UpdateHealth() { return m_hitPoints++; }
    
    // -- other useful functions// ...
    };