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

// https://fsymbols.com/text-art/

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

// #region DEFS
// ██████╗░███████╗███████╗░██████╗
// ██╔══██╗██╔════╝██╔════╝██╔════╝
// ██║░░██║█████╗░░█████╗░░╚█████╗░
// ██║░░██║██╔══╝░░██╔══╝░░░╚═══██╗
// ██████╔╝███████╗██║░░░░░██████╔╝
// ╚═════╝░╚══════╝╚═╝░░░░░╚═════╝░
// clang-format off
enum layers {
  _BASE,
  _NAV,
  _NUM,
  _SYM,
  _F
};
// clang-format on

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

#define XX_CUT LT(0, KC_X)
#define C_COPY LT(0, KC_C)
#define V_PASTE LT(0, KC_V)
#define ESC_F20 LT(0, KC_ESC)

// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// #endregion DEFS

// #region COMBOS
// ░█████╗░░█████╗░███╗░░░███╗██████╗░░█████╗░░██████╗
// ██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔══██╗██╔════╝
// ██║░░╚═╝██║░░██║██╔████╔██║██████╦╝██║░░██║╚█████╗░
// ██║░░██╗██║░░██║██║╚██╔╝██║██╔══██╗██║░░██║░╚═══██╗
// ╚█████╔╝╚█████╔╝██║░╚═╝░██║██████╦╝╚█████╔╝██████╔╝
// ░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚═════╝░░╚════╝░╚═════╝░
const uint16_t PROGMEM combo_backslash[] = {KC_E, LCTL_F, COMBO_END};
const uint16_t PROGMEM combo_slash[]     = {RCTL_J, KC_I, COMBO_END};
const uint16_t PROGMEM combo_pipe[]      = {RCTL_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_f_layer[]   = {ESC_F20, LCTL_F, COMBO_END};

const uint16_t PROGMEM combo_eql[]        = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_dash[]       = {RCTL_J, RSFT_K, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM combo_l_paren[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_r_paren[] = {KC_R, KC_T, COMBO_END};

const uint16_t PROGMEM combo_l_square[] = {LSHT_D, LCTL_F, COMBO_END};
const uint16_t PROGMEM combo_r_square[] = {LCTL_F, KC_G, COMBO_END};

const uint16_t PROGMEM combo_l_curly[] = {C_COPY, V_PASTE, COMBO_END};
const uint16_t PROGMEM combo_r_curly[] = {V_PASTE, KC_B, COMBO_END};

const uint16_t PROGMEM combo_l_croc[] = {LCTL_F, KC_R, COMBO_END};
const uint16_t PROGMEM combo_r_croc[] = {KC_T, KC_G, COMBO_END};

// clang-format off
combo_t key_combos[] = {
  COMBO(combo_backslash, NO_BSLS),
  COMBO(combo_slash, NO_SLSH),
  COMBO(combo_pipe, NO_PIPE),
  COMBO(combo_semicolon, NO_SCLN),
  COMBO(combo_f_layer, TO(_F)),

  COMBO(combo_eql, NO_EQL),
  COMBO(combo_dash, NO_MINS),
  COMBO(combo_underscore, NO_UNDS),

  COMBO(combo_l_paren, NO_LPRN),
  COMBO(combo_r_paren, NO_RPRN),

  COMBO(combo_l_square, NO_LBRC),
  COMBO(combo_r_square, NO_RBRC),

  COMBO(combo_l_curly, NO_LCBR),
  COMBO(combo_r_curly, NO_RCBR),

  COMBO(combo_l_croc, NO_LABK),
  COMBO(combo_r_croc, NO_RABK),
};
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// clang-format on
// #endregion COMBOS

// #region KEY OVERRIDES
// ██╗░░██╗███████╗██╗░░░██╗  ░█████╗░██╗░░░██╗███████╗██████╗░██████╗░██╗██████╗░███████╗░██████╗
// ██║░██╔╝██╔════╝╚██╗░██╔╝  ██╔══██╗██║░░░██║██╔════╝██╔══██╗██╔══██╗██║██╔══██╗██╔════╝██╔════╝
// █████═╝░█████╗░░░╚████╔╝░  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝██████╔╝██║██║░░██║█████╗░░╚█████╗░
// ██╔═██╗░██╔══╝░░░░╚██╔╝░░  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗██╔══██╗██║██║░░██║██╔══╝░░░╚═══██╗
// ██║░╚██╗███████╗░░░██║░░░  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║██║░░██║██║██████╔╝███████╗██████╔╝
// ╚═╝░░╚═╝╚══════╝░░░╚═╝░░░  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░╚══════╝╚═════╝░
const key_override_t override__shift_backspace__delete = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t override__shift_quote__dblquote   = ko_make_basic(MOD_MASK_SHIFT, NO_QUOT, NO_DQUO);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {&override__shift_backspace__delete, &override__shift_quote__dblquote};

// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// clang-format on
// #endregion KEY OVERRIDES

// #region MOD TAP
// ███╗░░░███╗░█████╗░██████╗░  ████████╗░█████╗░██████╗░
// ████╗░████║██╔══██╗██╔══██╗  ╚══██╔══╝██╔══██╗██╔══██╗
// ██╔████╔██║██║░░██║██║░░██║  ░░░██║░░░███████║██████╔╝
// ██║╚██╔╝██║██║░░██║██║░░██║  ░░░██║░░░██╔══██║██╔═══╝░
// ██║░╚═╝░██║╚█████╔╝██████╔╝  ░░░██║░░░██║░░██║██║░░░░░
// ╚═╝░░░░░╚═╝░╚════╝░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░
// https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
static bool process_tap_or_long_press_key(keyrecord_t *record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false; // Skip default handling.
    }

    return true; // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// #endregion MOD TAP

// #region RGB
// ██████╗░░██████╗░██████╗░
// ██╔══██╗██╔════╝░██╔══██╗
// ██████╔╝██║░░██╗░██████╦╝
// ██╔══██╗██║░░╚██╗██╔══██╗
// ██║░░██║╚██████╔╝██████╦╝
// ╚═╝░░╚═╝░╚═════╝░╚═════╝░
/** * * * * * * * * * * * * * * * * * * * * * * * * *
    *                 RGB LED index                 *
    *  {18 17 12 11 4 3 21} {41 40 35 34 27 26 44}  *
    *  {19 16 13 10 5 2 22} {42 39 36 33 28 25 45}  *
    *  {20 15 14 9 6 1}        {43 38 37 32 29 24}  *
    *               {8 7 0} {31 30 23}              *
    * * * * * * * * * * * * * * * * * * * * * * * * */
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    // Primary buttons colored when on primary layer
    if (get_highest_layer(layer_state) == 0) {
        if (host_keyboard_led_state().caps_lock) {
            rgb_matrix_set_color(0, RGB_RED);
            rgb_matrix_set_color(23, RGB_RED);
        } else {
            rgb_matrix_set_color(0, RGB_GREEN);
            rgb_matrix_set_color(23, RGB_GREEN);
        }
    }

    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GOLD);
                }
            }
        }
    }
    return false;
}
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// #endregion RGB

