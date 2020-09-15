#include "Inventory.h"

Inventory::Inventory(){
    maxWeightCapacity = MAX_WEIGHT;
    currWeight = STARTING_WEIGHT;
}

Inventory::Inventory(int maxWeight){
    maxWeightCapacity = maxWeight;
    currWeight = STARTING_WEIGHT;
}

/**
 * adds an item to the inventory
 * @param item to add
 * @return weight by which item exceeds capacity, 0 if successfully added
 * */
float Inventory::addItem(Item itemToAdd){
    int newWeight = currWeight + itemToAdd.getWeightOfAllUnits();

    if (newWeight > maxWeightCapacity){
        return newWeight - maxWeightCapacity;
    }

    //if it exists, we need to update weight and quantity (C++20 will include map.contains)
    string currName = itemToAdd.getName();
    bool found = (1 == itemMap.count(currName));
    if (found){
        int newQuantity = itemMap.at(currName).getQuantity() +  itemToAdd.getQuantity();
        itemMap.at(currName).setQuantity(newQuantity);
    }
    else{
         itemMap.insert(pair<string,Item>(currName, itemToAdd));
    }
   
    return 0;
}

void Inventory::setMaxWeightCapacity(int myMaxWeightCapacity){
    maxWeightCapacity = myMaxWeightCapacity;
}

/**
 * adds an item to the inventory
 * @param item to add
 * @return true if item existed and was removed, false if no such item existed
 * */
bool Inventory::deleteItem(Item itemToDelete){
    bool removed = (1 == itemMap.erase(itemToDelete.getName()));
    if (removed){ 
        decrementWeight(itemToDelete.getWeightOfAllUnits());
    }

    return removed;
}

void Inventory::decrementWeight(float amt){
    float newWeight = getCurrWeight() - amt;
    setCurrWeight(newWeight);
}

float Inventory::getCurrWeight(){
    return currWeight;
}

void Inventory::setCurrWeight(float weight){
    currWeight = weight;
}