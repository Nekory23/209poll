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

static void fix_value(data_t *data)
{
    if (data->minus < 0)
        data->minus = 0;
    else if (data->plus > 100)
        data->plus = 100;
}

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

static void compute_interval(data_t *data, int confidence)
{
    if (confidence == 95) {
        data->minus = data->p - ((1.96 * sqrt(data->variance)) * 100);
        data->plus = data->p + ((1.96 * sqrt(data->variance)) * 100);
    }
    if (confidence == 99) {
        data->minus = data->p - ((2.58 * sqrt(data->variance)) * 100);
        data->plus = data->p + ((2.58 * sqrt(data->variance)) * 100);
    }
    fix_value(data);
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
    printf("Population size:\t %d\n", data.psize);
    printf("Sample size:\t\t %d\n", data.ssize);
    printf("Voting intentions:\t %.2f%%\n", data.p);
    printf("Variance:\t\t %.6f\n", data.variance);
    compute_interval(&data, 95);
    printf("95%% confidence interval:");
    printf(" [%.2f%%; %.2f%%]\n", data.minus, data.plus);
    compute_interval(&data, 99);
    printf("99%% confidence interval:"); 
    printf(" [%.2f%%; %.2f%%]\n", data.minus, data.plus);
    return SUCCESS;
}