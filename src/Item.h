#ifndef Item_H
#define Item_H

#pragma once
#include "Entity.h"


class Item : public Entity
{
public:
    Item();
    virtual ~Item();

    void print_item_stats(); //displays item stats (stats displayed vary depending on the item slot)
    
    void set_slot(const item_slot& slot);
    const item_slot& get_slot() const;

private:
    item_slot slot;
};

#endif