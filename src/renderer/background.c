/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include <SFML/Graphics.h>

#include "hunter.h"

int draw_background(hunterinfo_t *hf)
{
    hf->background.texture = sfTexture_createFromFile("assets/background.png",
        NULL);
    if (!hf->background.texture)
        return EXIT_FAILURE;
    hf->background.sprite = sfSprite_create();
    sfSprite_setTexture(hf->background.sprite,
        hf->background.texture, sfTrue);
    return EXIT_SUCCESS;
}

int draw_tree(hunterinfo_t *hf)
{
    hf->tree.texture = sfTexture_createFromFile("assets/grass.png",
        NULL);
    if (!hf->tree.texture)
        return EXIT_FAILURE;
    hf->tree.sprite = sfSprite_create();
    sfSprite_setTexture(hf->tree.sprite,
        hf->tree.texture, sfTrue);
    return EXIT_SUCCESS;
}
