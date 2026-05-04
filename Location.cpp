#include "Location.h"
#include "Enemy.h"
#include "Item.h"
#include "Combat.h"
#include "globals.h"
Location::Location(const std::string& name,Enemy* enemy,Item* item) : name(name), enemy(enemy), item(item){}

void Location::set_enemy(Enemy* e)
{
    enemy = e;
}
void Location::set_item(Item* i)
{
    item = i;
}
void Location::set_isCleared(bool is)
{
    isCleared = is;
}
void Location::set_name(std::string n)
{
    name = n;
}
void Location::enter(Player& player) 
{
    if(enemy !=nullptr) { // проверка локации на врага
        Combat::start(player,*enemy);
        if(!enemy->isLive()) {enemy = nullptr;
            if(item != nullptr)
                {player.get_inventory().add(item);
                item = nullptr;}
            totalKills++;
            }
        }
    else if(item != nullptr && isCleared == false)  // проверка на зачистку и сундук локации
        {player.get_inventory().add(item);
        item = nullptr;}
    isCleared = true; // установка зачистки после посещения локации
}
Enemy* Location::get_enemy() const
{
    return enemy;
}
Item* Location::get_item() const
{
    return item;
}
std::string Location::get_name ()const
{
    return name;
}
bool Location::clear() const
{
    return isCleared;
}
Location::~Location()
{
    delete item; // освобождение памяти
    delete enemy;
}
