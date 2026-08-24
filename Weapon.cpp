#include <iostream>
#include "Weapon.h"
#include "Player.h"
#include <string>
Weapon::Weapon(const std::string& n,short damage, short stamina, short defence,type_weapon gun) : Item(n),damage(damage), stamina(stamina), defence(defence), gun(gun)
{
    std::cout << "Weapoon: " << name << std::endl;
}
void Weapon::print()
{
    std::cout << "\033[31m" << name << "\033[0m" << std::endl <<"Damage: " << damage << std::endl << "Defence: " << defence << std::endl
    << "Stamina: " << stamina << std::endl << "Type: " << get_type_string() << std::endl;
}

std::string Weapon::get_type_string() const 
{
    switch (gun) {
        case melee: return "Melee";
        case range: return "Range";
        default: return "Unknown";
    }
}