#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
// doesn't compile due to a bad include. *shrug*
// #include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)

// #define KIT_LAYOUT_MAC
#define KIT_LAYOUT_UBUNTU

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  RGB_SLD = EZ_SAFE_RANGE,
#else
  RGB_SLD = SAFE_RANGE,
#endif
  EPRM,
  HSV_172_255_255,
  KC_Q_HOLDDOWN_LOADER,
  KC_W_HOLDDOWN,
  KC_A_HOLDDOWN,
  KC_S_HOLDDOWN,
  KC_D_HOLDDOWN,
  KC_MOUSE_LCLICK_HOLDDOWN,
  ALT_TAB,
  ALT_TILDE,
  KC_LCTRL_STICKY,
  KC_RSFT_STICKY,
  KC_RGUI_STICKY,
  KC_RALT_STICKY,
  KC_CLEAR_STICKYS
};

#define ALT_TAB_TIMEOUT_MS 500
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

#ifdef KIT_LAYOUT_MAC
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer -- default (from qmk_firmware/keyboards/ergodox_ez/keymaps/default/keymap.c)
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | End  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [0] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE,          KC_1,           KC_2,           KC_3,           KC_4,            KC_5,        KC_MS_BTN1,
    KC_TAB,             KC_B,           KC_W,           KC_F,           KC_D,            KC_Q,        LGUI(KC_R),
    LSFT(KC_MINUS),     LCTL_T(KC_A),   LSFT_T(KC_R),   LALT_T(KC_S),   LGUI_T(KC_T),    LT(1,KC_P),
    KC_RSFT_STICKY,     LT(2,KC_X),     LT(3,KC_G),     LT(4,KC_C),     KC_V,            KC_Z,        MT(MOD_MEH, KC_EQUAL),
    KC_LCTRL_STICKY,    TG(3),          OSL(5),         KC_LEFT,        KC_RIGHT,
                                                                           KC_PGDOWN,    KC_PGUP,
                                                                                                    TG(6),
                                                                           KC_BSPACE,    KC_TAB,    KC_ENTER,

    // right hand
    TG(6),          KC_6,           KC_7,            KC_8,            KC_9,            KC_0,                    ALT_TILDE,
    RGUI(KC_P),     KC_J,           KC_L,            KC_U,            KC_Y,            KC_SCOLON,               ALT_TAB,
    LT(1,KC_M),     RGUI_T(KC_N),   RALT_T(KC_E),    RSFT_T(KC_I),    RCTL_T(KC_O),    MT(MOD_MEH, KC_QUOTE),
    RGUI(KC_Z),     KC_K,           KC_H,            LT(4,KC_COMMA),  LT(3,KC_DOT),    KC_SLASH,                KC_MINUS,
    KC_DOWN,        KC_UP,          RGUI(KC_F),      LALT(KC_Y),      KC_GRAVE,
    KC_HOME,      KC_END,
    TG(7),
    RCTL(KC_S),   KC_ENTER,    KC_SPACE
  ),

  [1] = LAYOUT_ergodox(
    KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
    KC_DELETE,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_TRANSPARENT, 
    KC_TRANSPARENT,KC_TRANSPARENT,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
    KC_CLEAR_STICKYS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    LCTL(LGUI(KC_G)),HSV_172_255_255,
    LGUI(KC_D),
    KC_BSPACE,KC_PGUP,LGUI(KC_K),

    KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,KC_TRANSPARENT,KC_GRAVE,KC_7,KC_8,KC_9,KC_ASTR,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_4,RALT_T(KC_5),RSFT_T(KC_6),KC_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_0,KC_KP_DOT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_PGDOWN,KC_SPACE),

  [2] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN2,KC_MS_BTN1,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WWW_BACK),

  [3] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_MINUS),LCTL(KC_EQUAL),KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_C),LCTL(KC_V),LCTL(KC_L),KC_END,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_PGUP),LCTL(KC_PGDOWN),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,LSFT(KC_SPACE),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGUI(RSFT(KC_4)),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RCTL(RGUI(RSFT(KC_4))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGUI(KC_3),RCTL(RGUI(RSFT(KC_3))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [4] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CAPSLOCK,KC_TRANSPARENT,KC_HOME,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_PGUP),LCTL(KC_PGDOWN),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGUP,LGUI(KC_UP),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_CAPSLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGUI(KC_DOWN),KC_PGDOWN),

  [5] = LAYOUT_ergodox(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,LGUI(KC_B),LGUI(KC_W),LGUI(KC_F),LGUI(KC_D),LGUI(KC_Q),LGUI(LSFT(KC_T)),
    KC_TRANSPARENT,LGUI(KC_A),LGUI(KC_R),LGUI(KC_S),LGUI(KC_T),LGUI(KC_P),
    KC_TRANSPARENT,LGUI(KC_X),LGUI(KC_G),LGUI(KC_C),LGUI(KC_V),LGUI(KC_Z),LALT(KC_F1),
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_C),LCTL(KC_V),
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGUI(KC_J),RGUI(KC_L),RGUI(KC_U),RGUI(KC_Y),KC_TRANSPARENT,KC_TRANSPARENT,RGUI(KC_M),RGUI(KC_N),RGUI(KC_E),RGUI(KC_I),RGUI(KC_O),KC_TRANSPARENT,KC_TRANSPARENT,RGUI(KC_K),RGUI(KC_H),KC_TRANSPARENT,KC_TRANSPARENT,RGUI(KC_SLASH),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_ENTER),RCTL(KC_SPACE)),

  [6] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LSFT(KC_F10),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_TRANSPARENT,KC_F10,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_MINUS),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RSFT(KC_F12),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F12,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_MINUS)),

  [7] = LAYOUT_ergodox(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,
    KC_MS_BTN2,KC_Q_HOLDDOWN_LOADER,KC_W_HOLDDOWN,KC_E,KC_R,KC_T,LALT(LGUI(KC_1)),
    KC_LCTRL,KC_A_HOLDDOWN,KC_S_HOLDDOWN,KC_D_HOLDDOWN,KC_F,KC_G,KC_LSHIFT,
    KC_Z,KC_X,KC_C,KC_V,KC_B,LALT(LGUI(KC_2)),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TAB,KC_BSPACE,KC_TRANSPARENT,KC_SPACE,KC_MOUSE_LCLICK_HOLDDOWN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_TRANSPARENT,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_TRANSPARENT,KC_TRANSPARENT,KC_N,KC_M,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

#elif defined(KIT_LAYOUT_UBUNTU)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer -- default (from qmk_firmware/keyboards/ergodox_ez/keymaps/default/keymap.c)
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | End  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [0] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE,          KC_1,           KC_2,           KC_3,           KC_4,            KC_5,        KC_MS_BTN1,
    KC_TAB,             KC_B,           KC_W,           KC_F,           KC_D,            KC_Q,        ALT_TILDE,
    KC_LCTRL_STICKY,    LCTL_T(KC_A),   LSFT_T(KC_R),   LALT_T(KC_S),   LGUI_T(KC_T),    LT(1,KC_P),
    KC_RSFT_STICKY,     LT(2,KC_X),     LT(3,KC_G),     LT(4,KC_C),     KC_V,            KC_Z,        MT(MOD_MEH, KC_EQUAL),
    TG(1),    		KC_RALT_STICKY, OSL(5),         KC_LEFT,        KC_RIGHT,
                                                                           KC_PGDOWN,    KC_PGUP,
                                                                                                    TG(6),
                                                                           KC_BSPACE,    KC_ESCAPE, KC_ENTER,

    // right hand
    KC_GRAVE,       KC_6,           KC_7,            KC_8,            KC_9,            KC_0,                    ALT_TAB,
    TG(3),          KC_J,           KC_L,            KC_U,            KC_Y,            KC_SCOLON,               KC_MINUS,
    LT(1,KC_M),     RGUI_T(KC_N),   RALT_T(KC_E),    RSFT_T(KC_I),    RCTL_T(KC_O),    MT(MOD_MEH, KC_QUOTE),
    RCTL(KC_Z),     KC_K,           KC_H,            LT(4,KC_COMMA),  LT(3,KC_DOT),    KC_SLASH,                KC_RSFT_STICKY,
    KC_DOWN,        KC_UP,          KC_LCTRL_STICKY, KC_RALT_STICKY, TG(1),
    KC_RGUI_STICKY, LALT(KC_Y),
    TG(7),
    KC_CLEAR_STICKYS,   KC_ENTER,    KC_SPACE
  ),

  [1] = LAYOUT_ergodox(
    KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
    KC_DELETE,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_TRANSPARENT, 
    KC_TRANSPARENT,KC_TRANSPARENT,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_LCTRL_STICKY,KC_TRANSPARENT,KC_TRANSPARENT,
    LCTL(LGUI(KC_G)),HSV_172_255_255,
    LGUI(KC_D),
    KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_K),

    KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_GRAVE,KC_7,KC_8,KC_9,KC_ASTR,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_KP_4,RALT_T(KC_5),RSFT_T(KC_6),KC_PLUS,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_END,KC_TRANSPARENT,KC_TRANSPARENT),

  [2] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN2,KC_MS_BTN1,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WWW_BACK),

  [3] = LAYOUT_ergodox(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,LCTL(KC_MINUS),LCTL(KC_EQUAL),LALT(KC_LEFT),LALT(KC_RIGHT),KC_TRANSPARENT,RSFT(KC_PSCREEN),
    KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_C),LCTL(KC_V),LCTL(KC_L),KC_END,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_PGUP),LCTL(KC_PGDOWN),
    KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_SPACE,LSFT(KC_SPACE),KC_TRANSPARENT,
    
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_PSCREEN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [4] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CAPSLOCK,KC_TRANSPARENT,KC_HOME,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_PGUP),LCTL(KC_PGDOWN),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGUP,LCTL(KC_HOME),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_CAPSLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_END),KC_PGDOWN),

  [5] = LAYOUT_ergodox(
    KC_TRANSPARENT,    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,    LCTL(KC_B),LCTL(KC_W),LCTL(KC_F),LCTL(KC_D),LCTL(KC_Q),LCTL(LSFT(KC_T)),
    LCTL(LSFT(KC_R)),  LCTL(KC_A),LCTL(KC_R),LCTL(KC_S),LCTL(KC_T),LCTL(KC_P),
    KC_TRANSPARENT,    LCTL(KC_X),LCTL(KC_G),LCTL(KC_C),LCTL(KC_V),LCTL(KC_Z),LALT(KC_F1),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(LSFT(KC_C)),LCTL(LSFT(KC_V)),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_BSPACE),LCTL(KC_TAB),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_J),RCTL(KC_L),RCTL(KC_U),RCTL(KC_Y),KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_M),RCTL(KC_N),RCTL(KC_E),RCTL(KC_I),RCTL(KC_O),KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_K),RCTL(KC_H),KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_SLASH),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RCTL(KC_ENTER),RCTL(KC_SPACE)),

  [6] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LSFT(KC_F10),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_TRANSPARENT,KC_F10,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(KC_MINUS),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RSFT(KC_F12),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F12,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RALT(RSFT(KC_MINUS))),

  [7] = LAYOUT_ergodox(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,
    KC_MS_BTN2,KC_Q_HOLDDOWN_LOADER,KC_W_HOLDDOWN,KC_E,KC_R,KC_T,LALT(LGUI(KC_1)),
    KC_LCTRL,KC_A_HOLDDOWN,KC_S_HOLDDOWN,KC_D_HOLDDOWN,KC_F,KC_G,KC_LSHIFT,
    KC_Z,KC_X,KC_C,KC_V,KC_B,LALT(LGUI(KC_2)),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TAB,KC_BSPACE,KC_TRANSPARENT,KC_SPACE,KC_MOUSE_LCLICK_HOLDDOWN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_TRANSPARENT,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_TRANSPARENT,KC_TRANSPARENT,KC_N,KC_M,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};
