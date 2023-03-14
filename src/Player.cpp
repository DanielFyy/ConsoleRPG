#include "Player.h"

Player::Player()
{   
    created++;

    for(int i = 0; i < equipped_items.size(); i++) 
        equipped_items[i] = nullptr;

    set_stats();
}

Player::~Player()
{
    destroyed++;
}

const int Player::attack()
{
    std::random_device random;
    std::mt19937 rng{random()};

    std::uniform_int_distribution<int> damage{this->get_min_damage(), this->get_max_damage()};
    std::uniform_int_distribution<int> critical{1, 100};
    
    int attack_damage;
    if (this->get_critical() < critical(rng)) 
        attack_damage = damage(rng);
    else
        attack_damage = 2 * damage(rng);

    int attacks = attack_descriptions.size()-1;
    std::uniform_int_distribution<int> number{0, attacks};

    display_text(attack_descriptions[number(rng)]);

    return attack_damage;
}

void Player::take_damage(const int enemy_damage, const int enemy_accuracy)
{
    std::random_device random;
    std::mt19937 rng{random()};
    std::uniform_int_distribution<int> accuracy{1, 100};

    int defense = defense_descriptions.size()-1;
    std::uniform_int_distribution<int> number{0, defense};

    if (enemy_accuracy < accuracy(rng)) 
        display_text(defense_descriptions[number(rng)]);
    else
    {
        display_text(", dealing " + std::to_string(enemy_damage) + " damage.\n");
        this->set_health(this->get_health() - enemy_damage);
    }
}

void Player::set_attack_descriptions(const std::vector <std::string>& attack_descriptions)
{
    this->attack_descriptions = attack_descriptions;
}

void Player::set_defense_descriptions(const std::vector <std::string>& defense_descriptions)
{
    this->defense_descriptions = defense_descriptions;
}

void Player::set_stats()
{
    int min_damage = 1, max_damage = 2, accuracy = 95, critical = 5, defense = 0;

    if (equipped_items[weapon] != nullptr) 
    {
        min_damage = equipped_items[weapon]->get_min_damage();
        max_damage = equipped_items[weapon]->get_max_damage();
        accuracy = equipped_items[weapon]->get_accuracy();
        critical = equipped_items[weapon]->get_critical();
    }
    

    if (equipped_items[armor] != nullptr) 
    {   
        defense = equipped_items[armor]->get_defense();
    }

    set_min_damage(min_damage);
    set_max_damage(max_damage);
    set_accuracy(accuracy);
    set_critical(critical);
    set_defense(defense);
}


void Player::add_item(std::unique_ptr<Item> item)
{
    if (item != nullptr) 
    {
        display_text(item->get_name() + " added to inventory.\n");
        inventory.push_back(std::move(item));
    }
}

void Player::equip_item(Item* item)
{   
    if (item != nullptr && (item->get_slot() == weapon || item->get_slot() == armor)) 
    {   
        clear_screen();
        if (equipped_items[item->get_slot()] != nullptr) 
        {
            display_text("Unequipped " + equipped_items[item->get_slot()]->get_name() + ".\n");
        }
        display_text("Equipped " + item->get_name() + ".\n");
        press_any_key();
        equipped_items[item->get_slot()] = item;
        set_stats();
    }   
        
}

void Player::unequip_item(Item* item)
{
    if (item != nullptr)
        for(int i = 0; i < equipped_items.size(); i++) 
        {   
            if (equipped_items[i] == item) 
            {   
                clear_screen();
                display_text("Unequipped " + equipped_items[i]->get_name() + ".\n");
                press_any_key();
                equipped_items[i] = nullptr;
                set_stats();
                break;
            }
        }
}

const std::vector <std::unique_ptr<Item>>& Player::get_inventory() const
{
    return inventory;
}

Item* Player::get_item(const int index)
{
    return inventory[index].get();
}

bool Player::is_equipped(const int index)
{   
    for (const Item* item : equipped_items)
        if (inventory[index].get() == item)
            return true;

    return false;
}

Item* Player::get_equipped_weapon()
{
    return equipped_items[weapon];
}

void Player::print_stats() const
{

    std::string type_string;
    switch (get_type())
    {
    case warrior:
        type_string = "Warrrior";
        break;
    case wizard:
        type_string = "Wizard";
        break;
    case rogue:
        type_string = "Rogue";
        break;
    case druid:
        type_string = "Druid";
        break;
    default:
        type_string = "Legendary";
        break;
    }

    clear_screen();

    std::string equipped_weapon = "None";
    std::string equipped_armor = "None";

    if (equipped_items[weapon] != nullptr)
        equipped_weapon = equipped_items[weapon]->get_name();
    if (equipped_items[armor] != nullptr)
        equipped_armor = equipped_items[armor]->get_name();

    display_text(get_name() + " the " + type_string + ":\n");
    display_text("Health: " + std::to_string(get_health()) + "/" + std::to_string(get_max_health()) + "\n");
    display_text("Weapon: " + equipped_weapon + "\n");
    display_text("Armor: " + equipped_armor + "\n");
    display_text("Damage: " + std::to_string(get_min_damage()) + "-" + std::to_string(get_max_damage()) + "\n");
    display_text("Accuracy: " + std::to_string(get_accuracy()) + "%\n");
    display_text("Critical Hit Chance: " + std::to_string(get_critical()) + "%\n");
    display_text("Defense: " + std::to_string(get_defense()) + "%\n");
    press_any_key();
}

void Player::set_type(const player_type type)
{
    this->type = type;
}

const player_type Player::get_type() const
{
    return type;
}

void Player::set_max_health(const int max_health)
{
    this->max_health = max_health;
}

void Player::set_health(const int health)
{
    this->health = health;
}

const int Player::get_max_health() const
{
    return max_health;
}

const int Player::get_health() const
{
    return health;
}