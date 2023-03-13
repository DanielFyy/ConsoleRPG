#include "Enemy.h"

Enemy::Enemy()
{
    created++;
}

Enemy::~Enemy()
{
    destroyed++;
}

const int Enemy::attack()
{
    std::random_device random;
    std::mt19937 rng{random()};

    std::uniform_int_distribution<int> damage{get_min_damage(), get_max_damage()};
    std::uniform_int_distribution<int> critical{1, 100};
    
    int attack_damage;
    if (this->get_critical() < critical(rng)) 
        attack_damage = damage(rng);
    else
        attack_damage = 2 * damage(rng);

    int attacks = attack_descriptions.size()-1;
    std::uniform_int_distribution<int> number{0, attacks};

    display_text("The " + string_to_lower(get_name()) + attack_descriptions[number(rng)]);

    return attack_damage;
}

void Enemy::take_damage(const int& player_damage, const int& player_accuracy)
{
    display_text(string_to_lower(get_name()));
    
    std::random_device random;
    std::mt19937 rng{random()};
    std::uniform_int_distribution<int> number{1, 100};

    int damage_taken = player_damage * this->get_defense() / 100;
    if (player_accuracy - get_dodge() < number(rng)) 
        display_text(", but the " + string_to_lower(get_name()) + " avoids the attack.\n");
    else
    {
        display_text(", dealing " + std::to_string(damage_taken) + " damage.\n");
        set_health(get_health() - damage_taken);
    }
}

void Enemy::set_attack_descriptions(const std::vector <std::string>& attack_descriptions)
{
    this->attack_descriptions = attack_descriptions;
}

void Enemy::set_max_health(const int& max_health)
{
    this->max_health = max_health;
}

void Enemy::set_health(const int& health)
{
    this->health = health;
}

void Enemy::set_encounter_description(const std::string& description)
{
    encounter_description = description;
}

const int& Enemy::get_max_health() const
{
    return max_health;
}

const int& Enemy::get_health() const
{
    return health;
}

const std::string& Enemy::get_encounter_description() const
{
    return encounter_description;
}
