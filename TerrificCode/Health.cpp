#include "Health.h"

Health::Health (int currHealth, int maxHealth):
m_currHealth(currHealth),
m_maxHealth(maxHealth)
{
    if (currHealth <= maxHealth){
        m_currHealth = currHealth;
    }
    else{
         m_currHealth = maxHealth;
    }

    m_maxHealth = maxHealth;
}

/**
 * All health modifications go through here.
 */
int Health::modify(int amt){
    return m_currHealth += amt;
}

/**
 * NOTE: We have separate functions for damage health and heal health
 * as may require distinct handling down the line,
 * especially if certain power ups only affect damage or healing.
 * 
 * damage player by specified amount and return the new HP
 * 
 * @param amt, a positive amount to be subtracted from player health
 */ 
int Health::decrement(int amt) {  
    return modify(-amt); 
}
        
/**
 * heal player by specified amount and return the new HP
 * 
 * @param amt, a positive amount by which to increment player health
 */ 
int Health::increment(int amt) { 	
    return  modify(amt);
}

int Health::getCurrHealth(){
    return m_currHealth;
}