#include "WoodStaff.h"

WoodStaff::WoodStaff()
{
    created++;

    set_name("Wood Staff");
    set_min_damage(4);
    set_max_damage(10);
    set_accuracy(90);
    set_critical(5);
    set_dodge(0);
    set_defense(0);
    set_slot(weapon);
}

WoodStaff::~WoodStaff()
{
    destroyed++;
}