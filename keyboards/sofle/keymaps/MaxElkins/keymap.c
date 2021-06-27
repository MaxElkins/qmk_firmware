#include QMK_KEYBOARD_H
#include <stdio.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                    |  6 ^ |  7 & |  8 * |  9 ( |  0 ) | Bkspc|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Hyp  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  /?  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |LOWER | /Space  /       \Space \  |RAISE |  [{  |  ]}  |  =+  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_GRAVE, \
 C(S(KC_LALT)),   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,     _______,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                        KC_LCTRL,KC_LGUI,KC_LALT, KC_LOWER, KC_SPC,    KC_SPC,  KC_RAISE, KC_LBRC, KC_RBRC, KC_EQL \
),

/* LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  UP  |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS | LEFT | DOWN | RIGHT|      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |-------|    |-------|      |      |      |      |  \|  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |LOWER | /  Enter/       \Enter \  |RAISE |      |      |  -_  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  _______, _______,   KC_UP, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                           _______, _______, _______, _______, _______, _______, \
  KC_LSFT, _______, _______, _______, _______, _______,  _______,        _______, _______, _______, _______, _______, KC_BSLS, KC_RSFT, \
                    KC_LCTRL,KC_LGUI,KC_LALT, KC_LOWER, KC_ENT,        KC_ENT, KC_RAISE, _______, _______, KC_MINS \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |  %   |                    |   ^  |   &  |   *  |   (  |   )  |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |   ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |LOWER | /  Enter/       \Enter \  |RAISE |   {  |   }  |   +  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \

  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, KC_TILD, \
  _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, KC_COLN, KC_DQUO, \
  KC_LSFT, _______, _______, _______, _______, _______, _______,       _______,  _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_RSFT, \
                    KC_LCTRL,KC_LGUI,KC_LALT, KC_LOWER, KC_ENT,       KC_ENT, KC_RAISE, KC_LCBR, KC_RCBR, KC_PLUS \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |VOLDO |VOLUP | MUTE |      |      | PLAY |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |       |     |      |      |      |      |                    |      |      |      |      |      |KC_F13|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |  |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |LOWER | /       /       \      \  |RAISE |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, KC_MPLY, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F13, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, KC_LOWER, _______,     _______, KC_RAISE, _______, _______, _______ \
  )
};

#ifdef OLED_DRIVER_ENABLE

static void render_img(void) {
  static const char PROGMEM my_logo[] = {
    // 'earth2', 128x32px
    0x6d, 0x28, 0x80, 0xe1, 0x04, 0x65, 0x65, 0x44, 0x04, 0x4a, 0x0a, 0x0a, 0x3a, 0x34, 0x54, 0xcc,
    0x0c, 0xac, 0x88, 0x88, 0x88, 0x90, 0x90, 0x30, 0x30, 0xa2, 0xa0, 0xe0, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x02, 0x02, 0x07, 0x0f, 0x07, 0x02, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x3c, 0x07, 0xcf, 0x1c, 0xff, 0xff, 0x3f, 0xfe, 0xfd, 0x3a, 0xbc, 0x0c, 0xf0, 0x00, 0x00,
    0x05, 0xa3, 0x45, 0xd5, 0xc5, 0x05, 0xee, 0xe5, 0xe1, 0xe8, 0xdd, 0xd2, 0x4f, 0x17, 0xb7, 0x23,
    0xa9, 0x99, 0x1b, 0x7e, 0x5e, 0xdc, 0x9c, 0x98, 0x10, 0x90, 0x20, 0x60, 0xc0, 0x80, 0x88, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00,
    0xe0, 0x01, 0x00, 0xd6, 0xbe, 0x1f, 0x40, 0x00, 0xc3, 0x0f, 0x00, 0x01, 0x00, 0x0b, 0x00, 0x00,
    0x00, 0x00, 0xcf, 0xf7, 0x8f, 0x38, 0xff, 0xff, 0xff, 0x67, 0x77, 0x69, 0x76, 0x7b, 0xf8, 0xe0,
    0x05, 0xdd, 0xbd, 0x39, 0x09, 0x40, 0x10, 0x01, 0x00, 0xe0, 0x00, 0xe1, 0x86, 0x02, 0x85, 0x0b,
    0x06, 0x0e, 0x14, 0x20, 0x10, 0x20, 0xc0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0xff, 0x80, 0xfc, 0x9f, 0xef, 0xc0, 0xc3, 0x0b, 0x4a, 0xc8, 0xcd, 0xf8, 0xf0, 0x00, 0x00, 0x10,
    0x30, 0x2a, 0x69, 0x63, 0x55, 0xd0, 0xc9, 0xc0, 0xa2, 0xa3, 0x29, 0x2d, 0x2d, 0x2d, 0x2e, 0x1f,
    0x6f, 0x80, 0x0c, 0x81, 0xd4, 0x58, 0x16, 0x80, 0x81, 0xe0, 0xf8, 0xff, 0x7f, 0x70, 0x07, 0x6f,
    0x0d, 0x1d, 0x1a, 0x58, 0x58, 0x30, 0x03, 0x07, 0x0e, 0x19, 0x32, 0xcc, 0xd8, 0xf0, 0xc0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x1c, 0x7f, 0x1c, 0x08, 0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    else{
        // return OLED_ROTATION_270;
    }
    return rotation;
}

//Variable for WPM
char wpm_str[10];

//Test var
char mytest[] = "hello";
// oled_write(mytest, false);


//Print to screen
void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
        oled_write_P(PSTR("\n\n\n\n\n\n\n"), false);
        sprintf(wpm_str, "WPM: %03d", get_current_wpm());
        oled_write(wpm_str, false);
    } else {
        render_img();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        // default :
        //     oled_write(mytest, false);
    }

    return true;
}


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     oled_write(mytest, false);
//     oled_write_P(PSTR("\n\n\n\n\n\n\n"), false);

//     return true;
// }

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
