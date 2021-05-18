/* Copyright
 *   2021 solartempest
 *   2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "PS17.h"
#ifdef RGBLIGHT_ENABLE
	extern rgblight_config_t rgblight_config; // To pull layer status for RGBLIGHT
#endif

enum layer_names {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4,
    _LAYER5,
    _LAYER6,
    _LAYER7,
    _LAYER8,
    _LAYER9
};
	  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(
		KC_PGDOWN, KC__MUTE, KC_PGUP,
		MO(_LAYER1), KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
        KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER,
        KC_KP_0,          KC_KP_DOT
    ),
    [_LAYER1] = LAYOUT(
		KC_RIGHT, KC_TRNS, KC_LEFT,
        KC_TRNS, KC_MEDIA_STOP, KC_SPACE, KC_NUMLOCK,
        KC_TRNS, TG(_LAYER2), TG(_LAYER3), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS,          KC_TRNS
    ),
    [_LAYER2] = LAYOUT(
		KC_RBRACKET, KC_TRNS, KC_LBRACKET,
        TO(0), KC_B, KC_T, KC_TRNS,
        KC_J, KC_S, KC_D, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_M,
        KC_TRNS, KC_TRNS, KC_LSHIFT, KC_TRNS,
        KC_SPACE,          KC_LALT
    ),
    [_LAYER3] = LAYOUT(
		KC_PGDOWN, KC_TRNS, KC_PGUP,
        TO(0), KC_WWW_REFRESH, KC_HOME, KC_TRNS,
        KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_WWW_BACK, KC_SPACE, KC_WWW_FORWARD, KC_ENTER,
        KC_TRNS,          KC_TRNS
    ),
    [_LAYER4] = LAYOUT(
		KC_PGDOWN, KC_TRNS, KC_PGUP,
        TO(0), KC_WWW_REFRESH, KC_HOME, KC_TRNS,
        KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_WWW_BACK, KC_SPACE, KC_WWW_FORWARD, KC_ENTER,
        KC_TRNS,          KC_SCROLLLOCK
    ),
    [_LAYER5] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS
    ),
    [_LAYER6] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS
    ),
    [_LAYER7] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS
    ),
    [_LAYER8] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS
    ),
    [_LAYER9] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS
    )
};

void matrix_init_user(void) { //run when matrix is initiated, before all features init
};

void matrix_scan_user(void) { //run whenever user matrix is scanned
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { //Actions to override existing key behaviours
	return true;
};


void keyboard_post_init_user(void) {	//run as last task in keyboard init
  #ifdef RGB_MATRIX_ENABLE
    //NOTE 1: Layer lighting doesn't work in RGB matrix mode
	//NOTE 2: VIA lighting tab doesn't work and will crash in RGB matrix mode
	//NOTE 3: VIA layers doesn't seem to work properly in RGB matrix mode
	//rgb_matrix_enable_noeeprom(); //turn on RGB matrix based on previous state
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE); //set initial RGB matrix mode	
	rgb_matrix_sethsv_noeeprom(58, 255, 80); //sets LED to green-yellow
  #endif
  #ifdef RGBLIGHT_ENABLE
	rgblight_enable();
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT+8); //Set to static gradient 9. Looks great this way!
	rgblight_sethsv(58, 255, 30); //Set lower default brightness when connected as the right side dimming is not yet in effect
  #endif
};


#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		//This custom layer lighting is similar to RGB Light Gradient 9, but customized to separate key and case underglow brightness
		static uint16_t underglow_brightness = 140;
		static uint16_t perkey_brightness = 80;
		static uint16_t current_hue = 0; //hue calculated to be used
		static uint16_t layer0_huestart = 56; //hue gradient starting colour - green/blue
		static uint16_t layer0_hueincrement = 2; //hue gradient colour increment
		static uint16_t layer1_huestart = 15; //hue gradient starting colour - orange/green
		static uint16_t layer1_hueincrement = 2; //hue gradient colour increment
		static uint16_t layer2_huestart = 220; //hue gradient starting colour - magenta/orange
		static uint16_t layer2_hueincrement = 2; //hue gradient colour increment
		static uint16_t layer3_huestart = 135; //hue gradient starting colour - blue/purple
		static uint16_t layer3_hueincrement = 2; //hue gradient colour increment
		static uint16_t layer4_huestart = 30; //hue gradient starting colour - orange/red
		static uint16_t layer4_hueincrement = 1; //hue gradient colour increment
		
		/*#define RGBLIGHT_LED_MAP LED_LAYOUT( \
		1,                 0, \
		3,                 2, \
		9,   8, 7,  6,  5, 4, \
			13, 12, 11, 10,   \
		18, 17, 16, 15,    14,\
			22, 21, 20, 19,   \
		27, 26, 25, 24,    23 )*/
		
		case _LAYER0:
			for (uint8_t i = 0; i < RGBLED_NUM; i++){
				current_hue=i*layer0_hueincrement+layer0_huestart; //Determine the calculated hue
				if(current_hue>255){current_hue=current_hue-255;}; //Roll over max hue of 256
				if (i == 0  || i == 1 || i == 2 || i == 3 || i == 4 || i == 9 || i == 14 || i == 18 || i == 23 || i == 25 || i == 27) {	  
				  rgblight_sethsv_at(current_hue,255,underglow_brightness,i);
				} else {
				  rgblight_sethsv_at(current_hue,255,perkey_brightness,i);
				};
			};
			break;
		case _LAYER1:
			for (uint8_t i = 0; i < RGBLED_NUM; i++){
				current_hue=i*layer1_hueincrement+layer1_huestart; //Determine the calculated hue
				if(current_hue>255){current_hue=current_hue-255;}; //Roll over max hue of 256
				if (i == 0  || i == 1 || i == 2 || i == 3 || i == 4 || i == 9 || i == 14 || i == 18 || i == 23 || i == 25 || i == 27) {	  
				  rgblight_sethsv_at(current_hue,255,underglow_brightness,i);
				} else {
				  rgblight_sethsv_at(current_hue,255,perkey_brightness,i);
				};
			};
			break;
		case _LAYER2:
			for (uint8_t i = 0; i < RGBLED_NUM; i++){ //This code is for normal gradient colouration
				current_hue=i*layer2_hueincrement+layer2_huestart; //Determine the calculated hue
				if(current_hue>255){current_hue=current_hue-255;}; //Roll over max hue of 256
				if (i == 0  || i == 1 || i == 2 || i == 3 || i == 4 || i == 9 || i == 14 || i == 18 || i == 23 || i == 25 || i == 27) {	  
				  rgblight_sethsv_at(current_hue,255,underglow_brightness,i);
				} else {
				  rgblight_sethsv_at(current_hue,255,perkey_brightness,i);
				};
			};
			break;
		case _LAYER3:
			for (uint8_t i = 0; i < RGBLED_NUM; i++){
				current_hue=i*layer3_hueincrement+layer3_huestart; //Determine the calculated hue
				if(current_hue>255){current_hue=current_hue-255;}; //Roll over max hue of 256
				if (i == 0  || i == 1 || i == 2 || i == 3 || i == 4 || i == 9 || i == 14 || i == 18 || i == 23 || i == 25 || i == 27) {	  
				  rgblight_sethsv_at(current_hue,255,underglow_brightness,i);
				} else {
				  rgblight_sethsv_at(current_hue,255,perkey_brightness,i);
				};
			};
			break;
		case _LAYER4:
			for (uint8_t i = 0; i < RGBLED_NUM; i++){
				current_hue=i*layer4_hueincrement+layer4_huestart; //Determine the calculated hue
				if(current_hue>255){current_hue=current_hue-255;}; //Roll over max hue of 256
				if (i == 0  || i == 1 || i == 2 || i == 3 || i == 4 || i == 9 || i == 14 || i == 18 || i == 23 || i == 25 || i == 27) {	  
				  rgblight_sethsv_at(current_hue,255,underglow_brightness,i);
				} else {
				  rgblight_sethsv_at(current_hue,255,perkey_brightness,i);
				};
			};
		}
	return state;
	};
#endif
