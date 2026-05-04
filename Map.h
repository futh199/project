#pragma once
#include <iostream>
#include <string>
#include "Location.h"
class Map
{
private:
    static const int width = 3; // высота карты

    static const int height = 5; // длина карты

    Location* grid[width][height]; // координаты локации

    int x{0}; int y{0}; // координаты игрока

    bool complete{false}; // флаг на конец игры
    
public:
    Map(); // конструктор

    ~Map(); // деструктор

    void move(char direction); // передвижение по карте

    void print(); // вывод карты
    int getX() const {return x;}
    int getY() const {return y;}
    void setPlayerPosition(int x, int y);

    Location* get_current_locale() const; // получение локации в которой находится игрок

    bool win() const; // получение "конца игры"

};