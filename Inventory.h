#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Item.h"
class Player;
class Inventory{
private:
    std::vector<Item*> items; // векторный класс для удобного использования
public:
    Inventory() = default; // конструктор по умолчанию

    Inventory& operator+=(Item* right); // переопределение операции присваивания для добавления предмета

    std::string get_name(size_t index); // получение имени конкретного предмета

    void use_item(size_t index, Player& player); // использование предмета по индексу

    void add(Item* t); // добавление предмета в инвентарь

    void remove(size_t index); // удаление предмета из инвентаря

    virtual void print(); // вывод всего инвентаря

    size_t size() const; // вывод размера
    
    ~Inventory(); // деструктор
};