#include "Item.h"
#include "Inventory.h"

using namespace std;

class Bag : public Item, public Inventory{
    public:
        Bag(string myName, int myQuantity, float myWeightPerItem, int myMaxWeightCapacity): Item(myName, myQuantity, myWeightPerItem), Inventory(myMaxWeightCapacity){};
};