#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
    char a[3][3]={{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};

    int board[3][3] = { {2, 2, 2},
                        {2, 2, 2},
                        {2, 2, 2}
                        };
    int player=0, choice, i, isEvil=0, isEvilMarked=0, withplayer=0, flag=0, reset=0;
    char mark;
int startgame()
{
    int y;
    printf("Enter Your choice\n");
    printf("1. Want to play with smart computer\n");
    printf("2. Want to play with Evil computer\n");
    printf("3. Want to play with player\n");
    printf("4. Exit\n");
    scanf("%d", &y);
    return y;
}
void display()
{
    int row;
    system("cls");
    printf("#################### TIC TAC TOE ####################\n\n");
    printf("First player X\n");
    printf("Second player O\n\n\n");
    printf("_____ _____ _____\n");
    for(row=0;row<3;row++)
    {
        printf("     |     |     |\n");
        printf("  %c  |  %c  |  %c  |\n", a[row][0], a[row][1], a[row][2]);
        printf("_____|_____|_____|\n");
    }

}
void computermove()
{
    int row, col, multi=1, maxmulti=1, maxrow, maxcol;
    //winning condition for computer
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(board[row][col]==2)
            {
                board[row][col]=3;
                multi=board[row][0]*board[row][1]*board[row][2];
                if(multi==27)
                {
                    a[row][col]='X';
                    return ;
                }
                else if(multi>maxmulti)
                {
                    maxmulti=multi;
                    maxrow=row;
                    maxcol=col;
                }

                multi=board[0][col]*board[1][col]*board[2][col];
                if(multi==27)
                {
                    a[row][col]='X';
                    return ;
                }
                else if(multi>maxmulti)
                {
                    maxmulti=multi;
                    maxrow=row;
                    maxcol=col;
                }

                if(row==col)
                {
                    multi=board[0][0]*board[1][1]*board[2][2];
                    if(multi==27)
                    {
                        a[row][col]='X';
                        return;
                    }
                    else if(multi>maxmulti)
                    {
                        maxmulti=multi;
                        maxrow=row;
                        maxcol=col;
                    }
                }

                if((row==0 && col==2) || (row==1 && col==1) || (row==2 && col==0))
                {
                    multi=board[0][2]*board[1][1]*board[2][0];
                    if(multi==27)
                    {
                        a[row][col]='X';
                        return;
                    }
                    else if(multi>maxmulti)
                    {
                        maxmulti=multi;
                        maxrow=row;
                        maxcol=col;
                    }
                }
                board[row][col]=2;
            }
        }
    }
    //for checking player win
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(board[row][col]==2)
            {
                board[row][col]=3;
                multi=board[row][0]*board[row][1]*board[row][2];
                if(multi==3)
                {
                    reset=1;
                    a[row][col]='X';
                    if(isEvil==0)
                        return;
                    else
                        isEvilMarked=1;
                }

                multi=board[0][col]*board[1][col]*board[2][col];
                if(multi==3)
                {
                    reset=1;
                    a[row][col]='X';
                    if(isEvil==0)
                        return;
                    else
                        isEvilMarked=1;
                }

                if(row==col)
                {
                    multi=board[0][0]*board[1][1]*board[2][2];
                    if(multi==3)
                    {
                        reset=1;
                        a[row][col]='X';
                        if(isEvil==0)
                            return;
                        else
                            isEvilMarked=1;
                    }
                }

                if((row==0 && col==2) || (row==1 && col==1) || (row==2 && col==0))
                {
                    multi=board[0][2]*board[1][1]*board[2][0];
                    if(multi==3)
                    {
                        reset=1;
                        a[row][col]='X';
                        if(isEvil==0)
                            return;
                        else
                            isEvilMarked=1;
                    }
                }
                if(isEvilMarked==0)
                    board[row][col]=2;

                isEvilMarked=0;
            }
        }
    }
    if(reset==0)
    {
        board[maxrow][maxcol]=3;
        a[maxrow][maxcol]='X';
    }
    else
        reset=0;
}
void selectplayer()
{
    player = !player;
}
int checkplace(int row, int col)
{
    if(a[row][col] != 'X' && a[row][col] != 'O')
        return 1;
    else
        return 0;
}
void enterchoice()
{
    printf("Player %d,Enter your choice: ", player);
    fflush(stdin);
    scanf("%d", &choice);
    fflush(stdin);
}
void selectmark()
{
    mark = (player==1) ? 'O': 'X';
}
int checkwinner()
{
    int row, col, placefilled=1;
    for(row=0;row<3;row++)
    {
        if(a[row][0]==a[row][1] && a[row][1]==a[row][2])
            return 1;
    }

    for(col=0;col<3;col++)
    {
        if(a[0][col]==a[1][col] && a[1][col]==a[2][col])
            return 1;
    }

    if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
        return 1;
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
        return 1;

    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(checkplace(row, col))
            {
                placefilled=0;
            }
        }
    }
    if(placefilled==0)
        return -1;
    else
        return 0;
}
void input()
{
    int row, col, flag=0, place;
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            place=(row*3)+(col+1);
            if(choice==place && checkplace(row, col))
            {
                flag=1;
                a[row][col]=mark;
                board[row][col]=1;
            }
        }
    }
    if(flag==0)
    {
        printf("\n***Invalid place selected***\n\n");
        getch();
        if(withplayer==0)
            player--;
    }
    else
    {
        i=checkwinner();
        if(withplayer==0)
            player++;
        else
            selectplayer();
    }
}
void gameresult()
{
    if(i==1)
    {
        printf("\n\n***Player %d won***\n\n", --player);
    }
    else
    {
        printf("\n\n***Game draw***\n\n");
    }
}
void resetdata()
{
    player=0, isEvil=0, isEvilMarked=0, withplayer=0, flag=0, reset=0;
    int row, col;
    char b='1';
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            a[row][col]=b++;
            board[row][col]=2;
        }
    }

}
int main()
{

    while(1)
    {
        system("cls");
        int x;
        resetdata();
        x=startgame();
        switch(x)
        {
            case 1:
            case 2:
                {
                    isEvil=(x==2)?1:0;
                    do{
                        selectplayer();
                        display();
                        if(player==0)
                        {
                            computermove();
                            i=checkwinner();
                            if(i==1)
                            player++;
                        }
                        else
                        {
                            enterchoice();
                            selectmark();
                            input();
                            i=checkwinner();
                        }
                      }while(i== -1);
                      display();
                      gameresult();
                      getch();
                      break;
                }

            case 3:
            {
                withplayer=1;
                do
                {
                    display();
                    selectmark();
                    enterchoice();
                    input();

                }while(i == -1);
                display();
                gameresult();
                getch();
                break;




            }

            case 4:
                exit(0);
                break;
            default:printf("Invalid option selected\n\n");
        }
    }
    return 0;
}
