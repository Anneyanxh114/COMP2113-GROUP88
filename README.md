# COMP2113-GROUP88

## The Dungeon

### Group 88
### Group Members:
* Chen Ning - 3035951624
* Dong Fangyu - 3035845502
* Liu Peizhuo - 
* Ya Yixin - 3035844900
* Yan Xiaohan - 3035770604

### Game Description
Many monsters suddenly appeared near the peaceful village, breaking the good life of people. To let the villagers back to a good and happy life, as the village's strongest and bravest man, you decided to enter the lair of the monsters to destroy them. You may choose your role as `Warrior` or `Mage` to fight. Warrior has better defend power while mage has better attack power. Using `w` `s` `a` `d` to control the player on the map. If you successfully arrive the exit without being killed or maintaining $20 money, you win the game.

### Quick Start Guide
1. Choose the `START NEW GAME` to start a new game
2. choose your role & input your name
3. Use `w` `s` `a` `d` to control the player on the map
4. Try to reach the exit without being killed by the Monster
5. Choose the `SAVE` to see the saved players
6. Choose the `SUCCESSFUL PLAYER LIST` to check the successful players and their information

### Game Rules 
`o` is the player <br>
`#` is the Wall - hit the wall will make you lose <br>
`%` is the Junk Shop - you can choose to buy the weapons or defend tools or leave the shop <br>
`+` is the Supply Shop - you can choose to buy the supply food which adds value to your HP <br>
`M` is the Monster - you need to fight with it and kill it <br>
`*` is the Exit - if you reach it without being killed and you have no less than $20, you win the game <br>

### Game Features
- Allow users to choose from different identidies;
- Enable users to do purchase in various store to enhance attributes;
- Generate random mazes where users can move in using keyboard operations;
- Set random types of monsters in the maze which users may encounter when running through;
- Users can use different functions to combat monsters;
- Users can obtain money value after defeating the monsters;
- The game progress can be paused;
- The game progress is archived;
- According to the attribute data comparison, players can get the ranking at the end of the game.

### Coding Requirements
| Check | Requirements | Remarks |  
| --- | --- | --- |  
| ☑️ | Generation of random game sets or events  | - <cstdlib> to use rand() and srand() for random map <br>- <ctime> to generate seed for srand() <br>- <iomanip> to set width <br>- <string> for string manipulation <br>- Using switches, if-statements, and loops|  
| ☑️ | Data structures for storing game status  | ✅|  
| ☑️ | Dynamic memory management  | - using STL Map with a vector storing all the information of the player as value and player name as key|  
| ☑️ | File input/output (e.g., for loading/saving game status)  | ✅|  
| ☑️ | Program codes in multiple files  | ✅|  
| ☑️ | Proper indentation and naming styles  | ✅|  
| ☑️ | In-code documentation | ✅|  
| ☑️ | Tested on `academy11` server | ✅|  


### References
#### Non-standard C/C++ libraries
