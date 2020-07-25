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


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _EXT,
  _EXTR,
  _FN,
  _GAME,
  _GAME_EXT,
  _GAME_EXT2,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAME,
  EXT,
  EXTR,
  FOREGROUND,
  PASTE,
  DYNAMIC_MACRO_RANGE,
};

#define EXT OSL(_EXT)
#define EXTR OSL(_EXTR)
#define SENT MT(MOD_RSFT, KC_ENTER)
#define CESC MT(MOD_LCTL, KC_ENTER)
#define GEXT OSL(_GAME_EXT)
#define GEXT2 OSL(_GAME_EXT2)
#define MPLAY DYN_MACRO_PLAY1
#define MREC DYN_REC_START1
#define MRECS DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, SENT,
    KC_ESC,  MO(_FN), KC_LGUI, KC_LALT, KC_RSFT, EXT,     EXTR,     KC_SPC,  KC_GRAVE, KC_DEL,  MO(_FN), MO(_FN)
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,     KC_L,    KC_U,     KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,     KC_N,    KC_E,     KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, SENT,
    KC_ESC,  MO(_FN), KC_LGUI, KC_LALT, KC_RSFT, EXT,     EXTR,     KC_SPC,  KC_GRAVE, KC_DEL,  MO(_FN), MO(_FN)
),

/* EXT
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_EXT] = LAYOUT_planck_grid(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
		KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
		_______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______
		),


/* EXTR
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_EXTR] = LAYOUT_planck_grid(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
		KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
		),

[_FN] = LAYOUT_planck_grid( /* FUNCTION */
		KC_F1,     KC_F2,   KC_F3,      KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
		_______,   _______, _______,    _______, _______, _______, KC_HOME, KC_PGUP, KC_UP,   KC_PGDN,  _______, KC_PSCR,
		_______,   _______, _______,    _______, _______, _______, KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,  KC_SLCK,
		TG(_GAME), _______, _______,    _______, _______, _______, _______, _______, _______, _______,  _______, KC_PAUSE
		),

[_GAME] = LAYOUT_planck_grid( /* GAME MODE */
		KC_GRAVE,   GEXT2,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_NO,   KC_UP,    KC_NO,   KC_NO,     KC_HOME,
		KC_LSFT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,   KC_LEFT, KC_DOWN,  KC_RIGHT,KC_P,      KC_END,
		KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_NO,   KC_NO,    KC_NO,   KC_NO,     KC_NO,
		GEXT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_SPC,  KC_NO,    KC_NO,   KC_NO,     GAME
		),

[_GAME_EXT] = LAYOUT_planck_grid( /* GAME EXT */
		KC_ESC,  _______, S(KC_2), S(KC_2), S(KC_3),  S(KC_4), S(KC_5), KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_F10,  _______, _______, _______, KC_TAB,   KC_RBRC, KC_LBRC, KC_GRAVE, KC_F12,  KC_NO,   KC_NO,   KC_NO,
		KC_NO,   _______, _______, _______, _______,  KC_KP_5, _______, _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______,  KC_SPC,  _______, _______,  _______, _______, _______, _______   
		),

[_GAME_EXT2] = LAYOUT_planck_grid( /* GAME EXT */
		KC_ESC,  _______, KC_F1,   KC_F2,   KC_F3,    S(KC_4), S(KC_5), KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_F10,  _______, _______, _______, KC_TAB,   KC_RBRC, KC_LBRC, KC_GRAVE, KC_F12,  KC_NO,   KC_NO,   KC_NO,
		KC_NO,   _______, _______, _______, _______,  KC_KP_5, _______, _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______,  KC_SPC,  _______, _______,  _______, _______, _______, _______   
		),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      | QWERT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | DEBUG|      |      |             |      |      |      |      |  CMK |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, QWERTY,
    _______, _______, DEBUG,   _______, _______, _______, _______, _______, _______,  _______, _______, COLEMAK,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, RESET
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

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _EXT, _EXTR, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
#ifdef AUDIO_ENABLE
				PLAY_SONG(tone_qwerty);
#endif
				default_layer_set(1 << _QWERTY);
			}
			return false;
			break;
		case COLEMAK:
			if (record->event.pressed) {
#ifdef AUDIO_ENABLE
				PLAY_SONG(tone_colemak);
#endif
				default_layer_set(1 << _COLEMAK);
			}
			return false;
			break;
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
			return true;
	};
	return true;
}


bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case EXT:
    case EXTR:
      return false;
    default:
      return true;
  }
}

#ifdef AUDIO_ENABLE
void matrix_init_user(void) {
  startup_user();
}

void startup_user(void) {
  wait_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}

void shutdown_user(void) {
  PLAY_SONG(tone_goodbye);
  wait_ms(150);
  stop_all_notes();
}
#endif
