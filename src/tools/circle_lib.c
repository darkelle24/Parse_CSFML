/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** circle_lib
*/

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/CircleShape.h>
#include "proto/lib.h"

sfCircleShape *create_circle(sfVector2f pos, float rad, float th, sfColor col)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOrigin(circle, create_vect(rad, rad));
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, rad);
    sfCircleShape_setOutlineThickness(circle, th);
    sfCircleShape_setOutlineColor(circle, col);
    sfCircleShape_setFillColor(circle, create_color(0, 0, 0, 0));
    return (circle);
}