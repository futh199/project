#include <iostream>
#include <fstream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "ItemFactory.h"
#include "Combat.h"
#include "Location.h"
#include "Map.h"
#include "globals.h"

int totalKills = 0;
void save_game(Player& player, const Map& map, int kills){
    std::ofstream file("save.txt");
    if(!file.is_open()) return;
    // Данные игрока
    file << player.get_name() << "\n";
    file << player.get_health() << "\n";
    file << player.get_damage() << "\n";
    file << player.get_lvl() << "\n";
    file << player.get_exp() << "\n";

    // Позиция на карте
    file << map.getX() << ' ' << map.getY() << "\n";

    // Счётчик убийств
    file << kills << "\n";

    // Инвентарь (количество предметов и их названия)
    file << player.get_inventory().size() << "\n";
    for (size_t i = 0; i < player.get_inventory().size(); ++i) {
        file << player.get_inventory().get_name(i) << "\n";
    }

    file.close();
}
bool load_game(Player& player, Map& world, int& kills){
    std::ifstream file("save.txt");
    if (!file.is_open()) return false;

    std::string name;
    int health, damage, lvl, exp;
    int x, y;
    int killsCount;
    int invSize;

    file >> name >> health >> damage >> lvl >> exp;
    file >> x >> y;
    file >> killsCount;
    file >> invSize;

    player.set_name(name);
    player.gift_health(health - player.get_health()); // хитро, но проще пересоздать
    // Лучше: создать временного игрока и заменить

    // Позиция игрока на карте
    world.setPlayerPosition(x, y);

    kills = killsCount;

    // Загрузка инвентаря (по названиям)
    for (int i = 0; i < invSize; ++i) {
        std::string itemName;
        std::getline(file >> std::ws, itemName);
        // Создать предмет по имени (потребуется фабрика)
    }

    file.close();
    return true;
}
void test_food(){
    std::cout << "=== Testing Inventory ===\n";
    
    Inventory bag;
    Player hero("Hero",100,0,0);
    hero.gift_hungred(50);
    hero.gift_health(-99);
    // Добавляем предметы
    bag.add(ItemFactory::Bread());
    bag.add(ItemFactory::GoldenApple());
    bag.add(new Food("Meat",100,-100));
    
    std::cout << "Inventory size: " << bag.size() << " (expected 3)\n";
    bag.print();
    
    // Используем хлеб (индекс 0)
    bag.use_item(0, hero);
    std::cout << "After using bread, size: " << bag.size() << " (expected 2)\n";
    std::cout << "Health: " << hero.get_health() << " Hungred:" << hero.get_hungred() << std::endl;
    
    // Используем тот же индекс в надежде на поедания яблока
    bag.use_item(0, hero);
    std::cout << "After using GoldenApple, size: " << bag.size() << " (expected 2)\n";
    std::cout << "Health: " << hero.get_health() << " Hungred:" << hero.get_hungred() << std::endl;
    
    // Удаляем предмет (индекс 0)
    bag.remove(0);
    std::cout << "After removal, size: " << bag.size() << " (expected 1)\n";
    hero.gift_hungred(50);
    std::cout << "Xaracteristiki: " << "HP:" << hero.get_health() << " Hungred:" << hero.get_hungred() << std::endl;
    
    std::cout << "=== Test passed if no crashes ===\n\n";
};
void test_potion(){
    std::cout << "=== Testing Inventory ===\n";
    
    Inventory bag;
    Player hero("Hero",100,0,0);
    bag = hero.get_inventory();
    // Добавляем предметы
    bag.add(ItemFactory::Potion_Heal());
    bag.add(ItemFactory::Potion_Poison());
    bag.add(ItemFactory::Potion_Heal());
    
    std::cout << "Inventory size: " << bag.size() << " (expected 3)\n";
    bag.print();
    
    // Используем зелье хила (индекс 0)
    bag.use_item(0, hero);
    std::cout << "After use Potion_Heal, size: " << bag.size() << " (expected 2)\n";
    std::cout << "Health: " << hero.get_health() << " Hungred:" << hero.get_hungred() << " Damage: " << hero.get_damage() << " Stamina: " << hero.get_stamina() << std::endl;
    
    // Используем тот же индекс в надежде на поеданиe яблока
    bag.use_item(0, hero);
    std::cout << "After using Potion_Poison, size: " << bag.size() << " (expected 2)\n";
    std::cout << "Health: " << hero.get_health() << " Hungred:" << hero.get_hungred() << " Damage: " << hero.get_damage() << " Stamina: " << hero.get_stamina() << std::endl;
    
    // Удаляем предмет (индекс 0)
    bag.remove(0);
    std::cout << "After removal, size: " << bag.size() << " (expected 1)\n";
    std::cout << "=== Test passed if no crashes ===\n\n";
};
void test_weapon(){
    std::cout << "=== Testing Inventory ===\n";
    
    Inventory bag;
    Player hero("Hero",100,10,0);
    bag = hero.get_inventory();
    // Добавляем предметы
    bag.add(ItemFactory::IronSword());
    bag.add(ItemFactory::Dagger());
    bag.add(ItemFactory::CrossBow());
    
    std::cout << "Inventory size: " << bag.size() << " (expected 3)\n";
    bag.print();
    
    // Экипировка меча (индекс 0)
    bag.use_item(0, hero);
    std::cout << "After using IronSword, size: " << bag.size() << " (expected 2)\n";
    std::cout <<" Damage: " << hero.get_weapon_damage() << std::endl;
    
    // Экипировка лука (индекс 2)
    bag.use_item(2, hero);
    std::cout << "After equipped CrossBow, size: " << bag.size() << " (expected 2)\n";
    std::cout <<" Damage: " << hero.get_weapon_damage() << std::endl;
    
    // Удаляем предмет (индекс 1)
    bag.remove(1);
    std::cout << "After removal Dagger, size: " << bag.size() << " (expected 1)\n";
    std::cout << "Health: " << hero.get_health() << " Hungred:" << hero.get_hungred() << " Damage: " << hero.get_weapon_damage() << " Stamina: " << hero.get_stamina() << std::endl;
    std::cout << "Dont equipped Weapon: " << bag.get_name(0) << std::endl << "Weapon:" << hero.get_weapon() << std::endl;
    
    std::cout << "=== Test passed if no crashes ===\n\n";
};
void test_combat(){
    Player hero("Nikolai", 100, 10, 1);
    //Enemy Goblin = ItemFactory::Goblin();
    
    // Добавляем предметы
    hero.get_inventory().add(ItemFactory::GoldenApple());
    hero.get_inventory().add(ItemFactory::CrossBow());
    
    // Начинаем бой
    //Combat::start(hero, Goblin);
    std::cout << "Hero lvl: " << hero.get_lvl() << " |Exp: " << hero.get_exp() <<  std::endl;
    std::cout << "Max_Health: " << hero.get_max_hp() << " |Max_Stamina: " << hero.get_max_stamina() << " |Damage: " << hero.get_damage() << std::endl;
};
void test_map(){
    Player hero("Kolya", 100, 10, 1);
    Map world;
    hero.get_inventory().add(ItemFactory::Meat());
    hero.get_inventory() += (ItemFactory::Meat());
    while (hero.isLive() && !world.win()) {
        
        // Показать карту и продложить движение
        world.print();
        // Вход в локацию
        
        std::cout << "\nMove (W/A/S/D)";
        std::cout << "\nQ to exit";
        std::cout << "\nC to save";
        std::cout << "\nL to load: ";
        char input;
        std::cin >> input;
        if (input == 'q' || input == 'Q') break;
        if (input == 'c' || input == 'C') save_game(hero,world,totalKills);
        if (input == 'l' || input == 'L') load_game(hero,world,totalKills);
        else{
            world.move(input);
            Location* loc = world.get_current_locale();
            loc->enter(hero);
        }
    }
    if(!hero.isLive()){
        std::cout << "================" << std::endl;
        std::cout << "    YOU DIED" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << "Experience gained: " << hero.get_exp()+hero.get_lvl()*100 << std::endl;
        std::cout <<"Enemies killed: " << totalKills <<std::endl; 
        std::cout << "================" << std::endl;
    }
    else
        std::cout << "Game Over!\n";
    
};
int main(){
    /*Player pl("God",100,1,10);
    
     Добавляем предметы через фабрику
    pl.get_inventory().add(ItemFactory::IronSword());
    pl.get_inventory().add(ItemFactory::Potion_Heal());
    pl.get_inventory().add(ItemFactory::GoldenApple());
    pl.get_inventory().add(ItemFactory::CrossBow());
    
    */
    test_map();
    
    return 0;
}
