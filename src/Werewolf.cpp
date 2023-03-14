#include "Werewolf.h"

Werewolf::Werewolf()
{   
    created++;

    set_name("Werewolf");
    set_max_health(35);
    set_health(35);
    set_min_damage(5);
    set_max_damage(10);
    set_accuracy(100);
    set_critical(20);
    set_defense(33);
    const std::string werewolf_introduction = "You encounter a werewolf.\n";
    const std::string werewolf_claw = " swipes at you with its claws";
    const std::string werewolf_bite = " lunges to bite you";
    set_encounter_description(werewolf_introduction);
    set_attack_descriptions({werewolf_claw, werewolf_bite});

    const std::string werewolf_fast = " moves too fast and the attack misses.\n";
    const std::string werewolf_leap = " leaps out of the way.\n";
    set_defense_descriptions({werewolf_fast, werewolf_leap});
}

Werewolf::~Werewolf()
{
    destroyed++;
}