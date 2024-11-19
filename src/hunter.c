/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"
#include <stdbool.h>
#include <stdlib.h>

static
void handle_hunter_loop(hunterinfo_t *hf)
{
    sfTime time;
    float seconds;

    event_manager(hf);
    time = sfClock_getElapsedTime(hf->clock);
    sfRenderWindow_clear(hf->window, sfBlack);
    sfRenderWindow_drawSprite(hf->window, hf->background.sprite, NULL);
    display_ducks(hf);
    sfRenderWindow_drawSprite(hf->window, hf->cursor.sprite, NULL);
    sfRenderWindow_drawText(hf->window, hf->score_text, NULL);
    sfRenderWindow_display(hf->window);
    for (int i = 0; i < DUCK_NBR; i++)
        move_duck(hf, (sfVector2f){ 1, 0 }, i);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.5) {
        for (int i = 0; i < DUCK_NBR; i++)
            hf->ducks[i].version++;
        sfClock_restart(hf->clock);
    }
}

static
void draw_all(hunterinfo_t *hf)
{
    draw_background(hf);
    fill_ducks(hf);
    draw_cursor(hf);
    draw_score(hf);
    create_clock(hf);
}

int hunter(void)
{
    hunterinfo_t hf = { 0 };

    create_window(1920, 1080, &hf);
    draw_all(&hf);
    sfRenderWindow_setMouseCursorVisible(hf.window, false);
    sfRenderWindow_setFramerateLimit(hf.window, 144);
    while (sfRenderWindow_isOpen(hf.window)) {
        handle_hunter_loop(&hf);
        if (hf.score == DUCK_NBR && hf.shoot) {
            my_printf("WIN SCORE: %d, AC: %d\n", hf.score, hf.score /
                hf.shoot);
            return (EXIT_SUCCESS);
        }
    }
    if (hf.shoot)
        my_printf("SHOOT: %d, AC: %d\n", hf.shoot, hf.score / hf.shoot);
    return EXIT_SUCCESS;
}
