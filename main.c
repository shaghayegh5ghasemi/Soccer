#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

int column;
int row;
void showmoves(){
    printf("\n\n\n");
    printf("1  |  2  |  3\n8  |  #  |  4\n7  |  6  |  5\n");
}

void func1(int field[][7*column-6],int *x,int *y){
    if((*x-4==0)||(*y-7==0)){
            printf("Next move");
    }
    field[*x-4][*y-7]=3;
    field[*x][*y]=2;
    field[*x-1][*y-2]=1;
    field[*x-2][*y-4]=1;
    field[*x-3][*y-6]=1;
    *x=*x-4;
    *y=*y-7;
}
void func2(int field[][7*column-6],int * x,int *y){
    field[*x-4][*y]=3;
    field[*x][*y]=2;
    field[*x-1][*y]=1;
    field[*x-2][*y]=1;
    field[*x-3][*y]=1;
    *x=*x-4;
}
void func3(int field[][7*column-6],int *x,int *y){
    field[*x-4][*y+7]=3;
    field[*x][*y]=2;
    field[*x-1][*y+2]=1;
    field[*x-2][*y+4]=1;
    field[*x-3][*y+6]=1;
    *x=*x-4;
    *y=*y+7;
}
void func4(int field[][7*column-6],int *x,int *y){
    field[*x][*y+7]=3;
    field[*x][*y]=2;
    field[*x][*y+2]=1;
    field[*x][*y+4]=1;
    field[*x][*y+6]=1;
    *y=*y+7;
}
void func5(int field[][7*column-6],int *x,int *y){
    field[*x+4][*y+7]=3;
    field[*x][*y]=2;
    field[*x+1][*y+2]=1;
    field[*x+2][*y+4]=1;
    field[*x+3][*y+6]=1;
    *x=*x+4;
    *y=*y+7;
}
void func6(int field[][7*column-6],int *x,int *y){
    field[*x+4][*y]=3;
    field[*x][*y]=2;
    field[*x+1][*y]=1;
    field[*x+2][*y]=1;
    field[*x+3][*y]=1;
    *x=*x+4;
}
void func7(int field[][7*column-6],int *x,int *y){
    field[*x+4][*y-7]=3;
    field[*x][*y]=2;
    field[*x+1][*y-2]=1;
    field[*x+2][*y-4]=1;
    field[*x+3][*y-6]=1;
    *x=*x+4;
    *y=*y-7;
}
void func8(int field[][7*column-6],int *x,int *y){
    field[*x][*y-7]=3;
    field[*x][*y]=2;
    field[*x][*y-2]=1;
    field[*x][*y-4]=1;
    field[*x][*y-6]=1;
    *y=*y-7;
}

