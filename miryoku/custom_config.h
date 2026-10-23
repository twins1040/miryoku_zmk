// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku


// 홈로우 모드: S/D/F = GUI/ALT/CTRL (J/K/L 미러), Shift 는 양 바깥 엄지 (ESC: R+F, 한/영: U+J 콤보)
#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
&kp A,             U_MT(LGUI, S),     U_MT(LALT, D),     U_MT(LCTRL, F),    &kp G,             &kp H,             U_MT(LCTRL, J),    U_MT(LALT, K),     U_MT(LGUI, L),     &kp SQT,           \
U_LT(U_BUTTON, Z), U_MT(RALT, X),     &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         U_MT(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              &kp LSHFT,         U_LT(U_NAV, SPACE), U_LT(U_MOUSE, TAB), U_LT(U_SYM, RET), U_LT(U_NUM, BSPC), &kp RSHFT,         U_NP,              U_NP

// NAV: G 자리에 영역 캡처→클립보드(⌃⇧⌘4), Z 자리 홀드로 MEDIA 진입
#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         &kp LS(LC(LG(N4))), &kp LEFT,         &kp DOWN,          &kp UP,            &kp RIGHT,         &u_caps_word,      \
&mo U_MEDIA,       &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       U_NA,              &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           &kp INS,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

// NUM: / 자리 홀드로 FUN 진입
#define MIRYOKU_LAYER_NUM \
&kp LBKT,          &kp N7,            &kp N8,            &kp N9,            &kp RBKT,          U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp SEMI,          &kp N4,            &kp N5,            &kp N6,            &kp EQUAL,         U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
&kp GRAVE,         &kp N1,            &kp N2,            &kp N3,            &kp BSLH,          U_NA,              &u_to_U_NUM,       &u_to_U_NAV,       &kp RALT,          &mo U_FUN,         \
U_NP,              U_NP,              &kp DOT,           &kp N0,            &kp MINUS,         U_NA,              U_NA,              U_NA,              U_NP,              U_NP
