#pragma once
#include "Weapon.h"
#include "Potion.h"
#include "Food.h"
#include "Enemy.h"
#include <iostream>
#include <memory>
//создание пресетов для удобного пользования
struct ItemFactory{
    // Пресеты врагов
    static std::unique_ptr<Enemy> Wolf()
    {
        return std::make_unique<Enemy>("Wolf",60,14,5,90,nullptr);
  
    }
    static std::unique_ptr<Enemy> Orc()
    {
        return std::make_unique<Enemy>("Orc",80,30,7,300,nullptr);
    }
    static std::unique_ptr<Enemy> Rat()
    {
        return std::make_unique<Enemy>("Rat",10,5,1,50,nullptr);
    }
    static std::unique_ptr<Enemy> Dragon()
    {
        return std::make_unique<Enemy>("Dragon",300,40,20,500,nullptr);
    }
    static std::unique_ptr<Enemy> Skeleton()
    {
        return std::make_unique<Enemy>("Skeleton",55,13,6,100,nullptr);
    }
    static std::unique_ptr<Enemy> Ghost()
    {
        return std::make_unique<Enemy>("Ghost",40,25,6,110,nullptr);
    }
    static std::unique_ptr<Enemy> Player()
    {
        return std::make_unique<Enemy>("Player",100,100,75,1000,nullptr);
    }
    static std::unique_ptr<Enemy> Goblin()
    {
        return std::make_unique<Enemy>("Goblin",50,10,3,95,ItemFactory::Dagger());
    }
    // Пресеты оружия
    static std::unique_ptr<Weapon> IronSword()
    {
        return std::make_unique<Weapon>("Iron Sword",10,10,10,melee);
    }
    static std::unique_ptr<Weapon> Dagger()
    {
        return std::make_unique<Weapon>("Dagger",5,4,4,melee);
    }
    static std::unique_ptr<Weapon> Axe()
    {
        return std::make_unique<Weapon>("Axe",15,8,12,melee);
    }
    static std::unique_ptr<Weapon> Rapier()
    {
        return std::make_unique<Weapon>("Rapier",40,40,5,melee);
    }
    static std::unique_ptr<Weapon> PlasmaSword()
    {
        return std::make_unique<Weapon>("PLasmaSword",30,25,20,melee);
    }
    static std::unique_ptr<Weapon> Slingshot()
    {
        return std::make_unique<Weapon>("Slingshot",7,3,1,range);
    }
    static std::unique_ptr<Weapon> LightingBow()
    {
        return std::make_unique<Weapon>("LightingBow",50,50,-7,range); // переделать защиту в combat
    }
    static std::unique_ptr<Weapon> Harpoon()
    {
        return std::make_unique<Weapon>("Harpoon",20,15,6,range);
    }
    static std::unique_ptr<Weapon> Bow()
    {
        return std::make_unique<Weapon>("Bow",14,14,4,range);
    }
    static std::unique_ptr<Weapon> CrossBow()
    {
        return std::make_unique<Weapon>("CrossBow",25,30,2,range);
    }
    //Пресеты еды
    static std::unique_ptr<Food> Bread()
    {
        return std::make_unique<Food>("Bread",15,25);
    }
    static std::unique_ptr<Food> Apple()
    {
        return std::make_unique<Food>("Apple",20,15);
    }
    static std::unique_ptr<Food> Fish()
    {
        return std::make_unique<Food>("Fish",25,30);
    }
    static std::unique_ptr<Food> Meat()
    {
        return std::make_unique<Food>("Meat",30,50);
    }
    static std::unique_ptr<Food> Squirrel()
    {
        return std::make_unique<Food>("Squirrel",7,10);
    }
    static std::unique_ptr<Food> Borsch()
    {
        return std::make_unique<Food>("Borsh",50,50);
    }
    static std::unique_ptr<Food> God_eat()
    {
        return std::make_unique<Food>("God_Eat",200,200);
    }
    static std::unique_ptr<Food> Humanity()
    {
        return std::make_unique<Food>("Humanity",-15,100);
    }
    static std::unique_ptr<Food> Water()
    {
        return std::make_unique<Food>("Water",10,0);
    }
    static std::unique_ptr<Food> GoldenApple()
    {
        return std::make_unique<Food>("GoldenApple",100,50);
    }
    // Пресеты зельев
    static std::unique_ptr<Potion> Potion_Power()
    {
        return std::make_unique<Potion>("Potion_Power",0,-10,20); // сделать так что бы бонусы были временными на 3 атаки
    }
    static std::unique_ptr<Potion> Potion_God()
    {
        return std::make_unique<Potion>("Potion_God",50,50,50,50);
    }
    static std::unique_ptr<Potion> Potion_Reability()
    {
        return std::make_unique<Potion>("Potion_Reability",10,10,10,10);
    }
    static std::unique_ptr<Potion> Potion_Stamina()
    {
        return std::make_unique<Potion>("Potion_Stamina",0,-15,0,40);
    }
    static std::unique_ptr<Potion> Potion_Heal()
    {
        return std::make_unique<Potion>("Potion_Heal",50,5);
    }
    static std::unique_ptr<Potion> Potion_Poison()
    {
        return std::make_unique<Potion>("Potion_Posion",-10,20,-10,-10);
    }
};