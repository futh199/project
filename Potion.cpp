#include "Potion.h"
#include <iostream>
#include "Player.h"
#include "Item.h"
Potion::Potion(const std::string& n, short health,short hunger,short damage,short stamina) : Item(n), health(health), hunger(hunger), damage(damage), stamina(stamina){}
short Potion::get_health(){
    return health;
}
short Potion::get_damage(){
    return damage;
}
short Potion::get_hunger(){
    return hunger;
}
short Potion::get_stamina(){
    return stamina;
}
void Potion::use(Player& player){
    player.gift_health(health);
    player.gift_hungred(hunger);
    player.gift_stamina(stamina);
    player.set_weapon_damage(damage);
}
void Potion::print(){
    std::cout << name << ": Heal " << health << ", Hunger " << hunger << ", Stamina " << stamina << ", Damage " << damage << std::endl;
}