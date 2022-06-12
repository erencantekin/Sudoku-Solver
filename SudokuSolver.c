#include <stdio.h>
#include <stdlib.h>

int row,column;
int pos_x=-1,pos_y=-1;
void display_board(int board[][column]);
void find_empty(int board[][column]);
int check(int board[][column], int value,int pos_x, int pos_y);
int solveSudoku(int board[][column]);

int main()
{
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &column);

    int board[row][column];
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d", &board[i][j]);
        }
    }
    solveSudoku(board);
    display_board(board);
    return 0;
}

void display_board(int board[][column]){
    for(int i=0; i< row ;i++){
        if(i>0 && i % 3 == 0 && i != row-1){
            for(int j=0; j < (column + column/3)-1;j++){
                printf(" -");
            }
            printf("\n");
        }
        for(int k=0; k<column; k++){
            if(k % 3 == 0 && k>0){
                printf(" | %d", board[i][k]);
            }
            else{
                printf(" %d", board[i][k]);
            }
        }
        printf("\n");
    }
}


void find_empty(int board[][column]){
    for(int i=0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(board[i][j] == 0){
                pos_x = i;
                pos_y = j;
                return;
            }
        }
    }
    pos_x = -1;
    pos_y = -1; //this means there is no 0 in the board
}


int check(int board[][column], int value,int pos_x, int pos_y){
    for(int i=0;i<column;i++){
        if(board[pos_x][i]==value && pos_y != i){
            return 0; // false
        }
    }

    for(int j=0; j<row; j++){
        if(board[j][pos_y] == value && pos_x != j){
            return 0; // false
        }
    }

    int box_row = pos_y / 3;
    int box_column = pos_x / 3;

    for(int i=3*box_column; i<3*box_column+3;i++){
        for(int j = 3*box_row; j<3*box_row + 3; j++){
            if(board[i][j] == value && (pos_x != i || pos_y != j)){
                return 0; //false
            }
        }
    }
    return 1; //true
}


int solveSudoku(int board[][column]){
    int p_x,p_y;
    find_empty(board);
    if(pos_x == -1 && pos_y == -1){
        return 1;
    }
    else{
        p_x =pos_x;
        p_y=pos_y;
    }

    for(int i=1; i<10; i++){
        if(check(board, i,p_x,p_y)){
            board[p_x][p_y] = i;

            if(solveSudoku(board)){
                return 1;
            }
            board[p_x][p_y] = 0;
        }
    }
    return 0;
}
