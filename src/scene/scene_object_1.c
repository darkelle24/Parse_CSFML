/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scene_object
*/

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct/scene.h"
#include "proto/proto.h"
#include "proto/lib.h"

char *path_recup(char *phrase)
{
    int pos = strfind(phrase, "Path=");

    if (pos != -1)
        return (recup_str(phrase, pos, '\"'));
    else
        return (NULL);
}

sfVector2f pos_object_recup(char *phrase)
{
    int pos = strfind(phrase, "Pos=");

    if (pos != -1)
        return (recup_pos(phrase, pos));
    else
        return (create_vect(0, 0));
}

sfIntRect rect_recup(char *phrase)
{
    int pos = strfind(phrase, "Rect=");

    if (pos != -1)
        return (recup_rect(phrase, pos));
    else
        return (create_rect(0, 0, 0, 0));
}

int find_nbr(char *str, char *to_find)
{
    int pos = strfind(str, to_find);
    int nbr = 0;
    char *temp;

    if (pos != -1) {
        temp = recup_str(str, pos - 1, ' ');
        nbr = getnbr(temp);
        free (temp);
    }
    return (nbr);
}

void scene_object(scene_s *scene, char *phrase)
{
    char *path = path_recup(phrase);
    sfVector2f pos_object = pos_object_recup(phrase);
    sfIntRect rect = rect_recup(phrase);
    int type = find_nbr(phrase, "Type=");
    int prio = find_nbr(phrase, "Prio=");
    int affiche = find_nbr(phrase, "Disp=");
    int s = find_nbr(phrase, "Scale=");
    game_object *o = create_object(path, pos_object, rect, type);

    if (o == NULL) {
        write(2, "Problem with a game object\n", 27);
        return;
    }
    if (s > 100) {
        sfSprite_setScale(o->Sprite, create_vect(s / 100, s / 100));
    } else if (s < 100)
        sfSprite_setScale(o->Sprite, create_vect(s / 100 + 0.4, s / 100 + 0.4));
    o->affiche = affiche;
    free(path);
    game_list_add(scene->list_ob, o);
    display_list_add_object(&scene->order, o, prio);
}