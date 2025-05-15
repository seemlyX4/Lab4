#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion encargada de buscar la secuencia mas larga de 1s
void findSequence(int **matrix, int size, int *result) {
    *result = 0;
    int current = 0;

    // for para recorrer la matriz
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(*(matrix + i) + j) == 1) {
                current++;
                if (current > *result) {
                    *result = current;
                }
            } else {
                current = 0;
            }
        }
    }
}

// Función para reservar memoria para la matriz
void memory(int ***matrix, int size) {
    *matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        *(*matrix + i) = (int *)malloc(size * sizeof(int));
    }
}

// Función para llenar la matriz con valores aleatorios (0s y 1s)
void randomMatrix(int **matrix, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(matrix + i) + j) = rand() % 2;
        }
    }
}

// Funcion para imprimir la matriz
void printMatrix(int **matrix, int size) {
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// Funcion para liberar la memoria de la matriz
void matrixFree(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

//Ejecutamos todo en el main
int main() {
    int size, largestLine;
    int **matrix = NULL;
    
    //Solicitamos el tamano de la matriz
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &size);
    
    //Ejecutamos las funciones
    memory(&matrix, size);
    randomMatrix(matrix, size);
    printMatrix(matrix, size);

    findSequence(matrix, size, &largestLine);
    printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine);

    //Liberamos la memoria
    matrixFree(matrix, size);

    return 0;
}
