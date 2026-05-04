#include<iostream>
#include<exception>
#include<vector>
#include "Character.h"
#include "Weapon.h"
Character::Character(const std::string& n, short h, short d, short l,short e,Weapon* w,typ name_typ) : 
name(n), health(h), damage(d) , lvl(l), exp(e), equipped(w),name_typ(name_typ) // конструктор преобразования
{}
Character::~Character() {
    std::cout << "Character: " << name << " Deleted" << std::endl; // деструктор
}

