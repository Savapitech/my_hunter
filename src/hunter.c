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
void destroy_all2(hunterinfo_t *hf)
{
    for (int i = 0; i < DUCK_NBR; i++)
        if (hf->ducks[i].sprite != NULL)
            sfSprite_destroy(hf->ducks[i].sprite);
    for (int i = 0; i < AMMO_COUNT; i++)
        if (hf->ammos[i].sprite != NULL)
            sfSprite_destroy(hf->ammos[i].sprite);
    for (int i = 0; i < AMMO_COUNT; i++)
        if (hf->ducks[i].texture != NULL)
            sfTexture_destroy(hf->ducks[i].texture);
    for (int i = 0; i < AMMO_COUNT; i++)
        if (hf->ammos[i].texture != NULL)
            sfTexture_destroy(hf->ammos[i].texture);
}

void destroy_all(hunterinfo_t *hf)
{
    destroy_all2(hf);
    sfText_destroy(hf->score_text.text);
    sfFont_destroy(hf->score_text.font);
    sfText_destroy(hf->game_over_text.text);
    sfFont_destroy(hf->game_over_text.font);
    sfMusic_destroy(hf->shoot_sound);
    sfSprite_destroy(hf->background.sprite);
    sfTexture_destroy(hf->background.texture);
    sfSprite_destroy(hf->tree.sprite);
    sfTexture_destroy(hf->tree.texture);
    sfSprite_destroy(hf->cursor.sprite);
    sfTexture_destroy(hf->cursor.texture);
    sfClock_destroy(hf->clock.clock);
    sfClock_destroy(hf->clock2.clock);
    sfClock_destroy(hf->clock3.clock);
    sfRenderWindow_destroy(hf->window);
}

static
void display_all(hunterinfo_t *hf)
{
    sfRenderWindow_clear(hf->window, sfBlack);
    sfRenderWindow_drawSprite(hf->window, hf->background.sprite, NULL);
    display_ducks(hf);
    sfRenderWindow_drawSprite(hf->window, hf->tree.sprite, NULL);
    display_ammos(hf);
    sfRenderWindow_drawSprite(hf->window, hf->cursor.sprite, NULL);
    sfRenderWindow_drawText(hf->window, hf->score_text.text, NULL);
    if (hf->game_over)
        display_game_over(hf);
    sfRenderWindow_display(hf->window);
    if (hf->game_over)
        hf->paused = 1;
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
    if (MICRO_TO_SEC(hf->clock.time) > 0.35) {
        for (int i = 0; i < DUCK_NBR; i++)
            change_duck_version(hf, i);
        sfClock_restart(hf->clock.clock);
    }
    if (MICRO_TO_SEC(hf->clock2.time) > hf->clock2_time) {
        if (hf->move_count > 3000) {
            hf->duck_space /= 1.5;
            fill_ducks(hf);
            hf->move_count = 0;
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
    create_sounds(hf);
    draw_cursor(hf);
    draw_score(hf);
    create_clock(hf);
}

int hunter(void)
{
    hunterinfo_t hf = { 0, .ammo = AMMO_COUNT, .remaining_ducks = DUCK_NBR,
        .ducks[DUCK_NBR - 1].sprite = NULL, .clock2_time = 0.0005, .round = 1,
        .duck_space = 50 };

    create_window(1920, 1080, &hf);
    draw_all(&hf);
    sfRenderWindow_setMouseCursorVisible(hf.window, false);
    sfRenderWindow_setFramerateLimit(hf.window, FRAMERATE);
    get_score(&hf);
    while (sfRenderWindow_isOpen(hf.window)) {
        hf.window_size = sfRenderWindow_getSize(hf.window);
        while (hf.paused && sfRenderWindow_isOpen(hf.window))
            event_manager(&hf);
        handle_hunter_loop(&hf);
        if (!hf.remaining_ducks)
            break;
    }
    if (hf.score > hf.high_score)
        post_score(&hf);
    return (destroy_all(&hf), EXIT_SUCCESS);
}
