#pragma once
#include<iostream>
#include<string>
#include "Item.h"
class Player; 
class Potion : public Item{
private:
    short health{0};
    short hunger{0};
    short damage{0};
    short stamina{0};
public:
    Potion(const std::string& n, short health,short hunger=0,short damage=0,short stamina=0); // конструктор преобразования
    virtual void print() override; // вывод хар-ки зелья
    virtual void use(Player& player) override; // использование зелья 
    short get_health(); // получение здоровья
    short get_hunger(); // получение голода
    short get_damage(); // получение урона
    short get_stamina(); // получение стамины
    ~Potion(){} // деструктор
};