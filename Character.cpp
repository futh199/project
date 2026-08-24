#include<iostream>
#include <memory>
#include "Character.h"
#include "Weapon.h"
Character::Character(const std::string& n, short h, short d, short l,short e,std::unique_ptr<Weapon> w) : 
name(n), health(h), damage(d) , lvl(l), exp(e), equipped(std::move(w)) // конструктор преобразования
{}
Character::~Character() {
    std::cout << "Character: " << name << " Deleted" << std::endl; // деструктор
}

