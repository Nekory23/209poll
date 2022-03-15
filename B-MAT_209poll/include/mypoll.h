/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef MYPOLL_H_
#define MYPOLL_H_

/* INCLUDE */
#include <stdbool.h>

/* STRUCTURE */
typedef struct data_s
{
    int psize;
    int ssize;
    double p;
    double variance;
    double minus;
    double plus;
} data_t;

/* FUNCTIONS */
bool error_handling(int ac, char **av, data_t *data);

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

#endif /* !MYPOLL_H_ */
