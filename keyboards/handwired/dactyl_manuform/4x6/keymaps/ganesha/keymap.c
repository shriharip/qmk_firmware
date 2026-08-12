// Corrected keymap.c for your actual Dactyl Manuform layout (3x6 + 2 lower row + 6 thumb keys)
// Uses the exact LAYOUT macro from your default keymap
// Adds Danish unicode (æ ø å) in LOWER layer
// Keeps US layout only

#include QMK_KEYBOARD_H

enum layers { _BASE, _RAISE, _LOWER, _DANISH };

enum unicode_names { AE_LOWER, OE_LOWER, AA_LOWER, AE_UPPER, OE_UPPER, AA_UPPER };

const uint32_t unicode_map[] PROGMEM = {
    [AE_LOWER] = 0x00E6, // æ
    [OE_LOWER] = 0x00F8, // ø
    [AA_LOWER] = 0x00E5, // å
    [AE_UPPER] = 0x00C6, // AÉ
    [OE_UPPER] = 0x00D8, // OÉ
    [AA_UPPER] = 0x00C5  // AÅ
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define DANISH MO(_DANISH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        // first row left side
        DANISH, KC_Q, KC_W, KC_E, KC_R, KC_T,
        // first row right side
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        // second row left side
        HYPR_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,
        // second row right side
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        // third row left side
        KC_TAB, KC_Z, KC_X, KC_C, KC_V, KC_B,
        // third row right side
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
        // special keys on left side
        SC_LAPO, MEH_T(KC_X),
        // special keys on right side
        KC_EQUAL, SC_RAPC,
        // Thumb cluster
        KC_SPC, KC_BSPC,          KC_LGUI, KC_ENT,
        RAISE, KC_LSFT,           LCS_T(KC_PEQL), LOWER,
        KC_LCTL,KC_GRV,           LCTL(KC_C), LSG(KC_P)),

    // Raise layer is on the left hand side (qwert)
     [_RAISE] = LAYOUT(
         // first row left side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         // first row right side
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        // second row left side
        KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRNS,
        // second row right side
        MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, MS_BTN2, KC_TRNS,
        // third row left side
        MS_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // third row right side
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
       //special keys on left side
        KC_TRNS, KC_TRNS,
        // special keys on right side
        KC_TRNS, KC_TRNS,
        //Thumb Cluster
        KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS),

     // Lower layer is on the right hand side (yuiop)
       [_LOWER] = LAYOUT(
           // first row left side
        KC_TRNS, KC_TRNS, KC_UP, KC_LCBR, KC_RCBR, KC_PAST,
        // first row right side
        KC_PPLS, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        // second row left side
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NUBS, KC_HASH,
        // second row right side
        KC_AT, KC_4, KC_5, KC_6, KC_PERC, KC_CIRC,
        // third row left side
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_AMPR,
        // third row right side
        KC_DLR, KC_1, KC_2, KC_3, KC_EQL, LCTL(KC_SPC),
        //special keys left side
        KC_TRNS, KC_TRNS,
        //special keys right side
        KC_TRNS, KC_TRNS,
       // thumb cluster
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS),

     [_DANISH] = LAYOUT(
         // first row left side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         // first row right side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UM(AA_LOWER),
         // second row left side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         // second row right side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UM(AE_LOWER), UM(OE_LOWER),
         //third row left side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // third row right side
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         // special keys left side
         KC_TRNS, KC_TRNS,
        // special keys right side
         KC_TRNS, KC_TRNS,
         //thumb cluster
         KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS)

};