// #region KEYMAPS
// clang-format off
// ██╗░░██╗███████╗██╗░░░██╗███╗░░░███╗░█████╗░██████╗░░██████╗
// ██║░██╔╝██╔════╝╚██╗░██╔╝████╗░████║██╔══██╗██╔══██╗██╔════╝
// █████═╝░█████╗░░░╚████╔╝░██╔████╔██║███████║██████╔╝╚█████╗░
// ██╔═██╗░██╔══╝░░░░╚██╔╝░░██║╚██╔╝██║██╔══██║██╔═══╝░░╚═══██╗
// ██║░╚██╗███████╗░░░██║░░░██║░╚═╝░██║██║░░██║██║░░░░░██████╔╝
// ╚═╝░░╚═╝╚══════╝░░░╚═╝░░░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░░░░╚═════╝░
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    *  You can use _______ in place for KC_TRNS (transparent)   *
    *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      ESC_F20,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, NO_QUOT,     NO_GRV,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  NO_ARNG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,  LGUI_A,  LALT_S,  LSHT_D,  LCTL_F,    KC_G, NO_TILD,    XXXXXXX,    KC_H,  RCTL_J,  RSFT_K,  RALT_L,  RGUI_Ø,   NO_AE,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     MO(_NUM),    KC_Z,  XX_CUT,  C_COPY, V_PASTE,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, NO_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_DEL,  KC_SPC, KC_BSPC,     KC_ENT,MO(_NAV), MO(_SYM)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLU,    XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, KC_VOLD,    XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                      XXXXXXX,PREV_TAB, XXXXXXX,NEXT_TAB, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______,    NO_1,    NO_2,    NO_3,    NO_4,    NO_5, XXXXXXX,    XXXXXXX,    NO_6,    NO_7,    NO_8,    NO_9, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,    NO_4,    NO_5,    NO_6, KC_PAST, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         NO_0,    NO_1,    NO_2,    NO_3, KC_PERC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, NO_EXLM,   NO_AT, NO_HASH,  NO_DLR, NO_AMPR, XXXXXXX,    XXXXXXX, XXXXXXX, NO_LPRN, NO_RPRN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX,    XXXXXXX, NO_LABK, NO_LBRC, NO_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      NO_RABK, NO_LCBR, NO_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_F] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
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
// █████╗█████╗█████╗█████╗█████╗█████╗
// ╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝
// clang-format on
// #endregion KEYMAPS
