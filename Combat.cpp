#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Player_and_Shop.h"
#include "Menu_Operator.h"
using namespace std;

struct Monster{
  string Name;
  int ATK;
  int DEF;
  int HP;
  int Value;
};


string MonsterName[7]={"Warg","Cave Troll","Fellbeasts","Giant Spider","Balrog","Smaug","Mumakil"};
int MonsterAttack[7]={100,120,150,130,500,1000,70};
int MonsterDefence[7]={30,20,40,20,30,40,20};
int MonsterHP[7]={200,400,350,400,450,370,320};
int MonsterValue[7]={4,5,6,7,7,8,4};


int RandomMonster()//在0-6随机取数以确定怪物
{
 for (int i = 0; i < 10; ++i)
 srand(time(NULL));
 return rand() % 7;
}

int MoneyTri(int rows)
{
    int space;
    for(int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for(space = 1; space <= rows-i; ++space)
        {
            cout <<"  ";
        }

        while(k != 2*i-1)
        {
            cout << "$ ";
            ++k;
        }
        cout << endl;
    }
    return 0;
}

int printMonster(int i){
  if(i==0){
      cout<<"              /\\"<<endl;
      cout<<"             /  \\   /\\"<<endl;
      cout<<"            / /\\\\_/  \\_"<<endl;
      cout<<"          ##      /     \\_        ___________________}"<<endl;
      cout<<"         ##              \\_      -------------------"<<endl;
      cout<<"      ###   <##         |#"<<endl;
      cout<<"  <{###_____              ###                       ___________________}"<<endl;
      cout<<"      ^^^^^</         #####  #####                       -------------------"<<endl;
      cout<<"        ~ / ########      ###"<<endl;
      cout<<"       <#########        ###########                  ___________________}"<<endl;
      cout<<"          #########              ########        -------------------"<<endl;
      cout<<"             ######^#^#^#             ###########"<<endl;
      cout<<"              #^#^#^#^#####                    ##############     "<<endl;
      cout<<"             ##############                 ###################"<<endl;
      cout<<"           #############                           ##########"<<endl;
      return 15;
    }

    if (i==1){
      cout<<"               ¸....·········.....¸ "<<endl;
      cout<<"            .·´¨        ¸.·´¨     ` ·."<<endl;
      cout<<"        ¸·´ ¨        ¸¨                `·. "<<endl;
      cout<<"      .·¸____      ¸¨           _____   ¨`·¸ "<<endl;
      cout<<"     ( ¨¸·......¸˜¨¨·¸      ¸ .·´¨¸,.···..¨ '¸ "<<endl;
      cout<<"      ·¸        ` · ..¨·¨   ¸·´          )  "<<endl;
      cout<<"      ¸`·..,¸¸¸..·¨¸.·.¸   ¨·._____..··´   .´ "<<endl;
      cout<<"         /¨     `¸  .¨¸¸·¸¸¨. ¨·.,,¸¸,.·´ ¨ "<<endl;
      cout<<"         .¸     ¸¨              ___¸..·¨ "<<endl;
      cout<<"           ¨¨¯¸¨   ¸/          ¸¨·¸ "<<endl;
      cout<<"              ¸¨_¸,.¸_¸.¸_,.,_¸.·¨/ "<<endl;
      cout<<"              /¸/¸´/¸/´/¸'/¸''// "<<endl;
      cout<<"               ¨_ ¨ _ ¨_ ¨ _¨ _ ¨ "<<endl;
      cout<<"               |||||||||||||||"<<endl;
      return 14;
    }

    if(i==2){
      cout<<"                 '/¯¯\\                           /¯¯\\ "<<endl;
      cout<<"               / /:::\\ \\                       / /:::\\ \\ "<<endl;
      cout<<"             / /:::::::\\ \\      )\\  )\\       / /:::::::\\ \\ "<<endl;
      cout<<"           / /::::::::::\\ \\   / /-/ /     / /:::::::::::\\ \\ "<<endl;
      cout<<"         / /:::::::::::::\\ \\|(,\\/, )\\  /  /::::::::::::::\\ \\ "<<endl;
      cout<<"       / /:::::::::::::::::/ / /#/ ,) |/   \\::::::::::::::::\\ \\ "<<endl;
      cout<<"     / /:::::::::::::::::/  ( *¯* )|  ; /\\  \\::::::::::::::::\\ \\"<<endl;
      cout<<"   / /:::::::::::::::::/, /¯\\|¯¯|/ ,'¯\\   \\  \\::::::::::::::::\\ \\ "<<endl;
      cout<<"  |  |:::::::::::::::/'/'/'/'\\/| /:::/'/'/'/'\\|   |  |::::::::::::::::|  | "<<endl;
      cout<<"  \\  \\:::::::::::::'v'v'v'v'  |::::'v'v'v'v'  /  /::::::::::::::::/  / "<<endl;
      cout<<"    \\  \\::::::::::::::::\\ |\\ \\::::/    / /  /::::::::::::::::/  / "<<endl;
      cout<<"      \\ \\:::::::::::::::/¯¯  /¯¯  \\||   |:::::::::::::::/  / "<<endl;
      cout<<"        \\ \\:::::::::::/     /'/      /,  \\ \\:::::::::::::/  / "<<endl;
      cout<<"          \\ \\:::::::::\\     \\      \\  \\ \\:::::::::/  / "<<endl;
      cout<<"            \\ \\:::::/'/'/'/'/|/'/'/'/'/|::|   |\\ '::::::/  / "<<endl;
      cout<<"              \\ \\::'v'v'v'v' 'v'v'v'v' /::/  /   '\\:::/  / "<<endl;
      cout<<"                \\ \\   /           |::|   |      |\\  \\   / "<<endl;
      cout<<"                   '\\/             \\::\\  \\__/  |  \\/ "<<endl;
      cout<<"                                   \\;;\\____ /$#&"<<endl;
      return 19;

    }

    if (i==3)
      {
      cout<<"          /---.'.__             ____//"<<endl;
      cout<<"               '--\\           /.---'"<<endl;
      cout<<"          _______  \\         //"<<endl;
      cout<<"        /.------.\\ \\      .'/  ______"<<endl;
      cout<<"       //  ___  \\ \\ ||/|\\  //  _/_----.\\__"<<endl;
      cout<<"      |/  /.-\\  \\ \\:|< >|// _/.'..\\   '--'"<<endl;
      cout<<"         //   \\'.\\ \\'.|.'/ /_/ /  \\ "<<endl;
      cout<<"        //     \\  \\/---\\    \\ \\  "<<endl;
      cout<<"       //       '-._| :H: |'-.__   \\ "<<endl;
      cout<<"      //           (/'==='\\)'-._\\ \\   ||"<<endl;
      cout<<"      ||                        \\    \\|"<<endl;
      cout<<"      ||                         \\    '"<<endl;
      cout<<"      |/                          \\"<<endl;
      cout<<"                                   ||"<<endl;
      cout<<"                                   ||"<<endl;
      cout<<"                                   \\"<<endl;
      cout<<"                                    '"<<endl;
      return 17;
    }

    if (i==4)
    {
      cout<<"   <>=======() "<<endl;
      cout<<"  (/\\___   /|\\          ()==========<>_"<<endl;
      cout<<"        \\_/ | \\        //|\\   ______/ \\)"<<endl;
      cout<<"         \\_|  \\      // | \\_/"<<endl;
      cout<<"            \\|\\/|\\_   //  /\\/"<<endl;
      cout<<"             (oo)\\_//  /"<<endl;
      cout<<"            //_/\\_\\/ /  |"<<endl;
      cout<<"                \\_=\\_ \\ |"<<endl;
      cout<<"                  \\==\\ \\|\\_ "<<endl;
      cout<<"               __(\\===\\(  )\\"<<endl;
      cout<<"              (((~) __(_/   |"<<endl;
      cout<<"                   (((~) \\  /"<<endl;
      cout<<"                   ______/ /"<<endl;
      cout<<"                   '------'"<<endl;
      return 14;
    }

    if (i==5)
    {
      cout<<"                           _,,,.._       ,_"<<endl;
      cout<<"                        .gMMMMMMMMMp,_    \\"<<endl;
      cout<<"                     .dMMP'       ``^YMb..dP"<<endl;
      cout<<"                    dMMP'"<<endl;
      cout<<"                    MMM:"<<endl;
      cout<<"                    YMMb."<<endl;
      cout<<"                     YMMMb."<<endl;
      cout<<"                      `YMM/|Mb.  ,__"<<endl;
      cout<<"                     _,-~`--..-~-'_,/`--,,,____"<<endl;
      cout<<"               `##,_,/',_.-~_..-~/' ,/---~~~"""""<<endl;
      cout<<"          _,_,,,\\@)/'    \\,,-~'_,/`````-,7."<<endl;
      cout<<"         @v@\\,,,,__   \\,,-~~|_))))#####MMMMb"<<endl;
      cout<<"          `--''_..-~~\\   \\,-~~""  `\\_,/####YMMMMMb.."<<endl;
      cout<<"           ,|``-~~--./_,,_  _,,-~~'/_      `YMMMMMMMb."<<endl;
      cout<<"         ,/  `\\,_,,/`\\    `\\,___,,,/M/'      `YMMMMMMMb"<<endl;
      cout<<"                       .' /'      dMMM\\         !MMMMMMMMb"<<endl;
      cout<<"                   ,-'.-'""~~~--/M|M' \\        !MMMMMMMMM"<<endl;
      cout<<"                 ,/ .|...._____/MMM\\   b       gMMMMMMMMM"<<endl;
      cout<<"              ,'/'\\/          dMMP/'   M.     ,MMMMMMMMMP"<<endl;
      cout<<"             / `\\;/~~~~----...MP'     ,MMb..,dMMMMMMMMM'"<<endl;
      cout<<"            / ,_  |          _/      dMMMMMMMMMMMMMMMMB"<<endl;
      cout<<"            \\  |\\,\\,,,,___ _/    _,dMMMMMMMMMMMP"<<endl;
      cout<<"             \\  gY.     /      7MMMMMMMMMMP"<<endl;
      cout<<"                .dMMMb,-**|       `.~~""""|dMMMMPMMP "<<endl;
      cout<<"               .MMMMP^^^^\\\\      ################## "<<endl;
      cout<<"             _dMMMP'   ,' / | || || ||  }          PM^M^b"<<endl;
      cout<<"          _,' _,  \\_.._`./  } ; \\ \\``'      __,'_` _  `._"<<endl;
      cout<<"      ,-~/'./'| 7`,,__,}`   ``   ``        // _/`| 7``-._`}"<<endl;
      cout<<"     |_,}__{  {,/'   ``                    `\\{_  {,/'   ``"<<endl;
      cout<<"     ``  ```   ``                            ``   `"<<endl;
      return 30;
    }

    if(i==6)
      {
      cout<<"                              _"<<endl;
      cout<<"                            .' `'.__"<<endl;
      cout<<"                           /     \\ `''-  "<<endl;
      cout<<"          .-''###_###_###-/ .     |      \\"<<endl;
      cout<<"        .'      #######   ; :'     '.  a   |"<<endl;
      cout<<"       /                 | :.      \\     =\\"<<endl;
      cout<<"      ;                   \':.      /  ,-.__;.-;`"<<endl;
      cout<<"     /|     .              '--._   /-.7`._@@ |`"<<endl;
      cout<<"    ; |       '                |`-'     \\  =|"<<endl;
      cout<<"    |/\\        .   -' /     /  ;         |  =/"<<endl;
      cout<<"    (( ;.       ,_  .:|     | /     /\\   | =|"<<endl;
      cout<<"     ) /`\\     | `""`;     / |    | /   / =/"<<endl;
      cout<<"      /  '/|    /       )    |/     `-...-`"<<endl;
      cout<<"     /    | |  `|    /-'    /;"<<endl;
      cout<<"     `""`  \\  nnh  D_.-'L__nnh"<<endl;
      cout<<"            ~~~~}"<<endl;
      return 16;
      }
      return 0;
}

