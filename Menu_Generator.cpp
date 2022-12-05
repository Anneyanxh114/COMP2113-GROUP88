#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "Menu_Operator.h"
#include "Player_and_Shop.h"
using namespace std;

Player mainMenu(map<string, Player> &Records);

Player savesMenu(map<string, Player> &Records){
    setPos(35,9);
    Player p;
    cout << "BACK";

    int totalSaves = Records.size();
    
    int l = 0;
    for( map<string, Player> :: iterator it=Records.begin();it!=Records.end();it++){
        setPos(35,11 + 2 * l);
        cout << "Player: " << it -> first << " HP: " << it -> second.HP << endl;
        l ++;
        
    }

    setPos(35,11);


    if(totalSaves == 0){
        //totalSaves = -1 means there's no records
    }

    setPos(35, 9);
    int lineNum = 0;

    while(1){
        int key = scanKeyboard();
        if(key == 119 || key == 87){ // When press "W", go up.
            if(lineNum != 0){
                lineNum --;
                moveUp();
            }
        }
        if(key == 115 || key == 83){ // When press "S", go down.
            if(lineNum != totalSaves){
                lineNum ++;
                moveDown();
            }
        }
        if(key == 10){ // When press "Enter", go to the selected function.
            if(lineNum == 0){
                clear();
                p =  mainMenu(Records);
            }else{
                map<string, Player> :: iterator itr = Records.begin();
                advance(itr, lineNum - 1);
                p = itr -> second;
                clear();
                // p =  loadSaves(line);
            }
            break;
        }
    }
    clear();
    return p;
}

Player rankMenu(map<string, Player> &Records){
    Dungeon d;
    Player p;
    setPos(35,9);
    cout << "BACK";
    d.rankMenu();
    setPos(35,9);
    while(1){
        int key = scanKeyboard();

        if(key == 10){ // When press "Enter", go to the selected function.
            clear();
            p = mainMenu(Records);
        }
    }
    return p;
}

void welcomeMenu(){
    clear();
    setPos(33,8);
    setColor(33);
    cout<<"WELCOME!!!"<<std::endl;
    setColor(35);
    setPos(20,10);
    cout<<"Many monsters suddenly appeared near the peaceful village, breaking the good life of people." << endl;
    setPos(20,11);
    cout<<"To let the villagers back to a good and happy life, as the village's strongest and bravest man" << endl;
    setPos(32,12);
    cout<<"----You----" << endl;
    setPos(20,13);
    cout<<"decided to enter the lair of the monsters to destroy them." << endl;
    setPos(20,20);
    cout<<"----- PLEASE, PRESS ANY KEY TO CONTINUE -----";
    /*
    *
    *press any key to continue
    *
    */
    while(1){
        if(kbhit()){
            scanKeyboard();
            clear();
            // setPos(0,0);
            break;
        }
    }
}
/*
 * Generate the starting menu.
 * Press "START" to start the game.
 * Press "SAVES" to see saved documents which games have not finished before.
 * More functions can be added.
 */
Player mainMenu(map<string, Player> &Records){ //May need to set the initial mouse to the right position.
    
    Dungeon d;
    Player p;
    setPos(35,11);
    cout<<"START NEW GAME";
    setPos(35,13);
    cout<<"SAVES";
    setPos(35,15);
    cout<<"SUCCESSFUL PLAYER LIST";
    setPos(35,17);
    cout<<"EXIT";
    setPos(35,11);
    int lineNum = 0; //If lineNum = 0, "START NEW GAME". If lineNum = 1, the "SAVES" shows and choices the saved documents. If lineNum = 2, the "RANK LIST" shows rank. 
    while(1){
        int key = scanKeyboard();
        if(key == 119){ // When press "W", go up.
            if(lineNum != 0){
                lineNum --;
                moveUp();
            }
        }
        if(key == 115){ // When press "S", go down.
            if(lineNum != 3){
                lineNum ++;
                moveDown();
            }
        }
        if(key == 10){ // When press "Enter", go to the selected function.
            if(lineNum == 0){
                clear();
                p = d.choice_role();
                return p;
            }else if(lineNum == 1){
                clear();
                p = savesMenu(Records);// save the records of the game
                return p;
            }
            else if(lineNum == 2){
                clear();
                p = rankMenu(Records);// print the rankMenu
                return p;
            }
            else if(lineNum == 3){
                clear();
                setPos(0,0);
                exit(0);

            }
        }
    }
    clear();
    return p;
}







