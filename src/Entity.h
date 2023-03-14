#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include "Miscellaneous.h"

enum player_type {warrior, wizard, rogue, druid};
enum item_slot {weapon, armor};

class Entity
{
public:
    Entity();
    ~Entity();

    void set_name(const std::string name);
    void set_min_damage(const int min_damage);
    void set_max_damage(const int max_damage);
    void set_accuracy(const int accuracy);
    void set_critical(const int critical);
    void set_defense(const int defense);

    const std::string get_name() const;
    const int get_min_damage() const;
    const int get_max_damage() const;
    const int get_accuracy() const;
    const int get_critical() const;
    const int get_defense() const;

private:
    std::string name;
    
    int min_damage, max_damage, accuracy, critical;
    int defense;
};

#endif