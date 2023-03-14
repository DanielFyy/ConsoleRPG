#include "Rogue.h"

Rogue::Rogue(const std::string& name)
{
    created++;
    
    set_name(name);
    set_max_health(32);
    set_health(32);
    set_type(rogue);

    const std::string rogue_weapon = "You use your weapon to attack the ";
    set_attack_descriptions({rogue_weapon});

    const std::string rogue_roll = ", but you roll out of the way and avoid the attack.\n";
    const std::string rogue_dodge = ", but you evade the attack.\n";
    set_defense_descriptions({rogue_roll, rogue_dodge});
}

Rogue::~Rogue()
{
    destroyed++;
}