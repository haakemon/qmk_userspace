/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

// clang-format off
enum layers {
    _BASE,
    _NAV,
    _NUM,
    _SYM,
    _F
};
// clang-format on

// https://fsymbols.com/text-art/

// ░█████╗░░█████╗░███╗░░░███╗██████╗░░█████╗░░██████╗
// ██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔══██╗██╔════╝
// ██║░░╚═╝██║░░██║██╔████╔██║██████╦╝██║░░██║╚█████╗░
// ██║░░██╗██║░░██║██║╚██╔╝██║██╔══██╗██║░░██║░╚═══██╗
// ╚█████╔╝╚█████╔╝██║░╚═╝░██║██████╦╝╚█████╔╝██████╔╝
// ░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚═════╝░░╚════╝░╚═════╝░
const uint16_t PROGMEM combo_backslash[]   = {KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM combo_slash[]       = {KC_H, KC_U, COMBO_END};
const uint16_t PROGMEM combo_pipe_l[]      = {KC_G, KC_T, COMBO_END};
const uint16_t PROGMEM combo_pipe_r[]      = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_eql[]         = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_dash[]        = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_underscore[]  = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM combo_doublequote[] = {NO_QUOT, NO_GRV, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_backslash, NO_BSLS), COMBO(combo_slash, NO_SLSH), COMBO(combo_pipe_l, NO_PIPE), COMBO(combo_pipe_r, NO_PIPE), COMBO(combo_eql, NO_EQL), COMBO(combo_dash, NO_MINS), COMBO(combo_underscore, NO_UNDS), COMBO(combo_doublequote, NO_DQUO),
};
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// ███╗░░░███╗░█████╗░██████╗░  ████████╗░█████╗░██████╗░
// ████╗░████║██╔══██╗██╔══██╗  ╚══██╔══╝██╔══██╗██╔══██╗
// ██╔████╔██║██║░░██║██║░░██║  ░░░██║░░░███████║██████╔╝
// ██║╚██╔╝██║██║░░██║██║░░██║  ░░░██║░░░██╔══██║██╔═══╝░
// ██║░╚═╝░██║╚█████╔╝██████╔╝  ░░░██║░░░██║░░██║██║░░░░░
// ╚═╝░░░░░╚═╝░╚════╝░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░
// https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
#define XX_CUT LT(0, KC_X)
#define C_COPY LT(0, KC_C)
#define V_PASTE LT(0, KC_V)
#define ESC_F20 LT(0, KC_ESC)

static bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false; // Skip default handling.
    }

    return true; // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case XX_CUT:
            return process_tap_or_long_press_key(record, C(KC_X));

        case C_COPY:
            return process_tap_or_long_press_key(record, C(KC_INS));

        case V_PASTE:
            return process_tap_or_long_press_key(record, S(KC_INS));

        case ESC_F20:
            return process_tap_or_long_press_key(record, KC_F20);
    }

    return true; // Continue default handling.
}
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// ██████╗░░██████╗░██████╗░
// ██╔══██╗██╔════╝░██╔══██╗
// ██████╔╝██║░░██╗░██████╦╝
// ██╔══██╗██║░░╚██╗██╔══██╗
// ██║░░██║╚██████╔╝██████╦╝
// ╚═╝░░╚═╝░╚═════╝░╚═════╝░
#ifdef RGB_MATRIX_ENABLE

int get_led_index(int x, int y) {
    // clang-format off
    int grid[8][7] = {
        // left side - left-to-right
        {18, 17, 12, 11, 4, 3, 21},
        {19, 16, 13, 10, 5, 2, 22},
        {20, 15, 14, 9, 6, 1},
                         {8, 7, 0},

        // right side - right-to-left
        {41, 40, 35, 34, 27, 26, 44},
        {42, 39, 36, 33, 28, 25, 45},
            {43, 38, 37, 32, 29, 24},
        {31, 30, 23}
    };
    // clang-format on

    if (x < 0 || x >= 8) {
        return -1;
    }
    if (y < 0 || y >= sizeof(grid[x]) / sizeof(grid[x][0])) {
        return -1;
    }

    return grid[x][y];
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    // ESC key red if Caps Lock is on
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(get_led_index(0, 0), 255, 0, 0);
    }

    if (layer_state_is(_NAV)) {
        rgb_matrix_set_color(get_led_index(4, 3), 255, 0, 0);
        rgb_matrix_set_color(get_led_index(5, 2), 255, 0, 0);
        rgb_matrix_set_color(get_led_index(5, 3), 255, 0, 0);
        rgb_matrix_set_color(get_led_index(5, 4), 255, 0, 0);
        rgb_matrix_set_color(get_led_index(6, 2), 255, 0, 0);
        rgb_matrix_set_color(get_led_index(6, 4), 255, 0, 0);
    }

    return true;

}
#endif
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// clang-format off
// ██╗░░██╗███████╗██╗░░░██╗███╗░░░███╗░█████╗░██████╗░░██████╗
// ██║░██╔╝██╔════╝╚██╗░██╔╝████╗░████║██╔══██╗██╔══██╗██╔════╝
// █████═╝░█████╗░░░╚████╔╝░██╔████╔██║███████║██████╔╝╚█████╗░
// ██╔═██╗░██╔══╝░░░░╚██╔╝░░██║╚██╔╝██║██╔══██║██╔═══╝░░╚═══██╗
// ██║░╚██╗███████╗░░░██║░░░██║░╚═╝░██║██║░░██║██║░░░░░██████╔╝
// ╚═╝░░╚═╝╚══════╝░░░╚═╝░░░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░░░░╚═════╝░
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    *  You can use _______ in place for KC_TRNS (transparent)   *
    *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define LGUI_A LGUI_T(KC_A)
#define LALT_S LALT_T(KC_S)
#define LSHT_D LSFT_T(KC_D)
#define LCTL_F LCTL_T(KC_F)

#define RCTL_J RCTL_T(KC_J)
#define RSFT_K RSFT_T(KC_K)
#define RALT_L RALT_T(KC_L)
#define RGUI_Ø RGUI_T(NO_OSTR)

#define PREV_TAB LCTL(LSFT(KC_TAB))
#define NEXT_TAB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      ESC_F20,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, NO_QUOT,     NO_GRV,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  NO_ARNG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,  LGUI_A,  LALT_S,  LSHT_D,  LCTL_F,    KC_G, XXXXXXX,    XXXXXXX,    KC_H,  RCTL_J,  RSFT_K,  RALT_L,  RGUI_Ø,   NO_AE,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     MO(_NUM),    KC_Z,  XX_CUT,  C_COPY, V_PASTE,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, NO_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_DEL,  KC_SPC, KC_BSPC,     KC_ENT,MO(_NAV), MO(_SYM)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLU,    XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, KC_VOLD,    XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,                      XXXXXXX,PREV_TAB, XXXXXXX,NEXT_TAB, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______,    NO_1,    NO_2,    NO_3,    NO_4,    NO_5, XXXXXXX,    XXXXXXX,    NO_6,    NO_7,    NO_8,    NO_9, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,    NO_4,    NO_5,    NO_6, KC_PAST, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         NO_0,    NO_1,    NO_2,    NO_3, KC_PERC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, NO_EXLM,   NO_AT, NO_HASH,  NO_DLR, NO_AMPR, XXXXXXX,    XXXXXXX, NO_LPRN, NO_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, NO_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, NO_LBRC, NO_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      NO_LCBR, NO_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_F] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  )

//   [_X] = LAYOUT_split_3x6_3_ex2(
//   //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
//                                           XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
//                                       //`--------------------------'  `--------------------------'
//   )
};
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// clang-format on
