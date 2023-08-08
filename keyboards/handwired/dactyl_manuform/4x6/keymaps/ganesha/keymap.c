#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
    LAG(KC_B),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    HYPR_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_TAB, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,

                KC_LAPO, KC_EQL,             KC_GRV, KC_RAPC,           
                KC_SPC, KC_BSPC,            	KC_LGUI , KC_ENT,     
                
                RAISE, KC_LCTL,  HYPR(KC_F), LOWER,
                HYPR(KC_SPC), LAG(KC_V), KC_LSFT, LCTL(KC_C)),

    [_LOWER] = LAYOUT(
        _______, _______, LAG(KC_C), KC_LCBR, KC_RCBR, KC_PAST,
        KC_KP_PLUS, KC_7,   KC_8,   KC_9,   KC_0, _______, 

         _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HASH,
          KC_AT, KC_4,   KC_5,   KC_6,   KC_PERCENT, KC_CIRCUMFLEX,
          
        _______, _______, _______, KC_LBRC, KC_RBRC, KC_AMPERSAND,
                     KC_DLR, KC_1,   KC_2,   KC_3,   KC_EQL,  KC_UNDS,
                          _______, _______,   
                          _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, RESET,   _______, _______, _______, _______,          
        KC_F1, KC_F2, KC_F3,  KC_F4, KC_F5, KC_F6, 

        KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R ,  KC_LGUI, 
        KC_ML, KC_MD, KC_MU, KC_MR, KC_MB2, KC_AUDIO_MUTE,

        KC_MB1, _______, _______, _______, _______, LAG(KC_B),
				KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                          _______,_______,                                                 _______,  _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}