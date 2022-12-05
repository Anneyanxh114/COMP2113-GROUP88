#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Menu_Operator.h"
#include "Player_and_Shop.h"
using namespace std;

/**
 * @brief Choose the role of the player: warrior/mage
 * input the name of the player and display the welcome words
 * 
 * @return Player 
 */
Player Dungeon::choice_role(){
    Player p;
    cout << "Who are you ? Please input a number." << endl;
    cout << "1.Warrior" << endl; 
    cout << "2.Mage" << endl; 
    int SelectIdentity; 
    cin >> SelectIdentity;
    while (true){ 
        if (SelectIdentity == 1){ //warrior
            p.ATK = 150;
            p.DEF = 200;
            p.Career = "Warrior";
            cout << "Your name: " << endl;
            cin >> p.Name; //input the name of the player
            cout << "Welcome, Warrior " << p.Name << "!" << endl;
            break;
        }
        else if (SelectIdentity == 2){ //mage
            p.ATK = 200;
            p.DEF = 150;
            p.Career = "Mage";
            cout << "Your name: " << endl;
            cin >> p.Name; //input the name of the player
            cout << "Welcome, Mage " << p.Name << "!" << endl;
            break;
        }
        else{
            cin >> SelectIdentity;
        }
    }
    clear();
    return p;
}

/**
 * @brief JuckShop: Provides 6 types of weapon for the players to choose to add value to their ATK(attack).
 * 
 * @param p 
 * @return Player 
 */
Player Dungeon::JunkShop(Player p){
    cout << "\033[3A";
    cout << "\033[J";
    printPlayer(p);
    cout<<"Welcome to the Junk Shop!"<<endl; 
    cout<<"1. Knife($2 ATK+2)"<<endl; 
    cout<<"2、Sword($4 ATK+15)"<<endl; 
    cout<<"3、Machete($10 ATK+40)"<<endl; 
    cout<<"4、Bomb($14 ATK+60)"<<endl; 
    cout<<"5、Armor($4 DEF+30)"<<endl; 
    cout<<"6、Shield($7 DEF+60)"<<endl; 
    cout<<"7、Leave the Junk Shop"<<endl; 
    int Weapon; 
    cout << "Please select an option: ";
    cin >> Weapon; 
    while(Weapon!=7)
    { 
        switch(Weapon) 
        { 
            //buy Knife
            case 1 : 
                if(p.Money<2){
                    cout<<"You don't have enough money"<<endl;//if the money is not enough, return false
                }  
                else{
                    cout<<"Successful purchase！"<<endl;//if the money is not enough, return true
                    p.ATK+=2; 
                    p.Money-=2; 
                    break; 
                }  
            //buy Sword
            case 2 : 
                if(p.Money<4){
                    cout<<"You don't have enough money"<<endl; 
                } 
                else{
                    cout<<"Successful purchase！"<<endl; 
                    p.ATK+=20; 
                    p.Money-=4; 
                    break; 
                }  
            //buy Machete
            case 3 : 
                if(p.Money<10){
                    cout<<"You don't have enough money"<<endl; 
                } 
                else{
                    cout<<"Successful purchase！"<<endl; 
                    p.ATK+=40; 
                    p.Money-=10; 
                    break; 
                } 
            //buy Bomb
            case 4 : 
                if(p.Money<14){
                    cout<<"You don't have enough money"<<endl; 
                }
                else{
                    cout<<"Successful purchase！"<<endl; 
                    p.ATK+=60; 
                    p.Money-=14; 
                    break; 
                }  
            //buy Armor
            case 5 : 
                if(p.Money<4) 
                    cout<<"You don't have enough money"<<endl; 
                else{
                    cout<<"Successful purchase！"<<endl; 
                    p.DEF+=30; 
                    p.Money-=4; 
                    break; 
                }  
            //buy Shield
            case 6 :
                if (p.Money < 7){
                    cout<<"You don't have enough money"<<endl;                    
                }else{
                    cout<<"Successful purchase！"<<endl; 
                    p.DEF+=60; 
                    p.Money-=7;
                }
                break; 
            default:
                break; 
        }  
        cout << "\033[13A";
        printPlayer(p);
        cout << "\033[2K";
        cout<<"Welcome to the Junk Shop!"<<endl; 
        cout << "\033[2K";
        cout<<"1. Knife($2 ATK+2)"<<endl; 
        cout << "\033[2K";
        cout<<"2、Sword($4 ATK+15)"<<endl;
        cout << "\033[2K"; 
        cout<<"3、Machete($10 ATK+40)"<<endl; 
        cout << "\033[2K";
        cout<<"4、Bomb($14 ATK+60)"<<endl; 
        cout << "\033[2K";
        cout<<"5、Armor($4 DEF+30)"<<endl; 
        cout << "\033[2K";
        cout<<"6、Shield($7 DEF+60)"<<endl; 
        cout << "\033[2K";
        cout<<"7、Leave the Junk Shop"<<endl; 
        cout << "\033[2K";
        cout << "Please select an option: ";
        cin>>Weapon; 
        while(!(0 < Weapon <= 7)){
            cout << "\033[1A";
            cout << "\033[2K";
            cout << "Please select an option: ";
            cin>>Weapon; 
        }
        cout << "\033[2K";
    }
    return p;
}

