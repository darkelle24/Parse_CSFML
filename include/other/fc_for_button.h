/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** fc_for_button
*/

#ifndef FC_FOR_BUTTON_H_
    #define FC_FOR_BUTTON_H_
    #include <stddef.h>
    #include "struct/button.h"
    #include "proto/proto.h"

void fc_hover(button_t *but, void *lol);
void fc_hover_exit(button_t *but, void *lol);
void print(button_t *boutton, void *lol);
void fc_click_press(button_t *but, void *lol);

    const char *fc_name[] = {
        "hover",
        "hover_exit",
        "print",
        "press",
        "NULL",
        NULL
    };

    void (* const fonction[])(button_t *, void *) = {
        &fc_hover,
        &fc_hover_exit,
        &print,
        &fc_click_press,
        NULL
    };

#endif /* !FC_FOR_BUTTON_H_ */