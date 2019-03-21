/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** volume_bar
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "proto/proto.h"
#include "struct/volume_bar.h"

int volume_bar_free(volume_bar_t *vol_bar)
{
    sfRectangleShape_destroy(vol_bar->rect);
    sfRectangleShape_destroy(vol_bar->rect_ori);
    return (vol_bar->volume);
}

volume_bar_t *volume_bar_init(sfVector2f pos, sfVector2f size, int volume)
{
    volume_bar_t *strct = malloc(sizeof(volume_bar_t));

    strct->rect = sfRectangleShape_create();
    strct->rect_ori = sfRectangleShape_create();
    sfRectangleShape_setPosition(strct->rect_ori, pos);
    sfRectangleShape_setSize(strct->rect_ori, size);
    sfRectangleShape_setFillColor(strct->rect_ori, sfTransparent);
    sfRectangleShape_setOutlineColor(strct->rect_ori, sfWhite);
    sfRectangleShape_setOutlineThickness(strct->rect_ori, 5);
    sfRectangleShape_setPosition(strct->rect, pos);
    sfRectangleShape_setFillColor(strct->rect, create_color(200, 200
    , 200, 200));
    sfRectangleShape_setSize(strct->rect, create_vect((size.x / 100 * volume)
    , size.y));
    strct->volume = volume;
    strct->onclick = sfFalse;
    return (strct);
}

void volume_bar_move(volume_bar_t *vol_bar, sfVector2i orig_mouse)
{
    sfVector2f pos = sfRectangleShape_getPosition(vol_bar->rect_ori);
    sfVector2f size = sfRectangleShape_getSize(vol_bar->rect_ori);

    if (orig_mouse.x < pos.x) {
        sfRectangleShape_setSize(vol_bar->rect, create_vect(0, size.y));
        vol_bar->volume = 100;
    } else if (orig_mouse.x > pos.x + size.x) {
        sfRectangleShape_setSize(vol_bar->rect, size);
        vol_bar->volume = 100;
    } else {
        sfRectangleShape_setSize(vol_bar->rect, create_vect(orig_mouse.x - pos.x
        , size.y));
        vol_bar->volume =  100 - (size.x -
        (orig_mouse.x - pos.x)) / (size.x / 100);
    }
}

void volume_bar_active(volume_bar_t *vol_bar, sfRenderWindow *window)
{
    sfFloatRect button_vect =
    sfRectangleShape_getGlobalBounds(vol_bar->rect_ori);
    sfVector2i orig_mouse = sfMouse_getPositionRenderWindow(window);

    if (vol_bar->onclick == sfFalse && sfMouse_isButtonPressed
    (sfMouseLeft) == sfTrue && sfFloatRect_contains(&button_vect, orig_mouse.x
    , orig_mouse.y) == sfTrue) {
        vol_bar->onclick = sfTrue;
        sfRectangleShape_setFillColor(vol_bar->rect, sfWhite);
    } else if (vol_bar->onclick == sfTrue && sfMouse_isButtonPressed
    (sfMouseLeft) == sfFalse) {
        vol_bar->onclick = sfFalse;
        sfRectangleShape_setFillColor(vol_bar->rect, create_color(200, 200
        , 200, 200));
    }
    if (vol_bar->onclick == sfTrue)
        volume_bar_move(vol_bar, orig_mouse);
    sfRenderWindow_drawRectangleShape(window, vol_bar->rect_ori, NULL);
    sfRenderWindow_drawRectangleShape(window, vol_bar->rect, NULL);
}