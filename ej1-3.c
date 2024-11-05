//Universidad de Costa Rica
//IE-0117 Programacion bajo plataformas abiertas
//Profesora: Carolina Trejos
//Estudiante: Enrique Zamora Solis

//Laboratorio 4 - Ejercicio1 Parte3
//Cadena mas larga de 1s con aritmetica punteros
//Creacion de matriz cuadrada binaria del tamaño definido por usuario con valores aleatorios

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función genera matriz binaria cuadrada con valores aleatorios
void aleatoriobinario(int **matrix, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2;  // Generar 0 o 1 aleatorio
        }
    }
}

// Función para imprimir matriz
void printMatrix(int **matrix, int size) {
    printf("Matriz generada:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Secuencia más larga de 1s consecutivos en la matriz y 
//almacenarla en el puntero 'result'
void findLargestLine(int **matrix, int size, int *result) {
    int secuenciaunos = 0;  // Secuencia temporal de 1s
    int max = 0;            // Mayor secuencia encontrada

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {  // Acceso usando índices
                secuenciaunos++;
            } else {
                if (secuenciaunos > max) {
                    max = secuenciaunos;    // Actualiza Mayor secuencia
                }
                secuenciaunos = 0;          // Reinicia secuencia temporal
            }
        }
    }

    // Revisa último elemento si la última secuencia es la más larga
    if (secuenciaunos > max) {
        max = secuenciaunos;
    }

    *result = max;  // Almacena mayor secuencia en la dirección apuntada por 'result'
}

// Función Libera la memoria de la matriz
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);  // Liberar fila por fila
    }
    free(matrix);  // Liberar el arreglo de punteros
}

int main() {
    int size;
    int mayorSequencia;

    // Solicitar el tamaño de la matriz al usuario
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &size);

    // Solcitud de memoria para matriz cuadrada del tamaño ingresado
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    // Llamado para generar matriz cuadrada binaria aleatoria
    aleatoriobinario(matrix, size);

    // Imprimir matriz
    printMatrix(matrix, size);

    // Buscar mayor secuencia 1s y almacena el resultado en mayorSequencia
    findLargestLine(matrix, size, &mayorSequencia);

    // Mostrar el resultado
    printf("\nLa longitud de la secuencia más larga de 1s consecutivos es: %d\n", mayorSequencia);

    // Liberar la memoria asignada
    freeMatrix(matrix, size);

    return 0;
}
