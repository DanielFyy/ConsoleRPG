#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "Longsword.h"
#include "ChainmailArmor.h"
#include "Dagger.h"
#include "LeatherArmor.h"
#include "MagicWand.h"
#include "WizardRobe.h"
#include "WoodStaff.h"
#include "SimpleRobe.h"
#include "MoonlightSword.h"
#include "ObsidianDagger.h"
#include "ArchtreeStaff.h"
#include "ArcaneCrystal.h"

class Player : public Entity
{
public:
    Player();
    virtual ~Player();


    const int attack(); //returns a damage value and handles critical damage calculations and descriptions
    void take_damage(const int& enemy_damage, const int& enemy_accuracy); //handles damage taken calculations and descriptions

    void set_attack_descriptions(const std::vector <std::string>& attack_descriptions); //adds attack descriptions to the player

    void set_stats(); //calculates player stats, taking currently equipped items into account

    void add_item(std::unique_ptr<Item> item); //moves the item pointer to inventory
    void equip_item(Item* item); //equips an item and sets the stats accordingly
    void unequip_item(Item* item); //sets a coresponding equipped item to nullptr

    const std::vector <std::unique_ptr<Item>>& get_inventory() const;
    Item* get_item(const int& index); //returns raw pointer to item at inventory index
    bool is_equipped(const int& index); //returns true or false depending on if the inventory item at index is equipped
    Item* get_equipped_weapon(); //returns raw pointer to equipped weapon
    void print_stats() const; //displays player stats

    void set_max_health(const int& max_health);
    void set_health(const int& health);
    void set_type(const player_type& type);

    const int& get_max_health() const;
    const int& get_health() const;
    const player_type& get_type() const;
    
private:
    int max_health, health;
    std::vector <std::string> attack_descriptions;

    player_type type;
    std::vector <std::unique_ptr<Item>> inventory;
    std::array <Item*, 2> equipped_items;
};

#endif