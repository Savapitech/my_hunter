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
        if (hf->ducks[i].sprite != NULL && !hf->ducks[i].hide)
            sfRenderWindow_drawSprite(hf->window, hf->ducks[i].sprite, NULL);
}

static
void fill_duck2(hunterinfo_t *hf, int i)
{
    sfSprite_setPosition(hf->ducks[i].sprite, (sfVector2f){
        rand() % DUCK_NBR * hf->duck_space - DUCK_NBR * hf->duck_space,
        rand() % 700});
    sfSprite_setScale(hf->ducks[i].sprite, (sfVector2f){ 4, 4 });
    hf->ducks[i].version = rand() % 3;
}

int fill_ducks(hunterinfo_t *hf)
{
    for (int i = 0; i < DUCK_NBR; i++) {
        hf->ducks[i].hide = 0;
        hf->ducks[i].touched = 0;
        hf->ducks[i].texture =
            sfTexture_createFromFile("assets/duck_states.png", NULL);
        if (!hf->ducks[i].texture)
            return EXIT_FAILURE;
        hf->ducks[i].sprite = sfSprite_create();
        sfSprite_setTexture(hf->ducks[i].sprite,
            hf->ducks[i].texture, sfTrue);
        sfSprite_setTextureRect(hf->ducks[i].sprite,
            (sfIntRect){ 0, 0, 34, 30 });
        hf->ducks[i].size = sfTexture_getSize(hf->ducks[i].texture);
        hf->ducks[i].size.x *= 4;
        hf->ducks[i].size.y *= 4;
        hf->ducks[i].size.x /= 5;
        fill_duck2(hf, i);
    }
    return EXIT_SUCCESS;
}

int move_duck(hunterinfo_t *hf, sfVector2f pos, int i)
{
    if (hf->ducks[i].sprite == NULL)
        return EXIT_SUCCESS;
    if (hf->ducks[i].pos.y > 1100) {
        hf->ducks[i].hide = 1;
        return EXIT_SUCCESS;
    }
    sfSprite_move(hf->ducks[i].sprite, pos);
    hf->ducks[i].pos = sfSprite_getPosition(hf->ducks[i].sprite);
    sfSprite_setTextureRect(hf->ducks[i].sprite, (sfIntRect){ 34 *
        hf->ducks[i].version, 0, 34, 30 });
    return EXIT_SUCCESS;
}
