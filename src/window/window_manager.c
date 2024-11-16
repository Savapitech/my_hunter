/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include <SFML/Graphics.h>

#include "hunter.h"
#include "lib.h"

int create_window(size_t x, size_t y, hunterinfo_t *hunterinfo)
{
    sfVideoMode mode = { x, y, 32 };

    hunterinfo->window = sfRenderWindow_create(mode, "my_hunter",
        sfResize | sfClose, NULL);
    if (!hunterinfo->window)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void event_manager(hunterinfo_t *hunterinfo)
{
    sfEvent event;

    if (!hunterinfo->event)
        hunterinfo->event = &event;
    while (sfRenderWindow_pollEvent(hunterinfo->window, hunterinfo->event)) {
        my_printf("EVENT");
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(hunterinfo->window);
    }
}
