#include "functions.h"
#include <stdio.h>

#include "ctest.h"

CTEST(functions, checkLowercase)
{
    int expected = 1;
    int result = checkLowercase("asduka");
    ASSERT_EQUAL(expected, result);
}
