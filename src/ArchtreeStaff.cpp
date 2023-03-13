#include "ArchtreeStaff.h"

ArchtreeStaff::ArchtreeStaff()
{
    created++;
    
    set_name("Archtree Staff");
    set_min_damage(10);
    set_max_damage(20);
    set_accuracy(100);
    set_critical(18);
    set_dodge(0);
    set_defense(0);
    set_slot(weapon);
}

ArchtreeStaff::~ArchtreeStaff()
{
    destroyed++;
}