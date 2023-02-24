#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//初始游戏菜单
int prepare()
{
    cout<<"game start :1"<<endl;
    cout<<"game close :0"<<endl;
    int menu;
    cin>>menu;
    while(1)
    {
        if(menu==1||menu==0)
            return menu;
        else cout<<"What you type is wrong ,please type again!";
    }
}


//游戏棋盘初始化
void before_begin(char game[][3])
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            game[i][j]=' ';
    
    for(int i=0;i<3;i++)
    {
        cout<<' '<<game[i][0]<<'|'<<game[i][1]<<'|'<<game[i][2]<<endl<<
            "-------"<<endl;
    }



}

//玩家先走
void player(char game[][3])
{
    int first,second;
    cout<<"Where do you want to go?"<<endl;

    while(1)
    {
        cin>>first>>second;

        if(game[first-1][second-1]==' ')
        {
            game[first-1][second-1]='#';
            break;
        }
        else cout<<"Please type again!";
    }
    
}

//轮到人机走
void AI_play(char game [][3],int* who_win)
{
    srand((unsigned int) time (NULL));

    int AI_first ,AI_second;//创建人机的步数
    while(1)
    {
        //先检查棋盘是否满了
        int count=0;
        for(int i=0;i<3;i++)                //从第一个格子开始遍历，给count++。
            for(int j=0;j<3;j++)            
            {
                if(game[i][j]!=' ')count++;
            }
        if(count==9)                        //如果count加到了9，说明全是满的
        {
            *who_win=30;
            break;
        }
        //如果没满，人机开始下棋
        else
        {
            AI_first=rand()%3;
            AI_second=rand()%3;

            if(game[AI_first][AI_second]==' ')
            {
                game[AI_first][AI_second]='&';
                break;
            }
        }
        
    }
}


void print(char game[][3])
{
    for(int i=0;i<3;i++)
    {
        cout<<' '<<game[i][0]<<'|'<<game[i][1]<<'|'<<game[i][2]<<endl<<
            "-------"<<endl;
    }
}

int judge(char game[][3],int* who_win)
{
    //判断行是否相同
    for(int i=0;i<3;i++)
        if(game[i][0]==game[i][1]&&game[i][1]==game[i][2]&&game[i][2]!=' ')
        {
            if(game[i][0]=='#')*who_win=10;
            else *who_win=20;
            return 0;
        }
            

    //判断列是否相同
    for(int i=0;i<3;i++)
        if(game[0][i]==game[1][i]&&game[1][i]==game[2][i]&&game[1][i]!=' ')
        {
            if(game[0][i]=='#')*who_win=10;
            else *who_win=20;
            return 0;
        }

    //判断斜角是否相同
    if(game[0][0]==game[1][1]&&game[1][1]==game[2][2]&&game[2][2]!=' ')
        {
            if(game[0][0]=='#')*who_win=10;
            else *who_win=20;
            return 0;
        }
    else if(game[0][2]==game[1][1]&&game[1][1]==game[2][0]&&game[2][0]!=' ')
        {
            if(game[2][0]=='#')*who_win=10;
            else *who_win=20;
            return 0;
        }

    //死局
    int count=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(game[i][j]!=' ')count++;
        }
    if(count==9)
    {
        *who_win=30;
        return 0;
    }
    return 1;
}