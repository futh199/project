#include <iostream>
#include <string>
#include "Location.h"
#include "Map.h"
#include "ItemFactory.h"
Map::Map() : x(0), y(4) // ручное создание карты
{
    for(int i = 0;i<width;i++){
        for(int j = 0;j<height;j++){
            grid[i][j] = nullptr; // для заполнения всех полей пустыми значениями
        }
    }
    grid[0][0] = new Location("Dark forest", nullptr, ItemFactory::GoldenApple());
    grid[0][1] = new Location("Forest", ItemFactory::Goblin());
    grid[0][2] = new Location("Razor", nullptr, ItemFactory::PlasmaSword());
    grid[0][4] = new Location("Spawn");  // стартовая локация

    grid[1][1] = new Location("Eby alibabu", ItemFactory::Goblin(), ItemFactory::Potion_Heal());
    grid[1][2] = new Location("NightFall", nullptr, ItemFactory::Bread());
    grid[1][3] = new Location("Io", ItemFactory::Goblin());
    grid[1][4] = new Location("Lock", ItemFactory::Goblin());
    grid[1][0] = new Location("Gg");
    grid[2][0] = new Location("Win", ItemFactory::Goblin());

}

Map::~Map()
{
    for(int i = 0;i<width;i++)
        for(int j = 0;j<height;j++)
            delete grid[i][j]; // освобождение памяти
}

bool Map::win() const
{
    if(grid[2][0]->clear()) return true; // условие для победы
    return false;
}

void Map::print()
{
    std::cout << "===== Map =====" << std::endl;
    for(int i = 0;i<width;i++){
        for(int j = 0;j<height;j++){
            if(i == x && j == y) 
                std::cout << " \033[32m@\033[0m "; // значок игрока
            else if(grid[i][j] == nullptr)
                std::cout << " \033[90m.\033[0m "; // значок пустоты
            else if(grid[i][j]->get_item() && grid[i][j]->get_enemy() == nullptr)
                std::cout << " \033[33mI\033[0m "; // значок сундука
            else if(grid[i][j]->get_enemy() && grid[i][j]->get_item() == nullptr)
                std::cout << " \033[31mE\033[0m "; // значок врага
            else if(grid[i][j]->get_enemy() && grid[i][j]->get_item())
                std::cout << " \033[91mTr\033[0m "; // значок врага и сокровища
            else 
                std::cout << " \033[36m_\033[0m "; // значок пройденой локации

        }
        std::cout << std::endl;
    }
    std::cout << "==============" << std::endl;
    std::cout << "\033[32m@\033[0m-Player" << std::endl << "\033[31mE\033[0m-Enemy" << std::endl << "\033[33mI\033[0m-Item" << std::endl <<
    "\033[91mTr\033[0m-Enemy and Item" << std::endl << "\033[90m.\033[0m - Void" <<std::endl;
    std::cout << "==============" << std::endl;
}

void Map::move(char direction)
{
    int newx = x; int newy = y;
    switch(direction){
        case 'd': case 'D': newy++; break;
        case 'a': case 'A': newy--; break;
        case 'w': case 'W': newx--; break;
        case 's': case 'S': newx++; break;
        default:
            return;
    }
    if(newx < 0 || newx >= width || newy < 0 || newy >= height) // проверка на границы
    { 
        std::cout << "You can`t go that way" << std::endl;
        return;
    }
    if(grid[newx][newy]==nullptr) // проверка на пустую клетку
    {
        std::cout << "Nothing there" << std::endl;
        return;
    }
    // если все нормально, то присваиваем координаты
    x = newx;
    y = newy;

}
void Map::setPlayerPosition(int x, int y){
    this->x = x;
    this->y = y;
}
Location* Map::get_current_locale() const
{
    return grid[x][y];
}