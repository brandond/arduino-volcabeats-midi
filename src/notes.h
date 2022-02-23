// Note 38 is Lo or Hi Tom depending on accent
// Note 39 is Closed or Open Hat depending on accent
// All others are mapped straight left to right on the keypad

byte normal[128] {
 0,  0,  0,  0,  0,  0,  0,  0, // 0
 0,  0,  0,  0,  0,  0,  0,  0, // 8
 0,  0,  0,  0,  0,  0,  0,  0, // 16
 0,  0,  0,  0,  0,  0,  0,  0, // 24
 0,  0,  0,  0, 36, 38, 43, 42, // 32
39, 75, 67, 49,  0,  0,  0,  0, // 40
};

byte accent[128] {
 0,  0,  0,  0,  0,  0,  0,  0, // 0
 0,  0,  0,  0,  0,  0,  0,  0, // 8
 0,  0,  0,  0,  0,  0,  0,  0, // 16
 0,  0,  0,  0,  0,  0,  0,  0, // 24
 0,  0,  0,  0, 36, 38, 50, 46, // 32
39, 75, 67, 49,  0,  0,  0,  0, // 40
};
