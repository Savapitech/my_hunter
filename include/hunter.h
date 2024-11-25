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
    #define DUCK_NBR 200
    #define AMMO_COUNT 3
    #define FRAMERATE 300
    #define MICRO_TO_SEC(time) time.microseconds / 1000000.0
    #define API_HOST "http://45.88.180.12"
    #define API_PORT 3000
    #define API_TIMEOUT 2000000
    #define ANTI_RELOAD_SPAM_TIME 1.4

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2u size;
    int version;
    int touched;
    int hide;
} sprite_t;

typedef struct {
    sfText *text;
    sfFont *font;
} text_t;

typedef struct {
    sfClock *clock;
    sfTime time;
} h_clock_t;

typedef struct {
    sfRenderWindow *window;
    sfVector2u window_size;
    h_clock_t clock;
    h_clock_t clock2;
    h_clock_t clock3;
    sprite_t background;
    sprite_t tree;
    sprite_t cursor;
    sprite_t ducks[DUCK_NBR];
    sprite_t ammos[AMMO_COUNT];
    sfEvent *event;
    int score;
    int shoot;
    int ammo;
    text_t score_text;
    int paused;
    int remaining_ducks;
    float clock2_time;
    int round;
    double move_count;
    int high_score;
    int duck_space;
    sfTime last_reload_time;
    int game_over;
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
int draw_pause(hunterinfo_t *);
int inc_score(hunterinfo_t *);
void display_ammos(hunterinfo_t *);
int fill_ammos(hunterinfo_t *);
int change_ammo_version(hunterinfo_t *, int);
int get_score(hunterinfo_t *);
int post_score(hunterinfo_t *);
int display_game_over(hunterinfo_t *);
#endif
