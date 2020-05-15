/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls_gest
*/

#include "rpg.h"


type_controls_t *get_controls_type(global_data_t *data, char *name)
{
    type_controls_t *type = data->controls->list_type->first;

    while (type != NULL && cmp_string(type->name, name) != 0) {
        type = type->next;
    }
    return (type);
}

ctrl_t *get_controls_event_ctrl(global_data_t *data, \
char *name, ctrl_t *ctrl, ctrl_t *ctrl_actual)
{
    (void)data;
    if (ctrl->name != NULL && cmp_string(ctrl->name, name) == 0)
        ctrl_actual = ctrl;
    return (ctrl_actual);
}

ctrl_t *get_controls_name(global_data_t *data, char *name)
{
    type_controls_t *type = data->controls->list_type->first;
    ctrl_t *ctrl = NULL;
    ctrl_t *ctrl_actual;


    while (type) {
        while (ctrl) {
            ctrl_actual = get_controls_event_ctrl\
(data, name, ctrl, ctrl_actual);
            ctrl = ctrl->next;
        }
        ctrl = type->first;
        type = type->next;
    }
    if (cmp_string(ctrl_actual->name, name) != 0) {
        return (0);
    }
    return (ctrl_actual);
}

sfKeyCode get_controls(global_data_t *data, char *name)
{
    type_controls_t *type = data->controls->list_type->first;
    ctrl_t *ctrl = NULL;
    ctrl_t *ctrl_actual;


    while (type) {
        while (ctrl) {
            ctrl_actual = get_controls_event_ctrl\
(data, name, ctrl, ctrl_actual);
            ctrl = ctrl->next;
        }
        ctrl = type->first;
        type = type->next;
    }
    if (cmp_string(ctrl_actual->name, name) != 0) {
        return (0);
    }
    return (ctrl_actual->actual);
}

int get_controls_event(global_data_t *data, char *name)
{
    type_controls_t *type = data->controls->list_type->first;
    ctrl_t *ctrl = NULL;
    ctrl_t *ctrl_actual;

    while (type) {
        while (ctrl) {
            ctrl_actual = get_controls_event_ctrl\
(data, name, ctrl, ctrl_actual);
            ctrl = ctrl->next;
        }
        ctrl = type->first;
        type = type->next;
    }
    if (cmp_string(ctrl_actual->name, name) != 0)
        return (0);
    if (sfKeyboard_isKeyPressed(ctrl_actual->actual))
        return (1);
    if ((sfMouse_isButtonPressed(sfMouseLeft) && ctrl_actual->actual == -2) || \
(sfMouse_isButtonPressed(sfMouseRight) && ctrl_actual->actual == -3))
        return (1);
    return (0);
}