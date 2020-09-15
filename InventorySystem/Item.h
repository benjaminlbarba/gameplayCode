/**
 * Each Item has a name, quantity, and weight. 
 * */
#pragma once

#include "ItemTag.h"
#include <string>

class Item {
    protected:
        std::string name;
        int quantity;
        float weight;
        unordered_map<string, Item> tags;

    public:
        Item(std::string myName, int myQuantity, float myWeightPerItem);

        void setName(std::string myName);

        void setQuantity(int myQuantity);

        void setWeight(float myWeight);

        std::string getName();

        int getQuantity();

        float getWeightPerUnit();

        float getWeightOfAllUnits();
};