/**
 * @brief SupplyShop: choose the object with different buff in the HP value to supply the player's HP
 * 
 * @param p 
 * @return Player 
 */
Player Dungeon::SupplyShop(Player p){
    cout << "\033[3A";
    cout << "\033[J";
    printPlayer(p);
    cout<<"Welcome to the Supply Shop!"<<endl; 
    cout<<"1. Apple ($10 HP+500)"<<endl; 
    cout<<"2. Banana ($50 HP+1000)"<<endl; 
    cout<<"3. Peach ($100 HP+2000)"<<endl; 
    cout<<"4. Leave the Supply Shop."<<endl; 
    int Supply; 
    cout << "Please select an option: ";
    cin>>Supply; 
    while(Supply!=4) 
    { 
        switch(Supply) 
        { 
        case 1 : 
            if(p.Money<10){
                cout<<"You don't have enough money"<<endl; 
            } 
            else {
                cout<<"Successful purchase!"<<endl; 
                p.HP+=500; 
                p.Money-=10; 
                break; 
            } 
        case 2 : 
            if(p.Money<50){
                cout<<"You don't have enough money"<<endl; 
            }
            else{  
                cout<<"Successful purchase!"<<endl; 
                p.HP+=1000; 
                p.Money-=50; 
                break;
            } 
        case 3 : 
            if(p.Money<100){ 
                cout<<"You don't have enough money"<<endl; 
            }
            else{  
                cout<<"Successful purchase!"<<endl; 
                p.HP+=2200; 
                p.Money-=100; 
                break; 
            }
        default : 
            break; 
        
        }
        cout << "\033[10A";
        printPlayer(p);
        cout << "\033[2K";
        cout<<"Welcome to the Supply Shop!"<<endl; 
        cout << "\033[2K";
        cout<<"1. Apple ($10 HP+500)"<<endl; 
        cout << "\033[2K";
        cout<<"2. Banana ($50 HP+1000)"<<endl;
        cout << "\033[2K"; 
        cout<<"3. Peach ($100 HP+2000)"<<endl; 
        cout << "\033[2K";
        cout<<"4. Leave the Supply Shop."<<endl;
        cout << "\033[2K";
        cout << "Please select an option: ";
        cin>>Supply; 
        while(!(0 < Supply <= 4)){
            cout << "\033[1A";
            cout << "\033[2K";
            cout << "Please select an option: ";
            cin>>Supply; 
        }
        cout << "\033[2K";
    } 
    return p;
} 

/**
 * @brief save the parameters of the players to a txt file called "gamedoc.txt"
 * the parameters includes name, HP, ATK, DEF, Money, PersonalBest, Career
 * 
 * @param Records 
 */
void Dungeon::saveDoc(map<string, Player> Records){
  ofstream fout; 
  fout.open("gamedoc.txt");
  if ( fout.fail() ) {
    cout << "Error in file opening!" << endl; exit(1);
  }
  map<string, Player>::iterator itr;
  for (itr = Records.begin(); itr != Records.end(); itr++) {
    fout << "Player: " << (*itr).first << " HP: " << (*itr).second.HP
        << " ATK: " << (*itr).second.ATK << " DEF: " << (*itr).second.DEF <<  " Money: " << (*itr).second.Money 
        << " Score: " << (*itr).second.HP*2 + (*itr).second.Money << " Career: " << (*itr).second.Career <<  endl;
  }
  fout.close();
}


/*
 * print the players and their information
 */
void Dungeon::rankMenu(){
    char filename[80] = "gamedoc.txt";
    ifstream fin;
    fin.open(filename);
    if(fin.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    string line;
    int rank = 1;
    while(getline(fin, line)){ 
        setPos(35,11+(rank-1)*2);
        cout << rank << " " << line << endl;
        cout << endl;
        rank++;
    }
}

/**
 * @brief print the information of the player
 * 
 * @param p 
 */
void printPlayer(Player p){
    if(p.Name.length() >= 2){ // length of the name should be no less than 2
        cout << "\033[2K";
        cout<<"Name: " << p.Name << "\tHP: " << p.HP << endl;
    }else{
        cout << "\033[2K";
        cout<<"Name: " << p.Name << "\t\tHP: " << p.HP << endl;
    }
    cout << "\033[2K";
    cout << "ATK: " << p.ATK << "\tDEF: " << p.DEF << endl;
    cout << "\033[2K";
    cout << "Money: " << p.Money << endl;
}

