#ifndef SCENE_H
#define SCENE_H

#pragma once

#include "Warrior.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Druid.h"

#include "Mimic.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"

#include "Werewolf.h"
#include "Ogre.h"
#include "GreenDragon.h"

class Scene
{
public:
    Scene();
    ~Scene();


    void main_menu(); //main menu of the game
    void volume_menu(); //menu to set music volume
    void text_menu(); //menu to select how fast text will be displayed

    void introduction(); //describes the world and asks the player if they want to begin
    void setup_player(); //allow the player to choose a name, class, and set them up accordingly, including starting items
    void crossroads(); //scene with the crossroads
    bool chest(); //scene where the player finds a chest with class appropiate items
    std::unique_ptr<Enemy> generate_random_enemy(); //returns a randomly generated enemy from a pool

    void inventory_menu(); //menu that allows the player to see their character stats or view their items

    void items_menu(); //displays all items currently in the player inventory
    void selected_item_menu(const int& index); //menu where the player can equip, unequip, or see the stats of an item
    
    bool battle(Player* player, Enemy* enemy); //runs combat calculations and displays descriptions

    void play_music(const std::string& music_file);
private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Enemy> current_enemy;
    sf::Music music;
};

#endif