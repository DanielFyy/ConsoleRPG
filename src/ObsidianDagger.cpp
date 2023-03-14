#include "ObsidianDagger.h"

ObsidianDagger::ObsidianDagger()
{
    created++;
    
    set_name("Obsidian Dagger");
    set_min_damage(9);
    set_max_damage(27);
    set_accuracy(95);
    set_critical(33);
    set_defense(0);
    set_slot(weapon);
}

ObsidianDagger::~ObsidianDagger()
{
    destroyed++;
}