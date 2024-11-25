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

void display_ammos(hunterinfo_t *hf)
{
    for (int i = 0; i < AMMO_COUNT; i++)
        if (hf->ammos[i].sprite != NULL)
            sfRenderWindow_drawSprite(hf->window, hf->ammos[i].sprite, NULL);
}

int fill_ammos(hunterinfo_t *hf)
{
    hf->ammos[AMMO_COUNT - 1].sprite = NULL;
    for (int i = 0; i < AMMO_COUNT; i++) {
        hf->ammos[i].texture = sfTexture_createFromFile("assets/ammo.png",
            NULL);
        if (!hf->ammos[i].texture)
            return EXIT_FAILURE;
        hf->ammos[i].sprite = sfSprite_create();
        sfSprite_setTexture(hf->ammos[i].sprite,
            hf->ammos[i].texture, sfTrue);
        sfSprite_setTextureRect(hf->ammos[i].sprite,
            (sfIntRect){ 0, 0, 4, 7 });
        hf->ammos[i].size = sfTexture_getSize(hf->ammos[i].texture);
        hf->ammos[i].size.x /= 2;
        sfSprite_setScale(hf->ammos[i].sprite, (sfVector2f){ 5, 5 });
        sfSprite_setPosition(hf->ammos[i].sprite,
            (sfVector2f){ 10 * (i + 1) + i * 20, 900});
        hf->ammos[i].version = 0;
    }
    return EXIT_SUCCESS;
}

int change_ammo_version(hunterinfo_t *hf, int i)
{
    if (hf->ammos[i].sprite == NULL)
        return EXIT_SUCCESS;
    if (hf->ammos[i].version == 2)
            hf->ammos[i].version = 0;
    if (i < 0)
        return EXIT_FAILURE;
    sfSprite_setTextureRect(hf->ammos[i].sprite, (sfIntRect){ 4 *
        hf->ammos[i].version, 0, 4, 7 });
    return EXIT_SUCCESS;
}