void showmap(int field[][7*column-6]){
    int i,j;
    for(i = 1; i < (((column - 1) / 2)-1)*6 + ((column - 1) / 2); ++i){
        printf(" ");
    }
    for(i = 0; i < 15; ++i)
        printf("+");
    printf("\n");
    for(j = 0; j < 3; ++j){
    for(i = 1; i <(((column - 1) / 2)-1)*6 + ((column - 1) / 2); ++i){
        printf(" ");
    }
    printf("+");
    for(i = 0; i < 13; ++i)
        printf(" ");
    printf("+");
    printf("\n");
    }

    //3242
    for(i=0;i<4*row-3;i++){
        for(j=0;j<7*column-6;j++){
            if(field[i][j]==0){
                printf(" ");
            }
            if(field[i][j]==1){
                printf("*");
            }
            if(field[i][j]==2){
                printf("+");
            }
            if(field[i][j]==3){
                printf("#");
            }
        }
        printf("\n");
    }
    //888
    for(j = 0; j < 3; ++j){
    for(i = 1; i <(((column - 1) / 2)-1)*6 + ((column - 1) / 2); ++i){
        printf(" ");
    }
    printf("+");
    for(i = 0; i < 13; ++i)
        printf(" ");
    printf("+");
    printf("\n");
    }
    for(i = 1; i < (((column - 1) / 2)-1)*6 + ((column - 1) / 2); ++i){
        printf(" ");
    }
    for(i = 0; i < 15; ++i)
        printf("+");
}
void maingame(){
    printf("WELCOME :)\n\n\n\n");
    Sleep(2000);
    char playername[20],playername2[20];
    system("cls");
    Sleep(1000);
    printf("Enter your names:\n");
    printf("plyer1:");
    scanf("%s",playername);
    printf("\nplyer2:");
    scanf("%s",playername2);
    system("cls");
    Sleep(1000);
    int field[4*row-3][7*column-6];
    int i,j;

    //meqdar dehi avalie
    for(i = 0; i < 4*row-3; ++i){
        for(j = 0;j < 7*column-6; ++j){
            field[i][j] = 0;
        }
    }
        for(j = 0;j < 7*column-6; ++j){
            field[0][j] = 2;
            field[4*row-4][j]=2;
        }
        for(i=0;i<4*row-3;i++){
            field[i][0]=2;
            field[i][7*column-7]=2;
        }
        for(i=((7*column-6)+1)/2-2;i>=((7*column-6)+1)/2-7;i--){
            field[0][i]=0;
            field[4*row-4][i]=0;
        }
        for(i=((7*column-6)+1)/2;i<=((7*column-6)+1)/2+5;i++){
            field[0][i]=0;
            field[4*row-4][i]=0;
        }
        for(i=0;i<4*row-3;i+=4){
            for(j=0;j<7*column-6;j+=7){
                field[i][j]=2;
            }
        }
        field[(4*row-2)/2-1][(7*column-5)/2-1]=3;
        int x=(4*row-2)/2-1;
        int y=(7*column-5)/2-1;
        //meqdar dehi avalie
    showmap(field);
    Sleep(5000);
    system("cls");
    showmap(field);
    int gameend=0;
    int ply1turn=1;
    int ply2turn=0;
    int choice;
    while(gameend==0){
    if(ply1turn==1)
        printf("\nplyer 1\nchoose your move plz");
    if(ply2turn==1)
        printf("\nplyer 2\nchoose your move plz");
    showmoves();
    getchar();
    scanf("%d",&choice);
    if((x==4*row-4)&&y==((7*column-5)/2-1)&&choice==6){
        gameend==1;
        printf("%s win!", playername);
        break;
    }

    if((x==4*row-4)&&y==((7*column-5)/2-8)&&choice==5){
        gameend==1;
        printf("%s win!", playername);
        break;
    }

    if((x==4*row-4)&&y==((7*column-5)/2+6)&&choice==7){
        gameend==1;
        printf("%s win!", playername);
        break;
    }
    if(x==0&&y==((7*column-5)/2-1)&&choice==2){
        gameend==1;
        printf("%s win!", playername2);
        break;
    }

    if(x==0&&y==((7*column-5)/2-8)&&choice==3){
        gameend==1;
        printf("%s win!", playername2);
        break;
    }

    if(x==0&&y==((7*column-5)/2+6)&&choice==1){
        gameend==1;
        printf("%s win!", playername2);
        break;
    }
    switch(choice){
    case 1:
        if(x==0){
            printf("invalid move");
            continue;
        }
        if(y==0){
            printf("invalid move");
            continue;
        }
        if(field[x-1][y-1]){
            printf("invalid move");
            continue;
        }
        func1(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
            showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 2:
        if(y==7*column-7){
            printf("invalid move");
            continue;
        }
        if(x==0){
            printf("invalid move");
            continue;
        }
        if(y==0){
            printf("invalid move");
            continue;
        }
        if(field[x-1][y]==1){
            printf("invalid move");
            continue;
        }
        func2(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
            showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 3:
        if(y==7*column-7){
            printf("invalid move");
            continue;
        }
        if(x==0){
            printf("invalid move");
            continue;
        }
        if(field[x-1][y+1]==1){
            printf("invalid move");
            continue;
        }
        func3(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
                showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 4:
        if(x==4*row-4){
            printf("invalid move");
            continue;
        }
        if(y==7*column-7){
            printf("invalid move");
            continue;
        }
        if(x==0){
            printf("invalid move");
            continue;
        }
        if(field[x][y+1]==1){
            printf("invalid move");
            continue;
        }
        func4(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
            showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 5:
        if(x==4*row-4){
            printf("invalid move");
            continue;
        }
        if(y==7*column-7){
            printf("invalid move");
            continue;
        }
        if(field[x+1][y+1]){
            printf("invalid move");
            continue;
        }
        func5(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
            showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 6:
        if(x==4*row-4){
            printf("invalid move");
            continue;
        }
        if(y==7*column-7){
            printf("invalid move");
            continue;
        }
        if(y==0){
            printf("invalid move");
            continue;
        }
        if(field[x+1][y]==1){
            printf("invalid move");
            continue;
        }
        func6(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
            showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 7:
        if(x==4*row-4){
            printf("invalid move");
            continue;
        }
        if(y==0){
            printf("invalid move");
            continue;
        }
        if(field[x+1][y-1]==1){
            printf("invalid move");
            continue;
        }
        func7(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
            showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    case 8:
        if(x==4*row-4){
            printf("invalid move");
            continue;
        }
        if(x==0){
            printf("invalid move");
            continue;
        }
        if(y==0){
            printf("invalid move");
            continue;
        }
        if(field[x][y-1]==1){
            printf("invalid move");
            continue;
        }
        func8(field,&x,&y);
        if(x==0||x==4*row-4||y==0||y==7*column-7){
                showmap(field);
            continue;
        }
        else{
        ply1turn=!ply1turn;
        ply2turn=!ply2turn;
        }
        break;
    }
    showmap(field);
    }
}

int main(){
    printf("Please enter the rows and columns of the field:\nRow: ");
    scanf("%d", &row);
    printf("\nColumn: ");
    scanf("%d", &column);
    printf("\n");
    while((row % 2 == 0)||(column % 2 == 0) || (row == column)){
        printf("Please enter different odd numbers as row and column!\n\n");
        printf("Please enter the rows and columns of the field:\nRow: ");
        scanf("%d", &row);
        printf("\nColumn: ");
        scanf("%d", &column);
        printf("\n");
    }
    system("cls");
    maingame();
    return 0;
}

