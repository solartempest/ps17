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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x414B // "AK"
#define PRODUCT_ID      0x0015
#define DEVICE_VER      0x0002 // Ver2
#define MANUFACTURER    ATLANTIS
#define PRODUCT         PS17

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

    /*k10, k11, k12, k13 \
      k20, k21, k22, k23 \
      k30, k31, k32, ___ \
      k40, k41, k42, k43 \
      k50, ___, k52, ___  \*/

/* Planck PCB default pin-out */
#define MATRIX_ROW_PINS { B4, B5, B6, C6, C7 }
#define MATRIX_COL_PINS { F6, F7, D3, D6 }
#define UNUSED_PINS

//#define ENCODER_RESOLUTION 2 // default is 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST
#define RGB_DI_PIN B3
#ifdef RGB_DI_PIN
	#define RGBLIGHT_ANIMATIONS
	#define RGBLED_NUM 28 // 17 key + 11 underglow
	#define RGBLIGHT_HUE_STEP 8
	#define RGBLIGHT_SAT_STEP 8
	#define RGBLIGHT_VAL_STEP 8
	#define RGBLIGHT_LIMIT_VAL 150 //  brightness level max is 255
	#define RGBLIGHT_SLEEP //  if defined, RGB lighting off when host is sleeping
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
