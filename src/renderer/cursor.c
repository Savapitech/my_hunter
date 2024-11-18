/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include <SFML/Graphics.h>

#include "hunter.h"

int draw_cursor(hunterinfo_t *hf)
{
    hf->cursor.texture = sfTexture_createFromFile("assets/cursor.png", NULL);
    if (!hf->cursor.texture)
        return EXIT_FAILURE;
    hf->cursor.sprite = sfSprite_create();
    sfSprite_setTexture(hf->cursor.sprite, hf->cursor.texture, sfTrue);
    hf->cursor.size = sfTexture_getSize(hf->cursor.texture);
    return EXIT_SUCCESS;
}

int move_cursor(hunterinfo_t *hf, sfVector2f pos)
{
    sfSprite_setPosition(hf->cursor.sprite, pos);
    hf->cursor.pos = sfSprite_getPosition(hf->cursor.sprite);
    return EXIT_SUCCESS;
}
