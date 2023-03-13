#include "Item.h"

Item::Item()
{
    created++;
}

Item::~Item()
{
    destroyed++;
}

void Item::print_item_stats()
{   
    clear_screen();
    display_text(get_name() + " Details:\n");

    if (slot == weapon)
    {   
        display_text("Damage: " + std::to_string(get_min_damage()) + "-" + std::to_string(get_max_damage()) + "\n");
        display_text("Accuracy: " + std::to_string(get_accuracy()) + "%\n");
        display_text("Critical Hit Chance: " + std::to_string(get_critical()) + "%\n");
        press_any_key();
    }
    else if (slot == armor)
    {   
        display_text("Defense: " + std::to_string(get_defense()) + "%\n");
        display_text("Dodge: " + std::to_string(get_dodge()) + "%\n");
        press_any_key();
    }

    
}

void Item::set_slot(const item_slot& slot)
{
    this->slot = slot;
}

const item_slot& Item::get_slot() const
{
    return slot;
}