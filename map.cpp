#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

int MONEY_PR = 10;
int MONSTER_PR = 10;
int SUPPLY_PR = 2;
int JUNK_PR = 4;



struct element{
    int x;
    int y;
    bool wall; //false代表路true代表墙
    bool visited = false;
};


char** generateMap(){

    element ** map = new element*[21]; 
    for(int i = 0; i < 21; i ++){
        map[i] = new element[21];
        for(int j = 0; j < 21; j ++){
            map[i][j].x = i;
            map[i][j].y = j;
            if((i % 2 == 1) && (j % 2 == 1)){
                map[i][j].wall = false;
            }else{
                map[i][j].wall = true;
            }
        }
    }

    srand(time(0));
    list<element*> A;
    map[1][1].visited = true;
    A.push_back(&map[1][2]);
    A.push_back(&map[2][1]);
    int size = A.size();
    // cout << "Test 1" << endl;
    while(size > 0){
        element* new_e = NULL;
        int index = rand() % size;
        element* current;
        list<element*>::const_iterator itr = A.begin();
        // cout << "Test 2: ";
        // cout << index << " " << size <<endl;
        advance(itr, index);
        current = *itr; 
        // cout << current -> x << " " << current -> y << endl;
        A.remove(*itr);
        if(current -> x % 2 == 0 && current -> y % 2 != 0){
            // cout << "if 1" << endl;
            // cout << map[current -> x - 1][current -> y].visited << endl;
            // cout << map[current -> x + 1][current -> y].visited << endl;
            if(!map[current -> x - 1][current -> y].visited || !map[current -> x + 1][current -> y].visited){
                // cout << "if 2" << endl;
                current -> wall = false;
                if(current -> x - 1 > 0 && !map[current -> x - 1][current -> y].visited){
                    map[current -> x - 1][current -> y].visited = true;
                    new_e = &map[current -> x - 1][current -> y];
                }
                if(current -> x + 1 < 20 && !map[current -> x + 1][current -> y].visited){
                    map[current -> x + 1][current -> y].visited = true;
                    new_e = &map[current -> x + 1][current -> y];
                }

            }
            
        }
        if(current -> x % 2 != 0 && current -> y % 2 == 0){
            // cout << "if 1" << endl;
            // cout << map[current -> x][current -> y - 1].visited << endl;
            // cout << map[current -> x][current -> y + 1].visited << endl;
            if(!map[current -> x][current -> y - 1].visited || !map[current -> x][current -> y + 1].visited){
                // cout << "if 2" << endl;
                current -> wall = false;
                if(current -> y - 1 > 0 && !map[current -> x][current -> y - 1].visited){
                    map[current -> x][current -> y - 1].visited = true;
                    new_e = &map[current -> x][current -> y - 1];
                }
                if(current -> y + 1 < 20 && !map[current -> x][current -> y + 1].visited){
                    map[current -> x][current -> y + 1].visited = true;
                    new_e = &map[current -> x][current -> y + 1];
                }

            }
        }
        // cout << "Test 3" << endl;
        if(new_e != NULL){
            // cout << "Test 3" << new_e -> x << " " << new_e -> y << endl;
            if(new_e -> x + 1 < 20 && map[new_e -> x + 1][new_e -> y].wall)
                A.push_back(&map[new_e -> x + 1][new_e -> y]);
            if(new_e -> y + 1 < 20 && map[new_e -> x][new_e -> y + 1].wall)
                A.push_back(&map[new_e -> x][new_e -> y + 1]);
            if(new_e -> x - 1 > 0 && map[new_e -> x - 1][new_e -> y].wall)
                A.push_back(&map[new_e -> x - 1][new_e -> y]);
            if(new_e -> y - 1 > 0 && map[new_e -> x][new_e -> y - 1].wall)
                A.push_back(&map[new_e -> x][new_e -> y - 1]);
        }
        size = A.size();
            

    }
    char ** m = new char*[21]; 
    int pr;
    for(int i = 0; i < 21; i ++){
        m[i] = new char[22];
        m[i][21] = '\0';
        for(int j = 0; j < 21; j ++){
            if(map[i][j].wall){
                if((i % 2 + j % 2) % 2 == 1){
                    pr = rand() % 100;
                    if(pr < SUPPLY_PR){
                        m[i][j] = '+';
                        continue;
                    }
                    pr = rand() % 100;
                    if(pr < JUNK_PR){
                        m[i][j] = '%';
                        continue;
                    }
                
                }
                m[i][j] = '#';
            }else{
                pr = rand() % 100;
                if(pr < MONSTER_PR){
                    m[i][j] = 'M';
                    continue;
                }
                pr = rand() % 100;
                if(pr < MONEY_PR){
                    m[i][j] = '$';
                    continue;
                }
                m[i][j] = ' ';
            }

        }
    }

    m[1][1] = 'o';
    m[19][19] = '*';


    for(int i=0; i<21; i++){
        delete[] map[i];
    } 
        
    return m;   
}

void printMap(char **map){
    for (int i =0;i<=20;i++){
            puts(map[i]);
    }
}

// int main(){
//     printMap(generateMap());
// }