#include QMK_KEYBOARD_H

uint8_t key_led[MATRIX_ROWS*MATRIX_COLS] = {0};

enum custom_keycodes {
		      MY_MUTE = SAFE_RANGE, /* TODO: put MY_MUTE on base layer and make it transparent for all other layers */
		      };

#define MY_CAD (C(A(KC_DEL))) /* alt + ctrl + del (keycode = 054Ch -> 5h: modifier alt+ctrl pressed, 4Ch: KC_DELETE */

#define _BL 0
#define _FL 1
#define _ML 2

const char* PROGMEM layer_help[] = {
			[_BL] =	   "BASIC",
			[_FL] =	   "FUNCTION",
			[_ML] =	   "MOUSE"
};

/* from keycode.h */
const char* PROGMEM key_help[] = {
    [0x00] = "KC_NO",
    "KC_ROLL_OVER",
    "KC_POST_FAIL",
    "KC_UNDEFINED",
    "KC_A",
    "KC_B",
    "KC_C",
    "KC_D",
    "KC_E",
    "KC_F",
    "KC_G",
    "KC_H",
    "KC_I",
    "KC_J",
    "KC_K",
    "KC_L",
    "KC_M",  // 0x10
    "KC_N",
    "KC_O",
    "KC_P",
    "KC_Q",
    "KC_R",
    "KC_S",
    "KC_T",
    "KC_U",
    "KC_V",
    "KC_W",
    "KC_X",
    "KC_Y",
    "KC_Z",
    "KC_1",
    "KC_2",
    "KC_3",  // 0x20
    "KC_4",
    "KC_5",
    "KC_6",
    "KC_7",
    "KC_8",
    "KC_9",
    "KC_0",
    "KC_ENTER",
    "KC_ESCAPE",
    "KC_BSPACE",
    "KC_TAB",
    "KC_SPACE",
    "KC_MINUS",
    "KC_EQUAL",
    "KC_LBRACKET",
    "KC_RBRACKET",  // 0x30
    "KC_BSLASH",
    "KC_NONUS_HASH",
    "KC_SCOLON",
    "KC_QUOTE",
    "KC_GRAVE",
    "KC_COMMA",
    "KC_DOT",
    "KC_SLASH",
    "KC_CAPSLOCK",
    "KC_F1",
    "KC_F2",
    "KC_F3",
    "KC_F4",
    "KC_F5",
    "KC_F6",
    "KC_F7",  // 0x40
    "KC_F8",
    "KC_F9",
    "KC_F10",
    "KC_F11",
    "KC_F12",
    "KC_PSCREEN",
    "KC_SCROLLLOCK",
    "KC_PAUSE",
    "KC_INSERT",
    "KC_HOME",
    "KC_PGUP",
    "KC_DELETE",
    "KC_END",
    "KC_PGDOWN",
    "KC_RIGHT",
    "KC_LEFT",  // 0x50
    "KC_DOWN",
    "KC_UP",
    "KC_NUMLOCK",
    "KC_KP_SLASH",
    "KC_KP_ASTERISK",
    "KC_KP_MINUS",
    "KC_KP_PLUS",
    "KC_KP_ENTER",
    "KC_KP_1",
    "KC_KP_2",
    "KC_KP_3",
    "KC_KP_4",
    "KC_KP_5",
    "KC_KP_6",
    "KC_KP_7",
    "KC_KP_8",  // 0x60
    "KC_KP_9",
    "KC_KP_0",
    "KC_KP_DOT",
    "KC_NONUS_BSLASH",
    "KC_APPLICATION",
    "KC_POWER",
    "KC_KP_EQUAL",
    "KC_F13",
    "KC_F14",
    "KC_F15",
    "KC_F16",
    "KC_F17",
    "KC_F18",
    "KC_F19",
    "KC_F20",
    "KC_F21",  // 0x70
    "KC_F22",
    "KC_F23",
    "KC_F24",
    "KC_EXECUTE",
    "KC_HELP",
    "KC_MENU",
    "KC_SELECT",
    "KC_STOP",
    "KC_AGAIN",
    "KC_UNDO",
    "KC_CUT",
    "KC_COPY",
    "KC_PASTE",
    "KC_FIND",
    "KC__MUTE",
    "KC__VOLUP",  // 0x80
    "KC__VOLDOWN",
    "KC_LOCKING_CAPS",
    "KC_LOCKING_NUM",
    "KC_LOCKING_SCROLL",
    "KC_KP_COMMA",
    "KC_KP_EQUAL_AS400",
    "KC_INT1",
    "KC_INT2",
    "KC_INT3",
    "KC_INT4",
    "KC_INT5",
    "KC_INT6",
    "KC_INT7",
    "KC_INT8",
    "KC_INT9",
    "KC_LANG1",  // 0x90
    "KC_LANG2",
    "KC_LANG3",
    "KC_LANG4",
    "KC_LANG5",
    "KC_LANG6",
    "KC_LANG7",
    "KC_LANG8",
    "KC_LANG9",
    "KC_ALT_ERASE",
    "KC_SYSREQ",
    "KC_CANCEL",
    "KC_CLEAR",
    "KC_PRIOR",
    "KC_RETURN",
    "KC_SEPARATOR",
    "KC_OUT",  // 0xA0
    "KC_OPER",
    "KC_CLEAR_AGAIN",
    "KC_CRSEL",
    "KC_EXSEL",

#if 0
  // ***************************************************************
  // These keycodes are present in the HID spec, but are           *
  // nonfunctional on modern OSes. QMK uses this range (0xA5-0xDF) *
  // for the media and function keys instead - see below.          *
  // ***************************************************************

    [0xb0] = "KC_KP_00",
    "KC_KP_000",
    "KC_THOUSANDS_SEPARATOR",
    "KC_DECIMAL_SEPARATOR",
    "KC_CURRENCY_UNIT",
    "KC_CURRENCY_SUB_UNIT",
    "KC_KP_LPAREN",
    "KC_KP_RPAREN",
    "KC_KP_LCBRACKET",
    "KC_KP_RCBRACKET",
    "KC_KP_TAB",
    "KC_KP_BSPACE",
    "KC_KP_A",
    "KC_KP_B",
    "KC_KP_C",
    "KC_KP_D",
    "KC_KP_E",             //0xC0
    "KC_KP_F",
    "KC_KP_XOR",
    "KC_KP_HAT",
    "KC_KP_PERC",
    "KC_KP_LT",
    "KC_KP_GT",
    "KC_KP_AND",
    "KC_KP_LAZYAND",
    "KC_KP_OR",
    "KC_KP_LAZYOR",
    "KC_KP_COLON",
    "KC_KP_HASH",
    "KC_KP_SPACE",
    "KC_KP_ATMARK",
    "KC_KP_EXCLAMATION",
    "KC_KP_MEM_STORE",        //0xD0
    "KC_KP_MEM_RECALL",
    "KC_KP_MEM_CLEAR",
    "KC_KP_MEM_ADD",
    "KC_KP_MEM_SUB",
    "KC_KP_MEM_MUL",
    "KC_KP_MEM_DIV",
    "KC_KP_PLUS_MINUS",
    "KC_KP_CLEAR",
    "KC_KP_CLEAR_ENTRY",
    "KC_KP_BINARY",
    "KC_KP_OCTAL",
    "KC_KP_DECIMAL",
    "KC_KP_HEXADECIMAL",
#endif

    /* Modifiers */
    [0xe0] = "KC_LCTRL",
    "KC_LSHIFT",
    "KC_LALT",
    "KC_LGUI",
    "KC_RCTRL",
    "KC_RSHIFT",
    "KC_RALT",
    "KC_RGUI",

    // **********************************************
    // * 0xF0-0xFF are unallocated in the HID spec. *
    // * QMK uses these for Mouse Keys - see below. *
    // **********************************************


    /* Media and Function keys */
    /* Generic Desktop Page (0x01) */
    [0xa5] = "KC_SYSTEM_POWER",
    "KC_SYSTEM_SLEEP",
    "KC_SYSTEM_WAKE",

    /* Consumer Page (0x0C) */
    "KC_AUDIO_MUTE",
    "KC_AUDIO_VOL_UP",
    "KC_AUDIO_VOL_DOWN",
    "KC_MEDIA_NEXT_TRACK",
    "KC_MEDIA_PREV_TRACK",
    "KC_MEDIA_STOP",
    "KC_MEDIA_PLAY_PAUSE",
    "KC_MEDIA_SELECT",
    "KC_MEDIA_EJECT",  // 0xB0
    "KC_MAIL",
    "KC_CALCULATOR",
    "KC_MY_COMPUTER",
    "KC_WWW_SEARCH",
    "KC_WWW_HOME",
    "KC_WWW_BACK",
    "KC_WWW_FORWARD",
    "KC_WWW_STOP",
    "KC_WWW_REFRESH",
    "KC_WWW_FAVORITES",
    "KC_MEDIA_FAST_FORWARD",
    "KC_MEDIA_REWIND",
    "KC_BRIGHTNESS_UP",
    "KC_BRIGHTNESS_DOWN",

    /* Fn keys */
    [0xc0] = "KC_FN0",
    "KC_FN1",
    "KC_FN2",
    "KC_FN3",
    "KC_FN4",
    "KC_FN5",
    "KC_FN6",
    "KC_FN7",
    "KC_FN8",
    "KC_FN9",
    "KC_FN10",
    "KC_FN11",
    "KC_FN12",
    "KC_FN13",
    "KC_FN14",
    "KC_FN15",
    "KC_FN16",  // 0xD0
    "KC_FN17",
    "KC_FN18",
    "KC_FN19",
    "KC_FN20",
    "KC_FN21",
    "KC_FN22",
    "KC_FN23",
    "KC_FN24",
    "KC_FN25",
    "KC_FN26",
    "KC_FN27",
    "KC_FN28",
    "KC_FN29",
    "KC_FN30",
    "KC_FN31",

    /* Mouse Buttons */
    [0xf0] = "KC_MS_UP",
    "KC_MS_DOWN",
    "KC_MS_LEFT",
    "KC_MS_RIGHT",
    "KC_MS_BTN1",
    "KC_MS_BTN2",
    "KC_MS_BTN3",
    "KC_MS_BTN4",
    "KC_MS_BTN5",

    /* Mouse Wheel */
    "KC_MS_WH_UP",
    "KC_MS_WH_DOWN",
    "KC_MS_WH_LEFT",
    "KC_MS_WH_RIGHT",

    /* Acceleration */
    "KC_MS_ACCEL0",
    "KC_MS_ACCEL1",
    "KC_MS_ACCEL2"				  
};



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
		                         MY_CAD ,                     _______,                                             _______,                 KC_MUTE,          _______, DM_RSTP
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

    uint8_t my_layer = 0;
