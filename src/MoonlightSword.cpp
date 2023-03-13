#include "MoonlightSword.h"

MoonlightSword::MoonlightSword()
{
    created++;
    
    set_name("Moonlight Sword");
    set_min_damage(9);
    set_max_damage(18);
    set_accuracy(105);
    set_critical(15);
    set_dodge(0);
    set_defense(0);
    set_slot(weapon);
}

MoonlightSword::~MoonlightSword()
{
    destroyed++;
}