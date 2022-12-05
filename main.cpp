#include <iostream>
#include <cstdio>
#include <fstream>
#include "Menu_Operator.h"
#include "Menu_Generator.h"
#include "Player_and_Shop.h"
#include "Combat.h"
#include "string.h"
#include "map.h"
#include <chrono> 
using namespace std;
using namespace chrono;

/**
 * @brief win: calculate the score defined as hp+2money and store if it's the best score
 * 
 * @param p 
 * @param Records 
 */
void win(Player &p, map<string, Player> &Records){
    Dungeon du;
    int score;
    Records[p.Name] = p;
    score = p.HP*2+p.Money;
    p.PersonalBest = score;
    du.saveDoc(Records);
    cout<<"Congratulations! You have successfully escaped!"<<endl;
    cout<<"Your final score is "<< score <<endl;
    exit(0);
}

// print lose if the player is killed
void lose(){
    clear();
    cout<<"    L         OOOOOO     SSSSS      EEEEE" <<endl;     
    cout<<"    L         O    O     S          E    " <<endl;
    cout<<"    L         O    O     SSSSS      EEEEE" <<endl;
    cout<<"    L         O    O         S      E    " <<endl;
    cout<<"    LLLLLL    OOOOOO     SSSSS      EEEEE" <<endl;
    cout << "\033[5B" << endl;
    cout << "Game over, Please start a new game" << endl;
    exit(0);
}

//end of the game
void end(Player p, map<string, Player> &Records){
    if(p.HP>0 && p.Money>=20){//the condition to win
        win(p, Records);
    }
    else if(p.HP < 0){
        lose();
    }
}

//pause the game
void pause(){
    while(1){
        if(kbhit())
            break;
    }
}

/**
 * @brief including the moving of the player controlled by the key on the keyboard
 * 
 * @param p 
 * @param Records 
 * @return int 
 */
