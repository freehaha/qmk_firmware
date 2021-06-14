#include QMK_KEYBOARD_H
#include "version.h"

/* #define KC_MAC_UNDO LGUI(KC_Z) */
/* #define KC_MAC_CUT LGUI(KC_X) */
/* #define KC_MAC_COPY LGUI(KC_C) */
/* #define KC_MAC_PASTE LGUI(KC_V) */
/* #define KC_PC_UNDO LCTL(KC_Z) */
/* #define KC_PC_CUT LCTL(KC_X) */
/* #define KC_PC_COPY LCTL(KC_C) */
/* #define KC_PC_PASTE LCTL(KC_V) */
/* #define ES_LESS_MAC KC_GRAVE */
/* #define ES_GRTR_MAC LSFT(KC_GRAVE) */
/* #define ES_BSLS_MAC ALGR(KC_6) */
/* #define NO_PIPE_ALT KC_GRAVE */
/* #define NO_BSLS_ALT KC_EQUAL */
/* #define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc) */
/* #define BP_NDSH_MAC ALGR(KC_8) */
/*  */
enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_172_255_255,
  HSV_86_255_128,
};

enum layers {
	_QW,
	_CMK,
	_SYMBL,
	_SYMBR,
	/* _NUMB, */
	_UTIL,
	_FN,
	_GAME,
	_GEXT,
	_SWITCH,
};

#define CENT MT(MOD_LCTL, KC_ENTER)
#define SFT_SPC MT(MOD_RSFT, KC_SPC)
#define SYMBL_ESC LT(_SYMBL, KC_ESCAPE)
#define SYMBR_ENT LT(_SYMBR, KC_ENTER)
#define WWW_TN C(KC_TAB)
#define WWW_TP C(S(KC_TAB))

#define HM_A MT(MOD_LGUI, KC_A)
#define HM_S MT(MOD_LALT, KC_S)
#define HM_D MT(MOD_LSFT, KC_D)
#define HM_F MT(MOD_LCTL, KC_F)

#define HM_J MT(MOD_RCTL, KC_J)
#define HM_K MT(MOD_RSFT, KC_K)
#define HM_L MT(MOD_RALT, KC_L)
#define HM_SCLN MT(MOD_RGUI, KC_SCLN)

#define HM_O MT(MOD_RSFT, KC_O)
#define HM_W MT(MOD_LSFT, KC_W)
#define CTL_SL RCTL_T(KC_SLASH)
#define SFT_SL RSFT_T(KC_SLASH)
#define SFT_Z RSFT_T(KC_Z)

