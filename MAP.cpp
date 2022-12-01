#include <iostream>
#include <cstdio>
#include <chrono> 
#include <termios.h>
using namespace std;
using namespace chrono;

int HP=2000;
int Money=500;
 
int getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;
 
     if (tcgetattr(fd, &tm) < 0) {
          return -1;
     }
 
     tm_old = tm;
     cfmakeraw(&tm);
     if (tcsetattr(fd, TCSANOW, &tm) < 0) {
          return -1;
     }
 
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
          return -1;
     }
    
     return ch;
}

int main(){
    auto starting = system_clock::now(); // starting point of the game
    //create a map
    char map [21][21]=
    {
        "o ##################",
        "#    #### #### #####",
        "###     #######  ###",
        "#### ########## ####",
        "####  ########  %###",
        "#### #     #########",
        "####   ###     #####",
        "###  ##### ###   ###",
        "###$###### ##  # ###",
        "# #######    ### ###",
        "# ###  ## #  ### ###",
        "## ## ### # ####  ##",
        "####      #######  #",
        "# ##+###   ##   ####",
        "#### #### ##### ####",
        "###$   ## ##### ####",
        "#### ####         ##",
        "#### # ###  ##### ##",
        "#### #  ##+######  #",
        "################## *"
    };
    for (int i =0;i<=20;i++){
            puts (map[i]);
        }
    cout<<"o represents your position"<<endl;
    cout<<"please press 's' to move downward"<<endl;
    cout<<"please press 'w' to move upward"<<endl;
    cout<<"please press 'a' to move leftward"<<endl;
    cout<<"please press 'd' to move rightward"<<endl;
    int x=0, y=0;
    //move your position
    char d;
    while(HP>0){
        d=getch();
        //s:go down
        if(d=='s'){
            if(map[x+1][y]==' '){
                cout << "\033c";
                map[x][y]=' ';
                x++;
                map[x][y]='o';
                
            }
            else if(map[x+1][y]=='#'){
                cout << "\033c";
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                HP=HP-5;
            }
            else if(map[x+1][y]=='+'){
                cout << "\033c";
                void SupplyShop();
            }
            else if(map[x+1][y]=='$'){
                cout << "\033c";
                cout<<"Congratulations! You have found $10"<<endl;
                Money=Money+10;
            }
            else if (map[x+1][y]=='%'){
                cout << "\033c";
                void JunkShop();
            }
            else if (map[x+1][y]=='*'){
                cout << "\033c";
                void end();
                break;
            }
            else{
                cout << "\033c";
                //此处插入遇到怪兽的函数
            }
        }
        if(d=='w'){
            if(map[x-1][y]==' '){
                cout << "\033c";
                map[x][y]=' ';
                x--;
                map[x][y]='o';
                
            }
            else if(map[x-1][y]=='#'){
                cout << "\033c";
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                HP=HP-5;
            }
            else if(map[x-1][y]=='+'){
                cout << "\033c";
                void SupplyShop();
            }
            else if(map[x-1][y]=='$'){
                cout << "\033c";
                cout<<"Congratulations! You have found $10"<<endl;
                Money=Money+10;
            }
            else if (map[x-1][y]=='%'){
                cout << "\033c";
                void JunkShop();
            }
            else if (map[x-1][y]=='*'){
                cout << "\033c";
                void end();
                break;
            }
            else{
                cout << "\033c";
                //此处插入遇到怪兽的函数
            }
        }
        if(d=='a'){
            if(map[x][y-1]==' '){
                cout << "\033c";
                map[x][y]=' ';
                y--;
                map[x][y]='o';
                
            }
            else if(map[x][y-1]=='#'){
                cout << "\033c";
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                HP=HP-5;
            }
            else if(map[x][y-1]=='+'){
                cout << "\033c";
                void SupplyShop();
            }
            else if(map[x][y-1]=='$'){
                cout << "\033c";
                cout<<"Congratulations! You have found $10"<<endl;
                Money=Money+10;
            }
            else if (map[x][y-1]=='%'){
                cout << "\033c";
                void JunkShop();
            }
            else if (map[x][y-1]=='*'){
                cout << "\033c";
                void end();
                break;
            }
            else{
                //此处插入遇到怪兽的函数
            }
        }
        if(d=='d'){
            if(map[x][y+1]==' '){
                cout << "\033c";
                map[x][y]=' ';
                y++;
                map[x][y]='o';
            }
            else if(map[x][y+1]=='#'){
                cout << "\033c";
                cout<<"You have hit the wall"<<endl;
                cout<<"Please choose another way"<<endl;
                cout<<"HP: -5"<<endl;
                HP=HP-5;
            }
            else if(map[x][y+1]=='+'){
                cout << "\033c";
                void SupplyShop();
            }
            else if(map[x][y+1]=='$'){
                cout << "\033c";
                cout<<"Congratulations! You have found $10"<<endl;
                Money=Money+10;
            }
            else if (map[x][y+1]=='%'){
                cout << "\033c";
                void JunkShop();
            }
            else if (map[x][y+1]=='*'){
                cout << "\033c";
                void end();
                break;
            }
            else{
                cout << "\033c";
                //此处插入遇到怪兽的函数
            }
        }
        for (int i =0;i<=20;i++){
            puts (map[i]);
        }
        
    }
    
    void end();
    return 0;
}

void end(){
    if(HP>0&&Money>=20){
        void win();
    }
    else{
        void lose();
    }
}
void win(){
    //auto ending   = system_clock::now(); // ending point of the game
    //auto duration = duration_cast<microseconds>(ending - starting); // total duration of the game
    //double gameTime = double(duration.count()) * microseconds::period::num / microseconds::period::den;  //游戏通关用时


    //if (gameTime < map[Name].PersonalBest)
        //map[Name] = {Money, gameTime};
    //else    
        //map[Name] = {Money, PersonalBest};

    cout<<"Congratulations! You have successfully escaped!"<<endl;
    cout<<"Your final score is"<< HP*2+Money<<endl;
    //cout<<"You are ranked #"<<rank<<"out of all players"<<endl;
    //rank 为玩家的排名
}
void lose(){
    cout<<"    L         OOOOOO     SSSSS      EEEEE" <<endl;     
    cout<<"    L         O    O     S          E    " <<endl;
    cout<<"    L         O    O     SSSSS      EEEEE" <<endl;
    cout<<"    L         O    O         S      E    " <<endl;
    cout<<"    LLLLLL    OOOOOO     SSSSS      EEEEE" <<endl;
}