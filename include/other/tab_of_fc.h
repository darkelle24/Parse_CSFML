/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tab_of_fc
*/

#ifndef TAB_OF_FC_H_
    #define TAB_OF_FC_H_
    #include "struct/scene.h"
    #include "proto/proto.h"

    const char *Class_name[] = {
        "G",
        "B",
        "M",
        "S",
        "T",
        NULL
    };

    void (* const Command[])(scene_s *, char *) = {
        &scene_object,
        &scene_button,
        &scene_music,
        &scene_sound,
        &scene_text
    };

#endif /* !TAB_OF_FC_H_ */
