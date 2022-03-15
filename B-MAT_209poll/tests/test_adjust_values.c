/*
** EPITECH PROJECT, 2021
** B-MAT_209poll
** File description:
** test_adjust_values
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

#include "mypoll.h"

int start(int ac, char **av);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(adjust_values, too_small, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "10000", "100", "0.01"};

    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(adjust_values, too_big, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "10000", "100", "99.99"};

    cr_assert_eq(start(ac, av), SUCCESS);
}