# niko_split

![niko_split]

*A short description of the keyboard/project*
Split ergonomic column-staggered keyboard with 42 keys, 2 encoders, 2 OLED screens, per key and underglow RGB.
It includes an adoption of the keyboard pet Luna by [HellSingCoder](https://github.com/HellSingCoder/qmk_firmware/tree/master/keyboards/sofle/keymaps/helltm): [YouTube](https://www.youtube.com/watch?v=HgIQRazCAjo)

* Keyboard Maintainer: [Nikolaj Kaufmann](https://github.com/NikoKaufi)
* Hardware Supported: *RP2040 pro Micro*
* Hardware Availability: *Aliexpress*

Make example for this keyboard (after setting up your build environment):

    make handwired/nikokaufi/niko_split_v2:via

Flashing examples for left/right side

    qmk flash -kb niko_split_v2 -km via -bl uf2-split-left
    qmk flash -kb niko_split_v2 -km via -bl uf2-split-right

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:
I would only recommend the bootmagic option to fully reset the eeprom

* **Bootmagic reset LEFT**: Hold down the key at (0,0) in the matrix (Escape) and plug in the keyboard
* **Bootmagic reset RIGHT**: Hold down the key at (4,6) in the matrix (Minus) and plug in the keyboard

On both sides:
* **Physical reset button**: Briefly press the reset button on the lower side of the keyboard twice
* **physical boot button**: Briefly hold down the boot button while plugging in the cable

## Keymaps
* There will be several Keymaps from People, I gave this Keyboard to
* _'via'_ will be the standard Keymap
* _'via_noknob'_ is standard for Keymap with no knob, replaced by a keyswitch

## VIA
* There's only via version's keymap in the keymaps's folder

* You can find the matrix-files for the VIA implementation as _'matrix_niko_split_v2'_ and _'matrix_niko_split_v2_noknob'_ in the _'via-files'_ folder

## Building Process

If you're interested in the Building Process or need help on planning etc., I've made a [Youtube-Video](https://www.youtube.com/watch?v=oRykmV-ImSI&t=30s&pp=ygUobmlrb2xhaiBrYXVmbWFubiBob3cgdG8gYnVpbGQgYSBrZXlib2FyZA%3D%3D) on how to build this keyboard.