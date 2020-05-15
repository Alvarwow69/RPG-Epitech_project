/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** keyboard
*/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

typedef struct
{
    bool a;
    bool b;
    bool c;
    bool d;
    bool e;
    bool f;
    bool g;
    bool h;
    bool i;
    bool j;
    bool k;
    bool l1;
    bool m;
    bool n;
    bool o1;
    bool p;
    bool q;
    bool r;
    bool s;
    bool t;
    bool u;
    bool v;
    bool w;
    bool x;
    bool y;
    bool z;
    bool num0;
    bool num1;
    bool num2;
    bool num3;
    bool num4;
    bool num5;
    bool num6;
    bool num7;
    bool num8;
    bool num9;
    bool esc;
    bool lctrl;
    bool lmaj;
    bool lalt;
    bool lsys;
    bool rctrl;
    bool rmaj;
    bool ralt;
    bool rsys;
    bool menu;
    bool lbracket;
    bool rbracket;
    bool semicolon;
    bool comma;
    bool period;
    bool quote;
    bool slash;
    bool bslash;
    bool tilde;
    bool equal;
    bool dash;
    bool space;
    bool kreturn;
    bool back;
    bool tab;
    bool pageup;
    bool pagedown;
    bool end;
    bool home;
    bool insert;
    bool del;
    bool add;
    bool sub;
    bool mult;
    bool div;
    bool left;
    bool up;
    bool right;
    bool down;
    bool pad_0;
    bool pad_1;
    bool pad_2;
    bool pad_3;
    bool pad_4;
    bool pad_5;
    bool pad_6;
    bool pad_7;
    bool pad_8;
    bool pad_9;
    bool f1;
    bool f2;
    bool f3;
    bool f4;
    bool f5;
    bool f6;
    bool f7;
    bool f8;
    bool f9;
    bool f10;
    bool f11;
    bool f12;
    bool f13;
    bool f14;
    bool f15;
    bool pause;
    bool count;
    bool right_click;
    bool left_click;
    bool scroll_up;
    bool scroll_down;
    int mouse_wheel;
}keyboard_t;

//suppr
void disp_keyboard(global_data_t *data);


void event_keyboard(sfEvent event, global_data_t *data);

void key_pressed_a_j(sfEvent event, global_data_t *data);
void key_pressed_k_t(sfEvent event, global_data_t *data);
void key_pressed_u_num3(sfEvent event, global_data_t *data);
void key_pressed_num4_lalt(sfEvent event, global_data_t *data);
void key_pressed_lsystem_comma(sfEvent event, global_data_t *data);

void key_pressed_period_back(sfEvent event, global_data_t *data);
void key_pressed_tab_mult(sfEvent event, global_data_t *data);
void key_pressed_div_pad4(sfEvent event, global_data_t *data);
void key_pressed_pad5_f5(sfEvent event, global_data_t *data);
void key_pressed_f6_f15(sfEvent event, global_data_t *data);

void key_released_a_j(sfEvent event, global_data_t *data);
void key_released_k_t(sfEvent event, global_data_t *data);
void key_released_u_num3(sfEvent event, global_data_t *data);
void key_released_num4_lalt(sfEvent event, global_data_t *data);
void key_released_lsystem_comma(sfEvent event, global_data_t *data);

void key_released_period_back(sfEvent event, global_data_t *data);
void key_released_tab_mult(sfEvent event, global_data_t *data);
void key_released_div_pad4(sfEvent event, global_data_t *data);
void key_released_pad5_f5(sfEvent event, global_data_t *data);
void key_released_f6_f15(sfEvent event, global_data_t *data);

void init_keyboard_a_t(keyboard_t *new);
void init_keyboard_u_lalt(keyboard_t *new);
void init_keyboard_lsys_back(keyboard_t *new);
void init_keyboard_tab_pad4(keyboard_t *new);
void init_keyboard_num5_f15(keyboard_t *new);




#endif
