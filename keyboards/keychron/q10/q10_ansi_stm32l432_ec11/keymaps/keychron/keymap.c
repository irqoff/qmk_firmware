/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// clang-format off

enum {
    TD_HOME_END,
    TD_CTL_C_CTL_V,
    TD_CTL_D_CTL_Z,
    TD_GUI_SPC_ENT,
    TD_CTL_A_ESC,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
  [TD_CTL_C_CTL_V] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_V)),
  [TD_CTL_D_CTL_Z] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_D), LCTL(KC_Z)),
  [TD_GUI_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_SPC), KC_ENT),
  [TD_CTL_A_ESC] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_A), KC_ESC),
};

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,            KC_ESC,              KC_F1,             KC_F2, KC_F3,         KC_F4,   KC_F5,         KC_F6,    KC_F7,              KC_F8,          KC_F9, KC_F10,   KC_F11,   KC_F12,   MO(WIN_FN),              KC_DEL,
        KC_LEFT_GUI,        KC_GRV,              KC_1,              KC_2,  KC_3,          KC_4,    KC_5,          KC_6,     KC_7,               KC_8,           KC_9,  KC_0,     KC_MINS,  KC_EQL,   RCTL_T(KC_ESC),          KC_PGUP,
        KC_PRINT_SCREEN,    KC_TAB,              KC_Q,              KC_W,  KC_E,          KC_R,    KC_T,          KC_Y,     KC_U,               KC_I,           KC_O,  KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                 KC_PGDN,
        MO(WIN_FN),         OSM(MOD_LCTL),       KC_A,              KC_S,  KC_D,          KC_F,    KC_G,          KC_H,     KC_J,               KC_K,           KC_L,  KC_SCLN,  KC_QUOT,            KC_ENT,                  TD(TD_HOME_END),
        TD(TD_CTL_D_CTL_Z), TD(TD_GUI_SPC_ENT),                     KC_Z,  KC_X,          KC_C,    KC_V,          KC_B,     TD(TD_CTL_C_CTL_V), KC_N,           KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_LEFT_GUI,    KC_UP,
        MEH_T(KC_DEL),      TD(TD_CTL_C_CTL_V),  TD(TD_CTL_A_ESC),         OSM(MOD_LALT), KC_SPC,  OSM(MOD_LSFT),                               LSFT_T(KC_SPC),        KC_BSPC,                      KC_LEFT,        KC_DOWN, KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  MEH(KC_N), RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,   RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,   RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,   _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,   _______,                       _______,            _______,                       _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MACRO01,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MACRO02,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MACRO03,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MACRO04,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MACRO05,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     LSFT_T(KC_SPC),             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  MEH(KC_N),  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (!dip_switch_update_keychron(index, active)) {
        return false;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keychron(led_min, led_max)) {
        return false;
    }
    return true;
}
#endif // RGB_MATRIX_ENABLE
