/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** display_limits
*/

#include "mypoll.h"

static void display_limits_bis(display_t *disp)
{
    sfVector2f pos;

    for (int i = 0, res = 0; i != 4; ++i, res = 0)
        if (disp->data_conf.done[i]) {
            if (i % 2) {
                res = disp->data_val.goal[i] - disp->data_conf.goal[i];
                pos = compute_pos(res, i);
            }
            else {
                res = disp->data_val.goal[i] + disp->data_conf.goal[i];
                pos = compute_pos(res, i);
            }
            sfText_setPosition(disp->text.limit[i + 4], pos);
            sfRenderWindow_drawText(disp->win, disp->text.limit[i + 4], NULL);
        }
}

void display_limits(display_t *disp)
{
    sfVector2f pos;

    for (int i = 0; i != 4; ++i)
        if (disp->data_val.done[i]) {
            pos = compute_pos(disp->data_val.goal[i], i);
            sfText_setPosition(disp->text.limit[i], pos);
            sfRenderWindow_drawText(disp->win, disp->text.limit[i], NULL);
        }
    display_limits_bis(disp);
}