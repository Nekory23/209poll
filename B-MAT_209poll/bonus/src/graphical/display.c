/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** display
*/

#include "mypoll.h"

static void display_graph(display_t *disp)
{
    for (int i = 0; i != 4; i++) {
        sfRenderWindow_drawRectangleShape(disp->win,
        disp->shapes.values[i], NULL);
        sfRenderWindow_drawRectangleShape(disp->win,
        disp->shapes.confidence[i], NULL);
    }
    for (int i = 10; i != 14; i++)
        sfRenderWindow_drawText(disp->win, disp->text.limit[i], NULL);
    for (int i = 0; i != 4; ++i)
        sfRenderWindow_drawRectangleShape(disp->win, disp->shapes.limit[i], NULL);
    display_limits(disp);
}

static void display_everything(display_t *disp)
{
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawText(disp->win, disp->text.given_values[i], NULL);
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText(disp->win, disp->text.candidates[i], NULL);
    for (int i = 0; i != 2; i++)
        sfRenderWindow_drawText(disp->win, disp->text.confidence_int[i], NULL);
    sfRectangleShape_setPosition(disp->shapes.frame, (sfVector2f) {550, 100});
    sfRenderWindow_drawRectangleShape(disp->win, disp->shapes.frame, NULL);
    sfRectangleShape_setPosition(disp->shapes.frame, (sfVector2f) {1200, 100});
    sfRenderWindow_drawRectangleShape(disp->win, disp->shapes.frame, NULL);
    display_graph(disp);
}

void display_window(display_t *disp)
{
    while (sfRenderWindow_isOpen(disp->win)) {
        sfRenderWindow_clear(disp->win, disp->background_col);
        while (sfRenderWindow_pollEvent(disp->win, &disp->event))
            if (disp->event.type == sfEvtClosed)
                sfRenderWindow_close(disp->win);
        update_values(disp);
        update_confidence(disp);
        display_everything(disp);
        sfRenderWindow_display(disp->win);
    }
}