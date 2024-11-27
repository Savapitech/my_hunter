/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"

static
void display_game_over2(hunterinfo_t *hf, char *str)
{
    sfText_setString(hf->game_over_text.text, str);
    sfText_setColor(hf->game_over_text.text, (sfColor){ 30, 30, 30, 255 });
    sfText_setFont(hf->game_over_text.text, hf->game_over_text.font);
    sfText_setCharacterSize(hf->game_over_text.text, 100);
    sfText_setPosition(hf->game_over_text.text, (sfVector2f){ 740, 300 });
}

int display_game_over(hunterinfo_t *hf)
{
    char score[10];
    char high_score[10];
    char *str = "GAME OVER\nScore: ";

    hf->game_over_text.font =
        sfFont_createFromFile("assets/Jersey25-Regular.ttf");
    if (!hf->game_over_text.font)
        return EXIT_FAILURE;
    hf->game_over_text.text = sfText_create();
    my_numstr(score, hf->score);
    str = my_strcat(str, score);
    str = my_strcat(str, "\nHigh: ");
    my_numstr(high_score, hf->high_score);
    str = my_strcat(str, high_score);
    display_game_over2(hf, str);
    return (sfRenderWindow_drawText(hf->window, hf->game_over_text.text, NULL),
        EXIT_SUCCESS);
}
