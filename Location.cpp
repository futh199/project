#include "Location.h"
#include "Enemy.h"
#include "Item.h"
#include "Combat.h"
#include "globals.h"
Location::Location(const std::string& name,std::unique_ptr<Enemy> enemy,std::unique_ptr<Item> item,bool Exit) : name(name), enemy(std::move(enemy)), 
item(std::move(item)), Exit(Exit){}

void Location::set_enemy(std::unique_ptr<Enemy> e)
{
    enemy = std::move(e);
}
void Location::set_item(std::unique_ptr<Item> i)
{
    item = std::move(i);
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
    if(enemy) { // проверка локации на врага
        Combat::start(player,*enemy);
        if(!enemy->isLive())
        {enemy = nullptr;
            if(item)
                {
                    player.get_inventory().add(std::move(item));
                }
            totalKills++;
            }
        }
    else if(item && !isCleared)  // проверка на зачистку и сундук локации
        {player.get_inventory().add(std::move(item));
        }
    isCleared = true; // установка зачистки после посещения локации
}
Enemy* Location::get_enemy() const
{
    return enemy.get();
}
Item* Location::get_item() const
{
    return item.get();
}
std::string Location::get_name ()const
{
    return name;
}
bool Location::clear() const
{
    return isCleared;
}

