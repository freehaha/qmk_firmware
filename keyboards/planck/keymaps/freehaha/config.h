#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define ENCODER_RESOLUTION 4

#define DYNAMIC_MACRO_NO_NESTING
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 3500

// #define MOUSEKEY_INTERVAL       20
// #define MOUSEKEY_DELAY          0
// #define MOUSEKEY_TIME_TO_MAX    60
// #define MOUSEKEY_MAX_SPEED      7
// #define MOUSEKEY_WHEEL_DELAY 0

#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL       12
#define MOUSEKEY_MOVE_DELTA     2
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    20
#define MOUSEKEY_MAX_SPEED      12
#define MOUSEKEY_WHEEL_DELAY 0


#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
