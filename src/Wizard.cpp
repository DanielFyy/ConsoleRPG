#include "Wizard.h"

Wizard::Wizard(const std::string& name)
{
    created++;

    set_name(name);
    set_max_health(28);
    set_health(28);
    set_type(wizard);
    
    const std::string wizard_lightning = "You call forth a bolt of lightning to strike the ";
    const std::string wizard_fireball = "You hurl a ball of roaring fire at the ";
    const std::string wizard_elemental = "Your conjured water elemental attacks the ";
    const std::string wizard_missiles = "You shoot arcane missiles towards the ";
    set_attack_descriptions({wizard_lightning, wizard_fireball, wizard_elemental, wizard_missiles});

    const std::string wizard_armor = ", but your magical armor blocks the attack.\n";
    const std::string wizard_elemental_block = ", but your conjured water elemental protects you from the attack.\n";
    set_defense_descriptions({wizard_armor, wizard_elemental_block});
}

Wizard::~Wizard()
{
    destroyed++;
}