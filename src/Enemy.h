#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include "Longsword.h"
#include "ChainmailArmor.h"
#include "Dagger.h"
#include "LeatherArmor.h"
#include "MagicWand.h"
#include "WizardRobe.h"
#include "WoodStaff.h"
#include "SimpleRobe.h"

class Enemy : public Entity
{
public:
    Enemy();
    virtual ~Enemy();

    const int attack(); //returns a damage value and handles critical damage calculations and descriptions
    void take_damage(const int& player_damage, const int& player_accuracy); //handles damage taken calculations and descriptions
    
    void set_attack_descriptions(const std::vector <std::string>& attack_descriptions); //adds attack descriptions to the enemy

    void set_max_health(const int& max_health);
    void set_health(const int& health);
    void set_encounter_description(const std::string& description);

    const int& get_max_health() const;
    const int& get_health() const;
    const std::string& get_encounter_description() const; //returns the encounter description string for that enemy
private:
    int max_health, health;
    std::vector <std::string> attack_descriptions;
    std::string encounter_description;
};

#endif