char help_buf[30];
    uint8_t my_mute = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static uint8_t my_static_layer = _BL;
    uint8_t overwrite_mute = 0;
    

    switch (keycode) {
      #if 1
        case MY_MUTE:
            if (record->event.pressed) {
	      my_mute ^= 0x01; 
            } /*else {
	      my_mute = 0;
	      }*/
            break;
      #endif
      case MO(_FL):
        if (record->event.pressed) {
	  my_static_layer |= (1<<_FL);
        } else {
	  my_static_layer &= ~(1<<_FL);
	}
	overwrite_mute = 1;
        break;
      case MO(_ML):
        if (record->event.pressed) {
	  my_static_layer |= (1<<_ML);
        } else {
	  my_static_layer &= ~(1<<_ML);
	}
	overwrite_mute = 1;
        break;
		
    }



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
	if (keymaps[my_layer][m][n] == MO(_FL) || keymaps[my_layer][m][n] == MO(_ML)) {
	  key_led[m*MATRIX_COLS+n] = 3; // g+r = yellow (to highlight function keys)
	} else if (keymaps[my_layer][m][n] != _______) {
          key_led[m*MATRIX_COLS+n] = 4; // b = blue
	} else {
          key_led[m*MATRIX_COLS+n] = 0;
	}
      }
    }
    
    
    /* show help text when key is pressed and MY_MUTE is active */
    if (my_mute != 0 && overwrite_mute == 0) {
      if (IS_ANY(keycode)) {
	sprintf(help_buf,"%s\n", key_help[keycode]);
      } else {
	switch (keycode) {
	  case AU_TOG:
	    sprintf(help_buf,"AU_TOG\n");
	    break;
	  case DM_REC1:
	    sprintf(help_buf,"DM_REC1\n");
	    break;
	  case DM_PLY1:
	    sprintf(help_buf,"DM_PLY1\n");
	    break;
	  case DM_RSTP:
	    sprintf(help_buf,"DM_RSTP\n");
	    break;
	  case MY_CAD:
	    sprintf(help_buf,"Ctrl+Alt+Del\n");
	    break;
          default:
	    sprintf(help_buf,"UNKWN (%04Xh)\n", keycode);
	}
	
      }
      return false; // do not further process keycode
    } else {
      sprintf(help_buf,"\n", keycode);
      return true; // do further processing
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
  char buf[21*4]; // 4 lines a 21 characters
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
  if (my_layer == _BL && my_mute == 0) {
    render_logo();
  } else {
    sprintf(buf,"\nLayer: %s\n%s", layer_help[my_layer], help_buf);
    oled_write_P(PSTR(buf), false);
  }
    
  
  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}



#endif
