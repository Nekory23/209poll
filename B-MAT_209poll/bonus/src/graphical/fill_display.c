/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** fill_display
*/

#include "mypoll.h"

static void fill_display_conf_data(display_t *disp, data_t *data)
{
    disp->data_conf.goal[0] = (data->first[1] - data->first[0]) * 100;
    disp->data_conf.goal[1] = (data->first[1] - data->first[0]) * 100;
    disp->data_conf.goal[2] = (data->second[1] - data->second[0]) * 100;
    disp->data_conf.goal[3] = (data->second[1] - data->second[0]) * 100;
    for (int i = 0; i != 4; i++) {
        disp->data_conf.current_val[i] = 0;
        disp->data_conf.done[i] = false;
        disp->data_conf.check[i] = 0;
    }
}

static void fill_display_values_data(display_t *disp, data_t *data)
{
    disp->data_val.goal[0] = data->first[0] * 100;
    disp->data_val.goal[1] = (100 - data->first[0]) * 100;
    disp->data_val.goal[2] = data->second[0] * 100;
    disp->data_val.goal[3] = (100 - data->second[0]) * 100;
    for (int i = 0; i != 4; i++) {
        disp->data_val.current_val[i] = 0;
        disp->data_val.done[i] = false;
        disp->data_val.check[i] = 0;
    }
}

void fill_display(display_t *disp, data_t *data)
{
    sfVideoMode vm = {1920, 1080, 32};

    disp->win = sfRenderWindow_create(vm, "209poll", sfClose, NULL);
    disp->background_col = sfColor_fromRGBA(211, 211, 211, 255);
    disp->text.font = sfFont_createFromFile("res/coolvetica.ttf");
    fill_display_values_data(disp, data);
    fill_display_conf_data(disp, data);
    create_text(disp, data);
    create_shapes(disp);
}