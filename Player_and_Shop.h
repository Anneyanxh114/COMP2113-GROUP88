#ifndef PLAYER_SHOP_H
#define PLAYER_SHOP_H
#include <string>
#include <map>
using namespace std;

struct Player{
    double HP = 2000; //生命值 (游戏开始即初始化)
    int ATK; //攻击力
    int DEF; //防御值
    int Money = 100; //金钱数量 - 计入存档
    double PersonalBest = 0; // 最短游戏用时 - 计入存档
    string Name;//player name - 计入存档
    string Career;//career
};
Player choice_role();
Player JunkShop(Player p);
Player SupplyShop(Player p);
void printPlayer(Player p);

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
    map <string, Player> Records;
};


#endif