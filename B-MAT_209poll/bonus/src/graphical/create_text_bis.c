/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** craete_text_bis
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mypoll.h"

static char **allocate(void)
{
    char **str = malloc(sizeof(char *) * 15);

    if (str == NULL)
        exit(84);
    for (int i = 0; i != 15; i++) {
        str[i] = malloc(sizeof(char) * 100);
        if (str[i] == NULL)
            exit(84);
        memset(str[i], '\0', 100);
    }
    return str;
}

static char **fill_rest(char **str, data_t *data)
{
    char value[10];

    sprintf(value, "%.2f%%", data->first[1]);
    strcat(str[4], value);
    sprintf(value, "%.2f%%", 100 - data->first[1]);
    strcat(str[5], value);
    sprintf(value, "%.2f%%", data->second[1]);
    strcat(str[6], value);
    sprintf(value, "%.2f%%", 100 - data->second[1]);
    strcat(str[7], value);
    strcat(str[8], value);
    strcat(str[9], value);
    str[14] = NULL;
    return str;
}

static char **create_strings(data_t *data)
{
    char **str = allocate();
    char value[10];

    strcat(str[10], "50%");
    strcat(str[11], "50%");
    strcat(str[12], "100%");
    strcat(str[13], "100%");
    sprintf(value, "%.2f%%", data->p);
    strcat(str[8], value);
    strcat(str[9], value);
    sprintf(value, "%.2f%%", data->first[0]);
    strcat(str[0], value);
    sprintf(value, "%.2f%%", 100 - data->first[0]);
    strcat(str[1], value);
    sprintf(value, "%.2f%%", data->second[0]);
    strcat(str[2], value);
    sprintf(value, "%.2f%%", 100 - data->second[0]);
    strcat(str[3], value);
    str = fill_rest(str, data);
    return str;
}

static void set_limit_positions(display_t *disp)
{
    sfVector2f pos = {500, 520};

    for (int i = 0, x = 300; i != 14; i++, x += 100)
        sfText_setPosition(disp->text.limit[i], (sfVector2f) {x, 300});
    sfText_setPosition(disp->text.limit[10], pos);
    pos.x += 640;
    sfText_setPosition(disp->text.limit[11], pos);
    pos.x -= 640;
    pos.y -= 250;
    sfText_setPosition(disp->text.limit[12], pos);
    pos.x += 640;
    sfText_setPosition(disp->text.limit[13], pos);
}

void create_limit_text(display_t *disp, data_t *data)
{
    char **str = create_strings(data);

    for (int i = 0; i != 14; i++) {
        disp->text.limit[i] = sfText_create();
        sfText_setFont(disp->text.limit[i], disp->text.font);
        sfText_setColor(disp->text.limit[i], sfBlack);
        if (i >= 10)
            sfText_setCharacterSize(disp->text.limit[i], 40);
        else
            sfText_setCharacterSize(disp->text.limit[i], 30);
        sfText_setString(disp->text.limit[i], str[i]);
    }
    set_limit_positions(disp);
    for (int i = 0; i != 13; i++)
        free(str[i]);
    free(str);
}