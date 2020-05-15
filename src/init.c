/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init
*/

#include "rpg.h"

objects_t *init_objects(void)
{
    objects_t *objects = malloc(sizeof(objects_t));

    objects->game_object = NULL;
    objects->node = NULL;
    objects->scene = NULL;
    objects->cshape_other = NULL;
    objects->cshape_block = NULL;
    return (objects);
}

loading_t *init_loader(global_data_t *data)
{
    loading_t *loading = malloc(sizeof(loading_t));

    loading->loaded = false;
    loading->lock = sfMutex_create();
    loading->sprite = sfSprite_create();
    loading->lilodon = sfSprite_create();
    loading->lilo_tex = sfTexture_createFromFile("rsc/lilodon.png", NULL);
    sfSprite_setTexture(loading->sprite, data->ressources->textures[TEXTURE_LOADING], sfTrue);
    sfSprite_setTexture(loading->lilodon, loading->lilo_tex, sfTrue);
    sfSprite_setTextureRect(loading->lilodon, (sfIntRect){0, 0, 73, 73});
    sfSprite_setOrigin(loading->lilodon, (sfVector2f){36, 36});
    sfSprite_setPosition(loading->lilodon, (sfVector2f){1800, 950});
    return (loading);
}

void init_default_value(global_data_t *gdata)
{
    gdata->window = sfRenderWindow_create((sfVideoMode)\
    {1920, 1080, 32}, "Test", sfDefaultStyle, NULL);
    gdata->save_render_window_size = (sfVector2u)
    {sfRenderWindow_getSize(gdata->window).x\
    , sfRenderWindow_getSize(gdata->window).y};
    gdata->objects = init_objects();
    gdata->ressources = init_ressources();
    gdata->default_view =
    (sfView *)sfRenderWindow_getDefaultView(gdata->window);
    gdata->active_scene = NULL;
    gdata->loading = init_loader(gdata);
    gdata->selected_block = 14;
    gdata->background = 0;
    gdata->remove_tile = 0;
    gdata->sound_volume = 50;
    gdata->music_volume = 50;
    gdata->clock = sfClock_create();
    gdata->controls_need_reload = 0;
}

global_data_t *init_gdata(void)
{
    global_data_t *gdata = malloc(sizeof(global_data_t));

    if (!gdata)
        return (NULL);
    init_default_value(gdata);
    create_travel_scene(gdata);
    create_scene(gdata);
    init_quest(gdata);
    init_controls(gdata);
    init_keyboard(gdata);
    init_travel(gdata);
    sound_change_all_volume(gdata);
    music_change_all_volume(gdata);
    gdata->prev_game =  scene_get(gdata, "map");
    return (gdata);
}
