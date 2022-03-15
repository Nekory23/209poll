/*
** EPITECH PROJECT, 2021
** 209poll
** File description:
** error_handling
*/

#include <stdio.h>
#include <stdlib.h>

#include "mypoll.h"

static bool check_is_digit(char *av)
{
    for (int j = 0; av[j] != '\0'; ++j)
        if (av[j] < '0' || av[j] > '9')
            return true;
    return false;
}

static bool check_number(data_t *data)
{
    if ((int)data->p > 100) {
        fprintf(stderr, "Error: the pourcentage must be between 0 and 100\n");
        return true;
    }
    if (data->psize < data->ssize) {
        fprintf(stderr, "Error: the first argument must be greater than the second\n");
        return true;
    }
    return false;
}

bool error_handling(int ac, char **av, data_t *data)
{
    if (ac != 4) {
        fprintf(stderr, "Error: wrong number of arguments, retry with -h\n");
        return true;
    }
    for (int i = 1; i != ac - 1; ++i)
        if (check_is_digit(av[i])) {
            fprintf(stderr, "Error: argument must be a positive number\n");
            return true;
        }
    for (int i = 0; av[ac-1][i] != '\0'; ++i)
        if ((av[ac-1][i] < '0' || av[ac-1][i] > '9') && av[ac-1][i] != '.') {
            fprintf(stderr, "Error: argument must be a positive number\n");
            return true;
        }
    data->psize = atoi(av[1]);
    data->ssize = atoi(av[2]);
    data->p = atof(av[3]);
    data->variance = 0;
    if (check_number(data))
        return true;
    return false;
}