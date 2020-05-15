/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard_pressed
*/

#include "rpg.h"

void key_release(sfEvent event, global_data_t *data)
{
    key_released_a_j(event, data);
    key_released_k_t(event, data);
    key_released_u_num3(event, data);
    key_released_num4_lalt(event, data);
    key_released_lsystem_comma(event, data);
    key_released_period_back(event, data);
    key_released_tab_mult(event, data);
    key_released_div_pad4(event, data);
    key_released_pad5_f5(event, data);
    key_released_f6_f15(event, data);
    if (event.key.code == sfKeyPause)
        data->key->pause = 0;
    if (event.key.code == sfKeyCount)
        data->key->count = 0;
}

void key_pressed(sfEvent event, global_data_t *data)
{
    key_pressed_a_j(event, data);
    key_pressed_k_t(event, data);
    key_pressed_u_num3(event, data);
    key_pressed_num4_lalt(event, data);
    key_pressed_lsystem_comma(event, data);
    key_pressed_period_back(event, data);
    key_pressed_tab_mult(event, data);
    key_pressed_div_pad4(event, data);
    key_pressed_pad5_f5(event, data);
    key_pressed_f6_f15(event, data);
    if (event.key.code == sfKeyPause)
        data->key->pause = 1;
    if (event.key.code == sfKeyCount)
        data->key->count = 1;
}

void event_keyboard2(sfEvent event, global_data_t *data)
{
    if (event.type == sfEvtKeyPressed){
        key_pressed(event, data);
    }
    if (event.type == sfEvtMouseButtonPressed){
        if (event.mouseButton.button == sfMouseRight)
            data->key->right_click = 1;
        if (event.mouseButton.button == sfMouseLeft)
            data->key->left_click = 1;
    }
}

void event_keyboard(sfEvent event, global_data_t *data)
{
    sfMouseWheelEvent mousewheel;
    if (event.type == sfEvtKeyReleased) {
        key_release(event, data);
    }
    if (event.type == sfEvtMouseButtonReleased){
        if (event.mouseButton.button == sfMouseRight)
            data->key->right_click = 0;
        if (event.mouseButton.button == sfMouseLeft)
            data->key->left_click = 0;
    }
    event_keyboard2(event, data);
    if (event.type == sfEvtMouseWheelMoved) {
        mousewheel = event.mouseWheel;
        data->key->mouse_wheel = mousewheel.delta;
    }
}

