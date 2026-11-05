
/*
  Tests unitaires des fonctions Sobel et Morph

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sobel.h"
#include "morph.h"

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "ECHEC : %s (ligne %d)\n", \
                #condition, __LINE__); \
        exit(EXIT_FAILURE); \
    } \
} while (0)



/*DILATATION :  le maximum du voisinage
 */

void test_dilation(void)
{
    int height = 3;
    int width = 3;
    int window = 1;

    unsigned char input[9] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    unsigned char output[3] = {0};

    unsigned char expected[3] = {
        7, 8, 9
    };

    dilation(height, width, window, input, output);

    CHECK(memcmp(output, expected, sizeof(expected)) == 0);

    printf("TEST DILATION : OK\n");
}


/* EROSION :  minimum du voisinage
 */

void test_erosion(void)
{
    int height = 3;
    int width = 3;
    int window = 1;

    unsigned char input[9] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    unsigned char output[3] = {0};

    unsigned char expected[3] = {
        1, 2, 3
    };

    erosion(height, width, window, input, output);

    CHECK(memcmp(output, expected, sizeof(expected)) == 0);

    printf("TEST EROSION : OK\n");
}


/* SOBEL: calcul du gradient horizontal
 
 */

void test_sobel(void)
{
    int width = 3;
    int height = 3;

    
       Image en niveaux de gris :

        0   4   8
        0   4   8
        0   4   8

       Au pixel central :
       gx = 32
       gy = 0

       Résultat attendu :
       (gx*gx + gy*gy) / 8 = 128
    

    unsigned char input[9] = {
        0, 4, 8,
        0, 4, 8,
        0, 4, 8
    };

    unsigned char output[9] = {0};

    sobel(width, height, input, output);

    CHECK(output[1] == 128);

    printf("TEST SOBEL : OK\n");
}



int main(void)
{
    printf("\n===== DEBUT DES TESTS UNITAIRES =====\n\n");

    test_dilation();

    test_erosion();

    test_sobel();

    printf("\n===== TOUS LES TESTS SONT REUSSIS =====\n");

    return EXIT_SUCCESS;
}

