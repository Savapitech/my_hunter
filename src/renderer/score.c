/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"
#include <SFML/Graphics.h>

int draw_score(hunterinfo_t *hf)
{
    hf->score_text.font = sfFont_createFromFile("assets/Jersey25-Regular.ttf");
    if (!hf->score_text.font)
        return EXIT_FAILURE;
    hf->score_text.text = sfText_create();
    sfText_setString(hf->score_text.text, "0");
    sfText_setFont(hf->score_text.text, hf->score_text.font);
    sfText_setCharacterSize(hf->score_text.text, 50);
    sfText_setPosition(hf->score_text.text, (sfVector2f){ 10, 0 });
    return EXIT_SUCCESS;
}

int inc_score(hunterinfo_t *hf)
{
    char score[10];

    if (hf->score_text.text == NULL)
        return EXIT_FAILURE;
    my_numstr(score, hf->score);
    sfText_setString(hf->score_text.text, score);
    return EXIT_SUCCESS;
}
