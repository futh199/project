#include<iostream>
#include<string>
#include "Food.h"
#include "Player.h"
#include "Item.h"
Food::Food(const std::string n, short h,short hun) : Item(n), health(h), hunger(hun)
    { 
        std::cout << "Food: " << name << std::endl;
    }

void Food::print()
{
    std::cout << "\033[32m" << name << "\033[0m" << ": Health " << health << ", hunger " << hunger << std::endl;
}

void Food::use(Player& player)
{
    player.gift_health(health);
    player.gift_hungred(hunger);
}

short Food::get_health()
{
    return health;
}

short Food::get_hunger()
{
    return hunger;
}