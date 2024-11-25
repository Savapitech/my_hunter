/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"

static
void print_usages(void)
{
    my_putstr("My_hunter is a litle game like duck hunt\n");
    my_putstr("Usage: ./my_hunter [-h]\nThe goal of the game is to shoot the");
    my_putstr(" ducks by clicking on them and try to achieve the highest");
    my_putstr(" score.\n");
}

int main(int ac, char **av)
{
    if (ac > 1)
        if (!my_strcmp(av[1], "-h"))
            return (print_usages(), EXIT_SUCCESS);
    hunter();
}
