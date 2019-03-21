/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scene_text
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "struct/text.h"
#include "struct/scene.h"
#include "list/macro.h"
#include "proto/proto.h"

sfColor color_recup(char *phrase, char *to_find)
{
    int pos = strfind(phrase, to_find);

    if (pos != -1)
        return (recup_color(phrase, pos));
    else
        return (create_color(0, 0, 0, 0));
}

char *str_recup(char *phrase, char *to_find)
{
    int pos = strfind(phrase, to_find);

    if (pos != -1)
        return (recup_str(phrase, pos, '\"'));
    else
        return (NULL);
}

void scene_text(scene_s *scene, char *phrase)
{
    text_t *text = malloc(sizeof(text_t));
    char *path = path_recup(phrase);
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfColor color = color_recup(phrase, "Color=");
    int id = find_nbr(phrase, "ID=");
    int disp = find_nbr(phrase, "Disp=");
    int size = find_nbr(phrase, "Sizechar=");

    text->str = str_recup(phrase, "Str=");
    text_init(text, position, disp, id);
    sfText_setColor(text->text, color);
    sfText_setCharacterSize(text->text, size);
    if (text->str != NULL)
        sfText_setString(text->text, text->str);
    if (path != NULL) {
        text->font = sfFont_createFromFile(path);
        sfText_setFont(text->text, text->font);
    }
    text_list_add(scene->list_text, text);
}
