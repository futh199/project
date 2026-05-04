#pragma once
#include "Inventory.h"
#include<string>
#include<iostream>
#include "Weapon.h"
#include "Character.h"
#include "Item.h"
#include "ItemFactory.h"
class Player : public Character{
private:
    Inventory inventar; // класс инвентаря
    short max_hp = 100;
    short min_hp = 0;
    short max_stamina = 100;
    bool isBlock{false};
    double hungred{100};
    short stamina{100};
    short weapon_damage{0};
    void add_power(short d); // выдача урона
public:
    Player(const std::string& n, short h, short d, short l); // конструктор преобразования

    Inventory& get_inventory(); // получение ссылки на инвентарь

    void open_inventory() ; // вывод всех предметов в инвентаре

    Weapon& get_gun() ; // получение экипированного оружия

    std::string get_weapon() const; // вывод экипированного оружия

    void set_defence(short d); // задать защиту

    void set_weapon(Weapon* weapon); // экипирование
    
    short get_max_hp() const;

    short get_max_stamina() const;

    short get_defence() const; // получение защиты

    short get_hungred() const; // получение голода

    short get_stamina() const; // получение стамины
    
    bool isBlocking() const;
    
    void set_block(bool block);

    void lvl_up(); // поднятие уровня

    void gift_exp(short e); // выдача опыта

    void gift_health(short e); // выдача хп, не может превысить значение health 100

    void gift_damage(short damage); // получение урона от чего-либо 

    void set_name(const std::string& name); // переименование 

    void gift_hungred(short h); // выдача голода

    void gift_stamina(short s); // выдача стамины

    void update_hungred(short n);

    void update_stamina();

    void set_weapon_damage(short d);

    short get_weapon_damage() const; // получение урона оружия

    virtual ~Player(); // деструктор
};