/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** compute_pos
*/

#include "mypoll.h"

static int get_x(int mode)
{
    int x = 0;

    switch (mode) {
        case 0:
            x = 560;
            break;
        case 1:
            x = 840;
            break;
        case 2:
            x = 1210;
            break;
        case 3:
            x = 1150 + 340;
            break;
    }
    return x;
}

sfVector2f compute_pos(int goal, int mode)
{
    sfVector2f pos;
    int x = get_x(mode);
    int res = 0;

    res = goal / 20;
    pos.x = x;
    pos.y = 770 - res;
    return pos;
}
