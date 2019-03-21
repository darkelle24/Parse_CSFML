/*
** EPITECH PROJECT, 2019
** lib
** File description:
** constains all things in lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>

    int my_strlen(char *str);
    void my_putstr(char *str);
    int getnbr(char *buff);
    int my_put_nbr(long long nb);
    sfVector2f create_vect(float x, float y);
    sfColor create_color(int red, int blue, int green, int alpha);
    sfIntRect create_rect(int top, int left, int width, int height);
    sfFloatRect create_frect(float top, float left, float width, float height);
#endif
