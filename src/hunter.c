/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include <stdlib.h>

int hunter(void)
{
    hunterinfo_t hf = { 0 };
    int version = 0;
    sfTime time;
    float seconds;

    create_window(1920, 1080, &hf);
    draw_background(&hf);
    draw_duck(&hf);
    create_clock(&hf);
    while (sfRenderWindow_isOpen(hf.window)) {
        event_manager(&hf);
        time = sfClock_getElapsedTime(hf.clock);
        sfRenderWindow_clear(hf.window, sfBlack);
        move_duck(&hf, (sfVector2f){ 0, 0 }, version);
        sfRenderWindow_drawSprite(hf.window, hf.background.sprite, NULL);
        sfRenderWindow_drawSprite(hf.window, hf.duck.sprite, NULL);
        sfRenderWindow_display(hf.window);
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
