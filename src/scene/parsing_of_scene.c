/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** parsing_of_scene
*/

#include <stdio.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "list/tab_of_fc.h"
#include "struct/text.h"
#include "struct/scene.h"
#include "proto/proto.h"
#include "proto/lib.h"

void desactive(button_t *button, void *color)
{
    sfColor collor = *(sfColor *)color;

    if (button->pass == 1) {
        button_desactivate(button, collor);
        button->to_send_click = (void *) &sfRed;
    } else if (button->pass == 2) {
        button_activate(button, collor);
        button->to_send_click = (void *) &sfWhite;
    }
}

sfColor recup_color(char *phrase, int pos)
{
    char *strr = recup_str(phrase, pos, ',');
    char *strb = recup_str(phrase
    , pos + my_strlenchar(strr, '\0') + 1, ',');
    char *strg = recup_str(phrase
    , pos + my_strlenchar(strr, '\0')
    + my_strlenchar(strb, '\0') + 2, ',');
    char *stra = recup_str(phrase
    , pos + my_strlenchar(strr, '\0')
    + my_strlenchar(strb, '\0') + my_strlenchar(strg, '\0') + 3, ')');
    sfColor color = create_color(getnbr(strr), getnbr(strb), getnbr(strg),
    getnbr(stra));

    free(strr);
    free(strb);
    free(strg);
    free(stra);
    return (color);
}

int command_test(char *phrase, scene_s *scene)
{
    int count = 0;

    while (Class_name[count] != NULL) {
        if (Class_name[count][0] == phrase[0]) {
            Command[count](scene, phrase);
            return (1);
        }
        count++;
    }
    return (-1);
}

void init_scene(scene_s *scene)
{
    scene->list_but = create_button_list();
    scene->list_ob = create_game_list();
    scene->list_text = create_text_list();
    scene->list_music = create_music_list();
    scene->list_sound = create_sound_list();
    scene->order = create_display_list();
}

scene_s *load_scene(char *path)
{
    FILE *fp = fopen(path, "r");
    char *buff = NULL;
    size_t len = 0;
    scene_s *scene = malloc(sizeof(scene_s));

    if (fp == NULL)
        return (NULL);
    init_scene(scene);
    while (getline(&buff, &len, fp) != -1) {
        if (buff[0] != '#') {
            if (command_test(buff, scene) == -1)
                return NULL;
        }
        free(buff);
        buff = NULL;
    }
    fclose(fp);
    scene->general = sfClock_create();
    return (scene);
}