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

    std::unique_ptr<Weapon> set_weapon(std::unique_ptr<Weapon> new_weapon); // экипирование
    
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
// class HealthManager{
// private:
//     short current_hp;
//     short hp_max{100};
//     short min_hp{0};
//     bool isLive{true};
// public:
//     void take_damage(short d)
//     {
//         current_hp -= d;
//         if(current_hp <= 0) isLive = false;
//     }

//     void increase_max_hp(short h)

//     {hp_max+=h;}

//     void heal(short h)
//     {
//         current_hp+=h;
//         if (current_hp >= hp_max) current_hp = hp_max;
//     }

//     bool isLive() const {return isLive;}

//     short get_current() const {return current_hp;}

// };
// class HungerManager{
// private:
//     double hungred{0};
// public:
//     double get_hungred()const {return hungred;}

//     void change(double h){
//         hungred += h;
//         if(hungred>100) hungred=100;
//         if(hungred<0) hungred=0;
//     }
// };
// class StaminaManager{
// private:
//     short current_stamina{100};
//     short max_stamina{100};
// public:
//     short get_stamina() const{ return current_stamina;}
//     void increase_stamina(short s){max_stamina+=s;}
//     void consume(short s) {
//         current_stamina-=s;
//         if(current_stamina<0) current_stamina = 0;
//     }
//     void restore(short s){
//         current_stamina +=s;
//         if(current_stamina>max_stamina) current_stamina = max_stamina;
//     }

// };
// class ExperienceManager{
// private:
//     short exp{0};
//     short max_exp{100};
//     short lvl{1};
// public:
//     short get_lvl()const {return lvl;}
//     short get_exp()const {return exp;}
//     bool shouldLevelUp() const { return exp >= max_exp; }
//     void add_exp(short e) {exp+=e;}
//     void lvl_up()
//     {
//         lvl++;
//         exp-=max_exp;
//         max_exp+=20;
//     }
// };
// class StatsManager{
// private:
//     short base_damage{10};
//     short base_defence{5};
//     short spent_stamina{5};
//     short weapon_damage{0};
//     short weapon_defence{0};
// public:
//     short get_spent()const {return spent_stamina;}
//     short get_damage()const{return base_damage+weapon_damage;}
//     short get_defence()const{return base_defence+weapon_defence;}
//     void add_base_defence(short d) {base_defence+=d;}
//     void add_base_damage(short d) {base_damage+=d;}
//     void add_weapon_defence(short d) {weapon_defence+=d;}
//     void add_weapon_damage(short d) {weapon_damage+=d;}
// };
// class Player{
// private:
//     Inventory inventory;
//     HealthManager health;
//     HungerManager hungred;
//     StaminaManager stamina;
//     StatsManager stats;
//     bool isBlock{false};
//     std::string name;
//     std::unique_ptr<Weapon> weapon;
// public:
    
// };