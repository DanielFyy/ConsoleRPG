#include "Druid.h"

Druid::Druid(const std::string& name)
{
    created++;

    set_name(name);
    set_max_health(36);
    set_health(36);
    set_type(druid);

    const std::string druid_cloud = "You spew a poisonous cloud towards the ";
    const std::string druid_gust = "You send forth a gust of wind to blast the ";
    const std::string druid_insects = "You call a buzzing swarm of insects to sting the ";
    const std::string druid_entangle = "You cause roots and vines to sprout from the ground and lash at the ";
    set_attack_descriptions({druid_cloud, druid_gust, druid_entangle, druid_insects});

    const std::string druid_bark = ", but your bark-like skin protects you from the attack.\n";
    set_defense_descriptions({druid_bark});
}

Druid::~Druid()
{
    destroyed++;
}