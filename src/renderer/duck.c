/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include <SFML/Graphics.h>

#include "hunter.h"

int draw_duck(hunterinfo_t *hf)
{
    hf->duck.texture = sfTexture_createFromFile("assets/duck.png", NULL);
    if (!hf->duck.texture)
        return EXIT_FAILURE;
    hf->duck.sprite = sfSprite_create();
    sfSprite_setTexture(hf->duck.sprite,
        hf->duck.texture, sfTrue);
    sfSprite_setTextureRect(hf->duck.sprite, (sfIntRect){ 0, 0, 110, 110 });
    return EXIT_SUCCESS;
}

int move_duck(hunterinfo_t *hf, sfVector2f pos, int duck_version)
{
    sfSprite_move(hf->duck.sprite, pos);
    hf->duck.pos = sfSprite_getPosition(hf->duck.sprite);
    sfSprite_setTextureRect(hf->duck.sprite, (sfIntRect){ 110 * duck_version,
        0, 110, 110 });
    return EXIT_SUCCESS;
}
