#include <stdio.h>
#include <stdlib.h>

//mudar pra 16 e 8
#define w 8
#define h 4

int **create_board()
{    
    int **board = (int **)malloc(w * sizeof(int *));

    for (int i = 0; i < w; i++) {
        board[i] = (int *)malloc(h * sizeof(int));
    }

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            board[i][j] = 0;
        }
    }

    return board;
}

// you must supply the number of rows
void free_board(int **board) 
{
    int row;
    int Rows = w;

    // first free each row
    for (row = 0; row < Rows; row++) {
         free(board[row]);
    }

    // Eventually free the memory of the pointers to the rows
    free(board);
 }

void print_board(int** board){
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

//implementando o tetris
//1. fazer algum tipo de estrutura pra representar o bloquinho
//2. fazer o bloquinho descer (no momento só esperando um scanf mesmo sla)
//obs: era bom fazer um gameloop, acho que ia diminuir o trabalho ao longo prazo pra implementar as coisas
//3. dar a opção do jogar rotacionar o bloquinho e mexer ele direita esquerda
//acho que aqui vai ter que tratar bastante erro (se for girar pra dentro da parede, ou de alguma peça)
//4. quando o bloco chegar no chão, fazer ele parar, setar os valores pra 1 na board, partir pro próximo bloco
//5. fazer sistema pra ver se pode limpar as linhas, contabilizar isso em alguma score
//6. fazer game over

int** move_block(int** board, int** block, int direction){
    //apaga na board os 1 do block
    for(int i = 0; i < 4; i++){
            board[block[i][0]][block[i][1]] = 0;
        }    

    //direction 0 = baixo
    if(direction == 0){
        int collision = 0;      

        //vê se vai colidir com a parede ou com um bloco já existente
        for(int i = 0; i < 4; i++){
            if (block[i][0] == w-1){
                collision = 1;
            }
            else if (board[block[i][0]][block[i][1] + 1] == 1){
                collision = 1;
            }
        }


        //altera a posição no block
        for(int i = 0; i < 4; i++){
            block[i][0] += 1;
        }
    }

    //direction -1 = esquerda
    if(direction == -1){
        int collision = 0;      

        //vê se vai colidir com a parede ou com um bloco já existente
        for(int i = 0; i < 4; i++){
            if (block[i][1] == 0){
                collision = 1;
            }
            else if (board[block[i][0]][block[i][1] - 1] == 1){
                collision = 1;
            }
        }

        //altera a posição no block
        if (collision == 0){
            for(int i = 0; i < 4; i++){
                block[i][1] -= 1;
            }
        }
    }

    //direction 1 = direita
    if(direction == 1){
        int collision = 0;      

        //vê se vai colidir com a parede ou com um bloco já existente
        for(int i = 0; i < 4; i++){
            if (block[i][1] == h-1){
                collision = 1;
            }
            else if (board[block[i][0]][block[i][1] + 1] == 1){
                collision = 1;
            }
        }

        //altera a posição no block
        if (collision == 0){
            for(int i = 0; i < 4; i++){
                block[i][1] += 1;
            }
        }
    }

    //preenche de volta na board os 1 do block
    for(int i = 0; i < 4; i++){
            board[block[i][0]][block[i][1]] = 1;
        } 

    return board;
}

int** create_block(){
    int **block = (int **)malloc(4 * sizeof(int *));

    for (int i = 0; i < 4; i++) {
        block[i] = (int *)malloc(2 * sizeof(int));
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            block[i][j] = 0;
        }
    }

    block[0][0] = 0;
    block[0][1] = 0;
    block[1][0] = 0;
    block[1][1] = 1;
    block[2][0] = 1;
    block[2][1] = 0;
    block[3][0] = 1;
    block[3][1] = 1;

    return block;
}

//representar o block a partir de 4 pontos, isso dá uma board 2x4 

int main(){
    int** board = create_board();
    int** block = create_block();
    int input;

    while (1){
        scanf("%d", &input);
        move_block(board, block, input);
        print_board(board);
    }


    free(board);

    return 0;
}