#define PASTE S(KC_INS)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_ergodox_pretty(
    KC_CAPS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,                                        KC_RIGHT,       KC_6,           KC_7,           KC_8,             KC_9,           KC_0,        KC_NO,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           OSL(_SWITCH),                                   TG(_UTIL),      KC_Y,           KC_U,           KC_I,             KC_O,           KC_P,        KC_BSPC,
    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,             KC_L,           KC_SCLN,     LGUI_T(KC_QUOTE),
    KC_LSFT,        SFT_Z,          KC_X,           KC_C,           KC_V,           KC_B,           KC_HYPR,                                        KC_MEH,         KC_N,           KC_M,           KC_COMMA,         KC_DOT,         SFT_SL,      KC_RSFT,
	KC_ESC,         OSL(_FN),       KC_LALT,        KC_LGUI,        CENT,                                                                                                           KC_SPC,         LALT_T(KC_GRAVE), KC_LBRACKET,    MO(_FN),     KC_ESC,
                                                                                                    LCA_T(KC_APPLICATION),  KC_LGUI, KC_LALT,       LCTL_T(KC_ESCAPE),
                                                                                                                            KC_HOME, KC_PGUP,
                                                                                    OSL(_SYMBL),     KC_ESC,                KC_END,  KC_PGDOWN,     KC_LALT ,       OSL(_SYMBR)
  ),
  [_CMK] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           LGUI_T(KC_QUOTE),
    KC_TRANSPARENT, SFT_Z,          KC_X,           KC_C,           KC_D,           KC_V,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_K,           KC_H,           KC_COMM,        KC_DOT,         SFT_SL,         KC_TRNS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_SYMBL] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                  KC_TRANSPARENT,  KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRNS,                                         KC_TRANSPARENT,  KC_CIRC,      KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRNS,
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                                                            KC_F6,        KC_UNDS,        KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_TRNS,
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_TRNS,                                         KC_TRANSPARENT,  KC_F12,       KC_PIPE,        KC_ESCAPE,      KC_ENTER,       KC_GRAVE,       KC_TRNS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_ESC,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_ESC
  ),
  [_SYMBR] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRNS,                                        KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                                                          KC_F6,          KC_MINUS,       KC_EQUAL,       KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_CAPS,        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_TRNS,                                        TO(_QW),        KC_F12,         KC_BSLASH,      KC_ESCAPE,      KC_ENTER,       TO(_FN),       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PASTE,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ESC,         KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_UTIL] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS,
    KC_TRANSPARENT, WWW_TP,         KC_MS_LEFT,     KC_MS_UP,       KC_MS_RIGHT,    KC_MS_WH_UP,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,             KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, WWW_TN,         KC_MS_BTN2,     KC_MS_DOWN,     KC_MS_BTN3,     KC_MS_WH_DOWN,                                                                  KC_LCTL,        KC_4,             KC_5,           KC_6,           KC_TRANSPARENT, KC_TRNS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, C(KC_W),        C(S(KC_F)),                                     TO(_QW),        KC_TRANSPARENT, KC_1,             KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRNS,        KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN1,                                                                                                     KC_0,             KC_PDOT,        KC_TRNS,        KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_WWW_FORWARD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),

  [_GAME] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_RIGHT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,             KC_NO,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_P5,                                          TG(_UTIL),      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,             KC_BSPC,
    KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           LT(_FN, KC_SCLN), LGUI_T(KC_QUOTE),
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,                                           TO(_QW),        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH), KC_RSHIFT,
    KC_ESC,         KC_NO,          KC_F10,         KC_LALT,        KC_LSFT,                                                                                                        KC_SPACE,       KC_GRAVE,       KC_LBRACKET,    MO(_FN),          KC_ESC,
                                                                                                    KC_END,         KC_LGUI,        KC_LALT,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPC,         OSL(_GEXT),     KC_END,         KC_PGDOWN,      KC_LALT,         SYMBR_ENT
  ),

  [_GEXT] = LAYOUT_ergodox_pretty(
    KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_RIGHT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,             KC_NO,
    KC_LBRC,        KC_P1,          KC_P2,          KC_P3,          KC_P4,          KC_P5,          KC_TRNS,                                        TG(_UTIL),      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,             KC_BSPC,
    KC_RBRC,        KC_F11,         KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           LT(_FN, KC_SCLN), LGUI_T(KC_QUOTE),
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_GRAVE,       KC_F12,         KC_TRNS,                                        KC_MEH,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH), KC_RSHIFT,
    LALT(KC_N),     KC_NO,          KC_TRNS,        KC_LALT,        KC_LSFT,                                                                                                        KC_SPACE,       KC_GRAVE,       KC_LBRACKET,    MO(_FN),          KC_ESC,

                                                                                                    TG(_GAME),      KC_LGUI,        KC_LALT,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_TRNS,        KC_TAB,         KC_END,         KC_PGDOWN,      KC_LALT,         SYMBR_ENT
  ),

  // KC_F is the "t" in colemak
  [_FN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS,
    KC_TRANSPARENT, WWW_TP,         KC_MS_LEFT,     KC_MS_UP,       KC_MS_RIGHT,    KC_MS_WH_UP,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,          KC_UP,          KC_PGDOWN,      KC_HOME,        KC_TRANSPARENT,
    KC_TRANSPARENT, WWW_TN,         KC_MS_BTN2,     KC_MS_DOWN,     KC_MS_BTN3,     KC_MS_WH_DOWN,                                                                  KC_LCTL,        KC_LEFT,          KC_DOWN,        KC_RIGHT,       KC_END,         KC_MEDIA_PLAY_PAUSE,
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, C(KC_W),        C(S(KC_F)),                                     TO(_QW),        KC_TRANSPARENT, KC_ACL0,          KC_ACL1,        KC_ACL2,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN1,                                                                                                     TO(_QW),          KC_PDOT,        KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_WWW_BACK,    KC_WWW_FORWARD, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENT,         KC_TRNS
  ),
  [_SWITCH] = LAYOUT_ergodox_pretty(
    TG(_GAME),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(_QW),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRNS,        KC_TRNS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(_CMK),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TO(_QW),        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case CENT:
		/* case SFT_Z: */
		case SFT_SL:
            return false;
        default:
            return true;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case HM_SCLN:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case CTL_SL:
		case SFT_Z:
			return TAPPING_TERM - 50;
		case HM_SCLN:
		case HM_A:
		case HM_O:
		case HM_W:
			return TAPPING_TERM;
		case SYMBL_ESC:
		case SYMBR_ENT:
            return 100;
        default:
            return TAPPING_TERM;
    }
}

/* bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case SYMB_ESC: */
/*             return true; */
/*         default: */
/*             return false; */
/*     } */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

uint32_t layer_state_set_user(uint32_t state) {
	uint8_t layer = biton32(state);
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
		case _SYMBL:
			ergodox_right_led_1_on();
			break;
		case _SYMBR:
			ergodox_right_led_2_on();
			break;
		case _UTIL:
			ergodox_right_led_3_on();
			break;
		case _FN:
			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
			break;
		case 30: // not used atm
			ergodox_right_led_1_on();
			ergodox_right_led_3_on();
			break;
		case _SWITCH:
			ergodox_right_led_2_on();
			ergodox_right_led_3_on();
			break;
		case _GAME:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
