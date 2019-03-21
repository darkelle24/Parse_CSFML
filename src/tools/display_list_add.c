/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** display_list_add
*/

#include <stdlib.h>
#include "struct/scene.h"
#include "struct/button.h"

void init_display_list(display_order *list, button_t *button
, game_object *object, int prio)
{
    list->object = object;
    list->priority = prio;
    list->button = button;
}

void display_list_add_object(display_order **list, game_object *object
, int prio)
{
    display_order *save;
    display_order *backup = *list;

    if ((*list)->priority == -1) {
        init_display_list((*list), NULL, object, prio);
    } else if ((*list)->priority <= prio) {
        save = malloc(sizeof(display_order));
        save->next = *list;
        init_display_list((*list), NULL, object, prio);
        *list = save;
    } else {
        while ((*list)->next != NULL && (*list)->next->priority >= prio)
            *list = (*list)->next;
        save = (*list)->next;
        (*list)->next = malloc(sizeof(display_order));
        (*list)->next->next = save;
        init_display_list((*list)->next, NULL, object, prio);
        *list = backup;
    }
}

void display_list_add_button(display_order **list, button_t *button, int prio)
{
    display_order *save;
    display_order *backup = *list;

    if ((*list)->priority == -1) {
        init_display_list(*list, button, NULL, prio);
    } else if ((*list)->priority <= prio) {
        save = malloc(sizeof(display_order));
        save->next = *list;
        init_display_list(save, button, NULL, prio);
        *list = save;
    } else {
        while ((*list)->next != NULL && (*list)->next->priority >= prio)
            *list = (*list)->next;
        save = (*list)->next;
        (*list)->next = malloc(sizeof(display_order));
        (*list)->next->next = save;
        init_display_list((*list)->next, button, NULL, prio);
        *list = backup;
    }
}