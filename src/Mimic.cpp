#include "Mimic.h"

Mimic::Mimic()
{
    created++;

    set_name("Mimic");
    set_max_health(13);
    set_health(13);
    set_min_damage(3);
    set_max_damage(6);
    set_accuracy(80);
    set_critical(15);
    set_defense(0);

    const std::string mimic_introduction = "The chest springs to life, revealing inside a drooling mouth filled with rows of sharp teeth.\n";
    const std::string mimic_bite = " snaps its jaws at you";
    set_encounter_description(mimic_introduction);
    set_attack_descriptions({mimic_bite});

    const std::string mimic_defense = " avoids the attack.\n";
    set_defense_descriptions({mimic_defense});
}

Mimic::~Mimic()
{
    destroyed++;
}