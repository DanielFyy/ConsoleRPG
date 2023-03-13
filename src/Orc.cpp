#include "Orc.h"

Orc::Orc()
{
    created++;

    set_name("Orc");
    set_max_health(18);
    set_health(18);
    set_min_damage(3);
    set_max_damage(6);
    set_accuracy(85);
    set_critical(7);
    set_dodge(15);
    set_defense(100);

    const std::string orc_introduction = "You encounter an orc.\n";
    const std::string orc_axe = " swings his axe at you";
    const std::string orc_javelin = " throws a javelin at you";
    set_encounter_description(orc_introduction);
    set_attack_descriptions({orc_axe, orc_javelin});
}

Orc::~Orc()
{
    destroyed++;
}