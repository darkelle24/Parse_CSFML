/*
** EPITECH PROJECT, 2019
** qd
** File description:
** qd
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_
    #include "struct/button.h"
    #include "struct/music_sound.h"
    #include "struct/text.h"

    typedef struct display_order_t
    {
        game_object *object;
        button_t *button;
        int priority;
        struct display_order_t *next;
    }       display_order;

    typedef struct scene_t
    {
        game_list *list_ob;
        button_list_t *list_but;
        multi_music *list_music;
        multi_sound *list_sound;
        text_list_t *list_text;
        display_order *order;
        sfClock *general;
    }       scene_s;



#endif /* !INCLUDE_H_ */
