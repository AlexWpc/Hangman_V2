#include "ctest.h"
#include "functions.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>

CTEST(functions, checkLowercase)
{
    int expected = 1;
    int result = checkLowercase("asduka");
    ASSERT_EQUAL(expected, result);
}

CTEST(functions, LetterCheck_incorrect)
{
    int expected = 4;
    int mass[4] = {0, 0, 0, 0};
    int result = LetterCheck(4, "aska", "hjjgkf", 3, mass);
    ASSERT_EQUAL(expected, result);
}

CTEST(functions, LetterCheck_correct)
{
    int expected = 4;
    int mass[5] = {0, 1, 0, 0, 0};
    int result = LetterCheck(5, "astka", "angrybird", 4, mass);
    ASSERT_EQUAL(expected, result);
}

CTEST(functions, SolvedLetterCheck_correct)
{
    int expected = 1;
    int mass[6] = {1, 1, 1, 1, 1, 1};
    int result = SolvedLetterCheck(6, 0, mass);
    ASSERT_EQUAL(expected, result);
}

CTEST(functions, SolvedLetterCheck_correct_fail)
{
    int expected = 0;
    int mass[4] = {1, 0, 1, 1};
    int result = SolvedLetterCheck(4, 0, mass);
    ASSERT_EQUAL(expected, result);
}
