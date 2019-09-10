/* 
	make keebio/levinson/rev2:keyaa:avrdude
*/

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------|-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Lower |  OS  | Alt  | Tab  |Raise |Space |Numpad|Raise |Lower | Left | Down |Right |
 * `-----------------------------------------|-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT, \
  LOWER,   KC_LGUI, KC_LALT, KC_TAB,  RAISE,   KC_SPC,  NUMPAD,  RAISE,   LOWER,   KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Lower
 * ,-----------------------------------------|-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |  /   |  ?   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_SLSH, KC_QUES, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |  /   |  ?   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_SLSH, KC_QUES, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Numpad
 * ,-----------------------------------------|-----------------------------------------.
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------|-----------------------------------------.
 * |      |      |      |      |      |      |      |Click1|MouseU|Click2|      |Reset |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Vol- | Vol+ | Mute |Prtscr| PgUp |      |MouseL|MouseD|MouseR|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Bri- | Bri+ | Home | End  | PgDn |      |Accel0|Accel1|Accel2|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, RESET, \
  _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PSCR, KC_PGUP, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
  _______, KC_BRID, KC_BRIU, KC_HOME, KC_END,  KC_PGDN, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
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
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}