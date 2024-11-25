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
    hf->clock.clock = sfClock_create();
    if (hf->clock.clock == NULL)
        return EXIT_FAILURE;
    hf->clock2.clock = sfClock_create();
    if (hf->clock2.clock == NULL)
        return EXIT_FAILURE;
    hf->clock3.clock = sfClock_create();
    if (hf->clock3.clock == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
