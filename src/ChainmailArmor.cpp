#include "ChainmailArmor.h"

ChainmailArmor::ChainmailArmor()
{
    created++;

    set_name("Chainmail Armor");
    set_min_damage(0);
    set_max_damage(0);
    set_accuracy(0);
    set_critical(0);
    set_dodge(-20);
    set_defense(40);
    set_slot(armor);
}

ChainmailArmor::~ChainmailArmor()
{
    destroyed++;
}