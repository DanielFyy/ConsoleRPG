#include "Longsword.h"

Longsword::Longsword()
{
    created++;
    
    set_name("Longsword");
    set_min_damage(4);
    set_max_damage(8);
    set_accuracy(95);
    set_critical(10);
    set_defense(0);
    set_slot(weapon);
}

Longsword::~Longsword()
{
    destroyed++;
}