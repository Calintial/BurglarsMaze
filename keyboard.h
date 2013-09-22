#define KEYBOARD_HW_LINES 10
//Array to handle the 80 physical keys bit state
unsigned char aKeyboard[KEYBOARD_HW_LINES];


////////////////////////////////////////////////////////////////////////
//ReadKeyboard()
//Copied and adapted from the function shown in CPCWiki:
//http://www.cpcwiki.eu/index.php/Programming:Keyboard_scanning
////////////////////////////////////////////////////////////////////////
void ReadKeyboard()
{
  #asm
    di
    ld hl, #_aKeyboard
    ld bc,#0xf782
    out (c),c
    ld bc,#0xf40e
    ld e,b
    out (c),c
    ld bc,#0xf6c0
    ld d,b
    out (c),c
    ld c,#0x00
    out (c),c
    ld bc,#0xf792
    out (c),c
    ld a,#0x40
    ld c,#0x4a
    _loop:
    ld b,d
    out (c),a
    ld b,e
    ini
    inc a
    cp c
    jr c,_loop
    ld bc,#0xf782
    out (c),c
    ei
  #endasm;
}
////////////////////////////////////////////////////////////////////////
//Enumeration to identify each physical key
typedef enum _eKey
{
  Key_CursorUp = 0,
  Key_CursorRight,
  Key_CursorDown,
  Key_F9,
  Key_F6,
  Key_F3,
  Key_Enter,
  Key_FDot,
  Key_CursorLeft, //8
  Key_Copy,
  Key_F7,
  Key_F8,
  Key_F5,
  Key_F1,
  Key_F2,
  Key_F0,
  Key_Clr, //16
  Key_BraceOpen,
  Key_Return,
  Key_BraceClose,
  Key_F4,
  Key_Shift,
  Key_BackSlash,
  Key_Control,
  Key_Caret, //24
  Key_Hyphen,
  Key_At,
  Key_P,
  Key_SemiColon,
  Key_Colon,
  Key_Slash,
  Key_Dot,
  Key_0, //32
  Key_9,
  Key_O,
  Key_I,
  Key_L,
  Key_K,
  Key_M,
  Key_Comma,
  Key_8, //40
  Key_7,
  Key_U,
  Key_Y,
  Key_H,
  Key_J,
  Key_N,
  Key_Space,
  Key_6_Joy2Up, //48
  Key_5_Joy2Down,
  Key_R_Joy2Left,
  Key_T_Joy2Right,
  Key_G_Joy2Fire,
  Key_F,
  Key_B,
  Key_V,
  Key_4, //56
  Key_3,
  Key_E,
  Key_W,
  Key_S,
  Key_D,
  Key_C,
  Key_X,
  Key_1, //64
  Key_2,
  Key_Esc,
  Key_Q,
  Key_Tab,
  Key_A,
  Key_CapsLock,
  Key_Z,
  Key_Joy1Up, //72
  Key_Joy1Down,
  Key_Joy1Left,
  Key_Joy1Right,
  Key_Joy1Fire1,
  Key_Joy1Fire2,
  Key_Joy1Fire3,
  Key_Del,
  Key_Max //80
}_ekey;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//IsKeyPressed
////////////////////////////////////////////////////////////////////////
unsigned char IsKeyPressed(enum _eKey eKey)
{
  unsigned char nKeyLine = eKey / 8;
  unsigned char nBit = eKey % 8;
  
  if(((unsigned char)1 << nBit & aKeyboard[nKeyLine]) == 0)
    return 1;
  
  return 0;
}
////////////////////////////////////////////////////////////////////////