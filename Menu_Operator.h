#ifndef MENU_OPERATOR_H
#define MENU_OPERATOR_H

void setColor(int n);
void setPos(int x, int y);
void resetColor();
void moveUp();
void moveDown();
void moveleft();
void moveright();
int scanKeyboard();
void clear();
bool kbhit();
void hideCursor();
void showCursor();

#endif