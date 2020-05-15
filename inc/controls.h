/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** controls
*/

#ifndef CONTROLS_H_
#define CONTROLS_H_

typedef struct ctrl_s{
    char *name;
    sfKeyCode base;
    sfKeyCode actual;
    struct ctrl_s *next;
}ctrl_t;

typedef struct type_controls_s{
    char *name;
    sfVector2f pos;
    struct ctrl_s *first;
    struct type_controls_s *next;
}type_controls_t;

typedef struct {
    type_controls_t *first;
}list_type_controls_t;


typedef struct {
    int load_controls;
    int scale_background;
    int tmp;
    list_type_controls_t *list_type;
}controls_t;

void create_setting_controls(global_data_t *data);
void controls_load(global_data_t *data);
void controls_event(global_data_t *data);
int get_controls_event(global_data_t *data, char *name);

void create_controls(global_data_t *data);
void create_type_controls(global_data_t *data);
void add_controls(global_data_t *data, char *name, char *node, sfKeyCode key);
void add_type_controls(global_data_t *data, char *name_node, char *name);
char *text_key_2(global_data_t *data, char *name_ctrl);
sfKeyCode get_controls(global_data_t *data, char *name);
void change_button(global_data_t *data, button_t *button);
sfKeyCode recup_key(global_data_t *data);
void reset_button(global_data_t *data, button_t *button);
void init_controls(global_data_t *data);
sfVector2f button_scale_text(global_data_t *data, char *name, char *text);
void controls_return_button(global_data_t *data, button_t *button);
void button_controls(global_data_t *data, char *name, char *node, type_controls_t *type);
ctrl_t *get_controls_name(global_data_t *data, char *name);
type_controls_t *get_controls_type(global_data_t *data, char *name);
void add_type_controls_struct(global_data_t *data, char *name_node);
void button_controls_reset(global_data_t *data, char *name, char *node, type_controls_t *type);

//test_key
char *test_key_left_click_g(sfKeyCode test);
char *test_key_h_p(sfKeyCode test);
char *test_key_q_z(sfKeyCode test);
char *test_key_0_8(sfKeyCode test);
char *test_key_9_alt(sfKeyCode test);
char *test_key_sys_slash(sfKeyCode test);
char *test_key_backslash_up(sfKeyCode test);
char *test_key_down_divide(sfKeyCode test);
char *test_key_gauche_4(sfKeyCode test);
char *test_key_5_f4(sfKeyCode test);
#endif