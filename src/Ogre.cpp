#include "Ogre.h"

Ogre::Ogre()
{   
    created++;

    set_name("Ogre");
    set_max_health(46);
    set_health(46);
    set_min_damage(8);
    set_max_damage(14);
    set_accuracy(70);
    set_critical(5);
    set_dodge(5);
    set_defense(100);

    const std::string ogre_introduction = "You encounter an ogre.\n";
    const std::string ogre_swing = " swings his club at you";
    const std::string ogre_boulder = " hurls a boulder at you";
    set_encounter_description(ogre_introduction);
    set_attack_descriptions({ogre_swing, ogre_boulder});
}

Ogre::~Ogre()
{
    destroyed++;
}