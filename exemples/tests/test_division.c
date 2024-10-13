#include <criterion/criterion.h>
#include "../include/division.h"

Test(DivisionTest, BasicDivision)
{
    float a = 10.0;
    float b = 3.0;
    float quotient = 0;
    float reste = 0;

    Division(a, b, &quotient, &reste);
    cr_assert_float_eq(quotient, 3.0, 0.01, "Le quotient devrait être 3.0");
    cr_assert_float_eq(reste, 1.0, 0.01, "Le reste devrait être 1.0");
}

Test(DivisionTest, NegativeNumerator)
{
    float a = -10.0;
    float b = 3.0;
    float quotient = 0;
    float reste = 0;

    Division(a, b, &quotient, &reste);
    cr_assert_float_eq(quotient, -3.0, 0.01, "Le quotient devrait être -3.0");
    cr_assert_float_eq(reste, -1.0, 0.01, "Le reste devrait être -1.0");
}

Test(DivisionTest, NegativeDenominator)
{
    float a = 10.0;
    float b = -3.0;
    float quotient = 0;
    float reste = 0;

    Division(a, b, &quotient, &reste);
    cr_assert_float_eq(quotient, -3.0, 0.01, "Le quotient devrait être -3.0");
    cr_assert_float_eq(reste, 1.0, 0.01, "Le reste devrait être 1.0");
}

Test(DivisionTest, BothNegative)
{
    float a = -10.0;
    float b = -3.0;
    float quotient = 0;
    float reste = 0;

    Division(a, b, &quotient, &reste);
    cr_assert_float_eq(quotient, 3.0, 0.01, "Le quotient devrait être 3.0");
    cr_assert_float_eq(reste, -1.0, 0.01, "Le reste devrait être -1.0");
}

Test(DivisionTest, DivisionByZero)
{
    float a = 10.0;
    float b = 0.0;
    float quotient = 0;
    float reste = 0;

    Division(a, b, &quotient, &reste);
    cr_assert_float_eq(quotient, 0.0, 0.01, "Le quotient devrait être 0.0 en cas de division par zéro");
    cr_assert_float_eq(reste, 0.0, 0.01, "Le reste devrait être 0.0 en cas de division par zéro");
}