void printPlayerInFight(Player p){
    setPos(75,1);
    cout << "Player:";
    setPos(75,2);
    if(p.Name.length() >= 2){
        cout << "\033[0K";
        cout<<"Name: " << p.Name << "\tHP: " << p.HP;
    }else{
        cout << "\033[0K";
        cout<<"Name: " << p.Name << "\t\tHP: " << p.HP;
    }
    // cout<<"Name: " << p.Name << "\tHP: " << p.HP;
    setPos(75,3);
    cout << "\033[0K";
    cout << "ATK: " << p.ATK << "\t\tDEF: " << p.DEF;
    setPos(75,4);
    cout << "\033[0K";
    cout << "Money: " << p.Money << endl;
}

void printMonsterAttr(Monster m){
    setPos(75,6);
    cout << "Monster:";
    setPos(75,7);
    if(m.Name.length() >= 2){
        cout << "\033[0K";
        cout<<"Name: " << m.Name << "\tHP: " << m.HP;
    }else{
        cout << "\033[0K";
        cout<<"Name: " << m.Name << "\t\tHP: " << m.HP;
    }
    // cout<<"Name: " << p.Name << "\tHP: " << p.HP;
    setPos(75,8);
    cout << "\033[0K";
    cout << "ATK: " << m.ATK << "\t\tDEF: " << m.DEF;
}


