/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"

int display_game_over(hunterinfo_t *hf)
{
    sfFont *font = sfFont_createFromFile("assets/Jersey25-Regular.ttf");
    sfText *text;
    char score[10];
    char high_score[10];
    char *str = "GAME OVER\nScore: ";

    if (!font)
        return EXIT_FAILURE;
    text = sfText_create();
    my_numstr(score, hf->score);
    str = my_strcat(str, score);
    str = my_strcat(str, "\nHigh: ");
    my_numstr(high_score, hf->high_score);
    str = my_strcat(str, high_score);
    sfText_setString(text, str);
    sfText_setColor(text, (sfColor){ 30, 30, 30, 255 });
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, (sfVector2f){ 740, 300 });
    return (sfRenderWindow_drawText(hf->window, text, NULL), EXIT_SUCCESS);
}
