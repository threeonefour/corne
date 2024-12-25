#include QMK_KEYBOARD_H
#include "sendstring_german.h"

enum custom_keycodes {
 SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A, 
    CKC_S,
    CKC_D,
    CKC_F,
	CKC_J,
	CKC_K,
	CKC_L,
	CKC_HASH,
    SMTD_KEYCODES_END,

};

#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

if (!process_smtd(keycode, record)) {
        return false;
    }
/*
const uint8_t mods = get_mods();
const uint8_t oneshot_mods = get_oneshot_mods();


switch (keycode) {
    case BRACES:  // Types opening brackets
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        tap_code(DE_LCBR);
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        tap_code(DE_LBRC);
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        tap_code(DE_LABK);
      } else {
        tap_code(DE_LPRN);
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
	case BRACES_CL:  // closes brackets
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        tap_code(DE_RCBR);
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        tap_code(DE_RBRC);
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        tap_code(DE_RABK);
      } else {
        tap_code(DE_RPRN);
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
	
    case SPEC:  // Some special characters
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        tap_code(DE_DEG);
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        tap_code(DE_EURO);
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        tap_code(DE_AT);
      } else {
        tap_code(DE_CIRC);
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
	
	case INTRPKT:  // Types . , ; or : depending on pressed mod
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        tap_code(DE_COMM);
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        tap_code(DE_COLN);
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        tap_code(DE_SCLN);
      } else {
        tap_code(DE_DOT);
      }
      register_mods(mods);  // Restore mods.
    }
    return false;

  case UEMLAUT:  // Types u U ü Ü.
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING("U");
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING("ü");
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        SEND_STRING("Ü");
      } else {
        SEND_STRING("u");
      }
            register_mods(mods);  // Restore mods.
    }
    return false;
	
	case AEMLAUT:  // a A ä Ä
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING("A");
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING("ä");
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        SEND_STRING("Ä");
      } else {
        SEND_STRING("a");
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
	case OEMLAUT: // you get the idea
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING("O");
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING("ö");
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        SEND_STRING("Ö");
      } else {
        SEND_STRING("o");
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
	case EXCLM:  //  Exclamation, question and slashes
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING("!");
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING("?");
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        SEND_STRING("/");
      } else {
        SEND_STRING("\\");
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
	case ESZET:  // some more german snowflake stuff
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING("S");
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING("ß");
      }	else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        SEND_STRING("ß");
      } else {
        SEND_STRING("s");
      }
      
      register_mods(mods);  // Restore mods.
    }
    return false;
	
  }
	
	*/
return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {  // smtd mod tap implementation
    switch (keycode) {
        SMTD_MT(CKC_A, DE_A, KC_LSFT)
        SMTD_MT(CKC_S, DE_S, KC_LEFT_ALT)
        SMTD_MT(CKC_D, DE_D, KC_LEFT_CTRL)
        SMTD_MT(CKC_F, DE_F, KC_LEFT_GUI)
		SMTD_MT(CKC_J, DE_J, KC_LEFT_GUI)
        SMTD_MT(CKC_K, DE_K, KC_LEFT_CTRL)
        SMTD_MT(CKC_L, DE_L, KC_LEFT_ALT)
        SMTD_MT(CKC_HASH, DE_HASH, KC_LSFT)
		
		
		
    }
}



#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3_ex2(
  //,--------------------------------------------------------------------------.         ,-----------------------------------------------------------------------.
         DE_Q,            DE_W,           DE_E,       DE_R,      DE_T, KC_ESC,            DE_SS,     DE_Y,    DE_U,       DE_I,       DE_O,       DE_P,
  //+----------------+-------------+-------------+-------------+--------------+          |---------+-----+-------------+-------------+-------------+-------------+
         CKC_A,          CKC_S,       CKC_D,       CKC_F,       DE_G, LCTL(DE_C),         LCTL(DE_V),DE_H,   CKC_J,       CKC_K,       CKC_L,       CKC_HASH,
  //+----------------+-------------+-------------+-------------+-----+--------'          `---------+-----+-------------+-------------+-------------+-------------+
         DE_Z,              DE_X,        DE_C,        DE_V,     DE_B,                                DE_N,    DE_M,       DE_COMM,        DE_DOT,      DE_MINS,
  //+----------------+-------------+-------------+-------------+-----+--------.          ,---------+-----+-------------+-------------+-------------+-------------+
                                               KC_TAB,    TL_UPPR,    KC_SPC,             KC_ENT,    TL_LOWR,    KC_BSPC
                                          //`---------------------------------'            ---------------------------------'

  ),

  [1] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,------------------------------------------------------.
         DE_1,    DE_2,    DE_3,    DE_4,    DE_5, _______,   _______,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
     _______,  _______, _______, _______, DE_SLSH, _______,    _______, DE_BSLS, XXXXXXX, KC_UP     ,DE_PIPE, DE_AT,
  //+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      DE_EXLM, DE_DQUO, DE_DLR, DE_PERC, DE_AMPR,                      DE_CIRC, KC_LEFT, KC_DOWN,  KC_RIGHT, DE_EURO,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                _______, _______,   _______,   _______, _______, _______
                            //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,------------------------------------------------------
     DE_7,      DE_8,   DE_9,    DE_PLUS, DE_MINS, _______,     _______, DE_LBRC, DE_RBRC, DE_LCBR, DE_RCBR, DE_ACUT,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
     DE_4,      DE_5,   DE_6,   DE_ASTR, DE_SLSH, _______,    _______, XXXXXXX,_______,_______,_______,_______,
  //|--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      DE_1,      DE_2,    DE_3,     DE_0, XXXXXXX,                      DE_LPRN, DE_RPRN, DE_LABK, DE_RABK, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                  _______, _______,  _______,    _______, _______, _______
                             //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.  ,-----------------------------------------------------
      XXXXXXX, XXXXXXX, XXXXXXX, DE_DEG, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, DE_UDIA, XXXXXXX, DE_ODIA, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
      DE_ADIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,_______,_______,_______,_______,
  //+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+
                                  _______, _______,  _______,     _______, _______, _______
                             //`--------------------------'  `--------------------------'
  )
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
  [1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
  [2] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
  [3] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
};
#endif
