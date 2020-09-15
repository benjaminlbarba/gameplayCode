/**
 * players have an inventory of equipment, money, and useableitems.
 * Some items, such as the Bag of Holding,can actually contain other items! 
 * Players can add, remove, or use items, as well as transfer toother player’s inventories. 
 * Finally, each player is limited to what they can carry by weight, 
 * */
#pragma once

#include <iostream> 
#include <unordered_map> 
#include "Item.h"

using namespace std;

const int MAX_WEIGHT = 100;
const int STARTING_WEIGHT = 0;

class Inventory {
    protected:
        float maxWeightCapacity;
        float currWeight;
        unordered_map<string, Item> itemMap; //for a UI an ordered map would be better, but no UI here :)

        void incrementWeight(float amt);
        void decrementWeight(float amt);
        void setCurrWeight(float weight);

    public:
        Inventory();
        Inventory(int maxWeight);
        float getCurrWeight();
        void setMaxWeightCapacity(int myMaxWeightCapacity);

        float addItem(Item itemToAdd);
        bool deleteItem(Item itemToDelete);
        bool hasItem(Item itemToSearch);
};