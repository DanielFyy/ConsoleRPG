#include "Troll.h"

Troll::Troll()
{
    created++;

    set_name("Troll");
    set_max_health(25);
    set_health(25);
    set_min_damage(5);
    set_max_damage(8);
    set_accuracy(75);
    set_critical(5);
    set_defense(10);

    const std::string troll_introduction = "You encounter a troll.\n";
    const std::string troll_swing = " swings a tree branch at you";
    const std::string troll_spores = " emanates poisonous spores";
    set_encounter_description(troll_introduction);
    set_attack_descriptions({troll_swing, troll_spores});

    const std::string troll_hide = "'s tough hide protects it from your attack.\n";
    set_defense_descriptions({troll_hide});
}

Troll::~Troll()
{
    destroyed++;
}