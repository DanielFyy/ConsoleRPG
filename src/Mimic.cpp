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
    set_dodge(0);
    set_defense(100);

    const std::string mimic_introduction = "The chest springs to life, revealing a drooling mouth filled with rows of sharp teeth.\n";
    const std::string mimic_bite = " snaps its mouth at you";
    set_encounter_description(mimic_introduction);
    set_attack_descriptions({mimic_bite});
}

Mimic::~Mimic()
{
    destroyed++;
}