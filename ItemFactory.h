#pragma once
#include "Weapon.h"
#include "Potion.h"
#include "Food.h"
#include "Enemy.h"
#include <iostream>
//создание пресетов для удобного пользования
struct ItemFactory{
    // Пресеты врагов
    static Enemy* Wolf()
    {
        return new Enemy("Wolf",60,14,5,90,nullptr);
    }
    static Enemy* Orc()
    {
        return new Enemy("Orc",80,30,7,300);
    }
    static Enemy* Rat()
    {
        return new Enemy("Rat",10,5,1,50);
    }
    static Enemy* Dragon()
    {
        return new Enemy("Dragon",300,40,20,500);
    }
    static Enemy* Skeleton()
    {
        return new Enemy("Skeleton",55,13,6,100);
    }
    static Enemy*Ghost()
    {
        return new Enemy("Ghost",40,25,6,110);
    }
    static Enemy* Player()
    {
        return new Enemy("Player",100,100,75,1000);
    }
    static Enemy* Goblin()
    {
        return new Enemy("Goblin",50,10,3,95,ItemFactory::Dagger());
    }
    // Пресеты оружия
    static Weapon* IronSword()
    {
        return new Weapon("Iron Sword",10,10,10,melee);
    }
    static Weapon* Dagger()
    {
        return new Weapon("Dagger",5,4,4,melee);
    }
    static Weapon* Axe()
    {
        return new Weapon("Axe",15,8,12,melee);
    }
    static Weapon* Rapier()
    {
        return new Weapon("Rapier",40,40,5,melee);
    }
    static Weapon* PlasmaSword()
    {
        return new Weapon("PLasmaSword",30,25,20,melee);
    }
    static Weapon* Slingshot()
    {
        return new Weapon("Slingshot",7,3,1,range);
    }
    static Weapon* LightingBow()
    {
        return new Weapon("LightingBow",50,50,-7,range); // переделать защиту в combat
    }
    static Weapon* Harpoon()
    {
        return new Weapon("Harpoon",20,15,6,range);
    }
    static Weapon* Bow()
    {
        return new Weapon("Bow",14,14,4,range);
    }
    static Weapon* CrossBow()
    {
        return new Weapon("CrossBow",25,30,2,range);
    }
    //Пресеты еды
    static Food* Bread()
    {
        return new Food("Bread",15,25);
    }
    static Food* Apple()
    {
        return new Food("Apple",20,15);
    }
    static Food* Fish()
    {
        return new Food("Fish",25,30);
    }
    static Food* Meat()
    {
        return new Food("Meat",30,50);
    }
    static Food* Squirrel()
    {
        return new Food("Squirrel",7,10);
    }
    static Food* Borsch()
    {
        return new Food("Borsh",50,50);
    }
    static Food* God_eat()
    {
        return new Food("God_Eat",200,200);
    }
    static Food* Humanity()
    {
        return new Food("Humanity",-15,100);
    }
    static Food* Water()
    {
        return new Food("Water",10,0);
    }
    static Food* GoldenApple()
    {
        return new Food("GoldenApple",100,50);
    }
    // Пресеты зельев
    static Potion* Potion_Power()
    {
        return new Potion("Potion_Power",0,-10,20); // сделать так что бы бонусы были временными на 3 атаки
    }
    static Potion* Potion_God()
    {
        return new Potion("Potion_God",50,50,50,50);
    }
    static Potion* Potion_Reability()
    {
        return new Potion("Potion_Reability",10,10,10,10);
    }
    static Potion* Potion_Stamina()
    {
        return new Potion("Potion_Stamina",0,-15,0,40);
    }
    static Potion* Potion_Heal()
    {
        return new Potion("Potion_Heal",50,5);
    }
    static Potion* Potion_Poison()
    {
        return new Potion("Potion_Posion",-10,20,-10,-10);
    }
};