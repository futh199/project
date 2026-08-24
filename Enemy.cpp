#include<string>
#include<iostream>
#include<memory>
#include "Character.h"
#include "Enemy.h"

Enemy::Enemy(const std::string& n, short h, short d, short l, short e,std::unique_ptr<Weapon> w) : Character(n,h,d,l,e,std::move(w)) {
        std::cout << "Create Enemy: " << name << std::endl;
        max_hp = h;
        if(equipped)
        {   
            set_damage(equipped->get_damage());
            set_defence(equipped->get_defence());
        }
}
Enemy::~Enemy(){
        std::cout << "Enemy dead " << name << std::endl;
}
short Enemy::get_defence(){
    return def;
}
void Enemy::set_damage(short d){
    damage+=d;
}
void Enemy::set_defence(short d){
    def+=d;
}

void Enemy::gift_damage(short damage) {
    health -= damage;
    if(health<=0) live = false;
        //дать выбор
}

