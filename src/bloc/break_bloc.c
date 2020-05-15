/*
** EPITECH PROJECT, 2020
** break_bloc.c
** File description:
** 
*/

#include "rpg.h"

collide_shape_t *create_little_collision(global_data_t *data, char *name)
{
    collide_shape_t *cshape = collide_shape_create(data
    , concat_fstring("%s_target_collision", name)
    , name, CTYPE_BLOCK);

    collide_shape_add_point(cshape, (sfVector2f){10, 10});
    collide_shape_add_point(cshape, (sfVector2f){21, 10});
    collide_shape_add_point(cshape, (sfVector2f){21, 21});
    collide_shape_add_point(cshape, (sfVector2f){10, 21});
    return (cshape);
}

void define_destroyed_bloc(global_data_t *data, bloc_t *bloc, sfIntRect rect)
{
    if (bloc->destruction_level >= 20) {
        collide_shape_destroy(data, concat_fstring("%s_bloc_collision",
        bloc->gameobject->name));
        bloc->collide_shape = create_little_collision(data,
        bloc->gameobject->name);
        bloc->broken = 1;
        bloc->gravity = 1;
        texture_rect_percent(bloc->sprite, rect, 100, "top");
        bloc->move->vec.x = (rand() % 2) ? -0.5f : 0.5f;
        bloc->move->vec.y = 0;
        bloc->move->force = -7;
        bloc->move->total_time = 0;
        node_get(data, bloc->gameobject->node)->update = true;
        play_sound_reset(data, SOUND_DESTROY_BLOC);
    }
}

void break_block(global_data_t *data, game_object_t *gameobject,
char **list_name)
{
    sfTime time = sfClock_getElapsedTime(data->clock);
    bloc_t *bloc = gameobject->object.bloc;
    float seconds = (time.microseconds - bloc->time_break) / 1000000;
    sfIntRect rect = tile_map[get_number(list_name[3])].rect;

    if (seconds > 0.2) {
        bloc->time_break = time.microseconds;
        bloc->destruction_level += 1;
        define_destroyed_bloc(data, bloc, rect);
    }
}

int can_break(global_data_t *data, char **game_name, game_object_t *gameobject,
sfVector2f pos)
{
    sfVector2i gird_pos;
    game_object_t *player = gameobject_get(data, "player_go");
    weapon_t *weapon_i = player->object.player->inventory->wear->wearable;
    sfVector2f p_pos = gameobject_get_g_position(data, player);

    gird_pos = get_real_pos(data, pos, gameobject->node);
    return (get_number(game_name[1]) == gird_pos.x &&
    get_number(game_name[2]) == gird_pos.y &&
    gameobject->type == TYPE_BLOC && weapon_i &&
    !gameobject->object.bloc->broken && weapon_i->type == WT_PICKAXE
    && (float)weapon_i->cshape->max.left - p_pos.x < pos.x
    && (float)weapon_i->cshape->max.width + p_pos.x > pos.x
    && (float)weapon_i->cshape->max.top - p_pos.y < pos.y
    && (float)weapon_i->cshape->max.height + p_pos.y > pos.y);
}

void destroy_block(global_data_t *data, sfVector2f pos)
{
    game_object_t *player = gameobject_get(data, "player_go");
    game_object_t *first =
    get_chunk(data, player->object.player->body_collision);
    game_object_t *gameobject = first;
    char **game_name = NULL;

    while (gameobject && !cmp_string(gameobject->node, first->node)) {
        game_name = str_to_tab(gameobject->name, "-");
        if (can_break(data, game_name, gameobject, pos)) {
            gameobject->object.bloc->action = 1;
            break_block(data, gameobject, game_name);
            return;
        }
        gameobject = gameobject->next;
    }
}