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
void display_all(hunterinfo_t *hf)
{
    sfRenderWindow_clear(hf->window, sfBlack);
    sfRenderWindow_drawSprite(hf->window, hf->background.sprite, NULL);
    display_ducks(hf);
    sfRenderWindow_drawSprite(hf->window, hf->tree.sprite, NULL);
    display_ammos(hf);
    sfRenderWindow_drawSprite(hf->window, hf->cursor.sprite, NULL);
    sfRenderWindow_drawText(hf->window, hf->score_text, NULL);
    sfRenderWindow_display(hf->window);
}

static
void second_clock(hunterinfo_t *hf)
{
    for (int i = 0; i < DUCK_NBR; i++)
        if (!hf->ducks[i].touched)
            move_duck(hf, (sfVector2f){ 1, 0 }, i);
        else
            move_duck(hf, (sfVector2f){ 0, 1 }, i);
}

static
void change_duck_version(hunterinfo_t *hf, int i)
{
    if (!hf->ducks[i].touched)
        hf->ducks[i].version = hf->ducks[i].version >= 2 ? 0 :
            hf->ducks[i].version + 1;
    else
        hf->ducks[i].version = hf->ducks[i].version == 3 ? 4 :
            hf->ducks[i].version;
}

static
void handle_hunter_loop(hunterinfo_t *hf)
{
    event_manager(hf);
    hf->clock.time = sfClock_getElapsedTime(hf->clock.clock);
    hf->clock2.time = sfClock_getElapsedTime(hf->clock2.clock);
    display_all(hf);
    if (MICRO_TO_SEC(hf->clock.time) > 0.5) {
        for (int i = 0; i < DUCK_NBR; i++)
            change_duck_version(hf, i);
        sfClock_restart(hf->clock.clock);
    }
    if (MICRO_TO_SEC(hf->clock2.time) > hf->clock2_time) {
        if (hf->move_count == 1000) {
            hf->move_count = 0;
            hf->clock2_time /= 2;
            fill_ducks(hf);
            hf->round++;
        }
        second_clock(hf);
        hf->move_count++;
        sfClock_restart(hf->clock2.clock);
    }
}

static
void draw_all(hunterinfo_t *hf)
{
    draw_background(hf);
    draw_tree(hf);
    fill_ducks(hf);
    fill_ammos(hf);
    draw_cursor(hf);
    draw_score(hf);
    draw_pause(hf);
    create_clock(hf);
}

int hunter(void)
{
    hunterinfo_t hf = { 0, .ammo = AMMO_COUNT, .remaining_ducks = DUCK_NBR,
        .ducks[DUCK_NBR - 1].sprite = NULL, .clock2_time = 0.001, .round = 1 };

    create_window(1920, 1080, &hf);
    draw_all(&hf);
    sfRenderWindow_setMouseCursorVisible(hf.window, false);
    sfRenderWindow_setFramerateLimit(hf.window, FRAMERATE);
    while (sfRenderWindow_isOpen(hf.window)) {
        hf.window_size = sfRenderWindow_getSize(hf.window);
        while (hf.paused)
            event_manager(&hf);
        handle_hunter_loop(&hf);
        if (!hf.remaining_ducks)
            return (my_printf("WIN SCORE: %d, AC: %.2f\n", hf.score, hf.score /
                hf.shoot), EXIT_SUCCESS);
    }
    if (hf.shoot)
        my_printf("SHOOT: %d, AC: %.2f\n", hf.shoot, hf.score / hf.shoot);
    return EXIT_SUCCESS;
}
