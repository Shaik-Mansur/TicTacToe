#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isfull(int arr[],int len){
    int i=0;
    while(i<len&&arr[i]!=0){i++;}
    return i==len;
}
void showBoard(int arr[]) {
    int cell = 1;
    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            printf("---|---|---\n");
        }
        for (int j = 0; j < 3; j++) {
            if (arr[cell - 1] == 1) {
                printf(" X ");
            } else if (arr[cell - 1] == 2) {
                printf(" O ");
            } else {
                printf(" %d ", cell);
            }
            cell++;
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
    }
}

int whoWon(int arr[]){
    if(arr[0]==1&&arr[1]==1&&arr[2]==1||arr[3]==1&&arr[4]==1&&arr[5]==1||arr[6]==1&&arr[7]==1&&arr[8]==1||arr[0]==1&&arr[3]==1&&arr[6]==1||arr[1]==1&&arr[4]==1&&arr[7]==1||arr[2]==1&&arr[5]==1&&arr[8]==1||arr[0]==1&&arr[4]==1&&arr[8]==1||arr[2]==1&&arr[4]==1&&arr[6]==1)
    return 1;
    if(arr[0]==2&&arr[1]==2&&arr[2]==2||arr[3]==2&&arr[4]==2&&arr[5]==2||arr[6]==2&&arr[7]==2&&arr[8]==2||arr[0]==2&&arr[3]==2&&arr[6]==2||arr[1]==2&&arr[4]==2&&arr[7]==2||arr[2]==2&&arr[5]==2&&arr[8]==2||arr[0]==2&&arr[4]==2&&arr[8]==2||arr[2]==2&&arr[4]==2&&arr[6]==2)
    return 2;
    if(isfull(arr,9))
    return 0;
    return -1;
}
void clearScreen(){
    system("cls");
}
bool isValidMove(int arr[],int move){
    if(move>=1 && move<=9)
        return arr[move-1]==0;
    return false;
}
void newGame(){
    clearScreen();
    int board[9]={0},player=1,input,winner=0;
    printf("\nStart\n");
    while(!isfull(board,9)){
        showBoard(board);
    printf("Player %d\n",player);
    scanf("%d",&input);
    if(isValidMove(board,input)){
    board[input-1]=player;
    switch(player){
        case 1:
        player=2;
        break;
        case 2:
        player=1;
    }
     winner=whoWon(board);
     if(winner!=-1)
      break;
      clearScreen();
    }
      else {
        clearScreen();
        printf("Invalid Move Try again\n");
      }
    }
    clearScreen();
    showBoard(board);
    if(winner==0)
    printf("It's A Draw\n");
    else if(winner==1)
    printf("X : Player 1 Won\n");
    else
    printf("O : Player 2 Won\n");
}
int main(){
    int op;
    while(1){
        printf("\n1. New Game\n2. Exit\nSelect your choise\n");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
    newGame();
        break;
    case 2:
    exit(0);
    default:
     printf("Enter a valid Input\n");
        break;
    }
    }
    return 0;
}