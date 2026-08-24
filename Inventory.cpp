#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
Inventory& Inventory::operator+=(std::unique_ptr<Item> right)
{
    items.push_back(std::move(right));
    return *this;
}
void Inventory::use_item(size_t index, Player& player)
{
    if (index >= items.size()) return; // проверяем корректность индекса

    std::unique_ptr<Item> t = std::move(items[index]); // забираем предмет
    items.erase(items.begin() + index);

    // Проверяем, является ли предмет оружием
    Weapon* weapon = dynamic_cast<Weapon*> (t.get());
    if(weapon) {
        // Оружие: экипируем, НЕ удаляем
        auto old = player.set_weapon(std::unique_ptr<Weapon>(static_cast<Weapon*>(t.release())));
        if(old){
            add(std::move(old));
        }
    } 
    else 
    { 
        // Еда или зелье: используем и удаляем
        t->use(player);
    }
}
void Inventory::add(std::unique_ptr<Item> t)
{
    items.push_back(std::move(t)); // добавление в конец инвентаря предмета
}
void Inventory::remove(size_t index)
{
    if(index <items.size()) // проверка на корректность индекса
    {
        items.erase(items.begin()+index);
    }
}
size_t Inventory::size() const 
{
    return items.size(); 
}
std::string Inventory::get_name(size_t index)
{
    if (index >= items.size()) return "";
    return items[index]->get_name();
}
void Inventory::print()  
{
    for (size_t i = 0; i < items.size(); i++) //вывод всего инвентаря с индексом у предметов
    {
        std::cout << "===============" << std::endl;
        items[i]->print();
        std::cout << "Index: " << i+1 << std::endl;
        std::cout << "===============" << std::endl;
    }
}
