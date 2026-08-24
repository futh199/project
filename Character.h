#pragma once
#include <string>
#include <memory>
#include<iostream>
#include "Weapon.h"
class Character{

protected:
    std::string name;
    bool live{true}; // жив или мертв
    short health{0};
    short damage{0};
    short lvl{1};
    short exp{0};
    short def{0}; // защита
    std::unique_ptr<Weapon> equipped; // оружие
    Character(const std::string& n, short h, short d, short l,short e,std::unique_ptr<Weapon> w); // конструктор преобразования
public:
    virtual ~Character(); // деструктор
    Character(const Character&) = delete;
    Character(Character&&) = default;
    Character& operator=(const Character&) = delete;
    Character& operator=(Character&&) = default;
    bool isLive() const {return live;} // получение информации о жизни
    short get_health() const{return health;} // получение хп
    short get_damage() const{return damage;} // получение урона
    short get_exp() const{return exp;} // получение опыта
    short get_lvl() const{return lvl;} // получение лвл-а
    std::string get_name() const{return name;} //получение имени
};