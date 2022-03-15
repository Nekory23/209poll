/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** destroy
*/

#include "mypoll.h"

static void destroy_text(display_t *disp)
{
    for (int i = 0; i != 3; ++i)
        sfText_destroy(disp->text.given_values[i]);
    for (int i = 0; i != 4; ++i)
        sfText_destroy(disp->text.candidates[i]);
    for (int i = 0; i != 2; ++i)
        sfText_destroy(disp->text.confidence_int[i]);
    for (int i = 0; i != 14; ++i)
        sfText_destroy(disp->text.limit[i]);
}

static void destroy_shapes(display_t *disp)
{
    for (int i = 0; i != 4; ++i) {
        sfRectangleShape_destroy(disp->shapes.values[i]);
        sfRectangleShape_destroy(disp->shapes.confidence[i]);
    }
    for (int i = 0; i != 4; ++i)
        sfRectangleShape_destroy(disp->shapes.limit[i]);
    sfRectangleShape_destroy(disp->shapes.frame);
}

void destroy_everything(display_t *disp)
{
    destroy_text(disp);
    destroy_shapes(disp);
    sfFont_destroy(disp->text.font);
    sfRenderWindow_destroy(disp->win);
}