/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** scene_other_1
*/

#include <SFML/Graphics.h>
#include <malloc.h>
#include "struct/scene.h"
#include "struct/progress_bar.h"
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

void scene_progress_bar_2(progress_bar_t *pro, char *phrase)
{
    int mini_bar = find_nbr(phrase, "MB=");
    int size = find_nbr(phrase, "SizeMB=");
    sfColor color = color_recup(phrase, "Color_MB=");

    progress_bar_mini_bar(pro, mini_bar, color, size);
}

void scene_progress_bar(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color = color_recup(phrase, "Color=");
    sfColor color_miss = color_recup(phrase, "Color_Miss=");
    sfColor color_out = color_recup(phrase, "Color_Out=");
    int outlinethick = find_nbr(phrase, "Size_Out=");
    int pourc = find_nbr(phrase, "Pour=");
    int prio = find_nbr(phrase, "Prio=");
    int disp = find_nbr(phrase, "Disp=");
    int id = find_nbr(phrase, "ID=");
    progress_bar_t *pro = progress_bar_init(position, size, pourc);
    other_t *other = other_list_add(&scene->other, (void *) pro, 'P', id);

    scene_progress_bar_2(pro, phrase);
    other->disp = disp;
    sfRectangleShape_setOutlineColor(pro->rect_ori, color_out);
    sfRectangleShape_setOutlineThickness(pro->rect_ori, outlinethick);
    sfRectangleShape_setFillColor(pro->rect, color);
    sfRectangleShape_setFillColor(pro->rect_ori, color_miss);
    display_list_add_other(&scene->order, other, prio);
}

void scene_rectangle(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color = color_recup(phrase, "Color=");
    sfColor color_out = color_recup(phrase, "Color_Out=");
    int outlinethick = find_nbr(phrase, "Size_Out=");
    int prio = find_nbr(phrase, "Prio=");
    int disp = find_nbr(phrase, "Disp=");
    int id = find_nbr(phrase, "ID=");
    char *path = path_recup(phrase);
    sfIntRect rect_text = rect_recup(phrase);
    sfRectangleShape *rect = create_rectangle(position, size, color);
    rectangle_t *rect_strct = malloc(sizeof(rectangle_t));
    other_t *other;

    rect_strct->rect = rect;
    other = other_list_add(&scene->other, (void *) rect_strct, 'R', id);
    if (path != NULL) {
        rect_strct->text = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(rect, rect_strct->text, sfFalse);
        free(path);
    } else
        rect_strct->text = NULL;
    sfRectangleShape_setTextureRect(rect_strct->rect, rect_text);
    other->disp = disp;
    sfRectangleShape_setOutlineColor(rect_strct->rect, color_out);
    sfRectangleShape_setOutlineThickness(rect_strct->rect, outlinethick);
    display_list_add_other(&scene->order, other, prio);
}