/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

void display_ducks(hunterinfo_t *hf)
{
    for (int i = 0; i < DUCK_NBR; i++)
        if (hf->ducks[i].sprite != NULL)
            sfRenderWindow_drawSprite(hf->window, hf->ducks[i].sprite, NULL);
}

int fill_ducks(hunterinfo_t *hf)
{
    hf->ducks[DUCK_NBR - 1].sprite = NULL;
    for (int i = 0; i < DUCK_NBR; i++) {
        hf->ducks[i].texture = sfTexture_createFromFile("assets/duck.png",
            NULL);
        if (!hf->ducks[i].texture)
            return EXIT_FAILURE;
        hf->ducks[i].sprite = sfSprite_create();
        sfSprite_setTexture(hf->ducks[i].sprite,
            hf->ducks[i].texture, sfTrue);
        sfSprite_setTextureRect(hf->ducks[i].sprite,
            (sfIntRect){ 110, 0, 110, 110 });
        hf->ducks[i].size = sfTexture_getSize(hf->ducks[i].texture);
        hf->ducks[i].size.x /= 3;
        sfSprite_setPosition(hf->ducks[i].sprite, (sfVector2f){
            rand() % 600 - 600, rand() % 1000 + 50});
        hf->ducks[i].version = rand() % 4;
    }
    return EXIT_SUCCESS;
}

int move_duck(hunterinfo_t *hf, sfVector2f pos, int i)
{
    if (hf->ducks[i].sprite == NULL)
        return EXIT_SUCCESS;
    if (hf->ducks[i].version == 3)
            hf->ducks[i].version = 0;
    sfSprite_move(hf->ducks[i].sprite, pos);
    hf->ducks[i].pos = sfSprite_getPosition(hf->ducks[i].sprite);
    sfSprite_setTextureRect(hf->ducks[i].sprite, (sfIntRect){ 110 *
        hf->ducks[i].version, 0, 110, 110 });
    return EXIT_SUCCESS;
}
