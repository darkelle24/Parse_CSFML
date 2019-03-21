/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <SFML/Graphics.h>
    #include "game_object.h"

    typedef struct button_s button_t;

    struct button_s
    {
        sfRectangleShape *rect;
        int id;
        int pass;
        void (*callback_click)(button_t *, void *);
        void (*callback_hover)(button_t *, void *);
        void (*callback_hover_exit)(button_t *, void *);
        void *to_send_click;
        void *to_send_click2;
        game_object *on_button;
    };

    typedef struct button_list_s
    {
        button_t *button;
        struct button_list_s *next;
    }       button_list_t;

#endif /* !BUTTON_H_ */
