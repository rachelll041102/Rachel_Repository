#include<iostream>
#include"game_workspace.h"
using namespace std;

//游戏棋盘
char game[3][3];

int main()
{
    int who_win=0;  //用来判断谁赢了
    int global=prepare();   //游戏菜单，看是否开始游戏
    before_begin(game);     //初始化棋盘
    while(global)//游戏菜单输入1，游戏开始
    {
        system("cls");      //先清屏

        print(game);   //再打印            
        player(game);//玩家先走

        AI_play(game,&who_win);//人机走
        global=judge(game,&who_win);//判断游戏是否结束
        if(global==0)       //游戏结束
        {
            //游戏结束之后，需要先把屏幕内容清掉，然后把棋盘打印出来，不然不知道怎么结束的
            system("cls");
            print(game);//打印棋盘
        }
        

        //以下是对谁赢了进行判定
        //（可以塞一个函数来着，我懒得塞了）
        if(who_win==10)
        {
            cout<<"YOU WIN";
            system("pause");
        }
        else if(who_win==20)
        {
            cout<<"YOU LOSE";
            system("pause");
        }
        else if(who_win==30)
        {
            cout<<" No One Win!";
            system("pause");
        }

        //前面的游戏开始，while是按global来管理的
        //这里看是否需要继续玩这个游戏
        if(global==0)
        {
            who_win=0;      //这里对 谁赢了 重新初始化
            system("cls");
            global=prepare();   //重新调用菜单
            if(global==1)before_begin(game);    //如果继续玩，重新初始化
        }
    }
    system("pause");
    if(global==0)//游戏菜单输入0，游戏结束
    {
        system("cls");
        cout<<"Thank you for playing it!";
        system("pause");
    }
}