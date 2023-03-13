#include "Dagger.h"

Dagger::Dagger()
{
    created++;

    set_name("Dagger");
    set_min_damage(2);
    set_max_damage(9);
    set_accuracy(95);
    set_critical(25);
    set_dodge(0);
    set_defense(0);
    set_slot(weapon);
}

Dagger::~Dagger()
{
    destroyed++;
}