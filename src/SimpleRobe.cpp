#include "SimpleRobe.h"

SimpleRobe::SimpleRobe()
{   
    created++;

    set_name("Simple Robe");
    set_min_damage(0);
    set_max_damage(0);
    set_accuracy(0);
    set_critical(0);
    set_dodge(0);
    set_defense(0);
    set_slot(armor);
}

SimpleRobe::~SimpleRobe()
{
    destroyed++;
}