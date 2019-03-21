/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** volume_bar
*/

#ifndef VOLUME_BAR_H_
    #define VOLUME_BAR_H_

    #include <SFML/Graphics.h>

    typedef struct volume_bar_s
    {
        sfRectangleShape *rect;
        sfBool onclick;
        int volume;
        sfRectangleShape *rect_ori;
    }     volume_bar_t;

#endif /* !VOLUME_BAR_H_ */
