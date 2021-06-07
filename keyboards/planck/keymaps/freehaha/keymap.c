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
  _NUMBERS,
  _SWITCH,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAME,
  /* EXT, */
  /* EXTR, */
  FOREGROUND,
  PASTE,
  DYNAMIC_MACRO_RANGE,
};

#define EXT OSL(_EXT)
#define EXTR OSL(_EXTR)
#define SENT MT(MOD_RSFT, KC_ENTER)
#define CENT MT(MOD_LCTL, KC_ENTER)
#define CESC MT(MOD_LCTL, KC_ENTER)
#define GEXT OSL(_GAME_EXT)
#define GEXT2 OSL(_GAME_EXT2)
#define MPLAY DYN_MACRO_PLAY1
#define MREC DYN_REC_START1
#define MRECS DYN_REC_STOP
#define ACTL MT(MOD_LCTL, KC_A)
#define SLCTL MT(MOD_LCTL, KC_SLSH)
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
    KC_BSPC, ACTL,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,    KC_COMM,  KC_DOT,  SLCTL,   SENT,
    KC_ESC,  MO(_FN), KC_LALT, KC_LGUI, CENT,    EXT,     EXTR,     KC_SPC,  KC_GRAVE, KC_DEL,  MO(_FN), MO(_FN)
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
    KC_LCTL, ACTL,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,     KC_N,    KC_E,     KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_TRNS, KC_X,    KC_C,    KC_D,    KC_V,    KC_M,     KC_H,    KC_COMM,  KC_DOT,  KC_TRNS, SENT,
    KC_ESC,  MO(_FN), KC_LALT, KC_LGUI, CENT,    EXT,     EXTR,     KC_SPC,  KC_GRAVE, KC_DEL,  MO(_FN), MO(_FN)
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
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC,
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,   KC_LCBR, KC_RCBR, KC_ESC,
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PIPE,    KC_ENT,    KC_ESC,  KC_END,  _______,
		_______, _______, _______, _______, _______, _______, KC_ESC,  KC_BSPC,    _______,   _______, _______, _______
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
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        KC_DEL,
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,     KC_BSLS,
		KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSLS, KC_ENT,  KC_ESC,  TG(_SWITCH), TG(_FN),
		_______, _______, _______, _______, _______, KC_ESC,  KC_TRNS, KC_BSPC, _______, _______, _______,     _______
		),

[_FN] = LAYOUT_planck_grid( /* FUNCTION */
		KC_F1,     KC_F2,   KC_F3,      KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,       KC_F12,
		_______,   _______, _______,    _______, _______, _______,    KC_HOME, KC_PGUP, KC_UP,   KC_PGDN,  _______,      KC_PSCR,
		_______,   _______, _______,    _______, _______, _______,    KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,       KC_SLCK,
		_______, _______, _______,    _______, _______, TO(_QWERTY),_______, _______, _______, _______,  TG(_NUMBERS), KC_PAUSE
		),

[_NUMBERS] = LAYOUT_planck_grid( /* NUM PAD */
		_______, _______, _______, _______, _______,  _______, _______, KC_7,    KC_8,    KC_9,    KC_NO,        KC_NO,
		KC_F10,  _______, _______, _______, KC_TAB,   _______, _______, KC_4,    KC_5,    KC_6,    KC_NO,        KC_NO,
		KC_NO,   _______, _______, _______, _______,  _______, _______, KC_1,    KC_2,    KC_3,    _______,      _______,
		_______, _______, _______, _______, _______,  _______, _______, KC_0,    _______, KC_DOT,  TG(_NUMBERS), TG(_NUMBERS)
		),

/* Adjust
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
[_SWITCH] = LAYOUT_planck_grid(
		_______, _______, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_U,     KC_BTN2, KC_BTN1, KC_MS_U, KC_ENT,  _______, QWERTY,
		_______, _______, KC_BTN2, KC_MS_D, KC_BTN3, KC_WH_D,     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, COLEMAK,
		_______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		_______, _______, _______, KC_BTN2, KC_BTN1, TO(_QWERTY), _______, _______, _______, _______, _______, RESET
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

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _EXT, _EXTR, _ADJUST); */
/* } */

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
		/* case GAME: */
		/* 	if (record->event.pressed) { */
		/* 		layer_off(_GAME); */
		/* 	} */
		/* 	return false; */
		/* 	break; */
		case EXT:
			/* if (record->event.pressed) { */
			/* 	layer_on(_EXT); */
			/* 	update_tri_layer(_EXT, _EXTR, _ADJUST); */
			/* } else { */
			/* 	layer_off(_EXT); */
			/* 	update_tri_layer(_EXT, _EXTR, _ADJUST); */
			/* } */
			return true;
			break;
		case EXTR:
			/* if (record->event.pressed) { */
			/* 	layer_on(_EXTR); */
			/* 	update_tri_layer(_EXT, _EXTR, _ADJUST); */
			/* } else { */
			/* 	layer_off(_EXTR); */
			/* 	update_tri_layer(_EXT, _EXTR, _ADJUST); */
			/* } */
			return true;
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

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CENT:
        case SENT:
            return false;
        default:
            return true;
    }
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
