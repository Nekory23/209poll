/*
** EPITECH PROJECT, 2021
** 209poll
** File description:
** test_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mypoll.h"

int start(int ac, char **av);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(testerror, error1, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[] = {"\0"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error2, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "10", "60", "80"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error3, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "-1000", "60", "80"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error4, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "-60", "80"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error5, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "-80"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error6, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "180"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test, isGood, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "80"};

    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(test, help, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"\0", "-h"};

    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(testerror, error7, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "0", "80"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, divideBy0, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "0", "80"};

    start(ac, av);
    cr_assert_stderr_eq_str("Error: division by 0\n");
}