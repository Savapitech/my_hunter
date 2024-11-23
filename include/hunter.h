/*
** EPITECH PROJECT, 2024
** hunter
** File description:
** ./include/hunter.h
*/

#ifndef HUNTER_H_
    #define HUNTER_H_
    #include <SFML/Graphics.h>
    #define EXIT_FAILURE 84
    #define EXIT_SUCCESS 0
    #define CURSOR_SIZE 32
    #define DUCK_NBR 16
    #define FRAMERATE 144
    #define MICRO_TO_SEC(time) time.microseconds / 1000000.0

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2u size;
    int version;
} sprite_t;

typedef struct {
    sfClock *clock;
    sfTime time;
} h_clock_t;

typedef struct {
    sfRenderWindow *window;
    h_clock_t clock;
    h_clock_t clock2;
    sprite_t background;
    sprite_t tree;
    sprite_t cursor;
    sprite_t ducks[DUCK_NBR];
    sfEvent *event;
    int score;
    int shoot;
    sfText *score_text;
} hunterinfo_t;

int hunter(void);
int create_window(size_t x, size_t y, hunterinfo_t *);
int draw_background(hunterinfo_t *);
int draw_tree(hunterinfo_t *);
void event_manager(hunterinfo_t *);
int move_duck(hunterinfo_t *, sfVector2f, int);
int create_clock(hunterinfo_t *);
int draw_cursor(hunterinfo_t *);
int move_cursor(hunterinfo_t *, sfVector2f);
int fill_ducks(hunterinfo_t *);
void display_ducks(hunterinfo_t *);
int draw_score(hunterinfo_t *);
int inc_score(hunterinfo_t *);
#endif
