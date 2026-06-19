#pragma once
#include <iostream>
#include <string>
#include "Location.h"
class Map
{
private:
    static const int width = 5; // высота карты

    static const int height = 9; // длина карты

    Location* grid[width][height]; // координаты локации

    int x{0}; int y{0}; // координаты игрока

    bool complete{false}; // флаг на конец игры
    
public:
    void generateLocations();
    Map(); // конструктор

    ~Map(); // деструктор
    std::pair<int, int> getRandomFreeCell();
    void move(char direction); // передвижение по карте
    bool isFree(int row, int col);
    void print(); // вывод карты
    int getX() const {return x;}
    int getY() const {return y;}
    void setPlayerPosition(int x, int y);

    Location* get_current_locale() const; // получение локации в которой находится игрок

    bool win() const; // получение "конца игры"

};