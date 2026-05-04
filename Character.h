#pragma once
#include <string>
#include<iostream>
#include "Weapon.h"
enum typ {enemy = 0, fri = 1, player = 2};
class Character{

protected:
    std::string name;
    bool live{true}; // жив или мертв
    short health{0};
    short damage{0};
    short lvl{1};
    short exp{0};
    short def{0}; // защита
    Weapon* equipped{nullptr}; // оружие

private:
    typ name_typ; // тип персонажа
protected:
    Character(const std::string& n, short h, short d, short l,short e,Weapon* w,typ name_typ=enemy); // конструктор преобразования
public:
    virtual ~Character(); // деструктор
    bool isLive() const {return live;} // получение информации о жизни
    short get_health() const{return health;} // получение хп
    short get_damage() const{return damage;} // получение урона
    short get_exp() const{return exp;} // получение опыта
    short get_lvl() const{return lvl;} // получение лвл-а
    std::string get_name() const{return name;} //получение имени
};