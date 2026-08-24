#pragma once
#include<iostream>
#include<string>
#include "Item.h"

class Player; 
enum type_weapon{melee=0,range=1};
class Weapon : public Item{
private:
    short damage{0};
    short stamina{0};
    short defence{0};
    type_weapon gun; // тип оружия
public:
    Weapon(const std::string& n,short damage, short stamina, short defence,type_weapon gun); // конструктор преобразовния

    Weapon() = default; // конструктор по умолчанию

    virtual void print() override; // вывод хар-ки оружия

    virtual void use(Player& player) {}
    std::string get_type_string() const; // вывод типа оружия

    short get_damage(){return damage;} // получение урона

    short get_defence(){return defence;} // получение защиты

    short get_stamina(){return stamina;} // затраты стамины

    type_weapon get_type_weapon(){return gun;} // получение типа оружия
    
    virtual ~Weapon() {} // деструктор
};