/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"
#include <SFML/Graphics.h>

int draw_pause(hunterinfo_t *hf)
{
    sfFont *font = sfFont_createFromFile("assets/Jersey25-Regular.ttf");

    if (!font)
        return EXIT_FAILURE;
    hf->pause_text = sfText_create();
    sfText_setString(hf->pause_text, "PAUSE");
    sfText_setFont(hf->pause_text, font);
    sfText_setCharacterSize(hf->pause_text, 100);
    sfText_setPosition(hf->pause_text, (sfVector2f){ (float)hf->window_size.x /
        2, (float)hf->window_size.y / 2 });
    return EXIT_SUCCESS;
}
