#pragma once
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "ItemFactory.h"
// тесты на разные классы
void test_food(){
    std::cout << "=== Testing Inventory ===\n";
    
    Inventory bag;
    Player hero("Hero",100,0,0);
    bag = hero.get_inventory();
    hero.gift_hungred(50);
    hero.gift_health(-99);
    // Добавляем предметы
    bag.add(ItemFactory::Bread());
    bag.add(ItemFactory::GoldenApple());
    bag.add(new Food("Meat",100,-100));
    
    std::cout << "Inventory size: " << bag.size() << " (expected 3)\n";
    bag.print();
    
    // Используем хлеб (индекс 0)
    hero.get_inventory().use_item(0, hero);
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
    Player hero("Hero",100,0,0);
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
    std::cout <<" Damage: " << hero.get_damage() << std::endl;
    
    // Экипировка лука (индекс 2)
    bag.use_item(2, hero);
    std::cout << "After equipped CrossBow, size: " << bag.size() << " (expected 2)\n";
    std::cout <<" Damage: " << hero.get_damage() << std::endl;
    
    // Удаляем предмет (индекс 1)
    bag.remove(1);
    std::cout << "After removal Dagger, size: " << bag.size() << " (expected 1)\n";
    std::cout << "Health: " << hero.get_health() << " Hungred:" << hero.get_hungred() << " Damage: " << hero.get_damage() << " Stamina: " << hero.get_stamina() << std::endl;
    std::cout << "Dont equipped Weapon: " << bag.get_name(0) << std::endl << "Weapon:" << hero.get_weapon();
    
    std::cout << "=== Test passed if no crashes ===\n\n";
}
