#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printboard(char board[9]){
    // system("cls");
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
        if(board[i] != 'o' && board[i] != 'x'){
            return 0;
        }
    }

    return -1;
}

int main(){
    srand(time(NULL));
    char board[9] = {'1','2','3','4','5','6','7','8','9'}; //position tells player where he wants to play

    int player = 1;
    int position;
    char mark;
    int gameMode;

    printf("Enter 1 for Multiplayer or 2 for AI : ");
    
    while(scanf("%d",&gameMode) != 1 || (gameMode != 1 && gameMode != 2)){
        printf("Invalid Mode . Enter 1 or 2 : ");
        while(getchar() != '\n'); //to get rid of buffer input of scanf
    }

    if(gameMode == 1){
    while(1){
        system("cls");
        printf("============================\n");
        printf("   Game Mode : Multiplayer  \n");
        printf("Player 1 : O & Player 2 : X\n");
        printf("============================\n");
        printboard(board);

        int status = checkWin(board);
        // 1 means win , -1 means draw 
        if(status == 1){
            int winner = (player == 1) ? 2:1;
            printf("Game Over ! Player %d has WON .\n",winner);
            break;
        } else if(status == -1){
            printf("It's a DRAW .\n");
            break;
        }

        printf("Player %d turn : ",player);

        if(scanf("%d",&position) != 1 || position < 1 || position > 9){
            printf("Enter a valid position !\n");
            while(getchar() != '\n'); //to get off input buffer of scanf
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
    } } else {
        int aiDifficulty;

        printf("Enter difficulty mode : 1(easy), 2(medium), 3(hard) : ");

        while(scanf("%d",&aiDifficulty) != 1 || (aiDifficulty != 1 && aiDifficulty != 2 && aiDifficulty != 3)){

            printf("Invalid Mode. Enter 1, 2 or 3 : ");

            while(getchar() != '\n'); //to clear scanf buffer

        }
        if(aiDifficulty == 1){ //easy mode
        while(1){
        system("cls");
        printf("============================\n");
        printf("  Game Mode : SinglePlayer  \n");
        printf("Player 1 : O    &    AI : X\n");
        printf("============================\n");
            printboard(board);

            int status = checkWin(board);
            // 1 for win and -1 for draw

            if(status == 1){
                printf("Game Over ! You Lose .\n"); 
                break;
            } else if(status == -1){
                printf("It's a DRAW!\n");
                break;
            }

            printf("Your turn : ");
            if(scanf("%d",&position) != 1 || position < 1 || position > 9){
            printf("Enter a valid position !\n");
            while(getchar() != '\n'); //to get off input buffer of scanf
            system("pause");
            continue;
            }

             if(board[position-1] == 'o' || board[position-1] == 'x'){
            printf("Position is already occupied ! Try other ones .\n");
            system("pause");
            continue;
            }

            board[position-1] = 'o';

        system("cls");
        printf("============================\n");
        printf("  Game Mode : SinglePlayer  \n");
        printf("Player 1 : O    &    AI : X\n");
        printf("============================\n");
            printboard(board);

            status = checkWin(board);
            
            // 1 for win and -1 for draw
            if(status == 1){
                printf("Game Over ! You Won .\n"); 
                break;
            } else if(status == -1){
                printf("It's a DRAW!");
                break;
            }

            //AI Turn

            do{
                position = rand() % 9;
            } while (board[position] == 'o' || board[position] == 'x');

            board[position] = 'x';


        }}

        else if(aiDifficulty == 2){ //medium mode (defensive)
        
        while(1){
        system("cls");
        printf("============================\n");
        printf("  Game Mode : SinglePlayer  \n");
        printf("Player 1 : O    &    AI : X\n");
        printf("============================\n");
            printboard(board);

            int status = checkWin(board);
            // 1 for win and -1 for draw

            if(status == 1){
                printf("Game Over ! You Lose .\n"); 
                break;
            } else if(status == -1){
                printf("It's a DRAW!\n");
                break;
            }

            printf("Your turn : ");
            if(scanf("%d",&position) != 1 || position < 1 || position > 9){
            printf("Enter a valid position !\n");
            while(getchar() != '\n'); //to get off input buffer of scanf
            system("pause");
            continue;
            }

             if(board[position-1] == 'o' || board[position-1] == 'x'){
            printf("Position is already occupied ! Try other ones .\n");
            system("pause");
            continue;
            }

            board[position-1] = 'o';

        system("cls");
        printf("============================\n");
        printf("  Game Mode : SinglePlayer  \n");
        printf("Player 1 : O    &    AI : X\n");
        printf("============================\n");
            printboard(board);

            status = checkWin(board);
            
            // 1 for win and -1 for draw
            if(status == 1){
                printf("Game Over ! You Won .\n"); 
                break;
            } else if(status == -1){
                printf("It's a DRAW!");
                break;
            }

            //AI turn
            int aiMoved = 0; //will tell ai have tuen or not
            for(int i=0; i<9; i++){
                if(board[i] != 'o' && board[i] != 'x'){
                    char temp = board[i];
                    board[i] = 'o';
                    if(checkWin(board) == 1){
                        board[i] = 'x';
                        aiMoved = 1;
                        break;
                    } else {
                        board[i] = temp;
                    }
                }
            }

            if(aiMoved == 0){
                 do{
                position = rand() % 9;
            } while (board[position] == 'o' || board[position] == 'x');

            board[position] = 'x';
            }
        }
    }

    else { //hard mode(aggresive)
        while(1){
        system("cls");
        printf("============================\n");
        printf("  Game Mode : SinglePlayer  \n");
        printf("Player 1 : O    &    AI : X\n");
        printf("============================\n");
            printboard(board);

            int status = checkWin(board);
            // 1 for win and -1 for draw

            if(status == 1){
                printf("Game Over ! You Lose .\n"); 
                break;
            } else if(status == -1){
                printf("It's a DRAW!\n");
                break;
            }

            printf("Your turn : ");
            if(scanf("%d",&position) != 1 || position < 1 || position > 9){
            printf("Enter a valid position !\n");
            while(getchar() != '\n'); //to get off input buffer of scanf
            system("pause");
            continue;
            }

             if(board[position-1] == 'o' || board[position-1] == 'x'){
            printf("Position is already occupied ! Try other ones .\n");
            system("pause");
            continue;
            }

            board[position-1] = 'o';

        system("cls");
        printf("============================\n");
        printf("  Game Mode : SinglePlayer  \n");
        printf("Player 1 : O    &    AI : X\n");
        printf("============================\n");
            printboard(board);

            status = checkWin(board);
            
            // 1 for win and -1 for draw
            if(status == 1){
                printf("Game Over ! You Won .\n"); 
                break;
            } else if(status == -1){
                printf("It's a DRAW!");
                break;
            }

            //AI turn
            int aiMoved = 0;
            for(int i=0; i<9; i++){ // if attack possible , do it
                if(board[i] != 'o' && board[i] != 'x'){
                    char temp = board[i];
                    board[i] = 'x';

                    if(checkWin(board) == 1){
                        aiMoved = 1;
                        continue;
                    } else {
                        board[i] = temp;
                    }
                }
            }

            if(aiMoved == 0){ // if not attack then defense
                for(int i=0; i<9; i++){
                    if(board[i] != 'o' && board[i] != 'x'){
                        char temp = board[i];
                        board[i] = 'o';

                        if(checkWin(board) == 1){
                            board[i] = 'x';
                            aiMoved = 1;
                            break;
                        } else {
                            board[i] = temp;
                        }
                    }
                }
            }

            if(aiMoved == 0){ // if not attack and defense then capture best position
                if(board[4] != 'o' && board[4] != 'x'){
                    board[4] = 'x';
                    aiMoved = 1;
                }
            }

            if(aiMoved == 0){ // anyone is not possible then do random
                do{
                    position = rand() % 9;
                } while (board[position] == 'o' || board[position] == 'x');
                board[position] = 'x';
            }
    }
}
    }
    

    return 0;




    
}