#endif

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234}, {172,226,234} },

    [1] = { {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238}, {239,236,238} },

    [2] = { {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232}, {81,242,232} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {243,222,234}, {243,222,234}, {243,222,234}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0} },

    [7] = { {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240}, {44,236,240} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}


// for custom sticky keys behavior
#define STICKY_LCTRL_INDEX 0
#define STICKY_RSFT_INDEX 1
#define STICKY_RGUI_INDEX 2
#define STICKY_RALT_INDEX 3
#define STICKY_UNDEFINED 65535
#define NUM_STICKY_KEYS 4
#define STICKY_ENGAGED 0
#define STICKY_DISENGAGED 1
#define STICKY_HOLD 2

uint16_t get_sticky_keycode(uint8_t key_index) {
  switch (key_index) {
    // keycode for a given index
    case STICKY_LCTRL_INDEX:
      return KC_LCTRL;
    case STICKY_RSFT_INDEX:
      return KC_RSFT;
    case STICKY_RGUI_INDEX:
      return KC_RGUI;
    case STICKY_RALT_INDEX:
      return KC_RALT;
    default:
      return STICKY_UNDEFINED;
  }
}

uint16_t get_sticky_index(uint16_t keycode) {
  switch (keycode) {
    // index into known sticky keys
    case KC_LCTRL_STICKY:
      return 0;
    case KC_RSFT_STICKY:
      return 1;
    case KC_RGUI_STICKY:
      return 2;
    case KC_RALT_STICKY:
      return 3;
    default:
      return STICKY_UNDEFINED;
  }
}

