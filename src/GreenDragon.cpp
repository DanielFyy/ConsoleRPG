#include "GreenDragon.h"

GreenDragon::GreenDragon()
{   
    created++;
    
    set_name("Green Dragon");
    set_max_health(64);
    set_health(64);
    set_min_damage(10);
    set_max_damage(20);
    set_accuracy(75);
    set_critical(5);
    set_defense(25);

    const std::string green_dragon_introduction = "You encounter a green dragon.\n";
    
    const std::string green_dragon_breath = " opens its mouth and exhales a flame blast towards you";
    const std::string green_dragon_tail = " lashes out at you with its tail";
    set_encounter_description(green_dragon_introduction);
    set_attack_descriptions({green_dragon_breath, green_dragon_tail});

    const std::string green_dragon_scales = "'s scales protect it from the attack.\n";
    const std::string green_dragon_fly = " flies up in the air, avoiding the attack.\n";
    set_defense_descriptions({green_dragon_scales, green_dragon_fly});
}

GreenDragon::~GreenDragon()
{
    destroyed++;
}