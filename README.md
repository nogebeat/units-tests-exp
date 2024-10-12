### Projet de Division en C avec Tests Unitaires (Criterion)

Ce projet implémente une fonction `Division` qui calcule le quotient et le reste d'une division sans utiliser les opérateurs de division (`/`) ou modulo (`%`). Nous allons également écrire des tests unitaires avec la bibliothèque Criterion pour valider le comportement de cette fonction.

## 1. Installation de Criterion

### Ubuntu/Debian

Sur une distribution basée sur Ubuntu/Debian, vous pouvez installer Criterion via APT :

```bash
sudo apt-get update
sudo apt-get install criterion-dev
```
# Structure du Projet
Voici l'organisation des fichiers du projet :

```c
makefile
my_project/
├── src/
│   └── division.c        # Code source de la fonction Division
├── include/
│   └── division.h        # En-tête de la fonction Division
└── tests/
    └── test_division.c   # Tests unitaires de la fonction Division
```

# Implémentation de la Fonction
Le fichier src/division.c contient la fonction Division, qui calcule le quotient et le reste de deux nombres sans utiliser d'opérateurs de division ou modulo :
```c
#include "division.h"

void Division(float a, float b, float *quotient, float *reste) {
    if (b == 0) {
        *quotient = 0;
        *reste = 0;
        return;
    }

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
```

# En-tête de la Fonction
Le fichier include/division.h contient la définition de la fonction Division
```c
#ifndef DIVISION_H
#define DIVISION_H

void Division(float a, float b, float *quotient, float *reste);

#endif
```

#Tests Unitaires avec Criterion
Nous utilisons Criterion pour effectuer les tests unitaires de la fonction Division. Les tests sont situés dans le fichier tests/test_division.c.

```c
#include <criterion/criterion.h>
#include "../include/division.h"

Test(Division, test_division_positive_numbers) {
    float quotient, reste;

    Division(10, 3, &quotient, &reste);

    cr_assert_float_eq(quotient, 3, 0.001, "Expected quotient to be 3, but got %.2f", quotient);
    cr_assert_float_eq(reste, 1, 0.001, "Expected reste to be 1, but got %.2f", reste);
}

Test(Division, test_division_negative_numbers) {
    float quotient, reste;

    Division(-10, 3, &quotient, &reste);

    cr_assert_float_eq(quotient, -3, 0.001, "Expected quotient to be -3, but got %.2f", quotient);
    cr_assert_float_eq(reste, -1, 0.001, "Expected reste to be -1, but got %.2f", reste);
}

Test(Division, test_division_by_zero) {
    float quotient, reste;

    Division(10, 0, &quotient, &reste);

    cr_assert_float_eq(quotient, 0, 0.001, "Expected quotient to be 0 when dividing by zero");
    cr_assert_float_eq(reste, 0, 0.001, "Expected reste to be 0 when dividing by zero");
}

```
# Description des Tests
Test 1 : Vérifie la division de nombres positifs (10 / 3).
Test 2 : Vérifie la division de nombres négatifs (-10 / 3).
Test 3 : Vérifie le comportement de la division par zéro.

# Compilation et Exécution des Tests
Pour compiler le projet avec les tests unitaires, utilisez gcc comme suit :

```bash
gcc -Iinclude -L/usr/lib -lcriterion src/division.c tests/test_division.c -o test_division
```

Cela crée un exécutable nommé test_division. Vous pouvez ensuite l'exécuter pour voir les résultats des tests :

```bash
./test_division
```
# Résultats attendus
Si tous les tests passent, vous devriez voir une synthèse comme celle-ci :

```yaml
[====] Synthesis: Tested: 3 | Passing: 3 | Failing: 0 | Crashing: 0
```

### Contribution
Si vous souhaitez contribuer à ce projet, vous pouvez forker le dépôt, créer une branche, ajouter vos modifications, et soumettre une pull request.







