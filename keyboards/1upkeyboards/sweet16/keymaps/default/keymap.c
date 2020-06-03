#include QMK_KEYBOARD_H

uint8_t key_led[MATRIX_ROWS*MATRIX_COLS] = {0};

enum custom_keycodes {
  MY_MUTE = SAFE_RANGE
};

#define _BL 0
#define _FL 1
#define _ML 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if 0							      
    LAYOUT_ortho_4x4(
	RGB_TOG, RGB_HUI, RGB_MOD, KC_CALCULATOR,  
        KC_7,    KC_8,    KC_9,    KC_MS_UP,   
        KC_4,    KC_5,    KC_6,    KC_LOCKING_NUM, 
        KC_1,    KC_2,    KC_3,    KC_MS_DOWN
    )
#else
    #if 0
    /* KC_SYSTEM_WAKE @ TOP LEFT OF NUMLOCK (X|)*/
    LAYOUT_ortho_4x4(
		     KC_ESC,    KC_F1,       KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,    KC_F10, KC_F11,    KC_F12,                   KC_PSCREEN, KC_PAUSE,       KC_END,            KC_HELP,
		     KC_GRAVE,  KC_1,        KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,     KC_0,   KC_MINUS,  KC_EQUAL,    KC_BSPACE,   RGB_TOG,    KC_LOCKING_NUM, KC_LOCKING_SCROLL, KC_KP_SLASH,
/* FUNCTION KEY -> */KC_NO,     KC_TAB,      KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,   KC_P,      KC_LBRACKET, KC_RBRACKET, KC_KP_7,    KC_KP_8,        KC_KP_9,           KC_KP_ASTERISK,
		     KC_LCTRL,  KC_CAPSLOCK, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,   KC_SCOLON, KC_QUOTE,    KC_BSLASH,   KC_KP_4,    KC_KP_5,        KC_KP_6,           KC_KP_MINUS,
		     KC_LSHIFT, KC_NO,       KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMMA, KC_DOT, KC_SLASH,  KC_RSHIFT,   KC_ENTER,    KC_KP_1,    KC_KP_2,        KC_KP_3,           KC_KP_PLUS,
		                              KC_LALT,                     KC_SPACE,                              KC_RALT,                           KC_KP_0,                    KC_KP_DOT,         KC_KP_ENTER
		     )
    #else
        [_BL] = LAYOUT_ortho_4x4(
		     KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12  ,          KC_PSCR, KC_PAUS, KC_END , KC_HELP,
		     KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQUAL, KC_BSPC, RGB_TOG, KC_LNUM, KC_LSCR, AU_TOG ,
                     MO(_FL), KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC , KC_RBRC, RGB_MOD, RGB_VAI, RGB_SAI, CK_TOGG,
		     KC_LCTL, KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOTE, KC_BSLS, RGB_HUD, RGB_M_P, RGB_HUI, MU_TOG ,
		     KC_LSFT, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT , KC_ENT , RGB_RMOD,RGB_VAD, RGB_SAD, MU_MOD ,
		                         KC_LALT,                     KC_SPC,                                              KC_RALT,                 KC_KP_0,          KC_DEL , AU_OFF 
			     ),
        [_FL] = LAYOUT_ortho_4x4(
		     EEP_RST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          _______, _______, _______, _______,
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, DM_REC1,
                     _______, MO(_ML), MY_MUTE, KC_LGUI, _______, _______, _______, _______, KC_PGUP, KC_UP  , _______, _______,  _______, _______, _______, KC_VOLU, _______, DM_REC2,
		     KC_CAPS, KC_CAPS, _______, KC_SLEP, KC_DEL , _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,  KC_END , _______, KC_MPRV, KC_MPLY, KC_MNXT, DM_PLY1,
		     _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGDN, _______, _______, _______,  _______, _______, _______, KC_VOLD, _______, DM_PLY2,
		                         _______,                     _______,                                             _______,                 KC_MUTE,          _______, DM_RSTP
			     ),
        [_ML] = LAYOUT_ortho_4x4(
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          _______, _______, _______, _______,
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______,  _______, _______, _______, _______, _______, _______,
		     _______, _______, MY_MUTE, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,  _______, _______, _______, _______, _______, _______,
		     _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,  _______, _______, _______, _______, _______, _______,
		                         _______,                     KC_BTN1,                                             KC_BTN2,                 _______,          _______, _______
			     )
    #endif
#endif    
};

/*
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          _______, _______, _______, _______,
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
		     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
		                         _______,                     _______,                                             _______,                ________,          _______, _______
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    char buf[10];

    static uint8_t my_static_layer = _BL;
    uint8_t my_layer = 0;
    static uint8_t my_mute = 0;
    
    sprintf(buf,"   ", layer_state);
    switch (keycode) {
      #if 1
        case MY_MUTE:
            if (record->event.pressed) {
	      my_mute = 1; 
            } else {
	      my_mute = 0;
	    }
            break;
      #endif
      case MO(_FL):
        if (record->event.pressed) {
	  my_static_layer |= (1<<_FL);
          sprintf(buf,"_FL", layer_state); // overwrite buf
        } else {
	  my_static_layer &= ~(1<<_FL);
	}
        break;
      case MO(_ML):
        if (record->event.pressed) {
	  my_static_layer |= (1<<_ML);
          sprintf(buf,"_ML", layer_state); // overwrite buf
        } else {
	  my_static_layer &= ~(1<<_ML);
	}
        break;
    }

    sprintf(buf,"%s %02x", buf, layer_state);
    oled_write_P(buf, false);

    /* show active keys */
    if ((my_static_layer & (1<<_ML)) == (1<<_ML)) {
      my_layer = _ML;
    } else if ((my_static_layer & (1<<_FL)) == (1<<_FL)) {
      my_layer = _FL;
    } else {
      my_layer = _BL;
    }
    
    for (uint8_t m=0; m<MATRIX_ROWS; m++) {
      for (uint8_t n=0; n<MATRIX_COLS; n++) {
	if (keymaps[my_layer][m][n] != _______) {
          key_led[m*MATRIX_COLS+n] = 1;
	} else {
          key_led[m*MATRIX_COLS+n] = 0;
	}
      }
    }

    /* show help text when key is pressed and MY_MUTE is active */
    if (my_mute != 0) {
      sprintf(buf," %04x", keycode);
      oled_write_P(buf, false);
      return false;
    } else {
      sprintf(buf,"     ", keycode);
      oled_write_P(buf, false);
      return true;
    }
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
void encoder_update_user(int8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
#endif


#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}


void oled_task_user(void) {
  /*
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
  */
  render_logo();
  
  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}



#endif