int mainGame(Player p, map<string, Player> &Records){
    Dungeon du;
    //create a map
    char ** map = generateMap(); 
    setPos(0, 0);
    for (int i =0;i<=20;i++){
            puts(map[i]);
        }
    cout<<"o represents your position"<<endl; // o represents the position of the game
    cout<<"please press 's' to move downward"<<endl;
    cout<<"please press 'w' to move upward"<<endl;
    cout<<"please press 'a' to move leftward"<<endl;
    cout<<"please press 'd' to move rightward"<<endl;
    printPlayer(p);
    int x=1, y=1;
    //move your position
    int d;
    while(p.HP > 0){
        int d = scanKeyboard();
        if (d ==80 || d == 112){//user press "p" or "P" will stop the game and record the player into save.
            cout << "Please press \"p\" again to save your role." << endl;
            d = scanKeyboard();
            if (d ==80 || d == 112){
                Records[p.Name] = p;
                du.saveDoc(Records);
                exit(0);
            }
            else{
                break;
            }
        }
        //s:go down
        if(d == 115 || d == 83){
            if(map[x+1][y]==' '){
                map[x][y]=' ';
                x++;
                map[x][y]='o';    
            }
            else if(map[x+1][y]=='#'){
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                p.HP = p.HP-5;
                moveUp();moveUp();moveUp();
                printPlayer(p);
                pause();
            }
            else if(map[x+1][y]=='+'){
                p = du.SupplyShop(p);
            }
            else if(map[x+1][y]=='$'){
                map[x][y]=' ';
                x++;
                map[x][y]='o';
                p.Money=p.Money+10;
                clear();
                setPos(0, 0);
                for (int i =0;i<=20;i++){
                        puts(map[i]);
                    }
                cout<<"o represents your position"<<endl;
                cout<<"please press 's' to move downward"<<endl;
                cout<<"please press 'w' to move upward"<<endl;
                cout<<"please press 'a' to move leftward"<<endl;
                cout<<"please press 'd' to move rightward"<<endl;
                printPlayer(p);
                cout<<"Congratulations! You have found $10"<<endl;
                pause();
            }
            else if (map[x+1][y]=='%'){
                p = du.JunkShop(p);
            }
            else if (map[x+1][y]=='*'){
                end(p,Records);
                break;
            }
            else{
                map[x][y]=' ';
                x++;
                map[x][y]='o';
                clear();
                p = fight(p);
                if(p.HP < 0){
                    lose();
                }
            }
            clear();
            setPos(0, 0);
            for (int i =0;i<=20;i++){
                puts(map[i]);
            }
            cout<<"o represents your position"<<endl;
            cout<<"please press 's' to move downward"<<endl;
            cout<<"please press 'w' to move upward"<<endl;
            cout<<"please press 'a' to move leftward"<<endl;
            cout<<"please press 'd' to move rightward"<<endl;
            printPlayer(p);
            
        }
        if(d == 119 || d == 87){
            if(map[x-1][y]==' '){
                map[x][y]=' ';
                x--;
                map[x][y]='o';
            }
            else if(map[x-1][y]=='#'){
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                p.HP=p.HP-5;
                moveUp();moveUp();moveUp();
                printPlayer(p);
                pause();
            }
            else if(map[x-1][y]=='+'){
                p = du.SupplyShop(p);
            }
            else if(map[x-1][y]=='$'){
                map[x][y]=' ';
                x--;
                map[x][y]='o';
                p.Money = p.Money+10;
                clear();
                setPos(0, 0);
                for (int i =0;i<=20;i++){
                        puts(map[i]);
                    }
                cout<<"o represents your position"<<endl;
                cout<<"please press 's' to move downward"<<endl;
                cout<<"please press 'w' to move upward"<<endl;
                cout<<"please press 'a' to move leftward"<<endl;
                cout<<"please press 'd' to move rightward"<<endl;
                printPlayer(p);
                cout<<"Congratulations! You have found $10"<<endl;
                pause();
            }
            else if (map[x-1][y]=='%'){
                p = du.JunkShop(p);
            }
            else if (map[x-1][y]=='*'){
                end(p,Records);
                break;
            }
            else{
                map[x][y]=' ';
                x--;
                map[x][y]='o';
                clear();
                p = fight(p);
                if(p.HP < 0){
                    lose();
                }
            }
            clear();
            setPos(0, 0);
            for (int i =0;i<=20;i++){
                puts(map[i]);
            }
            cout<<"o represents your position"<<endl;
            cout<<"please press 's' to move downward"<<endl;
            cout<<"please press 'w' to move upward"<<endl;
            cout<<"please press 'a' to move leftward"<<endl;
            cout<<"please press 'd' to move rightward"<<endl;
            printPlayer(p);
        }
        if(d==97 || d==65){
            if(map[x][y-1]==' '){
                map[x][y]=' ';
                y--;
                map[x][y]='o';
                
            }
            else if(map[x][y-1]=='#'){
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                p.HP = p.HP-5;
                moveUp();moveUp();moveUp();
                printPlayer(p);
                pause();
            }
            else if(map[x][y-1]=='+'){
                p = du.SupplyShop(p);
            }
            else if(map[x][y-1]=='$'){
                map[x][y]=' ';
                y--;
                map[x][y]='o';
                p.Money = p.Money+10;
                clear();
                setPos(0, 0);
                for (int i =0;i<=20;i++){
                        puts(map[i]);
                    }
                cout<<"o represents your position"<<endl;
                cout<<"please press 's' to move downward"<<endl;
                cout<<"please press 'w' to move upward"<<endl;
                cout<<"please press 'a' to move leftward"<<endl;
                cout<<"please press 'd' to move rightward"<<endl;
                printPlayer(p);
                cout<<"Congratulations! You have found $10"<<endl;
                pause();
            }
            else if (map[x][y-1]=='%'){
                p = du.JunkShop(p);
            }
            else if (map[x][y-1]=='*'){
                end(p,Records);
                break;
            }
            else{
                map[x][y]=' ';
                y--;
                map[x][y]='o';
                clear();
                p = fight(p);
                if(p.HP < 0){
                    lose();
                }
            }
            clear();
            setPos(0, 0);
            for (int i =0;i<=20;i++){
                puts(map[i]);
            }
            cout<<"o represents your position"<<endl;
            cout<<"please press 's' to move downward"<<endl;
            cout<<"please press 'w' to move upward"<<endl;
            cout<<"please press 'a' to move leftward"<<endl;
            cout<<"please press 'd' to move rightward"<<endl;
            printPlayer(p);
        }
        if(d==100 || d == 68){
            if(map[x][y+1]==' '){
                map[x][y]=' ';
                y++;
                map[x][y]='o';
            }
            else if(map[x][y+1]=='#'){
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                p.HP = p.HP-5;
                moveUp();moveUp();moveUp();
                printPlayer(p);
                pause();
            }
            else if(map[x][y+1]=='+'){
                p = du.SupplyShop(p);
            }
            else if(map[x][y+1]=='$'){                
                map[x][y]=' ';
                y++;
                map[x][y]='o';
                p.Money=p.Money+10;
                clear();
                setPos(0, 0);
                for (int i =0;i<=20;i++){
                        puts(map[i]);
                    }
                cout<<"o represents your position"<<endl;
                cout<<"please press 's' to move downward"<<endl;
                cout<<"please press 'w' to move upward"<<endl;
                cout<<"please press 'a' to move leftward"<<endl;
                cout<<"please press 'd' to move rightward"<<endl;
                printPlayer(p);
                cout<<"Congratulations! You have found $10"<<endl;
                pause();
            }
            else if (map[x][y+1]=='%'){
                p = du.JunkShop(p);
            }
            else if (map[x][y+1]=='*'){
                end(p,Records);
                break;
            }
            else{
                map[x][y]=' ';
                y++;
                map[x][y]='o';
                clear();
                p = fight(p);
                if(p.HP < 0){
                    lose();
                }
            }
            clear();
            setPos(0, 0);
            for (int i =0;i<=20;i++){
                puts(map[i]);
            }
            cout<<"o represents your position"<<endl;
            cout<<"please press 's' to move downward"<<endl;
            cout<<"please press 'w' to move upward"<<endl;
            cout<<"please press 'a' to move leftward"<<endl;
            cout<<"please press 'd' to move rightward"<<endl;
            printPlayer(p);
        }
    }
    end(p,Records);
    return 0;
}

