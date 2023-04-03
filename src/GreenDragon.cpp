#include "GreenDragon.h"

GreenDragon::GreenDragon()
{   
    created++;
    
    set_name("Green Dragon");
    set_max_health(80);
    set_health(80);
    set_min_damage(10);
    set_max_damage(20);
    set_accuracy(85);
    set_critical(5);
    set_defense(25);

    const std::string green_dragon_introduction = "Walking through the forest, you arrive at a clearing.\nInside the clearing, you immediately notice a large reptilian creature, an emerald green dragon, its nostril's flaring as it sleeps.\nIn an instant, the dragon's eyelids open, burning yellow eyes glaring at you.\n";
    
    const std::string green_dragon_breath = " opens its mouth and exhales fire towards you";
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