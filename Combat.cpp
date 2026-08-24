#include "Combat.h"
#include <limits>
void printbar(short cur,short max, short width = 20){
    int f = (cur*width)/max;
    for(int i = 0;i<width ;i++){
        if(i<f)
            std::cout << "\033[32m█\033[0m";
        else
            std::cout << "\033[90m░\033[0m";
    }
    std::cout << ' ' << cur << '/' << max;
    std::cout << std::endl;
}
void Combat::start(Player& player, Enemy& enemy)
{
    std::cout << "======= Battle Start =======" << std::endl;
    std::cout << player.get_name() << " VS " << enemy.get_name() << std::endl;

    while(!live(player,enemy)){
        displayStatus(player,enemy);
        if(!turn(player,enemy))
            break;
    };

    if(!player.isLive()){
        std::cout << player.get_name() << " is Dead.... Noooooob" << std::endl;
        
    }
    else if(!enemy.isLive()){
        std::cout << "You kill " << enemy.get_name() << std::endl;
        player.gift_exp(enemy.get_exp());
    }
}
bool Combat::live(const Player& player, const Enemy& enemy){
    return !player.isLive() || !enemy.isLive();
}
void Combat::displayStatus(const Player& player, const Enemy& enemy){
    std::cout << "===Status===" << std::endl;
    std::cout << player.get_name();
    std::cout << " Health: ";
    printbar(player.get_health(),player.get_max_hp());
    std::cout << "Stamina: ";
    printbar(player.get_stamina(),player.get_max_stamina());
    std::cout << "Hunger: ";
    printbar(player.get_hungred(),100);
    std::cout << enemy.get_name() << " Health: ";
    printbar(enemy.get_health(),enemy.get_max_hp());
    std::cout << "------------" << std::endl;
}
int Combat::getPlayerAction(){
    std::cout << "Attack - |1|" << std::endl << "Use_item - |2|" << std::endl << "Defend - |3|" << std::endl;
    short choice = 0;
    while(!(std::cin >> choice)){
        std::cin.clear();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a number! Try again: ";
    }
    return choice;
}
void Combat::playerTurn(Player& player, Enemy& enemy){
    int action = getPlayerAction();
    switch(action){
        case 1: // атака
            {short damage = player.get_damage() + player.get_weapon_damage()-(enemy.get_defence()/2);
            if(damage<0) damage = 0;
            player.set_block(false);
            player.gift_stamina(-player.get_gun().get_stamina());
            player.update_hungred(1);
            if(player.get_stamina() == 0)
                {std::cout << "Not enough stamina" << std::endl;
                break;}
            enemy.gift_damage(damage);
            std::cout << player.get_name() << " Attacks for " << damage << "| Defence: " << enemy.get_defence()/2 << std::endl;
            break;}
        case 2: // использование предмета
            {size_t index = 0;
            player.set_block(false);
            player.get_inventory().print();
            player.update_stamina();
            player.update_hungred(2);
            std::cout << "Selest item index ";
            std::cin >> index;
            index-=1;
            if(index<player.get_inventory().size())
                player.get_inventory().use_item(index,player);
            else{
                std::cout << "Invalid choice! You lose your turn." << std::endl;
            }
            break;}
        case 3: // защита и восстановление
            player.update_stamina();
            player.update_hungred(1);
            player.set_block(true);
            std::cout << player.get_name() << " Choice Block, protection is enhanced in 2 " << std::endl;
            break;
        default:
            {std::cout << "Invalid choice! You lose your turn." << std::endl;
            break;}
    };
}
void Combat::enemyTurn(Player& player, Enemy& enemy){
    if(!player.isLive()) return;
    short damage = enemy.get_damage();
    short block = player.get_defence();
    if(player.isBlocking())
        damage -= block;
    else
        damage -= block/2;
    if(damage<0) damage = 0;
    player.gift_damage(damage);
    if(player.isBlocking())
        std::cout << enemy.get_name() << " Attacks for " << damage << "| Defence: " << block << std::endl;
    else
        std::cout << enemy.get_name() << " Attacks for " << damage << "| Defence: " << block/2 << std::endl;
}
bool Combat::turn(Player& player,Enemy& enemy){
    playerTurn(player,enemy);
    if(!enemy.isLive())
        return false;
    enemyTurn(player,enemy);
    return player.isLive();
}