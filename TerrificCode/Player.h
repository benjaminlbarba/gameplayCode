#include "HumanActor.h"

class Player: public HumanActor{
    public: Player(string myName, int startingHealth = STARTING_HEALTH): HumanActor(startingHealth, true){};
};