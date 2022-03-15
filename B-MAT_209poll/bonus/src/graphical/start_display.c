/*
** EPITECH PROJECT, 2021
** B-MAT_209poll
** File description:
** window
*/

#include "mypoll.h"

void start_graphical(data_t *data)
{
    display_t disp;

    fill_display(&disp, data);
    display_window(&disp);
    destroy_everything(&disp);
}