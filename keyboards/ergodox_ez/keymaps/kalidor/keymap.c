#include QMK_KEYBOARD_H
//#include "keymap_bepo.h"

//Interesting links
//https://beta.docs.qmk.fm/features/feature_macros

// Runs just one time when the keyboard initializes.
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
};
const uint32_t PROGMEM unicode_map[] = {
    [JAPANSMILE]  = 0x30C4,  // ツ
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
      } else {
      }
      break;
     case M_FRRDQUOT:
       if (record->event.pressed) {
        SEND_STRING(
              SS_RALT("]")
                );
      } else {
      }
      break;
     case EYES:
       if (record->event.pressed) {
        send_unicode_hex_string("0CA0 005F 0CA0"); // ಠ_ಠ
      } else {
      }
      break;
     case DONTKNOW:
       if (record->event.pressed) {
        send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF"); // ¯\_(ツ)_/¯
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox(
        //left
        KC_ESC,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,  KC_GRV,
        KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,
        KC_TRNS, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,
        LSFT_T(KC_CAPS), KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,  MO(2),
        KC_LCTL, KC_LALT, KC_LEFT, KC_RIGHT, KC_LGUI,
        //pouce
        MO(1), KC_TRNS, KC_HOME,  KC_BSPC, KC_DEL, KC_END,

        //right
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_EQL, KC_MINS,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSLS,
        KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        OSL(2),    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_UP,    KC_DOWN, KC_LBRC,   KC_RBRC, KC_RALT,
        //pouce
        KC_INS,    KC_DEL,   KC_PGUP, KC_PGDN, KC_ENTER, KC_SPC
        ),

        // RED
	[1] = LAYOUT_ergodox(
        //left
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   M_BSLSH,
        KC_NO,   KC_EXLM, KC_AT,   M_FRLDQUOT, M_FRRDQUOT, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //pouce
        RGB_MOD, KC_TRNS, KC_TRNS, RGB_VAD, RGB_VAI, KC_TRNS,
        
        //right
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
        KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_LCBR,    KC_RCBR, KC_TRNS,
        KC_DOWN, KC_4,    KC_5,    KC_LBRC,    KC_RBRC, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_TRNS,    KC_UP, KC_TRNS,
        KC_TRNS, KC_DOT,  KC_LEFT, KC_DOWN, KC_RIGHT,
        //pouce
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

        // GREEN
	[2] = LAYOUT_ergodox(
        //left
        M_TILD,  KC_TRNS, KC_TRNS, M_DQUOT, M_SQUOT, KC_TRNS, KC_TRNS,
        KC_TRNS, M_AE, KC_TRNS, M_EAIG,  M_EGRV,  M_ECIRC, KC_TRNS, 
        KC_TRNS, M_AGRV,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, M_CCDIL, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //pouce
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        // right
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EYES, X(JAPANSMILE),
        KC_VOLU, KC_TRNS, M_UGRV,  M_ICIRC, M_OE,    KC_TRNS,    DONTKNOW,
        KC_TRNS, KC_TRNS, M_ITRIM, KC_TRNS, KC_MNXT, KC_TRNS,
        KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //pouce
        KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK)
};

