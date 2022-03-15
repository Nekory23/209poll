/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** create_shapes_bis
*/

#include "mypoll.h"

void create_limit_shapes(display_t *disp)
{
    for (int i = 0; i != 4; i++) {
        disp->shapes.limit[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(disp->shapes.limit[i], sfBlack);
        sfRectangleShape_setSize(disp->shapes.limit[i], (sfVector2f) {580, 3});
    }
    sfRectangleShape_setPosition(disp->shapes.limit[0], (sfVector2f) {545, 290});
    sfRectangleShape_setPosition(disp->shapes.limit[1], (sfVector2f) {545 + 650, 290});
    sfRectangleShape_setPosition(disp->shapes.limit[2], (sfVector2f) {545, 540});
    sfRectangleShape_setPosition(disp->shapes.limit[3], (sfVector2f) {545 + 650, 540});
}