Player fight(Player p){
  Monster monster;
  int i;
  i = RandomMonster();
  monster.Name=MonsterName[i];
  monster.HP=MonsterHP[i]; //定义怪物生命
  monster.ATK=MonsterAttack[i]; //定义怪物攻击力
  monster.DEF=MonsterDefence[i]; //定义怪物防御力
  monster.Value=MonsterValue[i];//定义怪物金钱
  cout<<"You encounter "<<monster.Name<<"! ! !"<<endl;

  int startPos = printMonster(i) + 3;
  // cout<<"The battle begins!!!"<<endl;
  printPlayerInFight(p);
  printMonsterAttr(monster);

  double* Damage = new double;//用来计算主角对怪物的杀伤
  double* Hurt = new double;//用来计算怪物对主角的杀伤
  *Damage=0;
  *Hurt=0;
  int* round = new int;//定义回合数
  *round=1;


  int* choice=new int;
  while((monster.HP)>0 && p.HP>0 && (*choice)!=3){
    printPlayerInFight(p);
    printMonsterAttr(monster);
    setPos(0, startPos);
    cout << "\033[0J";
    cout<<"This is the "<<*round<<" round！"<<endl;
    cout<<"What are you going to do now ?!\n";
    cout<<"1.Attack!  2.Use Magic Power   3.Escape" << endl;//33
    cin>>*choice;
    switch((*choice))
    {
      case 1 :
        cout<<"You are making an attack！"<<endl;
        monster.HP-=(p.ATK*2-monster.DEF);
        *Damage = p.ATK*2-monster.DEF;
        cout<<"You caused "<<*Damage<<" point loss of "<<monster.Name<<endl;
        cout<<monster.Name<<"still have "<<(monster.HP)-(*Damage)<<" point of life."<<endl;

        *Hurt=(monster.ATK)*2-p.DEF > 10 ? (monster.ATK)*2-p.DEF : 10;
        p.HP-=*Hurt;
        printMonsterAttr(monster);
        setPos(0, startPos + 6);
        cout<<monster.Name<<" is attacking you!"<<endl;
        cout<<monster.Name<<" caused "<<*Hurt<<" loss of your life point！"<<endl;
        cout<<"Now you have "<<p.HP<<"point of life"<<endl;//39
        printPlayerInFight(p);
        setPos(0, startPos + 9);
        break;


      case 2 :
        cout<<"You enabled you magic power! Tell the ability you want to show:"<<endl;
        cout<<"   (\\{\\           "<<endl;
        cout<<"   { { \\ ,~,     "<<endl;
        cout<<"  { {   \\)))  *  "<<endl;
        cout<<"   { {  (((  /    "<<endl;
        cout<<"    {/{/; ,\\/    "<<endl;
        cout<<"       (( '       "<<endl;
        cout<<"        \\`       "<<endl;
        cout<<"        (/        "<<endl;
        cout<<"Expelliarmus: Weaken the attack power of the monster!\n"<<endl;
        cout<<"Sectumsempra: Increase your own attack power!\n"<<endl;
        cout<<"Petrificus Totalus: Weaken the defence power of the monster!\n"<<endl;
        cout<<"Expecto Patronum: Increase your own defence power!\n"<<endl;
        int y;
        cout<<"1.Expelliarmus  2.Sectumsempra  3.Petrificus Totalus  4.Expecto Patronum"<<endl;
        cin>>y;
        if (y==1)
        {
          if (p.HP>=100)
            {
              monster.ATK-=50;
              cout<<"You weakened the Attack power of your rival by 50 points!"<<endl;
            }
          else
            cout<<"You don't have enough power to do Expelliarmus right now."<<endl;//除你武器
        }

        else if (y==2)
        {
          if (p.HP>=50)
          {
            p.ATK+=50;
            cout<<"You enpowered your ATK power by 50 points!"<<endl;
          }
          else
            cout<<"You don't have enough power to do Sectumsempra right now."<<endl;//神锋无影
        }

        else if (y==3)
        {
          if (p.HP>=100)
          {
            monster.DEF-=50;
            cout<<"You weakened the Defence power of your rival by 50 points!"<<endl;
          }
          else
            cout<<"You don't have enough power to do Petrificus Totalus right now."<<endl;//统统石化
        }

        else if (y==4)
        {
          if (p.HP>=50)
          {
            p.DEF+=50;
            cout<<"You enpowered your DEF power by 50 points!"<<endl;
          }
          else
            cout<<"You don't have enough power to do Expecto Patronum right now."<<endl;//呼神护卫
        }
        printPlayerInFight(p);
        printMonsterAttr(monster);
        setPos(0, startPos + 7);
        *Hurt=(monster.ATK)*2-p.DEF > 10 ? (monster.ATK)*2-p.DEF : 10;
        p.HP-=*Hurt;
        cout<<monster.Name<<" is attacking you!"<<endl;
        cout<<monster.Name<<" caused "<<*Hurt<<" loss of your life point！"<<endl;
        cout<<"Now you have "<<p.HP-(*Hurt)<<" point of life"<<endl;
        printPlayerInFight(p);
        setPos(0, startPos + 10);
        break;

      case 3 :
        cout<<"You loser decided to escape!"<<endl;
        cout<<"Great escape! You survived anyway."<<endl;
        break;

      default :
        cout<<"What are you doing!? Don't do stupid choice!"<<endl;
        continue;
    }

    (*round)++;
    if((monster.HP)<=0 || p.HP<=0 || *choice == 3) break;
    scanKeyboard();
    while(1){
      // cout << kbhit() << endl;
      if(kbhit()){
        break;
      }
    }
  }
  if((monster.HP)<=0){//杀死怪物后的返回
      cout<<"You killed the "<<monster.Name<<" !!!!!!!"<<endl;
      cout<<"The death of monster "<<monster.Name<<" generates "<<monster.Value*monster.Value<<" more money for you!"<<endl;
      cout<<"PRESS ANY KEY, TO CONTINUE";
      MoneyTri(monster.Value);
      p.Money+=(monster.Value);
      // break;
    }
    else if(p.HP<=0){//被怪物杀死后的返回
      cout << "You are killed by "<<monster.Name<<". Sorry you cannot continue your journey anymore"<<endl;
      cout<<"PRESS ANY KEY, TO CONTINUE";
      // break;
    // 结束游戏
    }
    else if((*choice)==3){//逃跑的返回
      cout << "You loss 20 PH and Successfully Escape!!!" << endl;
      cout<<"PRESS ANY KEY, TO CONTINUE";
      p.HP -= 20;
      // break;
    }
  printPlayerInFight(p);
  scanKeyboard();
  while(1){
        if(kbhit()){
            scanKeyboard();
            break;
        }
    }
  return p;

}
