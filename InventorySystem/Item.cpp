#include "Item.h"

Item::Item(std::string myName, int myQuantity, float myWeightPerItem):
    name(myName),
    quantity(myQuantity),
    weight(myWeightPerItem)
    {}

void Item::setName(std::string myName) {
    name = myName;
}

void Item::setQuantity(int myQuantity) {
    quantity = myQuantity;
}

void Item::setWeight(float myWeightPerItem) {
    weight = myWeightPerItem;
}

std::string Item::getName(){
    return name;
}

int Item::getQuantity(){
    return quantity;
}

float Item::getWeightPerUnit(){
    return weight;
}

float Item::getWeightOfAllUnits (){
    return weight * quantity;
}
