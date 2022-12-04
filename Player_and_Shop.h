#ifndef PLAYER_SHOP_H
#define PLAYER_SHOP_H
#include <string>
#include <map>
using namespace std;

struct Player{
    double HP = 2000; //vitality
    int ATK; //attack
    int DEF; //defend 
    int Money = 100; //
    double PersonalBest = 0; //score
    string Name;//player name 
    string Career;//career
};
Player choice_role();
Player JunkShop(Player p);
Player SupplyShop(Player p);
void printPlayer(Player p);

/**
 * @brief Dungeon class: implement the 
 * 
 */
class Dungeon {
public: 
    Player choice_role();
    // void show_play(Player p);
    Player JunkShop(Player p);
    Player SupplyShop(Player p);
    void saveDoc(map<string, Player> Records);
    void DefPlayer(map<string, Player> &Records, Player &p);
    void rankMenu();
private:
    map <string, Player> Records;//STL map for storing the data of the player
};



#endif
