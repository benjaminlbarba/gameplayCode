#include "Bag.h"

Bag::Bag(string myName, int myQuantity, float myWeightPerItem, int myMaxWeightCapacity): Item(myName, myQuantity, myWeightPerItem), Inventory(myMaxWeightCapacity){
    //init item properties
    name = myName;
    quantity = myQuantity;
    weight = myWeightPerItem;

    //init inventory properties
    setMaxWeightCapacity(myMaxWeightCapacity);
}

