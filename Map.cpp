#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include "Location.h"
#include "Map.h"
#include "ItemFactory.h"
bool Map::isFree(int row, int col){
    if(grid[row][col] == nullptr)
        return true;
    else
        return false;
}
std::pair<int, int> Map::getRandomFreeCell() {
    int row, col;
    do {
        row = rand() % 5;
        col = rand() % 9;
    } while (!isFree(row, col));
    return {row, col};
}


Map::Map() // ручное создание карты
{
    std::vector<std::function<std::unique_ptr<Enemy>()>> enemyFactories = {
    ItemFactory::Goblin,
    ItemFactory::Wolf,
    ItemFactory::Rat,
    ItemFactory::Orc,
    ItemFactory::Skeleton,
    ItemFactory::Ghost
    };
    std::vector<std::function<std::unique_ptr<Item>()>> itemFactories = {
    ItemFactory::Dagger,
    ItemFactory::Axe,
    ItemFactory::Rapier,
    ItemFactory::PlasmaSword,
    ItemFactory::Slingshot,
    ItemFactory::LightingBow,
    ItemFactory::Harpoon,
    ItemFactory::Apple,
    ItemFactory::Fish,
    ItemFactory::Meat,
    ItemFactory::Squirrel,
    ItemFactory::Borsch,
    ItemFactory::God_eat,
    ItemFactory::Humanity,
    ItemFactory::Water,
    ItemFactory::GoldenApple,
    ItemFactory::Potion_God,
    ItemFactory::Potion_Power,
    ItemFactory::Potion_Reability,
    ItemFactory::Potion_Stamina,
    ItemFactory::Potion_Heal,
    ItemFactory::Bread,
    ItemFactory::IronSword
};
    grid[x][y] = std::make_unique<Location>("Старт");
    for(int i = 0;i<width;i++){
        for(int j = 0;j<height;j++){
            grid[i][j] = nullptr; // для заполнения всех полей пустыми значениями
        }
    }
    
    int enemyCount = 5 + rand() % 8; // от 5 до 12
    for (int i = 0; i < enemyCount; i++) {
        auto cell = getRandomFreeCell();
        int idx = rand() % enemyFactories.size();
        grid[cell.first][cell.second] = std::make_unique<Location>("Опасная зона", enemyFactories[idx]());
    }
    int itemCount = 4 + rand() % 8; // от 4 до 11
    for (int i = 0; i < itemCount; i++) {
        auto cell = getRandomFreeCell();
        int idx = rand() % itemFactories.size();
        grid[cell.first][cell.second] = std::make_unique<Location>("Сундук", nullptr, itemFactories[idx]());
    } 
    auto cell = getRandomFreeCell();
    grid[cell.first][cell.second] = std::make_unique<Location>("Выход", ItemFactory::Dragon(), nullptr, true);
    auto c = getRandomFreeCell();
    x = c.first;
    y = c.second;
    
}



bool Map::win() const
{
    return grid[x][y] != nullptr && grid[x][y]->isExit(); // условие для победы
}

void Map::print() const
{
    std::cout << "===== Map =====" << std::endl;
    for(int i = 0;i<width;i++){
        for(int j = 0;j<height;j++){
            if(i == x && j == y) 
                std::cout << " \033[32m@\033[0m "; // значок игрока
            else if(grid[i][j] == nullptr)
                std::cout << " \033[90m.\033[0m "; // значок пустоты
            else if(grid[i][j]->isExit())
                std::cout << " \033[35m>\033[0m "; // значок выхода
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
    "\033[91mTr\033[0m-Enemy and Item" << std::endl << "\033[90m.\033[0m - Void" <<std::endl <<  "\033[35m>\033[0m-Exit" << std::endl;
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
    return grid[x][y].get();
}