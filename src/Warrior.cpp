#include "Warrior.h"

Warrior::Warrior(const std::string& name)
{   
    created++;
    
    set_name(name);
    set_max_health(42);
    set_health(42);
    set_type(warrior);

    const std::string warrior_weapon = "You use your weapon to attack the ";
    set_attack_descriptions({warrior_weapon});
}

Warrior::~Warrior()
{
    destroyed++;
}