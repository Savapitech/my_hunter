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
    event_manager(hf);
    hf->clock.time = sfClock_getElapsedTime(hf->clock.clock);
    hf->clock2.time = sfClock_getElapsedTime(hf->clock2.clock);
    sfRenderWindow_clear(hf->window, sfBlack);
    sfRenderWindow_drawSprite(hf->window, hf->background.sprite, NULL);
    display_ducks(hf);
    sfRenderWindow_drawSprite(hf->window, hf->tree.sprite, NULL);
    sfRenderWindow_drawSprite(hf->window, hf->cursor.sprite, NULL);
    sfRenderWindow_drawText(hf->window, hf->score_text, NULL);
    sfRenderWindow_display(hf->window);
    if (MICRO_TO_SEC(hf->clock.time) > 0.5) {
        for (int i = 0; i < DUCK_NBR; i++)
            hf->ducks[i].version++;
        sfClock_restart(hf->clock.clock);
    }
    if (MICRO_TO_SEC(hf->clock2.time) > 0.001) {
        for (int i = 0; i < DUCK_NBR; i++)
            move_duck(hf, (sfVector2f){ 1, 0 }, i);
        sfClock_restart(hf->clock2.clock);
    }
}

static
void draw_all(hunterinfo_t *hf)
{
    draw_background(hf);
    draw_tree(hf);
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
    sfRenderWindow_setFramerateLimit(hf.window, FRAMERATE);
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
