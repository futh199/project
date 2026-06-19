#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
class Location{
private:
    std::string name;
    Enemy* enemy{nullptr};
    Item* item{nullptr};
    bool isCleared{false};
    bool Exit{false};

public:
    Location(const std::string& name, Enemy* enemy = nullptr, Item* item = nullptr,bool Exit = false); // конструктор преобразования

    void enter(Player& player); // запуск событий (бой,сундук)

    bool isExit() const { return Exit; }

    void set_enemy(Enemy* e); // установка врага

    void set_item(Item* i); // установка предмета

    void set_isCleared(bool is); // установка зачистки

    void set_name(std::string n); // установка имени

    Enemy* get_enemy() const; // получение врага

    Item* get_item() const; // получение предмета

    std::string get_name() const; // получение имени

    bool clear() const; // получение зачистки
    
    ~Location(); // деструктор
};