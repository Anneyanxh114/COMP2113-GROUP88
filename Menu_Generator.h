#ifndef MENU_GENERATOR_H
#define MENU_GENERATOR_H
#include "Player_and_Shop.h"
#include <string.h>
using namespace std;

void welcomeMenu();
Player mainMenu(map<string, Player> &Records);
Player savesMenu(map<string, Player> &Records);

#endif