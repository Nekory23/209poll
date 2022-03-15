/*
** EPITECH PROJECT, 2021
** 209poll
** File description:
** start
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "mypoll.h"

static bool compute_variance(data_t *data)
{
    double up = 0;

    if (data->ssize == 0 || data->psize - 1 == 0) {
        fprintf(stderr, "Error: division by 0\n");
        return true;
    }
    up = (data->p / 100) * (1 - (data->p / 100));
    data->variance = up / data->ssize;
    up = data->psize - data->ssize;
    data->variance *= up / (data->psize - 1);
    return false;
}

static void adjust_values(double *tab)
{
    if (tab[0] < 0 || tab[0] > 100) {
        if (tab[0] < 0)
            tab[0] = 0;
        else if (tab[0] > 100)
            tab[0] = 100;
    }
    if (tab[1] < 0 || tab[1] > 100) {
        if (tab[1] < 0)
            tab[1] = 0;
        else if (tab[1] > 100)
            tab[1] = 100;
    }
}

static void compute_interval(data_t *data)
{
    data->first[0] = data->p - ((1.96 * sqrt(data->variance)) * 100);
    data->first[1] = data->p + ((1.96 * sqrt(data->variance)) * 100);
    data->second[0] = data->p - ((2.58 * sqrt(data->variance)) * 100);
    data->second[1] = data->p + ((2.58 * sqrt(data->variance)) * 100);
    adjust_values(data->first);
    adjust_values(data->second);
}

static int display_help(char *prog)
{
    printf("USAGE\n");
    printf("    %s pSize sSize p\n\n", prog);
    printf("DESCRIPTION\n");
    printf("    pSize\tsize of the population\n");
    printf("    sSize\tsize of the sample (supposed to be representative)\n");
    printf("    p\t\tpercentage of voting intentions");
    printf("for a specific candidate\n");
    return SUCCESS;
}

int start(int ac, char **av)
{
    data_t data;

    if (ac == 2 && !strcmp(av[1], "-h"))
        return display_help(av[0]);
    if (error_handling(ac, av, &data))
        return ERROR;
    if (compute_variance(&data))
        return ERROR;
    compute_interval(&data);
    start_graphical(&data);
    return SUCCESS;
}