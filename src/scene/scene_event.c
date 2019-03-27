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
        button_list_is_hover(scene, scene->list_but, window);
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft)
        button_list_is_pressed(scene->list_but, window);
    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft)
        button_list_is_clicked(scene->list_but, window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code != sfKeyReturn) {
            button_move_with_button(event, scene, window);
        } else if (event.type == sfEvtKeyPressed
        && event.key.code == sfKeyReturn && scene->but_with_keyboard != NULL) {
            scene->but_with_keyboard->callback_click_release
            (scene->but_with_keyboard, scene->but_with_keyboard->to_send_click);
            scene->but_with_keyboard->callback_hover
            (scene->but_with_keyboard, scene->but_with_keyboard->to_send_click);
        }
    }
    if (event.type == sfEvtTextEntered)
        text_bar_write(event, scene);
}