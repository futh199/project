#pragma once
#include<iostream>
#include<string>

class Player; 
class Item {
protected:
    std::string name; // общее поле для дочерних классов
public:
    Item(const std::string& name) : name(name){} // конструктор преобразования
    virtual ~Item(){} // деструктор
    virtual void print() = 0; // чисто-виртуальный метод вывода инф-ции предмета
    virtual void use(Player& player) = 0; // чисто-виртуальный метод использования предмета
    virtual std::string get_name(){return name;} // получение имени
};