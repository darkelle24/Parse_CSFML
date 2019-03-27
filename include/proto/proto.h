/*
** EPITECH PROJECT, 2019
** MUL_my_defender_20180
** File description:
** proto.h
*/

#ifndef PROTO_H_
    #define PROTO_H_

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Color.h>
#include "struct/button.h"
#include "struct/color.h"
#include "struct/game_object.h"
#include "struct/music_sound.h"
#include "struct/scene.h"
#include "struct/progress_bar.h"
#include "struct/text.h"
#include "struct/volume_bar.h"
#include "struct/geo_form.h"
#include "struct/text_bar.h"

    sfVector2f create_vect(float x, float y);
    text_bar_t *create_text_bar(int lenght_max, sfVector2f pos
    , int sizechar, sfFont *font);
    void text_bar_create_barre(text_bar_t *text, int size_longeur
    , sfColor color);
    void text_bar_free(void *text_void);
    void text_bar_write(sfEvent event, scene_t *scene);
    void display_text_bar(other_t *other, sfRenderWindow *window);
    other_t *other_list_add(other_t **list, void *other, char type, int id);
    void scene_text_bar(scene_t *scene, char *phrase);
    char *create_array(char *nb, int i);
    float calcul_lenght(sfVector2f pos_target, sfVector2f pos_circle);
    sfSound *sound_find(multi_sound *list_sound, int id);
    button_t *check_up(button_list_t *list, button_t *button
    , sfRenderWindow *window);
    void rectangle_display(other_t *other, sfRenderWindow *window);
    void rectangle_free(void *rectangle_void);
    void scene_rectangle(scene_t *scene, char *phrase);
    void progress_bar_change_value(progress_bar_t *pro_bar, float new_value);
    void progress_bar_free(void *pro_bar_void);
    void scene_progress_bar(scene_t *scene, char *phrase);
    void progress_bar_display(other_t *other, sfRenderWindow *window);
    void progress_bar_mini_bar(progress_bar_t *strct, int mini_bar
    , sfColor color, int size);
    button_t *check_down(button_list_t *list, button_t *button
    , sfRenderWindow *window);
    void volume_bar_free(void *vol_bar_void);
    text_list_t *create_text_list();
    void button_list_is_hover(scene_t *scene, button_list_t *button_list
    , sfRenderWindow *window);
    void other_free(other_t *list);
    progress_bar_t *progress_bar_init(sfVector2f pos
    , sfVector2f size, int pourc);
    void button_move_with_button(sfEvent event, scene_t *scene
    , sfRenderWindow *window);
    void scene_volume_bar(scene_t *scene, char *phrase);
    volume_bar_t *volume_bar_init(sfVector2f pos, sfVector2f size, int volume);
    void volume_bar_active(volume_bar_t *vol_bar, sfRenderWindow *window);
    int text_list_add(text_list_t *list, text_t *text);
    char *str_recup(char *phrase, char *to_find);
    int my_put_nbr(long long nb);
    void text_init(text_t *text, sfVector2f position, int disp, int id);
    int my_strlenchar(char *str, char arrest);
    void display_list_text(sfRenderWindow *window, text_list_t *list);
    void button_init(button_t *button, sfVector2f position
    , sfVector2f size, int id);
    void button_desactivate(button_t *button, sfColor color);
    void button_activate(button_t *button, sfColor color);
    void button_invisible(button_t *button);
    void button_invi_and_desac(button_t *button);
    void button_set_status(button_t *button, int pass, sfColor color);
    void button_set_callback_on_click(button_t *button
    , void (*to_callback)(button_t *, void *), void *a_envoyer);
    int button_is_clicked(button_t *button, sfVector2f click_position);
    void destroy_object(game_object *obj, int nb, sfTexture **texture);
    void sprite_rotate(sfSprite *to_rotate, sfVector2f pos
    , float angle_of_start);
    void button_list_is_clicked(button_list_t *button_list
    , sfRenderWindow *window);
    button_list_t *create_button_list();
    void button_list_free(button_list_t *list);
    void button_free(button_t *button);
    int button_list_add(button_list_t *list, button_t *button);
    void button_set_outline(button_t *button, float thickness, sfColor color);
    void button_list_draw(sfRenderWindow *window, button_list_t *list);
    sfColor degrade_color(colordegrade *coloradd, sfColor actuelle
    , sfText *text);
    int find_nbr(char *str, char *to_find);
    char *recup_str(char *phrase, int n, char arrest);
    sfVector2f recup_pos(char *phrase, int pos);
    game_object *game_object_copy(game_object *to_copy, int display);
    int button_list_remove(button_list_t *list, button_t *button, int nbr);
    game_object *create_object(const char *path_to_spritesheet,
    sfVector2f pos, sfIntRect rect, int type);
    sfIntRect create_rect(int top, int left, int width, int height);
    sfRenderWindow *create_windows(int width, int height, int bit, char *title);
    sfColor degrade_color_basse(colordegrade *coloradd, sfColor actuelle);
    sfColor degrade_color_haute(colordegrade *coloradd, sfColor actuelle);
    sfColor create_color(int r, int b, int g, int a);
    sfFloatRect create_frect(float top, float left, float width, float height);
    void sprite_rotate(sfSprite *to_rotate, sfVector2f pos
    , float angle_of_start);
    sfIntRect rect_recup(char *phrase);
    sfRectangleShape *create_rectangle(sfVector2f pos
    , sfVector2f size, sfColor col);
    sfCircleShape *create_circle(sfVector2f pos, float radius
    , float outline_thickness, sfColor color_outline);
    game_list *create_game_list();
    void scene_font(scene_t *scene, char *phrase);
    int strfind(char const *str, char const *to_find);
    void scene_object(scene_t *scene, char *phrase);
    void scene_music(scene_t *scene, char *phrase);
    void scene_button(scene_t *scene, char *phrase);
    void scene_text(scene_t *scene, char *phrase);
    scene_t *load_scene(char *path);
    game_object *game_object_find(game_list *list_ob, int id);
    button_t *button_find(button_list_t *list, int id);
    int game_list_add(game_list *list, game_object *object);
    sfColor recup_color(char *phrase, int pos);
    char *path_recup(char *phrase);
    multi_music *create_music_list();
    void event_for_button(sfEvent event, scene_t *scene
    , sfRenderWindow *window);
    int music_list_add(multi_music *list, sfMusic *music, int id);
    void display_list_add_button(display_order **list
    , button_t *button, int prio);
    void display_list_add_object(display_order **list
    , game_object *object, int prio);
    void display_list_add_text(display_order **list, text_t *text, int prio);
    void button_desactivate(button_t *button, sfColor color);
    void button_activate(button_t *button, sfColor color);
    display_order *create_display_list();
    void volume_bar_display(other_t *other, sfRenderWindow *window);
    display_order **my_rev_list(display_order **begin, int size);
    void display_list_display(sfRenderWindow *window, display_order *list);
    void game_list_free(game_list *list);
    void music_list_free(multi_music *list);
    void free_scene(scene_t *scene);
    void button_list_is_pressed(button_list_t *button_list
    , sfRenderWindow *window);
    void desactive_all_mode(button_list_t *list);
    void display_list_free(display_order *list);
    int button_list_remove_with_number(button_list_t *list, int number);
    int button_list_remove_with_button(button_list_t *list, button_t *button);
    sfIntRect recup_rect(char *phrase, int pos);
    multi_sound *create_sound_list();
    int sound_list_add(multi_sound *list, sfSound *sound
    , sfSoundBuffer *buffer, int id);
    void scene_sound(scene_t *scene, char *phrase);
    void sound_list_free(multi_sound *list);
    void remove_display_object(display_order *list, game_object *object);
    void game_list_remove(game_list *list, game_object *object);
    sfColor color_recup(char *phrase, char *to_find);
    void display_list_add_other(display_order **list, other_t *other, int prio);
    sfVector2f pos_object_recup_str(char *phrase, char *to_find);

#endif /* !PROTO_H_ */
