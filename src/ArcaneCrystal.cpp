#include "ArcaneCrystal.h"

ArcaneCrystal::ArcaneCrystal()
{
    created++;
    
    set_name("Arcane Crystal");
    set_min_damage(15);
    set_max_damage(30);
    set_accuracy(90);
    set_critical(20);
    set_dodge(0);
    set_defense(0);
    set_slot(weapon);
}

ArcaneCrystal::~ArcaneCrystal()
{
    destroyed++;
}