/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** create_text
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mypoll.h"

static char **create_strings(data_t *data)
{
    char **str = malloc(sizeof(char *) * 4);
    char value[100];

    if (str == NULL)
        exit(84);
    for (int i = 0; i != 3; i++) {
        str[i] = malloc(sizeof(char) * 100);
        if (str[i] == NULL)
            exit(84);
        memset(str[i], '\0', 100);
    }
    sprintf(value, "Population size: %d", data->psize);
    strcat(str[0], value);
    sprintf(value, "Sample size: %d", data->ssize);
    strcat(str[1], value);
    sprintf(value, "Voting intentions: %.2f%%", data->p);
    strcat(str[2], value);
    str[3] = NULL;
    return str;
}

static void create_given_values_text(display_t *disp, data_t *data)
{
    char **str = create_strings(data);

    for (int i = 0; i != 3; i++) {
        disp->text.given_values[i] = sfText_create();
        sfText_setFont(disp->text.given_values[i], disp->text.font);
        sfText_setColor(disp->text.given_values[i], sfBlack);
        sfText_setCharacterSize(disp->text.given_values[i], 50);
    }
    sfText_setString(disp->text.given_values[0], str[0]);
    sfText_setPosition(disp->text.given_values[0], (sfVector2f) {100, 150});
    sfText_setString(disp->text.given_values[1], str[1]);
    sfText_setPosition(disp->text.given_values[1], (sfVector2f) {100, 250});
    sfText_setString(disp->text.given_values[2], str[2]);
    sfText_setPosition(disp->text.given_values[2], (sfVector2f) {100, 350});
    for (int i = 0; i != 3; i++)
        free(str[i]);
    free(str);
}

static void create_candidates_text(display_t *disp)
{
    for (int i = 0; i != 4; i++) {
        disp->text.candidates[i] = sfText_create();
        sfText_setFont(disp->text.candidates[i], disp->text.font);
        sfText_setColor(disp->text.candidates[i], sfBlack);
        sfText_setCharacterSize(disp->text.candidates[i], 30);
    }
    sfText_setString(disp->text.candidates[0], "Candidate 1");
    sfText_setPosition(disp->text.candidates[0], (sfVector2f) {660, 800});
    sfText_setString(disp->text.candidates[1], "Candidate 2");
    sfText_setPosition(disp->text.candidates[1], (sfVector2f) {930, 800});
    sfText_setString(disp->text.candidates[2], "Candidate 1");
    sfText_setPosition(disp->text.candidates[2], (sfVector2f) {1300, 800});
    sfText_setString(disp->text.candidates[3], "Candidate 2");
    sfText_setPosition(disp->text.candidates[3], (sfVector2f) {1580, 800});
}

static void create_confidence_text(display_t *disp)
{
    disp->text.confidence_int[0] = sfText_copy(disp->text.given_values[0]);
    sfText_setString(disp->text.confidence_int[0], "95% confidence interval:");
    sfText_setPosition(disp->text.confidence_int[0], (sfVector2f) {710, 850});
    disp->text.confidence_int[1] = sfText_copy(disp->text.given_values[0]);
    sfText_setString(disp->text.confidence_int[1], "99% confidence interval:");
    sfText_setPosition(disp->text.confidence_int[1], (sfVector2f) {1360, 850});
}

void create_text(display_t *disp, data_t *data)
{
    create_given_values_text(disp, data);
    create_candidates_text(disp);
    create_confidence_text(disp);
    create_limit_text(disp, data);
}