#include "MagicWand.h"

MagicWand::MagicWand()
{
    created++;
    
    set_name("Magic Wand");
    set_min_damage(6);
    set_max_damage(12);
    set_accuracy(90);
    set_critical(15);
    set_dodge(0);
    set_defense(0);
    set_slot(weapon);
}

MagicWand::~MagicWand()
{
    destroyed++;
}