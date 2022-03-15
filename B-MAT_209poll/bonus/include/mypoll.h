/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef MYPOLL_H_
#define MYPOLL_H_

/* INCLUDE */
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdbool.h>

/* STRUCTURE */
typedef struct data_s
{
    int psize;
    int ssize;
    double p;
    double variance;
    double first[2];
    double second[2];
} data_t;

// display structs
typedef struct text_s {
    sfFont *font;
    sfText *given_values[3];
    sfText *candidates[4];
    sfText *confidence_int[2];
    sfText *limit[14];
} text_t;

typedef struct shapes_s {
    sfRectangleShape *values[4];
    sfVector2f size_val[4];
    sfRectangleShape *confidence[4];
    sfVector2f size_conf[4];
    sfRectangleShape *frame;
    sfRectangleShape *limit[4];
} shapes_t;

typedef struct display_values_s {
    int goal[4];
    int current_val[4];
    int check[4];
    bool done[4];
} display_values_t;

typedef struct display_conf_s {
    int goal[4];
    int current_val[4];
    int check[4];
    bool done[4];
} display_conf_t;

typedef struct display_s
{
    sfRenderWindow *win;
    sfColor background_col;
    sfEvent event;
    shapes_t shapes;
    text_t text;
    display_values_t data_val;
    display_conf_t data_conf;
} display_t;

/* FUNCTIONS */
bool error_handling(int ac, char **av, data_t *data);

// display
void start_graphical(data_t *data);

void fill_display(display_t *disp, data_t *data);

void create_text(display_t *disp, data_t *data);
void create_limit_text(display_t *disp, data_t *data);

void create_shapes(display_t *disp);
void create_limit_shapes(display_t *disp);

void display_window(display_t *disp);
void display_limits(display_t *disp);
sfVector2f compute_pos(int goal, int mode);

void update_values(display_t *disp);
void update_confidence(display_t *disp);

void destroy_everything(display_t *disp);

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

#endif /* !MYPOLL_H_ */