// for custom holddown keys behavior
#define HOLDDOWN_HIJACK_TIMEOUT_MS 500
#define NUM_HOLDDOWN_KEYS 5
#define HOLDDOWN_UNDEFINED 65535
#define HOLDDOWN_PROP_INDEX 0
#define HOLDDOWN_PROP_OPP_KC 1
#define HOLDDOWN_PROP_REG_KEYCODE 2
#define HOLDDOWN_DISENGAGED 0
#define HOLDDOWN_ENGAGED 1
#define HOLDDOWN_WASD_OPPOSITE_DISENGAGE

uint16_t get_kc_property(uint16_t keycode, uint8_t prop) {
  switch (prop) {
    // index into holddown state arrays
    case HOLDDOWN_PROP_INDEX:
      switch (keycode) {
        case KC_W_HOLDDOWN:
          return 0;
        case KC_A_HOLDDOWN:
          return 1;
        case KC_S_HOLDDOWN:
          return 2;
        case KC_D_HOLDDOWN:
          return 3;
        case KC_MOUSE_LCLICK_HOLDDOWN:
          return 4;
      }
    // for WASD directional use, these are the "opposite" directions
    case HOLDDOWN_PROP_OPP_KC:
      switch (keycode) {
        case KC_W_HOLDDOWN:
          return KC_S_HOLDDOWN;
        case KC_A_HOLDDOWN:
          return KC_D_HOLDDOWN;
        case KC_S_HOLDDOWN:
          return KC_W_HOLDDOWN;
        case KC_D_HOLDDOWN:
          return KC_A_HOLDDOWN;
        default:
          return HOLDDOWN_UNDEFINED;
      }
    // lookup table for the corresponding normal keycode
    case HOLDDOWN_PROP_REG_KEYCODE:
      switch (keycode) {
        case KC_W_HOLDDOWN:
          return KC_W;
        case KC_A_HOLDDOWN:
          return KC_A;
        case KC_S_HOLDDOWN:
          return KC_S;
        case KC_D_HOLDDOWN:
          return KC_D;
        case KC_MOUSE_LCLICK_HOLDDOWN:
          return KC_MS_BTN1;
      }
  }

  // this shouldn't be reachable!
  return HOLDDOWN_UNDEFINED;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // see https://beta.docs.qmk.fm/features/feature_macros for context
  // to test/viz keyevents, go to https://w3c.github.io/uievents/tools/key-event-viewer.html

  // sticky keys start in an untriggered (key is not engaged, 0) state
  static uint8_t sticky_state[NUM_STICKY_KEYS] = {STICKY_DISENGAGED};
  // holddown keys start in an untriggered (key is up, 0) state
  static bool holddown_state[NUM_HOLDDOWN_KEYS] = {HOLDDOWN_DISENGAGED};
  // the last time a keyup happened.
  static uint16_t holddown_last_load_time = 0;
  static bool holddown_wasd_disengage_ignore_keyup = false;
  uint16_t holddown_index;

  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
          eeconfig_init();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;

    // Custom alt tab handling, from https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_RCMD);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } 
      else {
        unregister_code(KC_TAB);
      }
      return false;

    // similar, but for windows within the same application. Note that it 
    // uses the same timer as for alt tab
    case ALT_TILDE:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_RCMD);
        }
        alt_tab_timer = timer_read();
        register_code(KC_RSFT);
        register_code(KC_GRAVE);
      } 
      else {
        unregister_code(KC_GRAVE);
        unregister_code(KC_RSFT);
      }
      return false;

    case KC_Q_HOLDDOWN_LOADER:
      // on keydown
      if (record->event.pressed) {
        return false;
      }
      // on keyup
      else { 
        uint16_t key_time = timer_read();
        holddown_last_load_time = key_time;
        return false;
      }

    // SEPARATE LOADER HOLDDOWN BEHAVIOR: if you tap the holddown load key (for now,
    // KC_Q_HOLDDOWN_LOADER) and then a holddown key candidate within 
    // HOLDDOWN_HIJACK_TIMEOUT_MS, then the keyboard acts as if the holddown key is 
    // held down. 
    // Tap the holddown key again to deactivate.
    // You can also tap the opposite WASD key (W<->S, A<->D) to deactivate.
    // Multiple holddown keys can be engaged at once.
    // If you tap after HOLDDOWN_HIJACK_TIMEOUT_MS, regular key down and up 
    // signals are sent
    case KC_W_HOLDDOWN:
    case KC_A_HOLDDOWN:
    case KC_S_HOLDDOWN:
    case KC_D_HOLDDOWN:
      // on keydown
      if (record->event.pressed) {
        // if there is an "opposite" for this keycode and it is holddown engaged,
        // let's disengage it
        #ifdef HOLDDOWN_WASD_OPPOSITE_DISENGAGE
        uint16_t opp_keycode = get_kc_property(keycode, HOLDDOWN_PROP_OPP_KC);
        if (opp_keycode != HOLDDOWN_UNDEFINED) {
          uint16_t opp_index = get_kc_property(opp_keycode, HOLDDOWN_PROP_INDEX);
          if (holddown_state[opp_index] == HOLDDOWN_ENGAGED) {
            holddown_state[opp_index] = HOLDDOWN_DISENGAGED;
            unregister_code(get_kc_property(opp_keycode, HOLDDOWN_PROP_REG_KEYCODE));
            holddown_wasd_disengage_ignore_keyup = true;
            // this keypress serves only to cancel the opposing dirction
            return false;
          }
        }
        #endif

        register_code(get_kc_property(keycode, HOLDDOWN_PROP_REG_KEYCODE));
        return false;
      }
      // on keyup
      else {
        uint16_t key_time = timer_read();
        holddown_index = get_kc_property(keycode, HOLDDOWN_PROP_INDEX);

        // if we're ignoring this keyup, then quit early.
        if (holddown_wasd_disengage_ignore_keyup) {
          holddown_wasd_disengage_ignore_keyup = false;
          return false;
        }

        // if we're not in keydown mode, and a keypress was sent within
        // the TIMEOUT, this press activates keydown mode
        if (holddown_state[holddown_index] == HOLDDOWN_DISENGAGED &&
            key_time - holddown_last_load_time < HOLDDOWN_HIJACK_TIMEOUT_MS)
        {
          holddown_state[holddown_index] = HOLDDOWN_ENGAGED;
          // note that keydown event is sent on if (record->event.pressed), above
          return false;
        }
        // otherwise just send a regular keypress and exit keydown mode, if
        // we're in it
        else {
          holddown_state[holddown_index] = HOLDDOWN_DISENGAGED;
          unregister_code(get_kc_property(keycode, HOLDDOWN_PROP_REG_KEYCODE));
          return false;
        }
      }
      return true;

    // SINGLE CLICK HOLDDOWN BEHAVIOR: if you press the key, then the keyboard acts
    // as if the key is held down. Tap again to deactivate.
    case KC_MOUSE_LCLICK_HOLDDOWN:
      holddown_index = get_kc_property(keycode, HOLDDOWN_PROP_INDEX);
      // on keydown
      if (record->event.pressed) {
        if (holddown_state[holddown_index] == HOLDDOWN_DISENGAGED) {
          holddown_state[holddown_index] = HOLDDOWN_ENGAGED;
          register_code(get_kc_property(keycode, HOLDDOWN_PROP_REG_KEYCODE));
          holddown_wasd_disengage_ignore_keyup = true;
          return false;
        }
      }
      // on keyup
      else {
        // if we're ignoring this keyup, then quit early.
        if (holddown_wasd_disengage_ignore_keyup) {
          holddown_wasd_disengage_ignore_keyup = false;
          return false;
        }
        // if we're engaged, then disengage
        else if (holddown_state[holddown_index] == HOLDDOWN_ENGAGED) {
          holddown_state[holddown_index] = HOLDDOWN_DISENGAGED;
          unregister_code(get_kc_property(keycode, HOLDDOWN_PROP_REG_KEYCODE));
          return false;
        }
      }
      return true;

    // STICKY KEY BEHAVIOR. When a sticky key is pressed, it will be marked as 
    // "engaged" upon keydown. This allows the proper keycode for the sticky
    // key (gotten from get_sticky_keycode()) to be registered when a 
    // DIFFERENT, combo key is pressed. This combo key can be pressed either while 
    // the sticky key is still being held down or after the sticky key has had a
    // physical keyup. Pressing the sticky key a second time will put it into
    // sticky hold, where it will stay until hit again (just like sticky keys on mac)
    // Note that there is additional sticky behavior code at the end of this function
    case KC_LCTRL_STICKY:
    case KC_RSFT_STICKY:
    case KC_RGUI_STICKY:
    case KC_RALT_STICKY:
      // on keydown
      if (record->event.pressed) {
        uint8_t index = get_sticky_index(keycode);
        switch (sticky_state[index]) {
          // if disengaged and pressed, then register a keydown that will 
          // be used for the next combo key
          case STICKY_DISENGAGED:
            register_code(get_sticky_keycode(index));
            sticky_state[index] = STICKY_ENGAGED;
            break;
          // tapping again makes us hold sticky for an infinite number of combo keys
          case STICKY_ENGAGED:
            sticky_state[index] = STICKY_HOLD;
            break;
          // if we're in hold, break out
          case STICKY_HOLD:
            unregister_code(get_sticky_keycode(index));
            sticky_state[index] = STICKY_DISENGAGED;
            break;
        }
      }
      return false;
    // clears all sticky state, to get back to square one
    case KC_CLEAR_STICKYS:
      for (uint8_t isticky = 0; isticky < NUM_STICKY_KEYS; isticky++) {
        unregister_code(get_sticky_keycode(isticky));
        sticky_state[isticky] = STICKY_DISENGAGED;
      }
      return false;
  }

  // finally, unregister event (keydown state) for any engaged sticky keys
  // this code must be here so that the combo key press can cause sticky to
  // disengage (this code gets called for any keypress)
  for (uint8_t isticky = 0; isticky < NUM_STICKY_KEYS; isticky++) {
    // nothing on keydown
    if (record->event.pressed) {}
    // disengage it on keyup. Note that technically the sticky unregister (keyup)
    // happens before the combo key's keyup event. Still seems to deliver the 
    // desired behavior though.
    else {
      if (sticky_state[isticky] ==  STICKY_ENGAGED) {
        unregister_code(get_sticky_keycode(isticky));
        // disengage sticky after one use
        sticky_state[isticky] = STICKY_DISENGAGED;
      }
    }
  } 

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > ALT_TAB_TIMEOUT_MS) {
      unregister_code(KC_RCMD);
      is_alt_tab_active = false;
    }
  }
}
