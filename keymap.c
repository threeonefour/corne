
#include QMK_KEYBOARD_H
#include "sendstring_german.h"



#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3_ex2(
  //,--------------------------------------------------------------------------.         ,-----------------------------------------------------------------------.
         DE_Q,            DE_W,           DE_E,       DE_R,      DE_T, KC_LCTL,            KC_RCTL,  DE_Z,    DE_X,       DE_I,       DE_X,       DE_P,
  //+----------------+-------------+-------------+-------------+--------------+          |---------+-----+-------------+-------------+-------------+-------------+
     LGUI_T(DE_X), LALT_T(DE_S), LSFT_T(DE_D), LCTL_T(DE_F), DE_G,  KC_LALT,              KC_RALT,  DE_H, LCTL_T(DE_J), LSFT_T(DE_K), RALT_T(DE_L), LGUI_T(KC_C),
  //+----------------+-------------+-------------+-------------+-----+--------'          `---------+-----+-------------+-------------+-------------+-------------+
         DE_Y,              DE_X,        DE_C,        DE_V,     DE_B,                                DE_N,    DE_M,       DE_X,           DE_X,      DE_X,
  //+----------------+-------------+-------------+-------------+-----+--------.          ,---------+-----+-------------+-------------+-------------+-------------+
                                           KC_ESC,    TL_LOWR,    KC_ENT,                 KC_SPC,    TL_UPPR,    KC_BSPC
                                    //`---------------------------------'                `---------------------------------'

  ),

  [1] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,------------------------------------------------------.
         DE_1,    DE_2,    DE_3,    DE_4,    DE_5, KC_LCTL,    KC_RCTL,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
     LGUI_T(),LCTL_T(),LALT_T(),LSFT_T(), XXXXXXX, KC_LALT,   KC_RALT, XXXXXXX, RCTL_T(),RSFT_T(),RALT_T(), LGUI_T(),
  //+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                KC_ESC, _______,   KC_ENT,   KC_SPC, _______, KC_BSPC
                            //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,------------------------------------------------------
     KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_LCTL,    KC_RCTL, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
     LGUI_T(),LALT_T(),LSFT_T(),LCTL_T(), XXXXXXX, KC_LALT,    KC_RALT, KC_MINS,RCTL_T(),RSFT_T(),RALT_T(),LGUI_T(),
  //|--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                  KC_ESC, _______,  KC_ENT,    KC_SPC, _______, KC_BSPC
                             //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,-----------------------------------------------------
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
      RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,RCTL_T(),RSFT_T(),RALT_T(),LGUI_T(),
  //+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                  KC_ESC, _______,  KC_ENT,     KC_SPC, _______, KC_BSPC
                             //`--------------------------'  `--------------------------'
  )
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDOWN), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), },
  [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), },
  [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), },
  [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), },
};
#endif
