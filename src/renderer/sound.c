/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"

int create_sounds(hunterinfo_t *hf)
{
    hf->shoot_sound = sfMusic_createFromFile("assets/shoot.wav");
    if (!hf->shoot_sound)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
