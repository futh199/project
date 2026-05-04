#pragma once
#include<iostream>
#include<string>
#include "Item.h"
class Player; 
class Food : public Item {
private:
    short health{0};
    short hunger{0};
public:
    Food(const std::string n, short h,short hun); // конструктор преобразования

    virtual void print() override; // вывод инф-ции о еде

    virtual void use(Player& player) override; // использование еды для персонажа

    short get_health(); // получение хп

    short get_hunger(); // получение голода
    
    virtual ~Food() {} // деструктор
};