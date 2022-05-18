#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int row ,column;
int board[25][25];
int condition[26][25];
int input[26];
int recur(int board[25][25]);
int valid(int board[25][25]);
int output(int board[25][25]);
int filled(int board[25][25]);

int main(){

    scanf("%d %d",&row,&column); // input row and column

    //initialization
    memset(board,0,sizeof(int)*625);
    memset(condition,0,sizeof(int)*650);
    memset(input,0,sizeof(int)*26);

    for (int i=0;i<(row+column);i++){
        scanf("%d",&input[i]);
        for (int j=0;j<input[i];j++){
            scanf("%d",&condition[i][j]);
            }
    }



    //solving problem
    recur(board);



}

//0 not color
//1 black //2 white

int recur(int board[25][25]){

    if(filled(board)){
        if(valid(board)){
            output(board);
            return 1;
        }
        else return 0;
    }
    else{
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j]==0){
                    board[i][j]=1;
                    if (recur(board))return 1;
                    board[i][j]=2;

                    if (recur(board)) return 1;
                    board[i][j]=0;
                    return 0;
                }


            }
        }

    }
};

int valid(int board[25][25]){
    int count=0;
    int index;
    for(int i=0;i<row;i++){//row
        index=0;

        for(int j=0;j<column;j++){
            if(board[i][j]==0) return 0;
            if(count==0 && index!=input[i]&&board[i][j]==1){
                count=condition[i][index++];
            }
            if(count!=0){
                if(board[i][j]==1){
                    count--;
                    if(count==0 &&j<column-1&& board[i][j+1]==1){
                        return 0;
                    }
                    continue;
                }
                else return 0;
            }
            else{
                if(board[i][j]!=2) return 0;
            }

        }
        if(count!=0||index!=input[i]) return 0;
    }


    for(int i=0;i<column;i++){//column
        index=0;
        for(int j=0;j<row;j++){
            if(board[j][i]==0) return 0;
            if(count==0 && index!=input[i+row]&&board[j][i]==1){
                count=condition[i+row][index++];
            }
            if(count!=0){
                if(board[j][i]==1){
                    count--;
                    if(count==0 &&j<row-1&& board[j+1][i]==1){
                        return 0;
                    }
                    continue;
                }
                else return 0;
            }
            else{
                if(board[j][i]!=2) return 0;
            }

        }
        if(count!=0||index!=input[i+row]) return 0;
    }

    return 1;
};

int output(int board[25][25]){
    for (int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            /*if(board[i][j]==2)printf("_");
            else printf("o");*/
            if(board[i][j]==2)printf("_");
            else if (board[i][j]==1)printf("o");
            else printf("!");

        }
        if(i!=row) printf("\n");
    }
};

int filled(int board[25][25]){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(board[i][j]==0) return 0;
        }
    }
    return 1;
};
