#include "LeatherArmor.h"

LeatherArmor::LeatherArmor()
{   
    created++;

    set_name("Leather Armor");
    set_min_damage(0);
    set_max_damage(0);
    set_accuracy(0);
    set_critical(0);
    set_defense(50);
    set_slot(armor);
}

LeatherArmor::~LeatherArmor()
{
    destroyed++;
}