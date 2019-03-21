/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** fc_for_button
*/

#ifndef FC_FOR_BUTTON_H_
    #define FC_FOR_BUTTON_H_
    #include <stddef.h>
    #include "struct/button.h"
    #include "proto/proto.h"

    const char *fc_name[] = {
        "NULL",
        NULL
    };

    void (* const fonction[])(button_t *, void *) = {
        NULL
    };

#endif /* !FC_FOR_BUTTON_H_ */