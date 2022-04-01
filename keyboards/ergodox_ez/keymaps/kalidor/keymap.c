#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  ergodox_right_led_3_off();
};

// Runs constantly in the background, in a loop.
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
};

enum unicode_names {
    JAPANSMILE, 
    BIERE,
    BIBERON,
    CHECK,
    UNCHECK,
    SP_INSEC,
    ALIEN,
};
const uint32_t PROGMEM unicode_map[] = {
    [JAPANSMILE]  = 0x30C4,  // ツ
    [BIERE] = 0x1F37A,
    [BIBERON] = 0x1F37C,
    [CHECK] = 0x2705,
    [UNCHECK] = 0x274C,
    [SP_INSEC] = 0x00A0,
    [ALIEN] = 0x1F47E,
};
// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
       #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

// To get valid keycodes, see: https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h
enum custom_keycodes {
  M_EAIG = SAFE_RANGE,
  M_EGRV,
  M_ECIRC,
  M_OCIRC,
  M_OE,
  M_AE,
  M_AGRV,
  M_UGRV,
  M_TILD,
  M_SQUOT,
  M_DQUOT,
  M_ITRIM,
  M_ICIRC,
  M_CCDIL,
  M_GRV,
  M_BSLSH,
  M_FRLDQUOT,
  M_FRRDQUOT,
  EYES,
  DONTKNOW,
  SMILE,
  NBSP,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_EAIG:
      if (record->event.pressed) {
          SEND_STRING(
                SS_TAP(X_QUOTE)
                SS_TAP(X_E)
              );
      } else {
      }
      break;
    case M_EGRV:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_TAP(X_GRAVE)
              SS_TAP(X_E)
            );
      } else {
      }
      break;
    case M_ECIRC:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_LSFT("6")
              SS_TAP(X_E)
            );
      } else {
        // when keycode Key is released
      }
      break;
    case M_OCIRC:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_LSFT("6")
              SS_TAP(X_O)
            );
      } else {
        // when keycode Key is released
      }
      break;
    case M_OE:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_RALT("k")
            );
      } else {
        // when keycode Key is released
      }
      break;
    case M_AGRV:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_TAP(X_GRAVE)
              SS_TAP(X_A)
            );
      } else {
      }
      break;
    case M_AE:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_RALT("z")
            );
      } else {
        // when keycode Key is released
      }
      break;
    case M_UGRV:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_TAP(X_GRAVE)
              SS_TAP(X_U)
              );
      } else {
      }
      break;
    case M_TILD:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_LSFT("~")
              SS_TAP(X_SPACE)
            );
      } else {
        // when keycode Key is released
      }
      break;
    case M_SQUOT:
      if (record->event.pressed) {
          SEND_STRING(
                SS_TAP(X_QUOTE)
                SS_TAP(X_SPACE)
              );
      } else {
      }
      break;
    case M_DQUOT:
      if (record->event.pressed) {
          SEND_STRING(
                SS_DOWN(X_LSHIFT)
                SS_TAP(X_QUOTE)
                SS_TAP(X_SPACE)
                SS_UP(X_LSHIFT)
              );
      } else {
      }
      break;
    case M_ITRIM:
      if (record->event.pressed) {
          SEND_STRING(
                SS_DOWN(X_LSHIFT)
                SS_TAP(X_QUOTE)
                SS_UP(X_LSHIFT)
                SS_TAP(X_I)
              );
      } else {
      }
      break;
    case M_ICIRC:
      if (record->event.pressed) {
          SEND_STRING(
                SS_LSFT("6")
                SS_TAP(X_I)
                  );
      } else {
      }
    break;
    case M_CCDIL:
      if (record->event.pressed) {
          SEND_STRING(
                SS_RALT(",")
                  );
      } else {
      }
    break;
    case M_GRV:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_TAP(X_GRAVE)
              SS_TAP(X_SPACE)
            );
      } else {
      }
      break;
      case M_BSLSH:
      if (record->event.pressed) {
        // when keycode key is pressed
        SEND_STRING(
              SS_TAP(X_BSLASH)
            );
      } else {
      }
      break;
      case M_FRLDQUOT:
      if (record->event.pressed) {
        SEND_STRING(
              SS_RALT("[")
                );
        SEND_STRING(
              SS_RALT(" ")
                );
      } else {
      }
      break;
     case M_FRRDQUOT:
       if (record->event.pressed) {
        SEND_STRING(
              SS_RALT(" ")
                );
        SEND_STRING(
              SS_RALT("]")
                );
      } else {
      }
      break;
     //case EYES:
     //  if (record->event.pressed) {
     //   send_unicode_hex_string("0CA0 005F 0CA0"); // ಠ_ಠ
     // } else {
     // }
     // break;
     case DONTKNOW:
       if (record->event.pressed) {
        //send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF"); // ¯\_(ツ)_/¯
        send_unicode_string("¯\\_(ツ)_/¯");
      } else {
      }
      break;
     case SMILE:
      if (record->event.pressed) {
       //send_unicode_hex_string("30C4"); // ツ
       send_unicode_string("ツ");
     } else {
     }
     break;
  }
  return true;
};

 
#define FR_A KC_Q
#define FR_Z KC_W
#define FR_Q KC_A
#define FR_W KC_Z
#define FR_CIRC ALGR(KC_6)
#define FR_M KC_SCLN
#define FR_COMMA KC_M
#define FR_POINTVIRGULE KC_COMM

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | Esc  |           |   '  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   `    |
 * |--------+------+------+------+------+------| BSPC |           |  DEL |------+------+------+------+------+--------|
 * | Lock   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |  Ctrl |  Alt | Left | Right| Super|                                      |  MO2  |  UP  | DOWN |      | AltGr |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Home |  End |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PGUP |        |      |
 *                                 | MO(1)| SP   |------|       |------|  Enter |Space |
 *                                 |      |INSEC | End  |       | PGDWN|        |      |
 *                                 `--------------------'       `----------------------'
 */
    [0] = LAYOUT_ergodox(
            //left
            KC_EQL,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,  KC_ESC,
            KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,
            KC_TRNS, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,
            LSFT_T(KC_CAPS), KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,  KC_BSPC,
            KC_LCTL, KC_LALT, KC_LEFT, KC_RIGHT, KC_LGUI,
            //pouce
            KC_TRNS, KC_TRNS, KC_TRNS,  MO(1), X(SP_INSEC), KC_TRNS,

            //right
            KC_QUOT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,
            KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSLS,
            KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_GRV,
            KC_DEL,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
            MO(2),   KC_UP , KC_DOWN,   KC_TRNS, KC_ALGR,
            //pouce
            KC_HOME,    KC_END,   KC_PGUP, KC_PGDN, KC_ENTER, KC_SPC
            ),

    // RED
            /* Keymap 1: Basic layer
             *
             * ,--------------------------------------------------.           ,--------------------------------------------------.
             * |        |   F1 |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  | F9  |  F10 |  F11   |
             * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
             * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  F12   |
             * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
             * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
             * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
             * |        |      |      |      |      |      |      |           |      |      | Prev |      |      |      |        |
             * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
             *   |      |      |      |      |      |                                       | Next |      |      |      |       |
             *   `----------------------------------'                                       `----------------------------------'
             *                                        ,-------------.       ,-------------.
             *                                        |      |      |       |      |      |
             *                                 ,------|------|------|       |------+--------+------.
             *                                 |      |      |      |       |      |        |      |
             *                                 |      |      |------|       |------| Vol-   | Vol+ |
             *                                 |      |      |      |       |      |        |      |
             *                                 `--------------------'       `----------------------'
             */
    [1] = LAYOUT_ergodox(
            //left
            KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   M_BSLSH,
            KC_TRNS, KC_EXLM, KC_AT,   M_FRLDQUOT, M_FRRDQUOT, KC_PIPE, KC_TRNS,
            KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
            KC_TRNS, KC_PERC, KC_CIRC, LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            //pouce
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

            //right
            KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,
            KC_TRNS, KC_TRNS,   KC_7,    KC_8,    KC_TRNS,    KC_MPLY, KC_F12,
        KC_TRNS, KC_4,    KC_TRNS,    KC_LBRC,    KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MPRV,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MNXT, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
        //pouce
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU),

        // GREEN
 /*
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    ~   |   «  |   »  |   "  |   '  |   €  |      |           |      |      |      |      |      |  ツ |¯\_(ツ)_/¯|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  æ   |      |   é  |  è   |   ê  |      |           |      |      |  ù   |   î  |   œ  |   §  |    þ   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  à   |      |      |      |      |------|           |------|      |      |      |      |    |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |  ç   |      |      |           |      |      |      |  «   |   »  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                      |       |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
	[2] = LAYOUT_ergodox(
        //left
        M_TILD, M_FRLDQUOT, M_FRRDQUOT,  M_DQUOT, M_SQUOT,RALT(KC_5), KC_TRNS, 
        KC_TRNS, M_AE, KC_TRNS, M_EAIG,  M_EGRV,  M_ECIRC, KC_TRNS, 
        KC_TRNS, M_AGRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, M_CCDIL, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //pouce
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        // right
        KC_TRNS, X(BIERE), X(BIBERON), X(CHECK), X(UNCHECK), SMILE, DONTKNOW,
        KC_TRNS, KC_TRNS, M_UGRV,  M_ICIRC, M_OE,   RSA(KC_S), RALT(KC_T),
        KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_L), KC_TRNS, X(ALIEN),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //pouce
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NBSP)
};
// clang-format on

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

