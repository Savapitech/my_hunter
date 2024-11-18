/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include <stdbool.h>
#include <stdlib.h>

int hunter(void)
{
    hunterinfo_t hf = { 0 };
    int version = 0;
    sfTime time;
    float seconds;

    create_window(1920, 1080, &hf);
    sfRenderWindow_setMouseCursorVisible(hf.window, false);
    draw_background(&hf);
    draw_duck(&hf);
    draw_cursor(&hf);
    create_clock(&hf);
    sfRenderWindow_setFramerateLimit(hf.window, 300);
    while (sfRenderWindow_isOpen(hf.window)) {
        event_manager(&hf);
        time = sfClock_getElapsedTime(hf.clock);
        sfRenderWindow_clear(hf.window, sfBlack);
        sfRenderWindow_drawSprite(hf.window, hf.background.sprite, NULL);
        sfRenderWindow_drawSprite(hf.window, hf.duck.sprite, NULL);
        sfRenderWindow_drawSprite(hf.window, hf.cursor.sprite, NULL);
        sfRenderWindow_display(hf.window);
        move_duck(&hf, (sfVector2f){ 1, 0 }, version);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.5) {
            version++;
            if (version == 3)
                version = 0;
            sfClock_restart(hf.clock);
        }
    }
    return EXIT_SUCCESS;
}
