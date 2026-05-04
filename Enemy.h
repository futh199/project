#pragma once
#include<string>
#include<iostream>
#include "Character.h"
class Enemy : public Character{
private:
    short stamina{100}; 
    short max_hp{0};
public:
    Enemy(const std::string& n, short h, short d, short l,short e,Weapon* w=nullptr); // конструктор преобразования
    virtual ~Enemy(); // деструктор
    short get_max_hp() const{return max_hp;}
    void gift_damage(short damage); // получение урона
    short get_defence(); // получение защиты
    void set_damage(short d); // установка урона
    void set_defence(short d); // установка защиты
};