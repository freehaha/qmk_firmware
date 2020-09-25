/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QW,
  _CMK,
  _EXT,
  _EXTR,
  _FN,
  _GAME,
  _GAME_EXT,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAME,
  EXT,
  EXTR,
  FOREGROUND,
  PASTE,
  PROBE,
  FF_QE,
  DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"
#define SENT MT(MOD_RSFT, KC_ENTER)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QW] = LAYOUT_preonic_grid( /* QWERTY */
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPC,   \
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_ENTER,  \
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,     \
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLASH,  SENT,   \
	KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, KC_SPC,  EXT,     EXTR,    KC_SPC,  KC_GRAVE,KC_DEL,  MO(_FN),   MO(_FN)     \
	),

  [_CMK] = LAYOUT_preonic_grid( /* COLEMAK_DH */
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,     KC_9,    KC_0,      KC_BSPC,      \
	KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     KC_J,     KC_L,    KC_U,     KC_Y,    KC_SCOLON, KC_ENTER,  \
	KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,     KC_K,     KC_N,    KC_E,     KC_I,    KC_O,      KC_QUOTE,     \
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     KC_M,     KC_H,    KC_COMMA, KC_DOT,  KC_SLASH,  SENT,   \
	KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, KC_SPC,  EXT,      EXTR,     KC_SPC,  KC_GRAVE, KC_DEL,  MO(_FN),   MO(_FN)  \
	),


  /* EXT
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * | GRAVE  | F1     | F2     | F3     | F4     | F5     | F6     | F7     | (      | )      | DEL    |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * |        |        |        | fg     |        |        |        |        | [      | ]      | \      |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
   * |        |        |        | _      | +      |        |        | MINUS  | EQUAL  | PASTE  |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
   * | LSHIFT | ^z     |        |        |        |        |        |        |        |        |        | INSERT |        |        |        |
   * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_EXT] = LAYOUT_preonic_grid( /* extension */
	  KC_GRAVE,KC_F1,      KC_F2,      KC_F3,         KC_F4,        KC_F5,      KC_F6,      KC_F7,      KC_F8,         LSFT(KC_9),    LSFT(KC_0),    KC_DEL, \
	  _______, KC_ESC,     _______,    _______,       _______,      _______,    KC_DEL,     KC_BSPC,    _______,       KC_CBR,        KC_RCBR,       KC_PIPE, \
	  _______, _______,    _______,    LSFT(KC_MINS), LSFT(KC_EQL), _______,    _______,    KC_MINUS,   KC_EQUAL,      PASTE,         _______,       _______, \
	  _______, LCTL(KC_Z), _______,    _______,       _______,      _______,    _______,    _______,    _______,       _______,       _______,       KC_INSERT,  \
	  _______, _______,    _______,    _______,       _______,      _______,    _______,    _______,    _______,       _______,       _______,       _______  \
	  ),

  [_EXTR] = LAYOUT_preonic_grid( /* extension */
	KC_GRAVE,  KC_F1,      KC_F2,      KC_F3,      KC_F4,        KC_F5,      KC_F6,      KC_F7,      KC_F8,      LSFT(KC_9), LSFT(KC_0),  KC_DEL,   \
	_______, KC_ESC,     _______,    _______,    _______,      _______,      KC_DEL,     KC_BSPC,    _______,    KC_LBRC,    KC_RBRC,     KC_BSLASH, \
	_______, _______,    _______,    LSFT(KC_MINS), LSFT(KC_EQL),_______,    _______,    KC_MINUS,   KC_EQUAL,   PASTE,       _______,     _______,\
	_______, LCTL(KC_Z), _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,     _______,     KC_INSERT,  \
	_______, _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,     _______,     _______  \
	 ),

  /* FUNCTION
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        | PRTSCR | SCRLCK | PAUSE  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        |        | RESET  |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | GAME   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_FN] = LAYOUT_preonic_grid( /* FUNCTION */
		  KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  \
		  _______,   _______, _______,    _______, _______, _______, KC_HOME, KC_PGUP, KC_UP,   KC_PGDN,  _______, KC_PSCR,  \
		  _______,   _______, _______,    _______, _______, _______, KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,  KC_SLCK, \
		  TG(_GAME), _______, _______,    _______, _______, _______, _______, _______, _______, _______,  _______, KC_PAUSE, \
		  _______,   _______, _______,    _______, _______, _______, _______, _______, _______, _______,  _______, _______ \
		  ),

