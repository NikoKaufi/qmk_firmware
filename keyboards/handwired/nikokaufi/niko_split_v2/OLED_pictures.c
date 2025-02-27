//babycat
static const char PROGMEM babycat[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
        0x3c, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02,
        0x04, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x02, 0x04, 0x09, 0xf0, 0x84, 0xc0, 0x81, 0xe0,
        0xa0, 0x82, 0x85, 0x98, 0x50, 0x50, 0x50, 0x50,
        0x28, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* Sit */
static const char PROGMEM sit[4][ANIM_SIZE] = {
{/* 'sit1', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
        0x10, 0x09, 0x06, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
        0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'sit2', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
        0x10, 0x13, 0x0c, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
        0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'sit3', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
        0x10, 0x13, 0x0c, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x02, 0x05, 0x05, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
        0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/*'sit4', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
        0x10, 0x09, 0x06, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
        0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}};

/* Walk */
static const char PROGMEM walk[4][ANIM_SIZE] = {
{/* 'walk1', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
        0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'walk2', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x89, 0x72, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x05, 0x02, 0x00, 0x00, 0x81, 0x00, 0x02, 0x70, 0x89, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x0b, 0x08, 0x0f, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x0f, 0x08, 0x08, 0x0f, 0x01, 0x06, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'walk3', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
        0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'walk4', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x89, 0x72, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x05, 0x02, 0x00, 0x40, 0x81, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x0e, 0x03, 0x05, 0x05, 0x07, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x02, 0x04, 0x04, 0x0f, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}};

/* Run */
static const char PROGMEM run[4][ANIM_SIZE] = {
{/* 'run1', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
        0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'run2', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x08, 0x74, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xe0, 0x1c, 0x02, 0x01, 0xc2, 0x04, 0x04, 0x04, 0xc2, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x22, 0x1c, 0x81, 0x82, 0x02, 0x82, 0x82, 0x82, 0x82, 0x82,
        0x82, 0x82, 0x81, 0x00, 0x00, 0xc0, 0xc0, 0x81, 0x18, 0x24, 0x42, 0x81, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x05, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x04, 0x04, 0x07, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'run3', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
        0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* 'run4', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x08, 0x74, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xe0, 0x1c, 0x02, 0x01, 0xc2, 0x04, 0x04, 0x04, 0xc2, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x82, 0x7c, 0x01, 0x02, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
        0x82, 0x82, 0x81, 0x00, 0x20, 0x40, 0x80, 0x01, 0xf8, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x03, 0x01, 0x02, 0x02, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}};

/* Turn to sleep */
static const char PROGMEM turn_sleep[26][ANIM_SIZE] = {
{/* turn_sleep1, 32x22px */
        0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x05, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep2, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
        0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x84, 0x79, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x05,
        0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x0e, 0x09, 0x0f, 0x01, 0x01, 0x02, 0x02,
        0x1f, 0x10, 0x10, 0x1c, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep3, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38,
        0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc2, 0x3c, 0x01, 0x01, 0x02, 0x04, 0x05, 0x82,
        0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x07, 0x04, 0x07, 0x01, 0x1f,
        0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep4, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf4, 0x08, 0x70, 0x80, 0x00, 0x00, 0xc0, 0x38, 0x04,
        0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x3e, 0x00, 0x01, 0x01, 0x01, 0x82, 0x04,
        0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x07, 0x02, 0x03, 0x01, 0x0f, 0x08,
        0x08, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep5, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf4, 0x08, 0x70, 0x80, 0x00, 0xc0, 0x38, 0x04, 0x02,
        0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0xfd, 0x01, 0x82, 0x04, 0x00,
        0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x1f, 0x10, 0x10,
        0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep6, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x34, 0x48, 0xf8, 0x0c, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84,
        0x02, 0x04, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0xf0, 0x02, 0x00, 0x01,
        0x00, 0x04, 0x02, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c,
        0x08, 0x08, 0x0f, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep7, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3c, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x04,
        0x38, 0xc0, 0x08, 0x74, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0xf0, 0x02, 0x00, 0x01, 0x00, 0x04,
        0x82, 0x01, 0x01, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x10,
        0x1f, 0x01, 0x07, 0x04, 0x07, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep8, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3c, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x04, 0x38,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x88, 0x74, 0x08, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0xf0, 0x02, 0x00, 0x01, 0x00, 0x00, 0x82,
        0x05, 0x04, 0x02, 0x02, 0x01, 0x3c, 0xc2, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x1c, 0x10, 0x10, 0x1f,
        0x01, 0x07, 0x04, 0x07, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep9, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x3c, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x04, 0x38, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xe8, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0xf0, 0x02, 0x00, 0x01, 0x00, 0x00, 0x02, 0x05,
        0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x79, 0x84, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x02,
        0x02, 0x01, 0x01, 0x0f, 0x09, 0x0e, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep10, 32x22px */
        0x00, 0x00, 0x00, 0xc0, 0x3c, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x04, 0x38, 0xc0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xd0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0xf0, 0x02, 0x00, 0x01, 0x00, 0x00, 0x02, 0x05, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xf2, 0x09, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x08, 0x08, 0x0f, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x0e, 0x08, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep11, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0xc1, 0x02, 0x04, 0x04, 0xc4, 0x02, 0x01, 0x02, 0x1c, 0xe0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xd0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x02,
        0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xf2, 0x09, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x0e, 0x08, 0x08, 0x0f, 0x01,
        0x01, 0x01, 0x02, 0x02, 0x1e, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep12, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01, 0x02, 0x1c,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xd0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
        0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0xf2, 0x09, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x0e, 0x04, 0x07, 0x01,
        0x01, 0x01, 0x02, 0x0e, 0x08, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep13, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01, 0x02,
        0x1c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x20, 0xd0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x80, 0x00,
        0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0xf2, 0x09, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x0f, 0x08, 0x0f, 0x01,
        0x01, 0x02, 0x1e, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep14, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01,
        0x02, 0x1c, 0xe0, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xfc, 0x00, 0x00, 0x40, 0x80,
        0x82, 0x05, 0x04, 0x04, 0x04, 0xf2, 0x09, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x0f, 0x08, 0x0f,
        0x00, 0x1f, 0x10, 0x1e, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep15, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x01,
        0x02, 0x04, 0x04, 0x02, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x27, 0xe8, 0x08, 0x05, 0x06, 0x00,
        0x00, 0x00, 0x00, 0xfc, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1e, 0x10,
        0x10, 0x1f, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep16, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xd0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0xe0,
        0x1c, 0x02, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04,
        0x05, 0x82, 0x80, 0x40, 0x00, 0x00, 0xfc, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x1e, 0x10,
        0x1f, 0x00, 0x0f, 0x08, 0x0f, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep17, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0xe0,
        0x1c, 0x02, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x02,
        0x01, 0x00, 0x80, 0x00, 0x00, 0x00, 0xfc, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1e, 0x10, 0x1e, 0x02,
        0x01, 0x01, 0x0f, 0x08, 0x0f, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep18, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1c, 0x02, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02,
        0x02, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1e, 0x08, 0x0e, 0x02, 0x01,
        0x01, 0x01, 0x07, 0x04, 0x04, 0x0f, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep19, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1c, 0x02, 0x01, 0x02, 0xc4, 0x04, 0x04, 0x02, 0xc1, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02,
        0x02, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x01, 0x01,
        0x01, 0x0f, 0x08, 0x08, 0x0e, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep20, 32x22px */
        0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x05, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x1f, 0x10, 0x10, 0x1c, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep21, 32x22px */
        0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x05, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep22, 32x22px */
        0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x05, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x1f, 0x10, 0x10, 0x1c, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep23, 32x22px */
        0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x04, 0x09, 0xf2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x05, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep24, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0x40, 0x80, 0x80, 0x80, 0x40, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x3c, 0x42, 0x9d, 0x22, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x5c, 0x23, 0x00, 0x00, 0x18, 0x00, 0x20, 0x00, 0x98, 0x40, 0x23, 0x1c, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x14, 0x14, 0x1c, 0x10, 0x10,
        0x1c, 0x14, 0x14, 0x14, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep25, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x3c, 0x42, 0x9d, 0x22, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x78, 0x47, 0x00, 0x00, 0x30, 0x01, 0x41, 0x01, 0x30, 0x80, 0x47, 0x38, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x14, 0x14, 0x1c, 0x10, 0x10,
        0x1c, 0x14, 0x14, 0x14, 0x10, 0x10, 0x10, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* turn_sleep26, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x78, 0x47, 0x00, 0x00, 0x30, 0x01, 0x41, 0x01, 0x30, 0x80, 0x47, 0x38, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x16, 0x18, 0x10, 0x10, 0x14, 0x14, 0x1c, 0x10, 0x10,
        0x1c, 0x14, 0x14, 0x14, 0x10, 0x10, 0x10, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}};

/* Sleep */
static const char PROGMEM sleep[3][ANIM_SIZE] = {
{/* sleep1, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x78, 0x47, 0x00, 0x00, 0x20, 0x01, 0x41, 0x01, 0x20, 0x80, 0x47, 0x38, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x16, 0x18, 0x10, 0x10, 0x14, 0x14, 0x1c, 0x10, 0x10,
        0x1c, 0x14, 0x14, 0x14, 0x10, 0x10, 0x10, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* sleep2, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x92, 0x1a, 0x16, 0x12, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x78, 0x47, 0x00, 0x00, 0x20, 0x01, 0x41, 0x01, 0x20, 0x80, 0x47, 0x38, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x16, 0x18, 0x10, 0x10, 0x14, 0x14, 0x1c, 0x10, 0x10,
        0x1c, 0x14, 0x14, 0x14, 0x10, 0x10, 0x10, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/* sleep3, 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x09, 0x0d, 0x0b, 0x09, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x78, 0x47, 0x00, 0x00, 0x20, 0x01, 0x41, 0x01, 0x20, 0x80, 0x47, 0x38, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x16, 0x18, 0x10, 0x10, 0x14, 0x14, 0x1c, 0x10, 0x10,
        0x1c, 0x14, 0x14, 0x14, 0x10, 0x10, 0x10, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}};

/* Bark */
static const char PROGMEM bark[2][ANIM_SIZE] = {
{/* 'bark1', 32x22px */
        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
},
{/* 'bark2', 32x22px */
        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
}};

/* Sneak */
static const char PROGMEM sneak[2][ANIM_SIZE] = {
{/* 'sneak1', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
},
{/* 'sneak2', 32x22px */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
}};