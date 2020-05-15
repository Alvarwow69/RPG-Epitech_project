/*
** EPITECH PROJECT, 2020
** gameobject_utils.c
** File description:
** 
*/

#include "rpg.h"

static void set_other_type(global_data_t *data, game_object_t *gameobject)
{
    switch (gameobject->type) {
    case TYPE_BLOC:
        gameobject->object.bloc = init_bloc_struct();
        break;
    default:
        break;
    }
}

void define_type(global_data_t *gdata, game_object_t *gameobject)
{
    switch (gameobject->type) {
    case TYPE_IMAGE:
        gameobject->object.sprite = sfSprite_create();
        break;
    case TYPE_BUTTON:
        gameobject->object.button = init_button_struct();
        break;
    case TYPE_BACKGROUND:
        gameobject->object.sprite = sfSprite_create();
        break;
    case TYPE_PLAYER:
        gameobject->object.player = init_player(gdata);
        break;
    case TYPE_TEXT:
        gameobject->object.text = init_text_struct(gameobject);
        break;
    default:
        set_other_type(gdata, gameobject);
    }
}