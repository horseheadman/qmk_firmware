/* Copyright 2021 Giordano Cerizza
 * Modified from layout provided by Jack Humbert
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
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  ADJUST,
  FORLOOPC,
  IFTHENC,
  FORLOOPP,
  IFTHENP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Alt |  GUI |Adjust| Lower|    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_ENT,  \
  KC_LCTL, KC_LALT, KC_LGUI, ADJUST,  TG(_LOWER),   KC_SPC,  KC_SPC, TG(_RAISE),   KC_SLSH, KC_LEFT, KC_DOWN,   KC_RGHT \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |PrtScr| PgUp | PgDw | Home |  End |Insert|ScrlLk|NumLck|Pause |   [  |   ]  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl | RAlt | RGui |      |      |      |      |      |      |  \   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_PSCREEN, KC_PGUP, KC_PGDOWN, KC_HOME, KC_END, KC_INSERT, KC_SCROLLLOCK, KC_NUMLOCK, KC_PAUSE, KC_LBRACKET, KC_RBRACKET, KC_MINUS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DELETE, \
  KC_CAPSLOCK, FORLOOPC, IFTHENC, FORLOOPP, IFTHENP, _______, _______, _______, _______, _______, _______, _______, \
  KC_RSHIFT, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______, _______, _______, KC_ENT, \
  KC_RCTRL, KC_RALT, KC_RGUI, _______, _______, _______, _______, _______, KC_BSLASH,  _______, _______, _______	\
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |PrtScr| PgUp | PgDw | Home |  End |Insert|ScrlLk|NumLck|Pause |  {   |   }  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl | RAlt | RGui |      |      |      |      |      |      |  |   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_PSCREEN, KC_PGUP, KC_PGDOWN, KC_HOME, KC_END, KC_INSERT, KC_SCROLLLOCK, KC_NUMLOCK, KC_PAUSE, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_UNDERSCORE, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DELETE, \
  KC_CAPSLOCK, FORLOOPC, IFTHENC, FORLOOPP, IFTHENP, _______, _______, _______, _______, _______, _______, _______, \
  KC_RSHIFT, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______, _______, _______, KC_ENT, \
  KC_RCTRL, KC_RALT, KC_RGUI, _______, _______, _______, _______, _______, KC_PIPE, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Light|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
)


};

#define DEFAULT_SOUND E__NOTE(_F4)
//#define INTRO_SONG HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)

#ifdef AUDIO_ENABLE
//float layer0_song[][2] = SONG(INTRO_SONG);
float raise_low[][2] = SONG(TERMINAL_SOUND);
float adjust[][2] = SONG(UNICODE_LINUX);
float my_default[][2] = SONG(DEFAULT_SOUND);
#endif

const rgblight_segment_t PROGMEM rgb_lower[] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, HSV_GOLDENROD} );
const rgblight_segment_t PROGMEM rgb_raise[] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, HSV_GOLDENROD} );
const rgblight_segment_t PROGMEM rgb_adjust[] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, HSV_GREEN} );

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_lower,
    rgb_raise,
    rgb_adjust
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;  // Enable the LED layers
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(2, layer_state_cmp(state, _ADJUST));

  switch(biton32(state)) {
  case _RAISE:
    PLAY_SONG (raise_low);
    break;
  case _LOWER:
    PLAY_SONG (raise_low);
    break;
  case _ADJUST:
    PLAY_SONG (adjust);
    break;
  default: //  for any other layers, or the default layer
    PLAY_SONG (my_default);
    break;
  }

  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case FORLOOPC:
          if (record->event.pressed) {
            // when keycode C FORLOOP is pressed
            SEND_STRING("for (int i=0; i<N; i++){}");
          } else {
            // when keycode is released
          }
          break;
        case FORLOOPP:
          if (record->event.pressed) {
            // when keycode Python FORLOOP is pressed
            SEND_STRING("for x in list:");
          } else {
            // when keycode is released
          }
          break;
        case IFTHENC:
          if (record->event.pressed) {
            // when keycode C IFTHEN is pressed
            SEND_STRING("if (condition1) {// code block 1} else if (condition2){// code block 2} else {// code block 3}");
          } else {
            // when keycode is released
          }
          break;
        case IFTHENP:
          if (record->event.pressed) {
            // when keycode Python IFTHEN is pressed
            SEND_STRING("if b > a: #condition1 elif a == b: #condition2 else: #condition3");
          } else {
            // when keycode is released
          }
          break;	  
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case ADJUST:
          if (record->event.pressed) {
            layer_on(_RAISE);
            layer_on(_LOWER);
            layer_on(_ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
  return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
