/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** scene_event
*/

#include <SFML/Graphics.h>
#include "struct/scene.h"
#include "proto/proto.h"

void event_for_button(sfEvent event, scene_t *scene, sfRenderWindow *window)
{
    if (event.type == sfEvtMouseMoved)
        button_list_is_hover(scene->list_but, window);
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft)
        button_list_is_pressed(scene->list_but, window);
    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft)
        button_list_is_clicked(scene->list_but, window);
}