#include "Ogre.h"

Ogre::Ogre()
{   
    created++;

    set_name("Ogre");
    set_max_health(62);
    set_health(62);
    set_min_damage(8);
    set_max_damage(14);
    set_accuracy(80);
    set_critical(8);
    set_defense(0);

    const std::string ogre_introduction = "As you step through the cave entrance, you hear a low, grumbling roar.\nLooking further inside the cave you see a massive ogre approaching with heavy footsteps, club in hand.\n";
    const std::string ogre_swing = " swings his club at you";
    const std::string ogre_boulder = " hurls a boulder at you";
    set_encounter_description(ogre_introduction);
    set_attack_descriptions({ogre_swing, ogre_boulder});

    const std::string ogre_defense = " avoids the attack.\n";
    set_defense_descriptions({ogre_defense});
}

Ogre::~Ogre()
{
    destroyed++;
}