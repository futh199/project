#pragma once
#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include "Item.h"
class Player;
class Inventory{
private:
    std::vector<std::unique_ptr<Item>> items; // векторный класс для удобного использования
public:
    Inventory() = default; // конструктор по умолчанию
    
    Inventory(const Inventory&) = delete;

    Inventory(Inventory&&) = default;

    Inventory& operator=(const Inventory&) = delete;

    Inventory& operator=(Inventory&&) = default;

    Inventory& operator+=(std::unique_ptr<Item> right); // переопределение операции присваивания для добавления предмета

    std::string get_name(size_t index); // получение имени конкретного предмета

    void use_item(size_t index, Player& player); // использование предмета по индексу

    void add(std::unique_ptr<Item> t); // добавление предмета в инвентарь

    void remove(size_t index); // удаление предмета из инвентаря

    virtual void print(); // вывод всего инвентаря

    size_t size() const; // вывод размера
    
    ~Inventory() = default; // деструктор
};