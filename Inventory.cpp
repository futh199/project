#include<iostream>
#include<string>
#include<vector>
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
Inventory::~Inventory()
{
        for (auto* item : items) {
            delete item;  // освобождаем память
            }
}
Inventory& Inventory::operator+=(Item* right)
{
    if(right != nullptr)
        add(right); // добавляем предмет
    return *this;
}
void Inventory::use_item(size_t index, Player& player)
{
    if (index >= items.size()) return; // проверяем корректность индекса

    Item* item = items[index];

    // Проверяем, является ли предмет оружием
    if (dynamic_cast<Weapon*>(item) != nullptr) {
        items.erase(items.begin() + index);// Оружие: экипируем, НЕ удаляем
        item->use(player);
    } 
    else 
    {
        // Еда или зелье: используем и удаляем
        item->use(player);
        delete item;
        items.erase(items.begin() + index);
    }
}
void Inventory::add(Item* t)
{
    items.push_back(t); // добавление в конец инвентаря предмета
}
void Inventory::remove(size_t index)
{
    if(index <items.size()) // проверка на корректность индекса
    {
        delete items[index]; 
        items.erase(items.begin()+index);
    }
}
size_t Inventory::size() const 
{
    return items.size(); 
}
std::string Inventory::get_name(size_t index)
{
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