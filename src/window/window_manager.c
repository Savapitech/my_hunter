/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "lib.h"
#include <SFML/Graphics.h>
#include "hunter.h"

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
void shoot(hunterinfo_t *hf)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(hf->window);

    my_printf("SHOOT %d, %d\n", pos.x, pos.y);
    hf->shoot++;
    for (int i = 0; i < DUCK_NBR; i++) {
        if (pos.x < hf->ducks[i].pos.x || pos.x >
            (hf->ducks[i].pos.x + hf->ducks[i].size.x) || pos.y <
            hf->ducks[i].pos.y || pos.y >
            (hf->ducks[i].pos.y + hf->ducks[i].size.y))
            continue;
        hf->ducks[i].sprite = NULL;
        hf->score++;
        my_printf("SHOOTED SCORE: %d\n", hf->score);
    }
}

void event_manager(hunterinfo_t *hf)
{
    sfEvent event;

    if (!hf->event)
        hf->event = &event;
    while (sfRenderWindow_pollEvent(hf->window, hf->event)) {
        if (event.type == sfEvtMouseButtonPressed)
            shoot(hf);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(hf->window);
        if (event.type == sfEvtMouseMoved)
            move_cursor(hf,
                (sfVector2f){ event.mouseMove.x - (float)hf->cursor.size.x / 2,
                event.mouseMove.y - (float)hf->cursor.size.y / 2 });
        }
}
