#include "Entity.h"

Entity::Entity()
{
    created++;
}

Entity::~Entity()
{
    destroyed++;
}

void Entity::set_name(const std::string name)
{
    this->name = name;
}

void Entity::set_min_damage(const int min_damage)
{
    this->min_damage = min_damage;
}

void Entity::set_max_damage(const int max_damage)
{
    this->max_damage = max_damage;
}

void Entity::set_accuracy(const int accuracy)
{
    this->accuracy = accuracy;
}

void Entity::set_critical(const int critical)
{
    this->critical = critical;
}

void Entity::set_defense(const int defense)
{
    this->defense = defense;
}

const std::string Entity::get_name() const
{
    return name;
}

const int Entity::get_min_damage() const
{
    return min_damage;
}

const int Entity::get_max_damage() const
{
    return max_damage;
}

const int Entity::get_accuracy() const
{
    return accuracy;
}

const int Entity::get_critical() const
{
    return critical;
}

const int Entity::get_defense() const
{
    return defense;
}
