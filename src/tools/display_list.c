/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** display_list
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include "struct/scene.h"

void remove_display_object(display_order *list, game_object *object)
{
    display_order *save;

    while (list != NULL && list->next->object != object)
        list = list->next;
    if (list != NULL) {
        list->next->object = NULL;
        save = list->next;
        list->next = list->next->next;
        free(save);
    }
}

display_order *create_display_list(void)
{
    display_order *list = malloc(sizeof(display_order));

    if (list == NULL)
        return (NULL);
    list->object = NULL;
    list->button = NULL;
    list->priority = -1;
    list->next = NULL;
    return (list);
}

int count_order_list(display_order *list)
{
    int i = 0;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}

void display_list_display(sfRenderWindow *window, display_order *list)
{
    while (list != NULL) {
        if (list->object != NULL) {
            if (list->object->affiche > 0)
                sfRenderWindow_drawSprite(window
                , list->object->Sprite, NULL);
        } else if (list->button != NULL) {
            if (list->button->pass != 3
            && list->button->pass != 4) {
                sfRenderWindow_drawRectangleShape(window
                , list->button->rect, NULL);
            }
        }
        list = list->next;
    }
}