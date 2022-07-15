#include <stdio.h>
#include <stdlib.h>

//mudar pra 16 e 7
#define w 8
#define h 4

int **allocate_matrix()
{    
    int **matrix = (int **)malloc(w * sizeof(int *));

    for (int i = 0; i < w; i++) {
        matrix[i] = (int *)malloc(h * sizeof(int));
    }

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

// you must supply the number of rows
void free_matrix(int **board) 
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

void print_matrix(int** matrix){
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            printf("%d\t", matrix[i][j]);
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
//4. quando o bloco chegar no chão, fazer ele parar, setar os valores pra 1 na matrix, partir pro próximo bloco
//5. fazer sistema pra ver se pode limpar as linhas, contabilizar isso em alguma score
//6. fazer game over

int main(){
    int** matrix = allocate_matrix();
    int input;

    while (1){
        print_matrix(matrix);
        scanf("%d", &input);
        printf("%d\n\n", input);
    }


    free(matrix);

    return 0;
}