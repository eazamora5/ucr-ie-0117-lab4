//Universidad de Costa Rica
//IE-0117 Programacion bajo plataformas abiertas
//Profesora: Carolina Trejos
//Estudiante: Enrique Zamora Solis
//Laboratorio 4 - Ejercicio1 Parte1
//Cadena mas larga de 1s con aritmetica punteros

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int findLargestLine(int *matrix) {
    int secuenciaunos = 0;  // Contador secuencia temporal de unos
    int max = 0;            // Maximo valor de unos consecutivos

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (*(matrix + i * SIZE + j) == 1) {  // Acceso elementos usando aritmética de punteros
                secuenciaunos++;
            } else {
                if (secuenciaunos > max) {
                    max = secuenciaunos;
                }
                secuenciaunos = 0;  // Reinicia la secuencia actual
            }
        }
    }

    // Revisa al final del último elemento si la última secuencia es la más larga
    if (secuenciaunos > max) {
        max = secuenciaunos;
    }

    return max;
}

int main() {
    printf("Matriz pruebas:\n");

    int matrix[SIZE][SIZE] = {
        {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0}
    };

    // Imprime la matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    printf("\nLa secuencia más larga de 1s consecutivos es: %d\n", findLargestLine((int *)matrix));

    return 0;
}
