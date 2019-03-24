/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** scene_other
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <malloc.h>
#include "struct/scene.h"
#include "proto/proto.h"

other_t *other_list_add(other_t **list, void *other, char type, int id)
{
    other_t *new = malloc(sizeof(other_t));

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    new->type = type;
    new->id = id;
    new->other = other;
    if (*list == NULL)
        *list = new;
    else
        (*list)->next = new;
    return (new);
}

void scene_volume_bar(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color_unact = color_recup(phrase, "Color_Unact=");
    sfColor color_act = color_recup(phrase, "Color_Act=");
    sfColor color_out = color_recup(phrase, "Color_Out=");
    int outlinethick = find_nbr(phrase, "Size_Out=");
    int volume = find_nbr(phrase, "Vol=");
    int prio = find_nbr(phrase, "Prio=");
    int disp = find_nbr(phrase, "Disp=");
    int id = find_nbr(phrase, "ID=");
    volume_bar_t *vol = volume_bar_init(position, size, volume);
    other_t *other = other_list_add(&scene->other, (void *) vol, 'V', id);

    other->disp = disp;
    vol->unactive = color_unact;
    sfRectangleShape_setOutlineColor(vol->rect_ori, color_out);
    sfRectangleShape_setOutlineThickness(vol->rect_ori, outlinethick);
    vol->active = color_act;
    sfRectangleShape_setFillColor(vol->rect, vol->unactive);
    display_list_add_other(&scene->order, other, prio);
}