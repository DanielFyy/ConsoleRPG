#include "Goblin.h"

Goblin::Goblin()
{
    created++;

    set_name("Goblin");
    set_max_health(9);
    set_health(9);
    set_min_damage(2);
    set_max_damage(6);
    set_accuracy(90);
    set_critical(10);
    set_dodge(25);
    set_defense(100);

    const std::string goblin_introduction = "You encounter a goblin.\n";
    const std::string goblin_bow = " fires his shortbow at you";
    const std::string goblin_scimitar = " attacks you with his scimitar";
    set_encounter_description(goblin_introduction);
    set_attack_descriptions({goblin_bow});
}

Goblin::~Goblin()
{
    destroyed++;
}