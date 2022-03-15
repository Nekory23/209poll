/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** create_shapes
*/

#include "mypoll.h"

static void create_frame(display_t *disp)
{
    disp->shapes.frame = sfRectangleShape_create();
    sfRectangleShape_setFillColor(disp->shapes.frame, sfTransparent);
    sfRectangleShape_setOutlineThickness(disp->shapes.frame, 5);
    sfRectangleShape_setOutlineColor(disp->shapes.frame, sfBlack);
    sfRectangleShape_setPosition(disp->shapes.frame, (sfVector2f) {550, 100});
    sfRectangleShape_setSize(disp->shapes.frame, (sfVector2f) {570, 850});
}

static void set_value_positions(display_t *disp)
{
    sfVector2f pos = {630, 790};

    sfRectangleShape_setPosition(disp->shapes.values[0], pos);
    sfRectangleShape_setSize(disp->shapes.values[0], disp->shapes.size_val[0]);
    pos.x = 900;
    sfRectangleShape_setPosition(disp->shapes.values[1], pos);
    sfRectangleShape_setSize(disp->shapes.values[1], disp->shapes.size_val[1]);
    pos.x = 1270;
    sfRectangleShape_setPosition(disp->shapes.values[2], pos);
    sfRectangleShape_setSize(disp->shapes.values[2], disp->shapes.size_val[2]);
    pos.x = 1550;
    sfRectangleShape_setPosition(disp->shapes.values[3], pos);
    sfRectangleShape_setSize(disp->shapes.values[3], disp->shapes.size_val[3]);
}

static void create_values_shape(display_t *disp)
{
    sfVector2f size = {150, 0};
    sfColor t_blue = {0, 0, 255, 150};
    sfColor t_red = {255, 0, 0, 150};

    for (int i = 0; i != 4; i++)
        disp->shapes.size_val[i] = size;
    for (int i = 0; i != 4; i++) {
        disp->shapes.values[i] = sfRectangleShape_create();
        if (i % 2)
            sfRectangleShape_setFillColor(disp->shapes.values[i], t_red);
        else
            sfRectangleShape_setFillColor(disp->shapes.values[i], t_blue);
    }
    set_value_positions(disp);
}

static void create_confidence_shape(display_t *disp)
{
    sfRectangleShape *ref = sfRectangleShape_copy(disp->shapes.values[0]);
    sfColor t_blue = {0, 0, 255, 200};
    sfColor t_red = {255, 0, 0, 150};
    sfVector2f size = {150, 0};

    for (int i = 0; i != 4; i++)
        disp->shapes.size_conf[i] = size;
    for (int i = 0; i != 4; i++) {
        disp->shapes.confidence[i] = sfRectangleShape_copy(ref);
        if (i % 2)
            sfRectangleShape_setFillColor(disp->shapes.confidence[i], t_red);
        else
            sfRectangleShape_setFillColor(disp->shapes.confidence[i], t_blue);
    }
}

void create_shapes(display_t *disp)
{
    create_frame(disp);
    create_values_shape(disp);
    create_confidence_shape(disp);
    create_limit_shapes(disp);
}