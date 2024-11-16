/*
** EPITECH PROJECT, 2024
** hunter
** File description:
** clock
*/

#include "hunter.h"
#include <SFML/Graphics.h>

int create_clock(hunterinfo_t *hf)
{
    hf->clock = sfClock_create();
    if (hf->clock == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
