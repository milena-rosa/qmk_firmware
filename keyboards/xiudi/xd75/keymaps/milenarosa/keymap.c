/* Copyright 2017 Wunder
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

enum layer_names { _QW, _FN, _DEV };

enum custom_keycodes {
    OS_SWAP = SAFE_RANGE,
    KC_COMMANDS, // ctrl + shift + p
    KC_TOGGLE_COMMENT, // ctrl + /
    KC_RENAME,                 // f2
    KC_FIND_NEXT,              // f3
    KC_DEBUG,                  // f5
    KC_DEBUG_STOP,             // shift + f5
    KC_DEBUG_RESTART,          // ctrl + shift + f5
    KC_TOGGLE_BREAKPOINT,      // f9
    KC_DEBUG_INTO,             // f11
    KC_DEBUG_OUT,              // shift + f11
    KC_GO_DEF,                 // f12
    KC_GO_IMPL,                // shift + f12
    KC_FIND_ALL_REFS,          // shift + alt + f12
    KC_FORMAT,                 // ctrl + alt + f
    KC_UNFOLD_ALL,             // ctrl + k, ctrl + j
    KC_FOLD_ALL,               // ctrl + k, ctrl + 0
    KC_FOLD_COMMENTS,          // ctrl + k, ctrl + /
    KC_DUPLICATE_LINE,         // shift + alt + up
    KC_ADD_CURSOR_ABOVE,       // alt + ctrl + up
    KC_ADD_CURSOR_BELOW,       // alt + ctrl + down
    KC_ADD_CURSORS_LINE_ENDS,  // alt + shift + I
    KC_DELETE_LINE,            // shift + ctrl + k
    KC_OPEN_DEF_SIDE,          // ctrl + k, f12
    KC_SELECT_ALL_OCCURRENCES, // shift + ctrl + l
    KC_SUGGEST,                // ctrl + space
    KC_QUICK_FIX,              // ctrl + .
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAPS  | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | FN     | LCTRL  | LGUI   | LALT   | BACKSP  | ESC  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | DEV   | RALT   | HYPER  | RCTRL   |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15(/* QWERTY */
                              KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                              KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT,
                              KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_HOME, KC_DEL, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
                              KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END, KC_UP, KC_PGDN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                              MO(_FN), KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, KC_ESC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(_DEV), KC_RALT, MOD_HYPR, KC_RCTL),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | QK_BOOT  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15(/* FUNCTION */ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NUM, KC_SLSH, KC_ASTR, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7, KC_P8, KC_P9, KC_MINS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_APP, RGB_VAD, RGB_VAI, KC_P1, KC_P2, KC_P3, KC_PENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN), RGB_RMOD, RGB_MOD, OS_SWAP, RGB_TOG, KC_TRNS, KC_P0, KC_TRNS, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), OS_SWAP, KC_TRNS, KC_TRNS),

    /* DEV
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | _______| F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | _______| KC_DEL |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | KC_COMMANDS | KC_TOGGLE_COMMENT | RENAME |       |       |       |        |        |        |        |        | KC_DELETE_LINE | KC_FOLD_COMMENTS | KC_FOLD_ALL | KC_UNFOLD_ALL |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | KC_DEBUG | KC_DEBUG_RESTART | KC_DEBUG_STOP | KC_DEBUG_INTO | KC_DEBUG_OUT |       |      |       |        |       |       |        | QK_BOOT  |        |        | KC_TOGGLE_BREAKPOINT |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | KC_DUPLICATE_LINE | KC_ADD_CURSOR_ABOVE | KC_ADD_CURSOR_BELOW | KC_ADD_CURSORS_LINE_ENDS | KC_SELECT_ALL_OCCURRENCES |        |        |        |        |        | KC_FIND_ALL_REFS | KC_OPEN_DEF_SIDE | KC_GO_DEF | KC_GO_IMPL | KC_FORMAT |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |       | FN     |       |       |        |        |        |        |        | FN     |        |        | KC_QUICK_FIX |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_DEV] = LAYOUT_ortho_5x15(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_BSPC,
    KC_COMMANDS, KC_TOGGLE_COMMENT, KC_RENAME, LCTL(KC_LBRC), LCTL(KC_RBRC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DELETE_LINE, KC_FOLD_COMMENTS, KC_FOLD_ALL, KC_UNFOLD_ALL, KC_DEBUG, KC_DEBUG_RESTART, KC_DEBUG_STOP, KC_DEBUG_INTO, KC_DEBUG_OUT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_TOGGLE_BREAKPOINT, KC_DUPLICATE_LINE, KC_ADD_CURSOR_ABOVE, KC_ADD_CURSOR_BELOW, KC_ADD_CURSORS_LINE_ENDS, KC_SELECT_ALL_OCCURRENCES, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_FIND_ALL_REFS, KC_OPEN_DEF_SIDE, KC_GO_DEF, KC_GO_IMPL, KC_FORMAT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_QUICK_FIX)};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgblight_sethsv(HSV_WHITE);
            break;
        case OS_WINDOWS:
            rgblight_sethsv(HSV_BLUE);
            break;
        case OS_LINUX:
            rgblight_sethsv(HSV_ORANGE);
            break;
        case OS_UNSURE:
            rgblight_sethsv(HSV_RED);
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_SWAP:
            if (record->event.pressed) {
                // toggle modifier swap
                keymap_config.swap_lalt_lgui = !keymap_config.swap_lalt_lgui;
                keymap_config.swap_ralt_rgui = !keymap_config.swap_ralt_rgui;

                // LED indicator
                if (keymap_config.swap_lalt_lgui) {
                    // win/linux
                    rgblight_sethsv(0, 0, 255);
                } else {
                    // mac
                    rgblight_sethsv(127, 255, 255);
                }

                return false;
            }
            break;

        case KC_RENAME: // f2
            if (record->event.pressed) {
                tap_code16(KC_F2);
                return false;
            }
            break;

        case KC_FIND_NEXT: // f3
            if (record->event.pressed) {
                tap_code16(KC_F3);
                return false;
            }
            break;

        case KC_DEBUG: // f5
            if (record->event.pressed) {
                tap_code16(KC_F5);
                return false;
            }
            break;

        case KC_DEBUG_STOP: // shift + f5
            if (record->event.pressed) {
                tap_code16(LSFT(KC_F5));
                return false;
            }
            break;

        case KC_DEBUG_RESTART: // ctrl + shift + f5
            if (record->event.pressed) {
                tap_code16(LALT(LSFT(KC_F5)));
                return false;
            }
            break;

        case KC_TOGGLE_BREAKPOINT: // f9
            if (record->event.pressed) {
                tap_code16(KC_F9);
                return false;
            }
            break;

        case KC_DEBUG_INTO: // f11
            if (record->event.pressed) {
                tap_code16(KC_F11);
                return false;
            }
            break;

        case KC_DEBUG_OUT: // shift + f11
            if (record->event.pressed) {
                tap_code16(LSFT(KC_F11));
                return false;
            }
            break;

        case KC_GO_DEF: // f12
            if (record->event.pressed) {
                tap_code16(KC_F12);
                return false;
            }
            break;

        case KC_GO_IMPL: // shift + f12
            if (record->event.pressed) {
                tap_code16(LSFT(KC_F12));
                return false;
            }
            break;

        case KC_FIND_ALL_REFS: // shift + alt + f12
            if (record->event.pressed) {
                tap_code16(LGUI(LSFT(KC_F12)));
                return false;
            }
            break;

        case KC_FORMAT: // shift + alt + f
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LGUI("f")));
                // tap_code16(LSFT(LALT(KC_F)));
                return false;
            }
            break;

        case KC_UNFOLD_ALL: // ctrl + k, ctrl + j
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("kj"));
                // tap_code16(LCTL(KC_K));
                // tap_code16(LCTL(KC_J));
                return false;
            }
            break;

        case KC_FOLD_ALL: // ctrl + k, ctrl + 0
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("k0"));
                // tap_code(LCTL(KC_K));
                // tap_code(LCTL(KC_0));
                return false;
            }
            break;

        case KC_FOLD_COMMENTS: // ctrl + k, ctrl + /
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("k/"));

                // tap_code(LCTL(KC_K));
                // tap_code(LCTL(KC_SLSH));
                return false;
            }
            break;

        case KC_DUPLICATE_LINE: // shift + alt + up
            if (record->event.pressed) {
                // SEND_STRING(SS_LSFT(SS_LGUI(KC_UP)))

                tap_code16(LSFT(LGUI(KC_UP)));
                return false;
            }
            break;

        case KC_ADD_CURSOR_ABOVE: // alt + ctrl + up
            if (record->event.pressed) {
                tap_code16(LCTL(LGUI(KC_UP)));
                return false;
            }
            break;

        case KC_ADD_CURSOR_BELOW: // alt + ctrl + down
            if (record->event.pressed) {
                tap_code16(LCTL(LGUI(KC_DOWN)));
                return false;
            }
            break;

        case KC_ADD_CURSORS_LINE_ENDS: // alt + shift + I
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LGUI("i")));
                // tap_code(LSFT(LALT(KC_I)));
                return false;
            }
            break;

        case KC_DELETE_LINE: // shift + ctrl + k
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LALT("k")));

                // SEND_STRING(SS_LSFT(SS_LCTL(KC_K)));
                // tap_code(LSFT(LCTL(KC_K)));
                return false;
            }
            break;

        case KC_OPEN_DEF_SIDE: // ctrl + k, f12
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("k"));
                // tap_code16(LCTL(KC_K));
                tap_code16(KC_F12);
                return false;
            }
            break;

        case KC_SELECT_ALL_OCCURRENCES: // shift + ctrl + l
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LALT("l")));
                // tap_code(LSFT(LCTL(KC_L)));
                return false;
            }
            break;

        case KC_COMMANDS: // shift + ctrl + p
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LALT("p")));
                return false;
            }
            break;

        case KC_TOGGLE_COMMENT: // ctrl + /
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("/"));
                return false;
            }
            break;

        case KC_SUGGEST: // ctrl + space
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(" "));
                // tap_code(LCTL(KC_SPC));
                return false;
            }
            break;

        case KC_QUICK_FIX:
            if (record->event.pressed) {
                // Quick Fix
                SEND_STRING(SS_LCTL("."));
                return false;
            }
            break;
    }

    return true;
}

void eeconfig_init_user(void) {
    keymap_config.raw = eeconfig_read_user();
}

void keyboard_post_init_user(void) {
    // Default to Windows/Linux layout
    keymap_config.swap_lalt_lgui = false;
    keymap_config.swap_ralt_rgui = false;
}

// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, LSFT(KC_GRV));
// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

const key_override_t *key_overrides[] = {&tilde_esc_override, &grave_esc_override};