Player loadSaves(string line){
    Player p;
    int start = 8;
    int end = line.find(" HP: ");
    p.Name = line.substr(start, end-start);
    start = end + 5;
    end = line.find(" ATK: ");
    p.HP = atoi(line.substr(start, end-start).c_str());
    start = end + 6;
    end = line.find(" DEF: ");
    p.ATK = atoi(line.substr(start, end-start).c_str());
    start = end + 6;
    end = line.find(" Money: ");
    p.DEF = atoi(line.substr(start, end-start).c_str());
    start = end + 8;
    end = line.find(" PersonalBest: ");
    p.Money = atoi(line.substr(start, end-start).c_str());
    start = end + 8;
    end = line.find(" Career: ");
    p.PersonalBest = atoi(line.substr(start, end-start).c_str());
    p.Career = line.substr(end + 9, -1);
    return p;
}

int main(){
    map<string, Player> Records; //implement the STL map to store the information of the player

    ifstream fin; 
    fin.open("gamedoc.txt"); //create or open the gamedoc 
    if ( fin.fail() ) {
        cout << "Error in file opening!" << endl; exit(1);
    }
    string line;
    while(getline(fin, line)){
        Player player = loadSaves(line);
        Records[player.Name] = player;
    }
    Player p;
    welcomeMenu();
    p = mainMenu(Records);

    mainGame(p, Records);
}
