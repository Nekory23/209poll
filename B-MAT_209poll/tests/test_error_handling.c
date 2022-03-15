/*
** EPITECH PROJECT, 2021
** 209poll
** File description:
** test_error_handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

#include "mypoll.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(testerror, errorhandling1, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[] = {"\0"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_stderr_eq_str("Error: wrong number of arguments, retry with -h\n");
}

Test(testerror, errorhandling2, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "10", "60", "80"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_stderr_eq_str("Error: the first argument must be greater than the second\n");
}

Test(testerror, errorhandling3, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "-1000", "60", "80"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_stderr_eq_str("Error: argument must be a positive number\n");
}

Test(testerror, errorhandling4, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "-60", "80"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_stderr_eq_str("Error: argument must be a positive number\n");
}

Test(testerror, errorhandling5, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "-80"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_stderr_eq_str("Error: argument must be a positive number\n");
}

Test(testerror, errorhandling6, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "180"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_stderr_eq_str("Error: the pourcentage must be between 0 and 100\n");
}

Test(testhangling, isOK, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "80.80"};
    data_t data;

    cr_assert_eq(error_handling(ac, av, &data), false);
}

Test(testhangling, isDataIsOK, .init=redirect_all_stdout)
{
    int ac = 4;
    char *av[] = {"\0", "1000", "60", "80.80"};
    data_t data;

    error_handling(ac, av, &data);
    cr_assert_eq(data.psize, atoi(av[1]));
    cr_assert_eq(data.ssize, atoi(av[2]));
    cr_assert_eq(data.p, atof(av[3]));
    cr_assert_eq(data.variance, 0);
}