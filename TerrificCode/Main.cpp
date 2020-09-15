#include "Player.h"
#include <iostream>
#include <ostream>

int testHealth(Player* playerRef){
    playerRef->healthStat.decrement(20);

    cout << "Health after decrementing:" << playerRef->healthStat.getCurrHealth() << endl;

    playerRef->healthStat.increment(10);

    cout << "Health after incrementing:" << playerRef->healthStat.getCurrHealth() << endl;

    return 0;
}

void printBitMaskTest(Player* playerRef, int id){
    if (playerRef->checkForFlag(HUM_ACTOR_INJURED)){
        cout << "testBitMask: test[" << id << "] HUM_ACTOR_INJURED set!\n";
    }
    else{
        cout << "testBitMask: test[" << id << "] HUM_ACTOR_INJURED not set!\n";
    }
}

int testBitMask(Player* playerRef){
    printBitMaskTest(playerRef, 0);
    
    playerRef->setFlag(HUM_ACTOR_INJURED, true);

    printBitMaskTest(playerRef, 1);

    playerRef->setFlag(HUM_ACTOR_INJURED, false);

    printBitMaskTest(playerRef, 2);

    return 0;
}

int main(){
    Player player("Marston");

    testHealth(&player);
    std::cout << "main: Health after test:" << player.healthStat.getCurrHealth() << endl;
    
    testBitMask(&player);
    printBitMaskTest(&player, 3);

    return 0;
}