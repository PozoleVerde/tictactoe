#include <stdio.h>
#define rows 3
#define columns 3
int checkBoardWin(char arr[rows][columns], char val);
void displayBoard(char arr[rows][columns]);
int isDuplicate(char arr[rows][columns], int pos, char val);
int positionToRow(int pos);
void main(){
	char board[rows][columns];
	int i, j;
	for(i = 0; i < rows; i++)//fills array with spaces
		for(j = 0; j < columns; j++)
			board[i][j] = ' ';

    int pos; char val;
	for(i = 0; ;i++){
        if(i%2 == 0)
            val = 'X';
        else
            val = 'O';
        printf("\nCurrent Standings:\n\n");
        displayBoard(board);
        printf("\nCurrent Player: X\n");
        printf("\tEnter Position: ");
        scanf("%d", &pos);
        if(!isDuplicate(board, pos, 'O') && !isDuplicate(board, pos, 'X'))
            board[positionToRow(pos)][pos - positionToRow(pos) * 3 - 1] = val;
        else
            printf("\n\n\tHey pal, someone already placed something here... You lose your turn for being an idiot.\n\n");
        if(checkBoardWin(board, val))
            break;
	}
	printf("\nFinal Board:\n\n");
	displayBoard(board);
	printf("\n\nThanks for using the game.\n");
}
int checkBoardWin(char arr[rows][columns], char val){
    int i, j;
    for(i = 0; i < rows; i++){ //check rows
        j = 0;
        if(val == arr[i][j] && arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2]){
            printf("\n\n\t****%c wins.****\n", val);
            return 1;
        }
    }
    for(j = 0; j < columns; j++){ //check columns
        i = 0;
        if(val == arr[i][j] && arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j]){
            printf("\n\n\t****%c wins.****\n", val);
            return 1;
        }
    }
    i = 0; j = 0;//check diagonals
    if(val == arr[i][j] && arr[i][j] == arr[i + 1][j + 1] && arr[i + 1][j + 1] == arr[i + 2][j + 2]){
        printf("\n\n\t****%c wins.****\n", val);
        return 1;
    }
    if(val == arr[i][j+2] && arr[i][j+2] == arr[i + 1][j + 1] && arr[i + 1][j + 1] == arr[i + 2][j]){
        printf("\n\n\t****%c wins.****\n", val);
        return 1;
    }
    int tie = 1;
    for(i = 0; i < rows; i++)//check if tie
        for(j = 0; j < columns; j++)
            if(arr[i][j] == ' '){
                tie = 0;
                break;
            }
    if(tie){
        printf("\n\n\t****ISSA TIE, Y'ALL BOTH LOSERS****\n", val);
        return 1;
    }
	return 0;
}
void displayBoard(char arr[rows][columns]){
	int i, j, pos = 0;
	for(i = 0; i < rows; i++){
        printf("\t");
		for(j = 0; j < columns; j++)
			printf("%d.  %c  |", ++pos, arr[i][j]);
        printf("\b \b\n\t"); //deletes last vertical line on 3rd element of row
		if(i < 2)
            printf("-----------------------\n");
	}
}
int isDuplicate(char arr[rows][columns], int pos, char val){
    if(arr[positionToRow(pos)][pos - positionToRow(pos) * 3 - 1] == val)
        return 1;
    return 0;
}
int positionToRow(int pos){
    if(1 <= pos && pos <= 3)
        return 0;
    else if(4 <= pos && pos <= 6)
        return 1;
    else if(7 <= pos && pos <= 9)
        return 2;
    else
        return 0;
}
