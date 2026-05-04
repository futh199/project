#pragma once
#include<string>
#include<iostream>
#include "Player.h"
#include "Enemy.h"
#include <limits>
class Combat{
public:
    static void start(Player& player, Enemy& enemy); // цикл боя
    static bool turn(Player& player,Enemy& enemy); // ход игрока, после ход врага
    static bool live(const Player& player, const Enemy& enemy); // проверка на смерть
private:
    static void playerTurn(Player& player, Enemy& enemy); // ход игрока
    static void enemyTurn(Player& player, Enemy& enemy); // ход врага
    static void displayStatus(const Player& player, const Enemy& enemy); // отображение инф-ции игрока и врага
    static int getPlayerAction(); // получение действия
    
}
;