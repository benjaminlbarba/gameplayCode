#include "Inventory.h"

int main(){
    Inventory playerInventory(100);
    Item apple ("apple", 2, 5, createTags(CONSUMABLE));

    playerInventory.addItem(apple);

    return 0;
}