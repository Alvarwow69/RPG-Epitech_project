/*
** EPITECH PROJECT, 2020
** button_other_action.c
** File description:
** 
*/

#include "rpg.h"

void editor_b_background(global_data_t *data, button_t *button)
{
    (void)button;
    if (data->background) {
        data->background = 0;
        button_set_text(data, "editor_b_background", "Change to background",
        data->ressources->fonts[FONT_MAIN]);
    } else {
        data->background = 1;
        button_set_text(data, "editor_b_background", "Change to level",
        data->ressources->fonts[FONT_MAIN]);
    }
}

void create_hide_button(global_data_t *data)
{
    button_create(data, "editor_hide", "selection_editor",
    data->ressources->textures[BUTTON]);
    button_set_other_texture(data, "editor_hide",
    data->ressources->textures[BUTTON_HOVER],
    data->ressources->textures[BUTTON_PRESS]);
    button_set_text(data, "editor_hide", "Hide",
    data->ressources->fonts[FONT_MAIN]);
    button_set_position(data, "editor_hide", (sfVector2f){1850, 100});
    button_set_text_pos(data, "editor_hide", (sfVector2f){5, 20});
    button_set_text_scale(data, "editor_hide", 15);
    button_set_action(data, "editor_hide", &editor_hide);
    button_set_scale(data, "editor_hide", (sfVector2f){1.5f, 1.5f});
}

void editor_selector_action(global_data_t *data, button_t *button)
{
    char *name = NULL;
    float line = 0;
    float col = 0;

    for (int i = 1; i < TM_END; i++) {
        name = concat_fstring("block-%i", i);
        button_create(data, name, "selection_editor",
        data->ressources->textures[TEXTURE_TILE_MAP]);
        button_set_position(data, name,
        (sfVector2f){50 *col + 1550, 50 *line + 200});
        button_set_action(data, name, &editor_change_bloc);
        button_set_tex_rect(data, name, tile_map[i].rect);
        col += 1;
        if (col == 7) {
            col = 0;
            line += 1;
        }
        free(name);
    }
    gameobject_destroy(data, button->gameobject->name);
    create_hide_button(data);
}