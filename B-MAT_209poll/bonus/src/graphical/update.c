/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** update
*/

#include <stdio.h>
#include "mypoll.h"

static void set_new_values(display_t *disp, int i)
{
    disp->data_val.current_val[i] += 1;
    disp->data_val.check[i] += 1;
    if (disp->data_val.check[i] == 20) {
        disp->shapes.size_val[i].y -= 1;
        disp->data_val.check[i] = 0;
        sfRectangleShape_setSize(disp->shapes.values[i],
        disp->shapes.size_val[i]);
    }
}

void update_values(display_t *disp)
{
    for (int i = 0; i != 4; i++)
        if (!disp->data_val.done[i]) {
            if (disp->data_val.current_val[i] == disp->data_val.goal[i])
                disp->data_val.done[i] = true;
            else
                set_new_values(disp, i);
        }
}

static void set_pos_confidence(display_t *disp)
{
    sfFloatRect pos;

    for (int i = 0; i != 4; i++) {
        pos = sfRectangleShape_getGlobalBounds(disp->shapes.values[i]);
        sfRectangleShape_setPosition(disp->shapes.confidence[i],
        (sfVector2f) {pos.left, pos.top});
    }
}

static void set_new_conf(display_t *disp, int i)
{
    disp->data_conf.current_val[i] += 1;
    disp->data_conf.check[i] += 1;
    if (disp->data_conf.check[i] == 20) {
        if (i % 2)
            disp->shapes.size_conf[i].y += 1;
        else
            disp->shapes.size_conf[i].y -= 1;
        disp->data_conf.check[i] = 0;
        sfRectangleShape_setSize(disp->shapes.confidence[i],
        disp->shapes.size_conf[i]);
    }
}

void update_confidence(display_t *disp)
{
    static bool set_pos = false;

    for (int i = 0; i != 4; i++)
        if (disp->data_val.done[i] == false)
            return;
    for (int i = 0; i != 4; i++)
        if (!disp->data_conf.done[i]) {
            if (set_pos == false) {
                set_pos_confidence(disp);
                set_pos = true;
            }
            if (disp->data_conf.current_val[i] == disp->data_conf.goal[i])
                disp->data_conf.done[i] = true;
            else
                set_new_conf(disp, i);
        }
}