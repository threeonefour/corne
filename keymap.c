#include QMK_KEYBOARD_H
#include "sendstring_german.h"
#include "sm_td.c"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

if (!process_smtd(keycode, record)) {
        return false;
    }

return true;
}




bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 2:
                rgb_matrix_set_color(i, RGB_MAGENTA);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_SPRINGGREEN);
                break;
			 case 0:
                rgb_matrix_set_color(i, RGB_WHITE);
                break;
			case 3:
                rgb_matrix_set_color(i, RGB_TURQUOISE);
                break;
				
            default:
                break;
        }
		
    }
    return false;
}

const key_override_t exlm_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_EXLM, DE_QUES);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&exlm_key_override,
	&delete_key_override
};



smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {  // smtd mod tap implementation
    switch (keycode) {
        SMTD_MT(KC_A, KC_LSFT)
        SMTD_MT(KC_S, KC_LEFT_ALT)
        SMTD_MT(KC_D, KC_LEFT_CTRL)
        SMTD_MT(KC_F, KC_LEFT_GUI)
		SMTD_MT(KC_J, KC_LEFT_GUI)
        SMTD_MT(KC_K, KC_LEFT_CTRL)
        SMTD_MT(KC_L, KC_LEFT_ALT)
		SMTD_MT(DE_MINS, KC_RSFT)
        SMTD_MT(DE_ASTR, KC_LSFT)
		SMTD_MT(DE_DLR, KC_LEFT_ALT)
		SMTD_MT(DE_EQL, KC_LEFT_CTRL)
		SMTD_MT(DE_HASH, KC_LEFT_GUI)
		
		
		
		
    }
	return SMTD_RESOLUTION_UNHANDLED;
}



#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3_ex2(
  //,--------------------------------------------------------------------------.         ,-----------------------------------------------------------------------.
         DE_Q,            DE_W,           DE_E,       DE_R,      DE_T, KC_ESC,            KC_F5,     DE_Z,    DE_U,       DE_I,       DE_O,           DE_P,
  //+----------------+-------------+-------------+-------------+--------------+          |---------+-----+-------------+-------------+-------------+-------------+
         KC_A,          KC_S,       KC_D,       KC_F,       DE_G, LCTL(DE_C),             LCTL(DE_V), KC_H,   KC_J,       KC_K,       KC_L,         DE_MINS,
  //+----------------+-------------+-------------+-------------+-----+--------'          `---------+-----+-------------+-------------+-------------+-------------+
         DE_Y,              DE_X,        DE_C,        DE_V,     DE_B,                                DE_N,    DE_M,       DE_COMM,        DE_DOT,      DE_EXLM,
  //+----------------+-------------+-------------+-------------+-----+--------.          ,---------+-----+-------------+-------------+-------------+-------------+
                                               KC_TAB,    TL_UPPR,    KC_SPC,             KC_ENT,    TL_LOWR,    KC_BSPC 

  ),

  [1] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,------------------------------------------------------.
         DE_1,    DE_2,    DE_3,    DE_4,    DE_5, _______,   KC_F4,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
     DE_ASTR,  DE_DLR, DE_EQL, DE_HASH, DE_SLSH, LCTL(DE_X),LCTL(DE_C), DE_BSLS, DE_PIPE, KC_UP   ,LSG(KC_S), DE_AT,
  //+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      DE_TILD, DE_DQUO, DE_QUOT, DE_PERC, DE_AMPR,                      DE_CIRC, KC_LEFT, KC_DOWN,  KC_RIGHT, DE_PLUS,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                _______, _______,   _______,   _______, _______, _______
                            //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,------------------------------------------------------
     DE_LBRC, DE_RBRC, DE_LCBR,  DE_RCBR, DE_ACUT, _______,     _______, DE_MICR, DE_UDIA,DE_SECT, DE_ODIA, DE_DEG,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
     DE_ADIA,  DE_SS , DE_MICR  , DE_EURO, DE_DLR, KC_MUTE,    _______, DE_ASTR,  KC_J,   KC_K,     KC_L,   DE_QUES,
  //|--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
     DE_SUP2, DE_SUP3,  DE_TILD,  LCTL(KC_SPC), RCS(DE_M),                      DE_LPRN, DE_RPRN, DE_LABK, DE_RABK, DE_HASH,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                  _______, _______,  _______,    _______, _______, _______
                             //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,-----------------------------------------------------
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+-------
     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  //+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                     KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                  _______, _______,  _______,     _______, _______, _______
                             //`--------------------------'  `--------------------------'
  )
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
  [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
  [3] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
};
#endif
