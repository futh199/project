#include<iostream>
#include<string>
#include "Character.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemFactory.h"
class Item;

Player::Player(const std::string& n, short h, short d, short l) : Character(n,h,d,l,0,ItemFactory::IronSword()){
    std::cout << "Hero: " << name << std::endl;
    set_defence(equipped->get_defence());
    set_weapon_damage(equipped->get_damage());
}
Player::~Player () {
    std::cout << "Game Over" << std::endl;
    
}

short Player::get_max_hp() const{
    return max_hp;
}
short Player::get_max_stamina() const{
    return max_stamina;
}
short Player::get_stamina() const{
    return stamina;
}
short Player::get_hungred() const{
    return hungred;
}


bool Player::isBlocking() const{
    return isBlock;
}

void Player::set_block(bool block){
    isBlock = block;
}
void Player::open_inventory(){
    inventar.print();
}
std::string Player::get_weapon() const{
    return equipped->get_name();
}
void Player::set_defence(short d){
    def +=d;
}
std::unique_ptr<Weapon> Player::set_weapon(std::unique_ptr<Weapon> new_weapon){
    std::unique_ptr<Weapon> old_sword = std::move(equipped);
    if(old_sword){
        set_weapon_damage(-old_sword->get_damage());
        set_defence(-old_sword->get_defence());
    }
    
    equipped = std::move(new_weapon);
    if(equipped){
        set_weapon_damage(equipped->get_damage());
        set_defence(equipped->get_defence()); // снимаем старый бонус
    };
    return old_sword;       // добавляем новый бонус
}
Inventory& Player::get_inventory() {return inventar;}
void Player::lvl_up(){
        health +=10;
        max_hp +=10;
        damage += 5;
        stamina += 5;
        max_stamina +=5;
        lvl++;
}
Weapon& Player::get_gun() {
    return *equipped;
}

void Player::gift_exp(short e){
    exp +=e;
    while(exp>=100){
        lvl_up();
        exp -= 100;
        }; 
}

void Player::gift_health(short e){
    health += e;
    if(health>max_hp) health = max_hp; 
}

void Player::gift_damage(short damage){
    health -= damage;
    if(health<=min_hp){ live = false;
    std::cout << "Dead" << std::endl;
    //дать выбор
}}
short Player::get_defence() const{
    return def;
}
short Player::get_weapon_damage() const{
    return weapon_damage;
}
void Player::add_power(short d){
    damage+=d;
}
void Player::set_name(const std::string& name){
    this->name = name;
}
void Player::set_weapon_damage(short s){
    weapon_damage+=s;
}
void Player::gift_hungred(short h){
    hungred +=h;
    if(hungred > 100) hungred = 100;
    if(hungred < 0) hungred = 0; 
}
void Player::update_hungred(short n){
    switch(n)
    {   case 1: // атака
            gift_hungred(-7);
            break;
        case 2: // использование предмета
            gift_hungred(-2);
            break;
        case 3: // передвежение
            gift_hungred(-5);
            break;
        default:
            std::cout << "Invalide index" << std::endl;
            break;
    };
}
void Player::update_stamina(){
    if(hungred <= 100 && hungred >=75)
        gift_stamina(15);
    else if(hungred <75 && hungred >=50)
        gift_stamina(10);
    else if(hungred <50 && hungred >= 25)
        gift_stamina(5);
    else if(hungred <25)
        {std::cout << "You hungred, stamina decreases" << std::endl;
        gift_stamina(-3);}
    
}
void Player::gift_stamina(short s){
    stamina += s;
    if(stamina >100) stamina = 100;
    if(stamina < 0) stamina = 0;
}
    


