#include<stdio.h>
#include<stdlib.h>
void menu();
int panduan();
int main()
{
    char game[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int open,i,j,ai1,ai2;
    int panduan=1;
    int suiji_man=1,suiji_ai=1;
    menu();
    scanf("%d",&open);
    if(open)
    {
        do{
            printf("\n %c | %c | %c\n",game[0][0],game[0][1],game[0][2]);
            printf("------------\n");
            printf(" %c | %c | %c\n",game[1][0],game[1][1],game[1][2]);
            printf("------------\n");
            printf(" %c | %c | %c\n",game[2][0],game[2][1],game[2][2]);
            printf("------------\n");
            printf("请输入要走的步数:");
            suiji_man=1;
            while(suiji_man)
            {
                scanf("%d%d",&i,&j);
                if(game[i-1][j-1]==' '&&game[i-1][j-1]!='#'&&game[i-1][j-1]!='&')suiji_man=0;
                else printf("请重新输入:");
            }
            
            game[i-1][j-1]='#';
            for(i=0;i<3;i++)
            {
                if(game[i][0]==game[i][1]&&game[i][1]==game[i][2]&&game[i][0]!=' ')panduan=0;
                if(game[0][i]==game[1][i]&&game[1][i]==game[2][i]&&game[0][i]!=' ')panduan=0;
                if(game[0][0]==game[1][1]&&game[1][1]==game[2][2]&&game[0][0]!=' ')panduan=0;
                if(game[2][0]==game[1][1]&&game[1][1]==game[2][0]&&game[2][0]!=' ')panduan=0;
            }
            if(panduan==0)break;
            suiji_ai=1;
            while(suiji_ai)
            {
                ai1=rand()%3;
                ai2=rand()%3;
                if(game[ai1][ai2]==' '&&game[ai1][ai2]!='#'&&game[ai1][ai2]!='&')suiji_ai=0;
            }
            
            game[ai1][ai2]='&';
            for(i=0;i<3;i++)
            {
                if(game[i][0]==game[i][1]&&game[i][1]==game[i][2]&&game[i][0]!=' ')panduan=0;
                if(game[0][i]==game[1][i]&&game[1][i]==game[2][i]&&game[0][i]!=' ')panduan=0;
                if(game[0][0]==game[1][1]&&game[1][1]==game[2][2]&&game[0][0]!=' ')panduan=0;
                if(game[2][0]==game[1][1]&&game[1][1]==game[0][2]&&game[2][0]!=' ')panduan=0;
            }
            
        }while(panduan);
            printf("\n %c | %c | %c\n",game[0][0],game[0][1],game[0][2]);
            printf("------------\n");
            printf(" %c | %c | %c\n",game[1][0],game[1][1],game[1][2]);
            printf("------------\n");
            printf(" %c | %c | %c\n",game[2][0],game[2][1],game[2][2]);
            printf("------------\n");
        printf("game over");
        
        
    }
    



}
void menu()
{
    int a;
    printf("开始游戏请输入:1\n");
    printf("结束游戏请输入:0\n");
}