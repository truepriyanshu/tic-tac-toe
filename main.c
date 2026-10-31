#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printboard(char board[9]){
    system("cls");
    printf("     |     |       \n");
    printf("  %c  |  %c  |  %c  \n",board[0],board[1],board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |       \n");
    printf("  %c  |  %c  |  %c  \n",board[3],board[4],board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |       \n");
    printf("  %c  |  %c  |  %c  \n",board[6],board[7],board[8]);
    printf("     |     |       \n");
}

int checkWin(char board[]){
    //rows check
    if(board[0] == board[1] && board[1] == board[2]) return 1;
    if(board[3] == board[4] && board[4] == board[5]) return 1;
    if(board[6] == board[7] && board[7] == board[8]) return 1;

    //columns check
    if(board[0] == board[3] && board[3] == board[6]) return 1;
    if(board[1] == board[4] && board[4] == board[7]) return 1;
    if(board[2] == board[5] && board[5] == board[8]) return 1;

    //diagonals check
    if(board[0] == board[4] && board[4] == board[8]) return 1;
    if(board[2] == board[4] && board[4] == board[6]) return 1;

    //checkDraw
    for(int i=0; i<9; i++){
        if(board[i] != 'o' || board[i] != 'x'){
            return 0;
        }
    }

    return -1;
}

int main(){
    char board[9] = {'1','2','3','4','5','6','7','8','9'}; //position tells player where he wants to play

    int player = 1;
    int position;
    char mark;

    while(1){
        printboard(board);

        int status = checkWin(board);
        // 1 means win , -1 means draw 
        if(status == 1){
            printf("Game Over ! Player %d has WON .\n",player);
            break;
        } else if(status == -1){
            printf("It's a DRAW .\n");
            break;
        }

        printf("Player %d turn : ",player);

        if(scanf("%d",&position) != 1 || position < 1 || position > 9){
            printf("Enter a valid position !\n");
            getchar(); //to get off input buffer of scanf
            system("pause");
            continue;
        }

        if(board[position-1] == 'o' || board[position-1] == 'x'){
            printf("Position is already occupied ! Try other ones .\n");
            system("pause");
            continue;
        }

        if(player == 1){
            mark = 'o';
        } else {
            mark = 'x';
        }

        board[position-1] = mark;

        if(player == 1){
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;




    
}