#include "ItemTag.h"
#include <stdarg.h>
#include <unordered_map>

using namespace std;

class ItemsUtility{
    public: 
        unordered_map<ItemTag, ItemTag> createTags(ItemTag tag, ...){
            va_list args;
            va_start(args, count);

            unordered_map<ItemTag, ItemTag> tagMap;

            tagMap.insert(pair<ItemTag,ItemTag>(tag, tag));
            createTags(...);
        }
};