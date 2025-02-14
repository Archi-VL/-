#include <stdio.h>
#include <stdlib.h>

int** dinamic_memory(int stolbsi,int stroki){
    int** arr = malloc(sizeof(int*) * stolbsi);
    for (int i = 0; i < stolbsi; i++){
        arr[i] = malloc(sizeof(int) * stroki);    
    }
    return arr;
}

void input(int** arr, int stolbsi, int stroki) {
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < stolbsi; i++) {
        for (int j = 0; j < stroki; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void free_dinamic_memory(int** arr,int stolbsi){
    for (int i = 0; i < stolbsi; i++){
        free(arr[i]);
    }
    free(arr);
}

int main(void){
    int stolbsi,stroki;
    printf("введите порядок матрицы\n");
    scanf("%d%d", &stolbsi,&stroki);
    printf("ваша матрица имеет порядок [%d] x [%d]\n", stolbsi, stroki);
    int** matrix = dinamic_memory(stolbsi,stroki);
    input(matrix, stolbsi, stroki);
    printf("введите элемменты матрицы:\n");
    printf("Введенная матрица:\n");
    for (int i = 0; i < stolbsi; i++) {
        for (int j = 0; j < stroki; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    free_dinamic_memory(matrix, stolbsi);
    return 0;
}