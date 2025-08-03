[1mdiff --git a/keyboards/handwired/nikokaufi/niko_split_v2/keymaps/via/keymap.c b/keyboards/handwired/nikokaufi/niko_split_v2/keymaps/via/keymap.c[m
[1mindex d860c36be2..53f08aedc8 100644[m
[1m--- a/keyboards/handwired/nikokaufi/niko_split_v2/keymaps/via/keymap.c[m
[1m+++ b/keyboards/handwired/nikokaufi/niko_split_v2/keymaps/via/keymap.c[m
[36m@@ -180,38 +180,38 @@[m [menum combo_events {[m
     DEL,[m
     DESK_RI,[m
     DESK_LE,[m
[31m-  };[m
[31m-  #ifdef COMBO_ENABLE[m
[31m-      const uint16_t PROGMEM spc_bspc_del[]  = {SPC1, KC_BSPC, COMBO_END};[m
[31m-      const uint16_t PROGMEM desktop_right[] = {KC_G, DE_H, COMBO_END};[m
[31m-      const uint16_t PROGMEM desktop_left[]  = {KC_B, KC_N, COMBO_END};[m
[31m-      combo_t key_combos[] = {[m
[31m-          [DEL] = COMBO(spc_bspc_del, KC_DEL),[m
[31m-          [DESK_RI] = COMBO_ACTION(desktop_right),[m
[31m-          [DESK_LE] = COMBO_ACTION(desktop_left)[m
[31m-      };[m
[31m-      void process_combo_event(uint16_t combo_index, bool pressed) {[m
[31m-          switch(combo_index) {[m
[31m-              case DESK_RI:[m
[31m-                  if (pressed) {[m
[31m-                      register_code(KC_LCTL);[m
[31m-                      register_code(KC_LGUI);[m
[31m-                      tap_code(KC_RGHT);[m
[31m-                      unregister_code(KC_LCTL);[m
[31m-                      unregister_code(KC_LGUI);[m
[31m-                  }[m
[31m-                  break;[m
[31m-              case DESK_LE:[m
[31m-                  if (pressed) {[m
[31m-                      register_code(KC_LCTL);[m
[31m-                      register_code(KC_LGUI);[m
[31m-                      tap_code(KC_LEFT);[m
[31m-                      unregister_code(KC_LCTL);[m
[31m-                      unregister_code(KC_LGUI);[m
[31m-                  }[m
[31m-                  break;[m
[31m-          }[m
[31m-      }[m
[32m+[m[32m};[m
[32m+[m[32m#ifdef COMBO_ENABLE[m
[32m+[m[32m    const uint16_t PROGMEM spc_bspc_del[]  = {SPC1, KC_BSPC, COMBO_END};[m
[32m+[m[32m    const uint16_t PROGMEM desktop_right[] = {KC_G, DE_H, COMBO_END};[m
[32m+[m[32m    const uint16_t PROGMEM desktop_left[]  = {KC_B, KC_N, COMBO_END};[m
[32m+[m[32m    combo_t key_combos[] = {[m
[32m+[m[32m        [DEL] = COMBO(spc_bspc_del, KC_DEL),[m
[32m+[m[32m        [DESK_RI] = COMBO_ACTION(desktop_right),[m
[32m+[m[32m        [DESK_LE] = COMBO_ACTION(desktop_left)[m
[32m+[m[32m    };[m
[32m+[m[32m    void process_combo_event(uint16_t combo_index, bool pressed) {[m
[32m+[m[32m        switch(combo_index) {[m
[32m+[m[32m            case DESK_RI:[m
[32m+[m[32m                if (pressed) {[m
[32m+[m[32m                    register_code(KC_LCTL);[m
[32m+[m[32m                    register_code(KC_LGUI);[m
[32m+[m[32m                    tap_code(KC_RGHT);[m
[32m+[m[32m                    unregister_code(KC_LCTL);[m
[32m+[m[32m                    unregister_code(KC_LGUI);[m
[32m+[m[32m                }[m
[32m+[m[32m                break;[m
[32m+[m[32m            case DESK_LE:[m
[32m+[m[32m                if (pressed) {[m
[32m+[m[32m                    register_code(KC_LCTL);[m
[32m+[m[32m                    register_code(KC_LGUI);[m
[32m+[m[32m                    tap_code(KC_LEFT);[m
[32m+[m[32m                    unregister_code(KC_LCTL);[m
[32m+[m[32m                    unregister_code(KC_LGUI);[m
[32m+[m[32m                }[m
[32m+[m[32m                break;[m
[32m+[m[32m        }[m
[32m+[m[32m    }[m
   #endif //Combo[m
 [m
 /* TAP-DANCE */[m
[36m@@ -545,3 +545,4 @@[m [mbool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {[m
     //     }[m
     //     return true;[m
     // }[m
[41m+     [m
\ No newline at end of file[m
