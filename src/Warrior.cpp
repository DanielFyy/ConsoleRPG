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
    
    const std::string warrior_armor = ", but the attack glances off of your armor.\n";
    const std::string warrior_shield = ", but you block the attack with your shield.\n";
    set_defense_descriptions({warrior_armor, warrior_shield});
}

Warrior::~Warrior()
{
    destroyed++;
}