#define GEXT MO(_GAME_EXT)
#define MPLAY DYN_MACRO_PLAY1
#define MREC DYN_REC_START1
#define MRECS DYN_REC_STOP

  [_GAME] = LAYOUT_preonic_grid( /* GAME MODE */
		  KC_GRAVE,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,      KC_HOME,  \
		  KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,      KC_END, \
		  KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCOLON, KC_ENTER, \
		  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA, KC_UP,   KC_SLASH,  KC_LSFT, \
		  KC_ESC,        GEXT,    KC_F10,  KC_LGUI, KC_LSFT, GEXT,    KC_SPC,  MPLAY,   KC_LEFT,  KC_DOWN, KC_RIGHT,  GAME
		  ),

  [_GAME_EXT] = LAYOUT_preonic_grid( /* GAME EXT */
		  KC_ESC,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MINUS,  \
		  KC_LBRC,    KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______,   \
		  KC_RBRC,    KC_F11,  KC_QUOT, KC_MINUS,KC_GRAVE, _______, _______, KC_GRAVE,KC_F12,  _______, _______, _______,   \
		  XXXXXXX,    _______, _______, _______, _______, _______, _______, MREC,    _______, _______, _______, _______,   \
		  LGUI(KC_N), _______, _______, _______, _______, _______, _______, MRECS,   _______, _______, _______, _______ \
		  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 | QWER |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | Reset|      |      |      |      |      |      |      |      |      |  CMK |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      | RESET|
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_preonic_grid( \
	KC_F1,           KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  QWERTY,  \
	KC_SYSREQ,       _______, DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, COLEMAK,  \
	_______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
	_______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
	_______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  \
	)
};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_game[][2]    = SONG(GUITAR_SOUND);
float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_qwerty);
#endif
      default_layer_set(1 << _QW);
    }
    return false;
    break;
  case COLEMAK:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_colemak);
#endif
      default_layer_set(1 << _CMK);
    }
    return false;
    break;
  case PROBE:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      if(IS_LAYER_ON(_GAME)) {
        PLAY_SONG(tone_game);
      } else if(IS_LAYER_ON(_QW)) {
        PLAY_SONG(tone_qwerty);
      }
#endif
    }
    return false;
  case GAME:
    if (record->event.pressed) {
      layer_off(_GAME);
    }
    return false;
    break;
  case EXT:
    if (record->event.pressed) {
      layer_on(_EXT);
      update_tri_layer(_EXT, _EXTR, _ADJUST);
    } else {
      layer_off(_EXT);
      update_tri_layer(_EXT, _EXTR, _ADJUST);
    }
    return false;
    break;
  case EXTR:
    if (record->event.pressed) {
      layer_on(_EXTR);
      update_tri_layer(_EXT, _EXTR, _ADJUST);
    } else {
      layer_off(_EXTR);
      update_tri_layer(_EXT, _EXTR, _ADJUST);
    }
    return false;
    break;
  case FOREGROUND:
    if (record->event.pressed) {
      SEND_STRING("eg" SS_TAP(X_ENTER));
    } else {
    }
    break;
  case PASTE:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
    } else {
    }
    break;
  case FF_QE:
    if (record->event.pressed) {
      register_code(KC_Q);
      register_code(KC_E);
    } else {
      unregister_code(KC_Q);
      unregister_code(KC_E);
    }
    break;
  }
  return true;
};

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
  startup_user();
#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
  wait_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}

void shutdown_user()
{
  PLAY_SONG(tone_goodbye);
  wait_ms(150);
  stop_all_notes();
}

#endif
