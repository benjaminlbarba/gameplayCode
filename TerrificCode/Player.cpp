#include "Player.h"

Player::Player(string myName, int startingHealth = STARTING_HEALTH): HumanActor(startingHealth){
    setName(myName);
}