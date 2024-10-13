#include "../include/division.h"


void Division(float a, float b, float *quotient, float *reste)
{
    float q = 0;
    float abs_a = a < 0 ? -a : a;
    float abs_b = b < 0 ? -b : b;

    while (abs_a >= abs_b) {
        abs_a -= abs_b;
        q++;
    }

    *quotient = (a < 0 && b < 0) || (a > 0 && b > 0) ? q : -q;
    *reste = a < 0 ? -abs_a : abs_a;
}

int s_main(int ac, char **av)
{
    float a = 0;
    float b = 0;
    float quotient = 0;
    float reste = 0;

    if (ac != 3) {
        printf("Usage: %s <numérateur> <dénominateur>\n", av[0]);
        return 1;
    }
    a = atof(av[1]);
    b = atof(av[2]);
    if (b == 0) {
        printf("Erreur: Division par zéro\n");
        return 1;
    }
    Division(a, b, &quotient, &reste);
    printf("Résultat de la division de %.2f par %.2f:\n", a, b);
    printf("Quotient: %.2f\nReste: %.2f\n", quotient, reste);
    return 0;
}
