#pragma once

const int MAX_HEALTH = 100;
const int STARTING_HEALTH = 100;

class Health{
    private: int m_currHealth;
    private: int m_maxHealth;

    public: Health (int currHealth, int maxHealth);

    private: int modify(int amt);

    public: int decrement(int dmg);
            
    public: int increment(int amt);

    public: int getCurrHealth();
};