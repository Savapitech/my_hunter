/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"
#include <SFML/Graphics.h>

int create_window(size_t x, size_t y, hunterinfo_t *hunterinfo)
{
    sfVideoMode mode = { x, y, 32 };

    hunterinfo->window = sfRenderWindow_create(mode,
        "Call Of Duty | Black Ops 7", sfResize | sfClose, NULL);
    if (!hunterinfo->window)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static
void pause_game(hunterinfo_t *hf)
{
    if (!hf->paused)
        hf->paused = (sfRenderWindow_setFramerateLimit(hf->window, 0), 1);
    else if (hf->paused)
        hf->paused = (sfRenderWindow_setFramerateLimit(hf->window,
            FRAMERATE), 0);
}

static
void reload(hunterinfo_t *hf)
{
    hf->ammo = AMMO_COUNT;
    fill_ammos(hf);
}

static
void kill_duck(hunterinfo_t *hf, int i)
{
    hf->ducks[i].version = 3;
    hf->ducks[i].touched = (move_duck(hf, (sfVector2f){ 0, 0 }, i), 1);
    hf->score += 100;
    hf->ammo--;
    hf->ammos[hf->ammo].sprite = NULL;
    hf->remaining_ducks--;
    inc_score(hf);
}

static
void shoot(hunterinfo_t *hf)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(hf->window);

    if (hf->ammo <= 0)
        return;
    hf->shoot++;
    for (int i = 0; i < DUCK_NBR; i++) {
        if (pos.x < hf->ducks[i].pos.x || pos.x >
            (hf->ducks[i].pos.x + hf->ducks[i].size.x) || pos.y <
            hf->ducks[i].pos.y || pos.y >
            (hf->ducks[i].pos.y + hf->ducks[i].size.y) ||
            hf->ducks[i].sprite == NULL || hf->ducks[i].touched)
            continue;
        kill_duck(hf, i);
    }
}

void event_manager(hunterinfo_t *hf)
{
    sfEvent event;

    if (!hf->event)
        hf->event = &event;
    while (sfRenderWindow_pollEvent(hf->window, hf->event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR &&
            !hf->paused)
            reload(hf);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            pause_game(hf);
        if (event.type == sfEvtMouseButtonPressed && !hf->paused)
            shoot(hf);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(hf->window);
        if (event.type == sfEvtMouseMoved && !hf->paused)
            move_cursor(hf, (sfVector2f){ event.mouseMove.x -
                (float)hf->cursor.size.x / 2, event.mouseMove.y -
                (float)hf->cursor.size.y / 2 });
        }
}
